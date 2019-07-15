%{
#define VALID 1
#define INVALID 2
%}
delim			[ \t\n\r]
ws				{delim}+
valid			(1*(01*01*)+)|(0*(10*10*)+)
invalid			[^ \t\r\n]+		
%%
{ws}			{ ;}
{valid}			{return VALID;}
{invalid}		{return INVALID;}
%%
int main () {
	int i;
	while (i = yylex ()) {
		switch(i) {
			case VALID:
				printf ("%-20s: Aceita\n", yytext); 
				break;
			case INVALID:
				printf ("%-20s: Rejeitada\n", yytext); 
				break;
		}
	}
}