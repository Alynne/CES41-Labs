delim			[ \t\n\r]
ws				{delim}+
stringct        \"([^\"\\]|(\\\\)|(\\\")|(\\a)|(\\b)|(\\f)|(\\n)|(\\r)|(\\t)|(\\v)|(\\o)|(\\x))*\"
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
