%{
// No attribute atoms
#define ABPAR 1     // (
#define FPAR 2      // )
#define ABCHAV 3    // {
#define FCHAV 4     // }
#define ATRIB 5     // =
#define VIRG 6      // ,
#define PVIRG 7     // ;
// Reserved words
#define PROGRAM 8   // program
#define VAR 9       // var
#define INT 10      // int
#define REAL 11     // real
// Attributed atoms
#define ID 12       // Identifier
#define CTINT 13    // Int constant
#define CTREAL 14   // Real constant
#define OPAD 15     // Additive operator
#define OPMULT 16   // Multiplicative operator

// Operators' attributes
#define PLUS 17
#define MINUS 18
#define TIMES 19
#define DIV 20
union {
    char string[50];        // ID attribute
    int op;                 // OPAD and OPMULT attribute
    int intVal;             // INT attribute
    float realVal;          // REAL attribute
} yylval;
%}
delim			[ \t\n\r]
ws				{delim}+
letter          [a-zA-Z]
digit           [0-9]
id              {letter}({letter}|{digit})*
ctint           {digit}+
ctreal          {digit}+.{digit}+
opad_plus       +
%%
{ws}			{ ;}
"("             { return ABPAR; }
")"             { return FPAR; }
"{"             { return ABCHAV; }
"}"             { return FCHAV; }
"="             { return ATRIB; }
","             { return VIRG; }
";"             { return PVIRG; }
program         { return PROGRAM; }
var             { return VAR; }
int             { return INT; }
real            { return REAL; }
{id}            { strcpy(yylval.string, yytext); return ID; }
{ctint}         { yylval.intVal = atoi(yytext); return CTINT; }
{ctreal}        { yylval.realVal = atof(yytext); return CTREAL; }
"+"             { yylval.op = PLUS; return OPAD; }
"-"             { yylval.op = MINUS; return OPAD; }
"*"             { yylval.op = TIMES; return OPMULT; }
"/"             { yylval.op = DIV; return OPMULT; }
%%
int main () {
	int i;
    printf("-------------------------------------------\n");
    printf("%10s | %10s | %10s\n", "Texto", "Tipo", "Atributo");
    printf("-------------------------------------------\n");
	while (i = yylex ()) {
        printf ("%10s|%10d|", yytext, i);
        switch (i) {
			case ID:
				printf ("%10s", yylval.string); break;
			case CTINT:
				printf ("%10d", yylval.intVal); break;
			case CTREAL:
				printf ("%10f", yylval.realVal); break;
            case OPAD:
            case OPMULT:
                printf ("%10d", yylval.op); break;
            default:
                printf ("%10s", "X"); break;
		}
		printf ("\n");
	}
}