#ifndef _EVALUATION_H
#define _EVALUATION_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "Shell.h"

#define Mode_Normal 0
#define Mode_BG 1

int evaluer_expr(Expression *e, unsigned char mode);

void execute(Expression *e, unsigned char mode);
void redirect(Expression *e, unsigned char mode);

#endif
