/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "Analyse.y"
#include "Shell.h"
extern int yylex(void);
#line 6 "Analyse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  Expression *Expr;
  char       **ListeArgs;
  char	     identificateur[TAILLE_ID];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 37 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFICATEUR 257
#define ET 258
#define OU 259
#define IN 260
#define OUT 261
#define OUT_APPEND 262
#define ERR 263
#define ERR_OUT 264
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    4,    3,    3,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    1,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,   18,    0,    0,    0,    0,    0,    2,    0,    1,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,   16,    0,    0,    0,    0,   17,   10,   11,   14,
   12,   13,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,   28,
};
static const YYINT yysindex[] = {                       -38,
   -4,    0,  -22,    0,    9,  -30, -247,    0,  -37,    0,
    0,  -22,  -22,  -22,  -22, -245, -245, -245, -245, -245,
    0,    0, -121, -121, -121, -237,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                        10,
    0,    0,    0,    0,    0,   11,  -10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -1,    1,    3,   -3,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    2,    0,   28,
};
#define YYTABLESIZE 262
static const YYINT yytable[] = {                          5,
   11,    3,   15,   22,    9,    8,    9,   11,    6,   21,
    7,   27,    8,   23,   24,   25,   26,    3,   10,    3,
    4,   12,   16,   17,   18,   19,   20,    5,   12,    0,
    5,    0,    0,    0,    9,    0,    6,    9,    7,    6,
    8,    7,    0,    8,   29,   30,   31,   32,    5,    0,
    0,    0,    0,    0,    0,    9,    0,    6,    0,    7,
    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,    0,    0,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   16,   17,
   18,   19,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    2,    0,
   13,   14,   16,   17,   18,   19,   20,   13,   14,   16,
   17,   18,   19,   20,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    5,    5,
    5,    5,    5,    5,    9,    9,    6,    6,    7,    7,
    8,    8,
};
static const YYINT yycheck[] = {                         10,
   38,   40,  124,   41,    3,   10,   10,   38,   10,  257,
   10,  257,   10,   12,   13,   14,   15,   40,   10,   10,
   10,   59,  260,  261,  262,  263,  264,   38,   59,   -1,
   41,   -1,   -1,   -1,   38,   -1,   38,   41,   38,   41,
   38,   41,   -1,   41,   17,   18,   19,   20,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   -1,   59,   -1,   59,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,  261,
  262,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,
  258,  259,  260,  261,  262,  263,  264,  258,  259,  260,
  261,  262,  263,  264,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,
  261,  262,  263,  264,  258,  259,  258,  259,  258,  259,
  258,  259,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 264
#define YYUNDFTOKEN 271
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'&'",0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"IDENTIFICATEUR","ET","OU","IN","OUT","OUT_APPEND","ERR","ERR_OUT",0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : lignecommande",
"lignecommande : expression_ou_rien '\\n'",
"lignecommande : error '\\n'",
"expression_ou_rien :",
"expression_ou_rien : expression",
"expression : commande",
"expression : expression ';' expression",
"expression : expression ET expression",
"expression : expression OU expression",
"expression : expression '|' expression",
"expression : expression IN fichier",
"expression : expression OUT fichier",
"expression : expression ERR fichier",
"expression : expression ERR_OUT fichier",
"expression : expression OUT_APPEND fichier",
"expression : expression '&'",
"expression : '(' expression ')'",
"fichier : IDENTIFICATEUR",
"commande : IDENTIFICATEUR",
"commande : commande IDENTIFICATEUR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 113 "Analyse.y"

#line 251 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 26 "Analyse.y"
	{
  		      ExpressionAnalysee = yystack.l_mark[-1].Expr;
  		      YYACCEPT;
		    }
break;
case 2:
#line 31 "Analyse.y"
	{
  		      yyclearin;
		      YYABORT;
		    }
break;
case 3:
#line 38 "Analyse.y"
	{
  			yyval.Expr = ConstruireNoeud (VIDE, NULL, NULL, NULL);
		    }
break;
case 5:
#line 46 "Analyse.y"
	{
  			yyval.Expr = ConstruireNoeud (SIMPLE, NULL, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 6:
#line 50 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (SEQUENCE, yystack.l_mark[-2].Expr, yystack.l_mark[0].Expr, NULL);
		    }
break;
case 7:
#line 54 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (SEQUENCE_ET, yystack.l_mark[-2].Expr, yystack.l_mark[0].Expr, NULL);
		    }
break;
case 8:
#line 58 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (SEQUENCE_OU, yystack.l_mark[-2].Expr, yystack.l_mark[0].Expr, NULL);
		    }
break;
case 9:
#line 62 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (PIPE, yystack.l_mark[-2].Expr, yystack.l_mark[0].Expr, NULL);
		    }
break;
case 10:
#line 66 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (REDIRECTION_I, yystack.l_mark[-2].Expr, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 11:
#line 70 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (REDIRECTION_O, yystack.l_mark[-2].Expr, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 12:
#line 74 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (REDIRECTION_E, yystack.l_mark[-2].Expr, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 13:
#line 78 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (REDIRECTION_EO, yystack.l_mark[-2].Expr, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 14:
#line 82 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (REDIRECTION_A, yystack.l_mark[-2].Expr, NULL, yystack.l_mark[0].ListeArgs);
		    }
break;
case 15:
#line 86 "Analyse.y"
	{
  		      yyval.Expr = ConstruireNoeud (BG, yystack.l_mark[-1].Expr, NULL, NULL);
		    }
break;
case 16:
#line 90 "Analyse.y"
	{
  		      yyval.Expr = yystack.l_mark[-1].Expr;
		    }
break;
case 17:
#line 96 "Analyse.y"
	{
  		      char **p = InitialiserListeArguments ();
  		      yyval.ListeArgs = AjouterArg (p, yylval.identificateur);
		    }
break;
case 18:
#line 103 "Analyse.y"
	{
  		      char **p = InitialiserListeArguments ();
  		      yyval.ListeArgs = AjouterArg (p, yylval.identificateur);
		    }
break;
case 19:
#line 108 "Analyse.y"
	{
		      yyval.ListeArgs = AjouterArg (yystack.l_mark[-1].ListeArgs,yylval.identificateur);
		    }
break;
#line 565 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
