%{
// Reserved words
#define CALL 1          // call
#define CHAR 2          // char
#define DO 3            // do
#define ELSE 4          // else
#define FALSE 5         // false
#define FLOAT 6         // float
#define FOR 7           // for
#define FUNCTIONS 8     // functions
#define GLOBAL 9        // global
#define IF 10           // if
#define INT 11          // int
#define LOCAL 12        // local
#define LOGIC 13        // logic
#define MAIN 14         // main
#define PROGRAM 15      // program
#define READ 16         // read
#define RETURN 17       // return
#define STATEMENTS 18   // statements
#define TRUE 19         // true
#define VOID 20         // void
#define WHILE 21        // while
#define WRITE 22        // write
// Syntax atoms
#define ID 23           // Identifier
#define INTCT 24        // Constant int
#define CHARCT 25       // Constant character
#define FLOATCT 26      // Constant float
#define STRING 27       // Character chain
// Operators
#define OR 28           // ||
#define AND 29          // &&
#define NOT 30          // !
#define RELOP 31        // < <= > >= = !=
#define ADOP 32         // + -
#define MULTOP 33       // * / %
#define NEG 34          // ~
// Separators and other atoms without attributes
#define ASSIGN 35       // <-
#define OPPAR 36        // (
#define CLPAR 37        // )
#define OPBRAK 38       // [
#define CLBRAK 39       // ]
#define OPBRACE 40      // {
#define CLBRACE 41      // }
#define SCOLON 42       // ;
#define COMMA 43        // ,
#define COLON 44        // :
union {
    char string[128];        // ID and STRING attribute
    int op;                 // For RELOP, ADOP and MULTOPs
    char charVal;           // CHARCT attribute
    int intVal;             // INTCT attribute
    float floatVal;         // FLOATCT attribute
} yylval;
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
%}
delim			[ \t\n\r]
ws				{delim}+
stringct        \"(.)+\"
letter          [a-zA-Z]
digit           [0-9]
id              {letter}({letter}|{digit})*
intct           {digit}+
charct          '(.|(\\[0ntr]))'
floatct         {digit}+\.{digit}*((E|e)(\+|-)?{digit}+)?
%%
{ws}            { ; }
{stringct}      { strcpy(yylval.string, yytext); return STRING; }
"<-"            { return ASSIGN; }
"("             { return OPPAR; }
")"             { return CLPAR; }
"["             { return OPBRAK; }
"]"             { return CLBRAK; }
"{"             { return OPBRACE; }
"}"             { return CLBRACE; }
";"             { return SCOLON; }
","             { return COMMA; }
":"             { return COLON; }
"||"            { return OR; }
"&&"            { return AND; }
"<="            { yylval.op = LEQ; return RELOP; }
"<"             { yylval.op = LT; return RELOP; }
">="            { yylval.op = GEQ; return RELOP; }
">"             { yylval.op = GT; return RELOP; }
"="             { yylval.op = EQ; return RELOP; }
"!="            { yylval.op = DIF; return RELOP; }
"!"             { return NOT;}
"+"             { yylval.op = PLUS; return ADOP; }
"-"             { yylval.op = MINUS; return ADOP; }
"*"             { yylval.op = TIMES; return MULTOP; }
"/"             { yylval.op = DIV; return MULTOP; }
"%"             { yylval.op = REM; return MULTOP; }
"~"             { return NEG; }
call            { return CALL; }
char            { return CHAR; }
do              { return DO; }
else            { return ELSE; }
false           { return FALSE; }
float           { return FLOAT; }
for             { return FOR; }
functions       { return FUNCTIONS; }
global          { return GLOBAL; }
if              { return IF; }
int             { return INT; }
local           { return LOCAL; }
logic           { return LOGIC; }
main            { return MAIN; }
program         { return PROGRAM; }
read            { return READ; }
return          { return RETURN; }
statements      { return STATEMENTS; }
true            { return TRUE; }
void            { return VOID; }
while           { return WHILE; }
write           { return WRITE; }
{id}            { strcpy(yylval.string, yytext); return ID; }
{intct}         { yylval.intVal = atoi(yytext); return INTCT; }
{charct}        {
    if (strncmp(yytext, "'\\", 2) == 0) {
        switch (yytext[2]) {
            case '0':
                yylval.charVal = '\0'; break;
            case 'n':
                yylval.charVal = '\n'; break;
            case 't':
                yylval.charVal = '\t'; break;
            case 'r':
                yylval.charVal = '\r'; break;
        }
    } else {
        yylval.charVal = yytext[1];
    }
    return CHARCT;
}
{floatct}       { yylval.floatVal = atof(yytext); return FLOATCT; }
%%

const char* def2type(int def) {
    switch (def) {
        // Reserved words
        case CALL:
            return "CALL";
        case CHAR:
            return "CHAR";
        case DO:
            return "DO";
        case ELSE:
            return "ELSE";
        case FALSE:
            return "FALSE";
        case FLOAT:
            return "FLOAT";
        case FOR:
            return "FOR";
        case FUNCTIONS:
            return "FUNCTIONS";
        case GLOBAL:
            return "GLOBAL";
        case IF:
            return "IF";
        case INT:
            return "INT";
        case LOCAL:
            return "LOCAL";
        case LOGIC:
            return "LOGIC";
        case MAIN:
            return "MAIN";
        case PROGRAM:
            return "PROGRAM";
        case READ:
            return "READ";
        case RETURN:
            return "RETURN";
        case STATEMENTS:
            return "STATEMENTS";
        case TRUE:
            return "TRUE";
        case VOID:
            return "VOID";
        case WHILE:
            return "WHILE";
        case WRITE:
            return "WRITE";
            // Syntax atoms
        case ID:
            return "ID";
        case INTCT:
            return "INTCT";
        case CHARCT:
            return "CHARCT";
        case FLOATCT:
            return "FLOATCT";
        case STRING:
            return "STRING";
            // Operators
        case OR:
            return "OR";
        case AND:
            return "AND";
        case NOT:
            return "NOT";
        case RELOP:
            return "RELOP";
        case ADOP:
            return "ADOP";
        case MULTOP:
            return "MULTOP";
        case NEG:
            return "NEG";
            // Separators and other without attributes
        case ASSIGN:
            return "ASSIGN";
        case OPPAR:
            return "OPPAR";
        case CLPAR:
            return "CLPAR";
        case OPBRAK:
            return "OPBRAK";
        case CLBRAK:
            return "CLBRAK";
        case OPBRACE:
            return "OPBRACE";
        case CLBRACE:
            return "CLBRACE";
        case SCOLON:
            return "SCOLON";
        case COMMA:
            return "COMMA";
        case COLON:
            return "COLON";
        default:
            return "UNKNOWN TYPE";
    }
}

const char* relop2type(int op) {
    switch (op) {
        case LT:
            return "LT";
        case LEQ:
            return "LEQ";
        case GT:
            return "GT";
        case GEQ:
            return "GEQ";
        case EQ:
            return "EQ";
        case DIF:
            return "DIF";
        default:
            return "UNKNOWN RELOP";
    }
}

const char* adop2type(int op) {
    switch (op) {
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        default:
            return "UNKNOWN ADOP";
    }
}

const char* multop2type(int op) {
    switch (op) {
        case TIMES:
            return "TIME";
        case DIV:
            return "DIV";
        case REM:
            return "REM";
        default:
            return "UNKNOWN MULTOP";
    }
}

const char* expandChar(char c) {
    switch (c) {
            case '\0':
                return "\\0";
            case '\n':
                return "\\n";
            case '\t':
                return "\\t";
            case '\r':
                printf("\n\n");
                return "\\r";
            default:
                return NULL;
        }
    
}

int main () {
	int i;
    printf("-------------------------------------------------------------------------\n");
    printf("%27s | %10s | %28s\n", "Texto", "Tipo", "Atributo");
    printf("-------------------------------------------------------------------------\n");
	while (i = yylex ()) {
        printf ("%28s| %10s |", yytext, def2type(i));
        const char * expanded = "";
        switch (i) {
			case ID:
				printf("%28s", yylval.string); break;
			case INTCT:
				printf("%28d", yylval.intVal); break;
            case CHARCT:
                expanded = expandChar(yylval.charVal);
                if (expanded != NULL) {
                    printf("%28s", expanded);
                } else {
                    printf("%28c", yylval.charVal);
                }
                break;
			case FLOATCT:
				printf("%28f", yylval.floatVal); break;
            case STRING:
                printf("%28s", yylval.string); break;
            case RELOP:
                printf("%28s", relop2type(yylval.op)); break;
            case ADOP:
                printf("%28s", adop2type(yylval.op)); break;
            case MULTOP:
                printf("%28s", multop2type(yylval.op)); break;
            default:
                printf("%28s", "XXXXXXXX"); break;
		}
		printf ("\n");
	}
}