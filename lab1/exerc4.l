%{
#define WORD 1
%}
delim			[ \t\n\r]
ws				{delim}+
word            (0|1)+
%%
{ws}			{;}
{word}          {return WORD;}
%%

int main () {
	int token, length = 0, valid = 1;
    char word[50];
	while (token = yylex ()) {
        int block[5], ones = 0;
        int i = 0, length = 0;
        while(yytext[i]) {
            if (length < 5) {
                block[length] = yytext[i]-'0';
                ones += block[length];
                length++;
            }
            else if (ones < 3){
                break;
            }
            else {
                ones -= block[length%5];
                block[length%5] = yytext[i]-'0';
                ones += block[length%5];
                length++;
            }
            i++;
        }
        if (length >= 5 && ones >= 3)
            printf ("%-20s: Aceita\n", yytext); 
        else
            printf ("%-20s: Rejeita\n", yytext); 
	}
}