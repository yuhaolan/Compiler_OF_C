enum ASTtype {
    PROGRAM,
   INTTYPE,
    IDENT,
    NUMBER,
    CALL,
    ARGLIST,
    VARDEC,
    FUNCTIONDEC,
    BLOCK,
    EXPRSTMT,
    ASSIGN,
    IFSTMT,
    RETURNEXPR,
    READSTMT,
    EXPR,
    WHILEEXPR,
    ADDEXPR,
    PARAMEXPR,
    WRITESTMT,
    FACTOR,
};

enum OPERATORS {
   PLUS,
   MINUS,
   TIMES,
    DIVIDE,
    LESSTHANEQUAL,
    LESSTHAN,
    GREATERTHAN,
    GREATERTHANEQUAL,
    EQUAL,
    NOTEQUAL,
    INTDEC,// INT???
    VOIDDEC,// VOID????
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/
typedef struct ASTnodetype
{
    enum ASTtype type;
     enum OPERATORS operator;
    enum OPERATORS istype;//!!!!! /* the inherited or synthisized types from expressions */
     char * name;
     int value;
     struct ASTnodetype *left,*right; /* left is usually the connector for statements */
     struct ASTnodetype *s1,*s2 ;/* used for holding IF and WHILE components -- not very descriptive */
    struct SymbTab *symbol;//
} ASTnode;


