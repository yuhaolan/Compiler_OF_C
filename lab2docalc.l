/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
*/
%{
int linecount = 1;
static int mydebug=0;
#include "y.tab.h"
%}


%%
"int" {return(INT);};
"void" {return(VOID);};
"while" {return(WHILE);};
"if" {return(IF);};
"then" {return(THEN);};
"else" {return(ELSE);};
"read" {return(READ);};
"write" {return(WRITE);};
"for" {return(FOR);};
"return" {return(RETURN);};
"<=" {return(LE);};
">=" {return(GE);};
"==" {return(EQ);};
"!=" {return(NE);};
[a-zA-Z][a-zA-Z0-9]* {if (mydebug) fprintf(stderr,"Letter found with string %s\n",yytext);
                       yylval.string = strdup(yytext); 
                       return(ID);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                      yylval.value = atoi((const char *)yytext); 
                      return(NUM);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[\[\]=<>\-+*/%&|(){};,] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);// I add '(' and ')' here to solve the problem that  parenthesis does not work
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                        linecount++;   }

%%

int yywrap(void)
{   printf("all done\n");
    return 1;}


