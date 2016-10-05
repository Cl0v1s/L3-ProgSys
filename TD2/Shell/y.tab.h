#define IDENTIFICATEUR 257
#define ET 258
#define OU 259
#define IN 260
#define OUT 261
#define OUT_APPEND 262
#define ERR 263
#define ERR_OUT 264
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
extern YYSTYPE yylval;
