%{
    #include <stdio.h>
    // Operators desambiguation
    // RELOP
    #define LT 45           // <
    #define LEQ 46          // <=
    #define GT 47           // >
    #define GEQ 48          // >=
    #define EQ 49           // =
    #define DIF 50          // !=
    // ADOP
    #define PLUS 45         // +
    #define MINUS 46        // -
    // MULTOP
    #define TIMES 57        // *
    #define DIV 58          // /
    #define REM 59          // %
    // Number of tabulations for current line of pretty printer
    int ntabs = 0;
%}
%union {
    char string[128];        // ID and STRING attribute
    int op;                 // For RELOP, ADOP and MULTOPs
    char charVal;           // CHARCT attribute
    int intVal;             // INTCT attribute
    float floatVal;         // FLOATCT attribute
}
// Reserved words
%token CALL          // call
%token CHAR          // char
%token DO            // do
%token ELSE          // else
%token FALSE         // false
%token FLOAT         // float
%token FOR           // for
%token FUNCTIONS     // functions
%token GLOBAL        // global
%token IF           // if
%token INT          // int
%token LOCAL        // local
%token LOGIC        // logic
%token MAIN         // main
%token PROGRAM      // program
%token READ         // read
%token RETURN       // return
%token STATEMENTS   // statements
%token TRUE         // true
%token VOID         // void
%token WHILE        // while
%token WRITE        // write
// Syntax atoms
%token <string>     ID           // Identifier
%token <intVal>     INTCT        // Constant int
%token <charVal>    CHARCT       // Constant character
%token <floatVal>   FLOATCT      // Constant float
%token <string>     STRING       // Character chain
// Operators
%token OR           // ||
%token AND          // &&
%token NOT          // !
%token <op>     RELOP        // < <= > >= = !=
%token <op>     ADOP         // + -
%token <op>     MULTOP       // * / %
%token NEG          // ~
// Separators and other atoms without attributes
%token ASSIGN       // <-
%token OPPAR        // (
%token CLPAR        // )
%token OPBRAK       // [
%token CLBRAK       // ]
%token OPBRACE      // {
%token CLBRACE      // }
%token SCOLON       // ;
%token COMMA        // ,
%token COLON        // :
%%
Prog        :   PROGRAM ID OPBRACE {printf("program %s {\n\n", $2);} GlobDecls Functions CLBRACE {printf("}\n");}
GlobDecls   :    | GLOBAL COLON {print_tabs(); printf("global%c\n", ':'); ntabs++;} DeclList {ntabs--; printf("\n");}
DeclList    :   Declaration | DeclList Declaration
Declaration :   {print_tabs();} Type ElemList SCOLON {printf(";\n");}
Type        :   INT {printf("int");}  
            |   FLOAT {printf("float");}  
            |   CHAR {printf("char");}  
            |   LOGIC {printf("logic");}  
            |   VOID {printf("void");}
ElemList    :   Elem | ElemList COMMA {printf(",");} Elem
Elem        :   ID {printf(" %s", $1);} Dims
Dims        :    | OPBRAK {printf("[");} DimList CLBRAK {printf("]");}
DimList     :   INTCT {printf("%d", $1);} | DimList COMMA INTCT {printf(", %d", $3);}
Functions   :   FUNCTIONS COLON {print_tabs(); printf("functions%c\n", ':'); ntabs++;} FuncList {ntabs--;}
FuncList    :   Function {printf("\n");} | FuncList Function {printf("\n");}
Function    :   Header OPBRACE {printf(" {\n");} LocDecls Stats CLBRACE {print_tabs(); printf("}\n");}
Header      :   MAIN {printf("main");} 
            |   {print_tabs();} Type ID OPPAR {printf(" %s(", $3);} Params CLPAR {printf(")"); }
Params      :    | ParamList
ParamList   :   Parameter | ParamList COMMA {printf(", ");} Parameter
Parameter   :   Type ID {printf(" %s", $2);}
LocDecls    :    | LOCAL COLON {print_tabs(); printf("local%c\n", ':'); ntabs++;} DeclList {ntabs--;}
Stats       :   STATEMENTS COLON {print_tabs(); printf("statements%c\n", ':'); ntabs++;} StatList {ntabs--;}
StatList    :    | StatList Statement
Statement   :   CompStat
            |   {print_tabs();} IfStat
            |   {print_tabs();} WhileStat
            |   {print_tabs();} DoStat
            |   {print_tabs();} ForStat
            |   {print_tabs();} ReadStat {printf("\n");}
            |   {print_tabs();} WriteStat {printf("\n");} 
            |   {print_tabs();} AssignStat {printf("\n");}
            |   {print_tabs();} CallStat {printf("\n");}
            |   {print_tabs();} ReturnStat {printf("\n");}
            |   {print_tabs();} SCOLON {printf("\n");}
CompStat    :   OPBRACE {ntabs--; print_tabs(); ntabs++; printf("{\n");} StatList CLBRACE {ntabs--; print_tabs(); ntabs++; printf("}\n");}
IfStat      :   IF {printf("if");} OPPAR {printf(" (");} Expression CLPAR {printf(")\n"); ntabs++;} Statement {ntabs--;} ElseStat
ElseStat    :    | ELSE {print_tabs(); printf("else\n"); ntabs++;} Statement {ntabs--;}
WhileStat   :   WHILE {printf("while");} OPPAR {printf(" (");} Expression CLPAR {printf(")\n"); ntabs++;} Statement {ntabs--;}
DoStat      :   DO {printf("do\n"); ntabs++;} Statement WHILE OPPAR {ntabs--; print_tabs(); printf("while (");} Expression CLPAR SCOLON {printf(");\n");}
ForStat     :   FOR OPPAR {printf("for (");} Variable ASSIGN {printf(" <- ");} 
                Expression SCOLON {printf("; ");} Expression SCOLON {printf("; ");}
                Variable ASSIGN {printf(" <- ");} Expression CLPAR {printf(")\n"); ntabs++;} Statement {ntabs--;}
ReadStat    :   READ OPPAR {printf("read(");} ReadList CLPAR SCOLON {printf(");");}
ReadList    :   Variable | ReadList COMMA {printf(", ");} Variable
WriteStat   :   WRITE OPPAR {printf("write(");} WriteList CLPAR SCOLON {printf(");");}
WriteList   :   WriteElem | WriteList COMMA {printf(", ");} WriteElem
WriteElem   :   STRING {printf("%s", $1);} | Expression
CallStat    :   CALL {printf("call ");} FuncCall SCOLON {printf(";");}
FuncCall    :   ID OPPAR {printf("%s(", $1);} Arguments CLPAR {printf(")");} 
Arguments   :    | ExprList
ReturnStat  :   RETURN SCOLON {printf("return;\n");} | RETURN {printf("return ");} Expression SCOLON {printf(";\n");}
AssignStat  :   Variable ASSIGN {printf(" <- ");} Expression SCOLON {printf(";");}
ExprList    :   Expression | ExprList COMMA {printf(", ");} Expression
Expression  :   AuxExpr1 | Expression OR {printf(" || ");} AuxExpr1
AuxExpr1    :   AuxExpr2 | AuxExpr1 AND {printf(" && ");} AuxExpr2
AuxExpr2    :   AuxExpr3 | NOT {printf("!");} AuxExpr3
AuxExpr3    :   AuxExpr4 | AuxExpr4 RELOP {
    switch ($2) {
        case LEQ:
            printf(" <= ");
            break;
        case LT:
            printf(" < ");
            break;
        case GEQ:
            printf(" >= ");
            break;
        case GT:
            printf(" > ");
            break;
        case EQ:
            printf(" = ");
            break;
        case DIF:
            printf(" != ");
            break;
    }
} AuxExpr4
AuxExpr4    :   Term | AuxExpr4 ADOP {
    switch ($2) {
        case PLUS:
            printf(" + ");
            break;
        case MINUS:
            printf(" - ");
            break;
    }
} Term
Term        :   Factor | Term MULTOP {
    switch ($2) {
        case TIMES:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case REM:
            printf("%%");
            break;
    }
} Factor
Factor      :   Variable 
            |   INTCT {printf("%d", $1);}
            |   FLOATCT {printf("%g", $1);}
            |   CHARCT {
                printf("'");
                switch ($1) {
                    case '\0':
                        printf("\\0");
                        break;
                    case '\a':
                        printf("\\a");
                        break;
                    case '\b':
                        printf("\\b");
                        break;
                    case '\f':
                        printf("\\f");
                        break;
                    case '\n':
                        printf("\\n");
                        break;
                    case '\r':
                        printf("\\r");
                        break;
                    case '\t':
                        printf("\\t");
                        break;
                    case '\v':
                        printf("\\v");
                        break;
                    case '\'':
                        printf("\\'");
                    default:
                        printf("%c", $1);
                }
                printf("'");
            }
            |   TRUE {printf("true");}
            |   FALSE {printf("false");}
            |   NEG {printf("~");} Factor
            |   OPPAR {printf("(");} Expression CLPAR {printf(")");} | FuncCall
Variable    :   ID {printf("%s", $1);} Subscripts
Subscripts  :    | OPBRAK {printf("[");} SubscrList CLBRAK {printf("]");}
SubscrList  :   AuxExpr4 | SubscrList COMMA {printf(", ");} AuxExpr4
            ;
%%

#include "lex.yy.c"

int yyerror ( char * msg ) {
    fprintf ( stdout, "%s\n", msg ) ;
}

void print_tabs() {
    for (int i=0; i<ntabs; i++)
        printf("\t");
}

int main() {
	yyparse();
	return 0;
}