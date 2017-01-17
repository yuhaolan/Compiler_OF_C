/*   Abstract syntax tree code

     This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper February 2015

*/

#include<stdio.h>
#include<stdlib.h>
static int mydebug;

#ifndef SYMTABLE
#define SYMTABLE
#include "symbol.h"
#endif


#ifndef AST
#define AST
#include "AST.h"
#endif


/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

/* this is a partial list of NODE types for the ASTNode */

//ASTnode program ->  left  -> name ; value ;


/* uses malloc to create an ASTnode and passes back the heap address of the newly created node */
ASTnode *ASTCreateNode(enum ASTtype mytype)
{
    enum OPERATORS myoperator;
    ASTnode *p;
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p=(ASTnode *)malloc(sizeof(ASTnode));
    p->type=mytype;//VARDEC
    p->name=NULL;// x
    p->operator=myoperator;// INTDEC ??????!!!!!!
    p->left=NULL;
    p->right=NULL;
    p->s1=NULL;
    p->s2=NULL;
    p->value=0;// int x[200]   200 is the value
    return(p);
}

/* attach q to the left most part of p */
void ASTattachleft(ASTnode *p,ASTnode *q)
{
    while (p->left != NULL)
    {
        p = p->left;//!!
    }
    p->left = q;
}

ASTnode *program;

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)// what is level
{
   int i;
   if (p == NULL ) return;
   else
     { 
     for (i=0;i<level;i++) printf(" "); /* print tabbing blanks */
      
       switch (p->type)
    {
            //declaration
            case VARDEC :
                printf("Variable ");
                switch(p->operator)
                {
                    case INTDEC : printf("INT");break;
                    case VOIDDEC : printf("VOID");break;
                
                }
               printf(" %s",p->name);
                     if (p->value > 0)
                     {
                        printf("[%d]",p->value);
                     }
                     printf("\n");
                     break;
            
            //funciton
           case FUNCTIONDEC :
                switch(p->operator)
                {
                    case INTDEC : printf("INT ");break;
                    case VOIDDEC : printf("VOID ");break;
    
                }
               printf("FUNCTION %s\n",p->name);
               if (p->s1 == NULL)
               {
                   printf("(VOID)\n");
               }
               else
               {
                   printf("  (\n");
                   ASTprint(level+2,p->s1);//print the PARAMEXPR
                   printf(" )\n");
               }
               ASTprint(level+2,p->right);//print the BLOCK
               break;
            
           case BLOCK :
               printf("BLOCK STATEMENT\n");
               ASTprint(level+2,p->right);
               break;
            
           case PARAMEXPR :
            
            printf("PARAMETER ");
               switch(p->operator)
                {
                    case INTDEC : printf("INT");break;
                    case VOIDDEC : printf("VOID");break;
                
                }
            printf(" %s\n",p->name);
               if (p->value > 0)
                   printf("[%d]",p->value);
               break;
            
            //assignment statement
           case ASSIGN :
               printf(" ASSIGNMENT STATMENT\n");
               ASTprint(level+2,p->right);//VAR==IDENT
               ASTprint(level+2,p->s1);//
               break;
            
           case IDENT :
               printf("IDENTIFIER %s\n",p->name);
                //check the right is null or not
               if (p->right != NULL)
               {
                   printf("     Array Reference [\n");
                   ASTprint(level+2,p->right);
                   printf("      ] end array\n");
               }
               break;
            
           case EXPR :
               printf(" EXPR");
               switch(p->operator)
                {
                    case LESSTHANEQUAL : printf("   LE\n");break;
                    case LESSTHAN : printf("    <\n");break;
                    case GREATERTHAN : printf(" >\n");break;
                    case GREATERTHANEQUAL : printf("GE\n");break;
                    case EQUAL : printf("   EQ\n");break;
                    case NOTEQUAL : printf("    NE\n");break;
                    case PLUS : printf("    +\n");break;
                    case MINUS : printf("   -\n");break;
                    case TIMES : printf("   *\n");break;
                    case DIVIDE : printf("  /\n");break;
                }
               ASTprint(level+2,p->right);//additiveexpression
               //relop
               ASTprint(level+2,p->s1);//additiveexpression
               break;
            
            case NUMBER :
                if (p->value >0)
                    printf("Number with value %d\n",p->value);
                break;
            
            case CALL :
                printf("Call with name %s",p->name);
                ASTprint(level+2,p->right);
                break;
            
            //if statement
            case IFSTMT :
                printf("IF STATMENT\n");
                ASTprint(level+2,p->right);
                ASTprint(level+2,p->s1);
                ASTprint(level+2,p->s2);
            break;
            //while loop
            case WHILEEXPR :
                printf("WHILE STATMENT\n");
                ASTprint(level+2,p->right);
                ASTprint(level+2,p->s1);
                break;
            
            //return
            case RETURNEXPR :
                printf("RETURN STATMENT\n");
                ASTprint(level+2,p->right);
                break;
            //read
            case READSTMT :
                printf("READ STATMENT\n");
                ASTprint(level+2,p->right);
                break;
            //write
            case WRITESTMT :
                printf("WRITE STATMENT\n");
                ASTprint(level+2,p->right);
                break;
            case EXPRSTMT :
                printf("EXPRISSION STATMENT\n");
                ASTprint(level+2,p->right);
                break;
            case ARGLIST :
                printf("ARGLIST\n");
                ASTprint(level+2,p->right);
                ASTprint(level+2,p->left);
                break;
            
            
           default: printf("unknown type in ASTprint\n");


       }
         ASTprint(level,p->left);
     }

}


//!!
//!!!!

int CompareFormals(ASTnode *p, ASTnode *q)
{
    
    if ( (p == NULL) && (q ==NULL) ) { return (1);}
    else
        if  ( (p==NULL) ||  (q == NULL )) return (0);
        else
            if  (p->istype == q->right->istype )
                CompareFormals(p->left, q->left);
            else
            { printf ("comparing p %d and q %d \n",p->istype,q->istype);
                return(0);
            }
    
}

/*dummy main program so I can compile for syntax error independently
main()
{
}
 */
