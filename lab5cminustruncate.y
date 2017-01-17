%{
/*
 *			**** CMINUS ****
 *
 *
 */

/* 
   This lab is designed for you to create YACC directives using the EBNF description of Cminus.

   You are to take the EBNF of CMINUS and create YACC rules that will syntically check if an input
   program is syntactically correct.  You DO NOT have to do any type checking or any checking if an ID 
   has been defined.  

   The nice part of YACC is that it will do the checking for you as long as you define things correctly.
   You will need to report any syntax errors on the appropriate line.  If possible, you should have YACC
    continue with the parsing until end of file

   You will need to ensure that you define your tokens properly and with the correct return values.

   Shaun Cooper
    January 2015

*/


	/* begin specs */
#define max(a,b) (((a)>(b))?(a):(b))
static int level = 0;
static int goffset=0;
static int offset=0;
static int maxoffset=0;
    /* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "ast.c"
#include "symbol.c"
#include "emit.c"
#include "lex.yy.c"

#ifndef SYMTABLE
#define SYMTABLE
#include "symbol.h"
#endif


#ifndef AST
#define AST
#include "AST.h"
#endif


void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}

FILE *fp;

%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P

%union {
      int value;
      char * string;
      ASTnode * node;  /* so we can build an AST */
      enum OPERATORS operator;
      
}



%token <value> NUM INT VOID WHILE IF THEN ELSE READ WRITE FOR RETURN LE GE EQ NE
%token  <string> ID
%type <node> P DL DEC VARDEC FUNDEC compoundstmt localdeclarations statementlist expressionstmt assignmentstmt selectionstmt returnstmt readstmt expression var simpleexpression  factor call args arglist statement additiveexpression  iterationstmt writestmt term params paramlist param
%type <operator> typespec relop addop multop



%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

P	:	DL   /* PRogram -> Declartion-list */
        {
            program=$1;
        }
	;

DL	:	DEC
        {
            $$=$1;
        }   /*  Declaration-list -> Declaration { Declaration} */
    |      DEC DL//Right recusive!!!
        {
            $1->left=$2;
            $$= $1; /*left connect declarations */
            if (mydebug)  ASTprint(0,$1);//?????
            if (mydebug) ASTprint(0,$2);//?????
        }
    ;

DEC	: VARDEC
        {
            $$=$1;
        }
    | FUNDEC
        {
            $$=$1;
        } /*  Declaration -> Variable-Declaration | Function-Declaration */
    ;

VARDEC	: typespec ID  ';'
            { /* search symbol table for ID
                              insert if OK, then add the pointer from 
                              insertion into the  ASTnode to have reference
                              to the symbol table entry */
                
    //struct SymbTab * Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
                if (Search($2,level,0)==NULL)
                {
                    $$=ASTCreateNode(VARDEC);
                    $$->name=$2; /* this changes to symbol table*/
                    $$->operator=$1;
                    
                    
                    $$->istype=$1;//!!
                    $$->symbol = Insert($2,$1,0,level,1,offset,NULL);
                    offset += 1;
                }
                else
                {
                    yyerror($2);
                    yyerror("symbol already used ");
                    exit(1);
                }
                //Display();
            }
        | typespec ID  '[' NUM ']' ';'
            { /* search symbol table for ID, if not, place in there with size of array*/


                

                if (Search($2,level,0)==NULL)
                {
                    $$=ASTCreateNode(VARDEC);
                    $$->operator=$1;
                    $$->name=$2; /* this changes to symbol table*/
                    $$->value=$4; /* remember dimension*/
                    printf("found an array declaration \n");
                    
                    
                    $$->istype = $1;//!!
                    $$->symbol = Insert($2,$1,2,level,$4,offset,NULL);//2 is an array!!
                    offset += $4;
                }
                else
                {
                    yyerror($2);
                    yyerror("symbol already used ");
                    exit(1);
                }
                //Display();
            }
                         
        ;

typespec	: INT
                {
                    $$ = INTDEC;
                }
            | VOID
                {
                    $$ = VOIDDEC;
                }
            ;

FUNDEC	:  typespec ID '('

{
    if (Search($2,level,0)==NULL)
    {
        //printf("level in function is %d",level);
        goffset = offset;// when meet the function save the offset to goffset
        offset = 2;
        maxoffset=offset;
        Insert($2,$1,1,level,0,0,NULL);
    }
    else
    {
        yyerror($2);
        yyerror("name already used");
        exit(1);
    }
    //Display();
}


        params


{
        struct SymbTab *p;//!!
        p=Search($2,level,0);//!!
        p->fparms=$5;//!!
}








')' compoundstmt
                { /* search symbol table for ID
                              insert if OK, then add the pointer from
                              insertion into the  ASTnode to have reference
                              to the symbol table entry */

                            /* need to add paramater listing */
                    $$=ASTCreateNode(FUNCTIONDEC);
                    $$->operator=$1;//????
                    $$->name=$2; /* this changes to symbol table*/
                    $$->right = $8; /* compound statement */
                    $$->s1 = $5;
                    
                    
                    $$->istype=$1;//!!??
                    $$->symbol=Search($2,level,0);//!!??
                    
                     printf("@@@@@the offset in function is %d\n",offset);
                     maxoffset = max(maxoffset,offset);//!!

                     printf("##### MAXOFFSET is ####### %d\n",maxoffset);

                    $$->value=maxoffset;

                    offset -= Delete(1);//!!
                    level=0;//!!
                    
                    
                    offset = goffset;// When the function is done, we must reset the main offset to a stored global offset ( I call mine goffset ).
                    
                
                }

                   
        ;

params	: VOID
            {
                $$ = NULL;
            }
        |  paramlist
            {
                $$ = $1;
            }
        ;

paramlist	: param
                {
                    $$ = $1;
                }
            | paramlist ',' param//left recusive!!!
                {
                    //$1->left=$3;//???
                    ASTattachleft($1,$3);//link together
                    $$ = $1;//????
                    if (mydebug)  ASTprint(0,$1);//?????
                    if (mydebug) ASTprint(0,$3);//?????
                }

            ;

param	:	typespec ID
                {
                   
                    
                    if (Search($2,level+1,0)==NULL)// why is level+1? not 1
                    {
                        
                        
                        $$=ASTCreateNode(PARAMEXPR);
                        $$->operator=$1;
                        $$->name=$2;
                        
                        $$->istype=$1;//!!
                        $$->symbol=Insert($2,$1,0,level+1,1,offset,NULL);//all param is level 1
                                                            // why the myzise is 1
                                                            
                        mydebug && printf("Already in param insert %s %d\n",$2,level+1);//!!
                        $$->value=0;//!! not an array
                        offset += 1;
                    }
                    else
                    {
                        yyerror($2);
                        printf("the para has been declared\n");
                        exit(1);
                    }
                    //Display();
                    
                    
                }
	|	typespec ID '[' ']'
            {
              
                
                if (Search($2,level+1,0)==NULL)
                {
                    $$=ASTCreateNode(PARAMEXPR);
                    $$->operator=$1;
                    $$->name=$2;
                    //printf("insert");
                    $$->istype=$1;
                    $$->symbol=Insert($2,$1,2,level+1,1,offset,NULL);//0 scalar 1 function 2 array
                    offset += 1;
                }
                else
                {
                    yyerror($2);
                    yyerror("the para array has been declared\n");
                    exit(1);
                }
               // Display();
            }
	;

   /* need to fix this to include local declarations into symbol table*/
compoundstmt : '{'
{
    level++;
    mydebug && printf("BLOCK level is %d\n",level);
    
}

                  localdeclarations statementlist '}'

                        {
                            
                          $$=ASTCreateNode(BLOCK);
                          if ($3==NULL) /* no local declarations */
                                $$->right=$4;
                          else
                           { /* we had some declarations, put them together */
                             ASTattachleft($3,$4);
                             $$->right=$3;
                           }
                           
                           Display();  /* display symbol table as per requirement */
                           maxoffset=max(maxoffset,offset);
                            printf("##### MAXOFFSET is ######!!!! %d\n",maxoffset);

                           offset-=Delete(level);  /* decrease the offset count by the size of values allocated at level */
                           level--;  /* down one level */
                           Display();
                       }
 	      ;

localdeclarations :  VARDEC localdeclarations
                        {
                            $1->left=$2;//?? why use left??
                            $$=$1;
                        }
                  | /* empty */
                        {
                            $$=NULL;
                        }
                   ;

/* for statements , left is the next statement, right is what this statement is */
statementlist :  /* empty */
                {
                    $$=NULL;
                }
              | statement statementlist
                {
                    $1->left=$2;
                    $$=$1;
                }
              ;

statement : 	expressionstmt
                    {
                        $$ = $1;
                    } //!!!
		| compoundstmt
                    {
                        $$ = $1;
                    }
		| selectionstmt
                    {
                        $$ = $1;
                    }
		| iterationstmt
                    {
                        $$ = $1;
                    }
		| assignmentstmt
                    {
                        $$ = $1;
                    }
		| returnstmt
                    {
                        $$ = $1;
                    }
		| readstmt
                    {
                        $$ = $1;
                    }
		| writestmt
                    {
                        $$ = $1;
                    }
                ;

expressionstmt : expression ';'
                    {
                        //why!!??
                        $$=ASTCreateNode(EXPRSTMT);
                        $$->istype=$1->istype;
                        $$->right=$1;
                        //$$=$1;
                    }
		| ';'
            {
                $$=NULL;
            }
 		;

assignmentstmt : var '=' expressionstmt 
                      {$$=ASTCreateNode(ASSIGN);
                          /* Assignment statement  we leave left alone so that
                             it can be strung with other statements	*/ 
                              $$->right=$1;
                              $$->s1=$3;
                              
                              
                              
                              
                              if(($1->istype == VOIDDEC) || ($1->istype != $3->istype))
                              {
                                  yyerror("type error in assignment statement");
                                  exit(1);
                              }
                      }
               ;




selectionstmt : IF '(' expression ')' statement
                    {
                        $$=ASTCreateNode(IFSTMT);
                        $$->right=$3;
                        $$->s1=$5;
                        $$->s2=NULL;
                    }
                | IF '(' expression ')' statement ELSE statement
                    {
                        $$=ASTCreateNode(IFSTMT);
                        $$->right=$3;
                        $$->s1=$5;
                        $$->s2=$7;//!!
    
                    }

               ;

iterationstmt : WHILE '(' expression ')' statement
                    {
                        $$=ASTCreateNode(WHILEEXPR);
                        $$->right = $3;
                        $$->s1=$5;
                    }
                ;

returnstmt : RETURN ';'
                {
                    $$=ASTCreateNode(RETURNEXPR);
                }
|  RETURN expression  ';'
                {
                    $$=ASTCreateNode(RETURNEXPR);
                    $$->right=$2;
                }
    
            ;

readstmt : READ var ';'
            { /* make sure variable is in symbol table */
                        /*  Create a ASTnode for this statement on the right */
                $$=ASTCreateNode(READSTMT);
                          /* this will be pointer to symbol table */
                $$->right=$2;//????
            }
          ;


writestmt : WRITE expression ';'
                { /* make sure variable is in symbol table */
                    $$=ASTCreateNode(WRITESTMT);
                    $$->right=$2;
                          /*  Create a ASTnode for this statement on the right */
                          
                
                }
          ;


expression :   simpleexpression
                {
                    $$=$1;
                }
           ;


/* Here we make use of the SymTab structure. We first check to see if the symbol has been inserted, if not we can proceed to add. We create an ident node and set name, symbpl, etc. Accordingly. After we change the pointer to the symbol table, and create an istype. We check to see if p is a function, if it is we can print our our error message. Our else statement then shows that we have an undeclared varaible. For our ID expression we go thru the same emchanics, but include expression.*/
var	: ID
        {
            struct SymbTab *p;
            if ((p=Search($1,level,1)) != NULL)
            {  $$=ASTCreateNode(IDENT);
                $$->name=$1; /*change this to pointer to symbol table */
                $$->symbol=p;
                $$->istype=p->Type;
                if (p->IsAFunc == 2)
                { yyerror($1);
                    yyerror("variable is an array, syntax error ");
                    exit(1);
                }
            }
            else
            {   yyerror($1);
                yyerror("undeclared variable ");
                exit(1);
            }
            
            
            
        }
                /* we want to create a NODE called IDENTIFIER with a pointer to the SYMBOL table */
                 
	| ID  '[' expression ']'
        {
            struct SymbTab *p;
            if ((p=Search($1,level,1)) != NULL)
            {
                $$=ASTCreateNode(IDENT);
                $$->name=$1; /*change this to pointer to symbol table */
                $$->right=$3;
                $$->istype=p->Type;  /* inherit the type */
                /* check to see if the symbol is an array */
                if ( p->IsAFunc == 2) $$->symbol=p;  /* either 0 or bigger than 1 */
                else
                {
                    yyerror($1);
                    yyerror("not an array, type mismatch");
                    exit(1);
                }
            }
            else
            {
                yyerror($1);
                yyerror("undeclared variable ");
                exit(1);
            }
        
        
        
        }
    ;


simpleexpression : additiveexpression
                    {
                        $$=$1;
                    }//????
                  | additiveexpression relop additiveexpression 
                       {
                           
                           
                           if($1->istype != $3->istype)
                           {
                               yyerror("terms type mismatch");
                               exit(1);
                           }
                          
                               
                               $$=ASTCreateNode(EXPR);
                               $$->right=$1;
                               $$->operator=$2;
                               $$->s1=$3;
                           //Creating a temporary variable to hold the intermediate values
                           $$->name=CreateTemp();
                           
                           $$->istype=$1->istype;//The type is assigned to istype of the ASTnode to keep a track of it.

                           $$->symbol=Insert($$->name,INTDEC,0,level,1,offset,NULL);
                           
                           offset++;//!!
                           
                       }

                  ;


relop : LE
        {
            $$=LESSTHANEQUAL;
        }
      | '<'
        {
            $$=LESSTHAN;
        }
      | '>'
        {
            $$=GREATERTHAN;
        }
      | GE
        {
            $$=GREATERTHANEQUAL;
        }
      | EQ
        {
            $$=EQUAL;
        }
      | NE
        {
            $$=NOTEQUAL;
        }
      ;

additiveexpression : term
                        {
                            $$=$1;
                        }
    
                    | additiveexpression  addop term
                        {
                           
                            
                         
                            
                    // here we do the type checkingt
                            
                            if ($1->istype != $3->istype)
                            {
                                yyerror("Additive term Type confilct");
                                exit(1);
                            }
                            
                                $$=ASTCreateNode(EXPR);//!!
                                $$->right=$1;
                                $$->operator=$2;
                                $$->s1=$3;
                                
                                
                                
                                
                                $$->name=CreateTemp();
                                $$->istype=INTDEC;//!!??
                                $$->symbol=Insert($$->name,INTDEC,0,level,1,offset,NULL);//!!
                                offset++;//??



                            
                        }//!!
                    ;

addop : '+'
        {
            $$=PLUS;
        }
      | '-'
        {
            $$=MINUS;
        }
      ;

term : factor
        {
            $$=$1;
        }
     | term  multop factor// should left rucrise
        {
            //!!
            if ($1->istype != $3->istype)
            {
                yyerror("term type ERROR *mismatch* ");
                exit (1);
            }
            $$=ASTCreateNode(EXPR);
            $$->right=$1;
            $$->operator=$2;
            $$->s1=$3;
            //!!
            $$->istype=INTDEC;
            $$->name=CreateTemp();
            $$->symbol=Insert($$->name,INTDEC,0,level,1,offset,NULL);
            offset++;

        }
     ;

multop : '*'
            {
                $$=TIMES;
            }
       | '/'
            {
                $$=DIVIDE;
            }
       ;

factor : '(' expression ')'
            {
                $$=$2;
            }
       | NUM
            {
                $$=ASTCreateNode(NUMBER);
                $$->value=$1;
                
                $$->istype=INTDEC;//!!!!!
            }
       | var
            {
                $$=$1;
            }
       | call
            {
                $$=$1;
            }
       ;

call : ID '(' args ')'      // f()
          {
            
            
            //every time I see ID I need search
            struct SymbTab *p;

            if ((p=Search($1,level,1)) == NULL)//!! why is 0
            {
                yyerror($1);
                yyerror("Function name is not defined");
                exit(1);
            }
            else
            {
            
                if(p->IsAFunc!=1)
                { //Checking if the variable fund is a function.
                    printf("%d",p->IsAFunc);
                    yyerror($1);
                    yyerror("It is not a function");
                    exit(1);
                }
                
                if(CompareFormals(p->fparms,$3)!=1)
                { //The formal and actual parameters are compared.
                    
                    yyerror($1);
                    yyerror("Number of parameters in actual and formal are not equal or there is type mismatch");
                    exit(1);
                }
                
                
                $$=ASTCreateNode(CALL);
                $$->right=$3;
                $$->name=$1;  /*symbol table check */
                
                $$->symbol=p;
                $$->istype=p->Type;
                
                
                
            }
            
            
          }
     ;

args : arglist
        {
            $$=$1;
        }
      | /* empty */
        {
            $$=NULL;
        }
     ;

arglist : expression
            {
                $$=$1;
                //!!
                $$=ASTCreateNode(ARGLIST);
                $$->right=$1;
                $$->istype=$1->istype;
            }
         | expression ',' arglist
            {
                $$=ASTCreateNode(ARGLIST);
                $1->left=$3;
                $$=$1;
                //!!
           }
         ;



%%	/* end of rules, start of program */
main(int argc, char *argv[]){
    int i;
    int yaccDebug,lexDebug;
    //printf("%d",argc);
    for(i = 1; i < argc; i++){
        if(strcmp(argv[i],"-d")==0){
            yaccDebug = 1;
            lexDebug = 1;
        }
        if(strcmp(argv[i],"-o")==0){
            char s[100];//char *s  is wrong! because it did not give us enough memory size
            //argv[++i]
                      //  printf("I am here 3\n");

            strcpy(s,argv[++i]);
            strcat(s,".asm");
            fp = fopen(s,"w");
            if(fp==NULL)
            exit(1);
        }
    }
    yyparse();
    
    fprintf(stderr,"the input has been syntactically checked\n");
    fprintf(stderr,"Display runned in main\n");
    Display();
    ASTprint(0,program);
    emitASTprint(program,fp);//!!
    //fclose(fp);
}