#include "Evaluation.h"


void
verifier(int cond, char *s)
{
  if (!cond)
    {
      perror(s);
      exit(1);
    }
}



int
evaluer_expr(Expression *e, unsigned char mode)
{
  waitpid(-1, NULL, WNOHANG); // On élimine un zombie, non bloquant, si on a pas de zombie à eliminer on continue 
  switch(e->type)
  {
    case SIMPLE: // Execution d'une commande simple
      execute(e, mode);
    break;
    case REDIRECTION_O: // Redirection de la sortie standard mode normal
      redirect(e, mode);
    break;
    case BG: // Passage en mode background
      evaluer_expr(e->gauche, Mode_BG);
    break;  
    case SEQUENCE: // Examen d'une sequence contenant deux commandes
      evaluer_expr(e->gauche, mode);
      evaluer_expr(e->droite, mode);
      break;
    default:
      evaluer_expr(e->gauche, mode);
    break;
  }
  return 1;
}

void redirect(Expression *e, unsigned char mode)
{
      int backup, file;
      backup = dup(1); // Duplication de la sortie standard pour sauvegarde
      file = open(e->arguments[0], O_CREAT | O_WRONLY | O_TRUNC); // ouverture d'un nouveau fichier
      dup2(file, 1); // Copie du descripteur de fichier 
      evaluer_expr(e->gauche, mode); 
      dup2(backup, 1); //restauration de la sortie standard
      close(file); // Fermeture du fichier de sortie 
}

void execute(Expression *e, unsigned char mode)
{
      int child;
      child = fork();
      if(child == 0)
      {
        execvp(e->arguments[0], e->arguments);
      }
      else
      {
        if(mode != Mode_BG) // SI on est pas en mode background, on ne récupère pas la main tant que le procéssus n'est pas terminés
          wait(NULL);
      }
}
