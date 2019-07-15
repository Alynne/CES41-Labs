%{
#define VALID 1
#define INVALID 2
%}
delim			[ \t\n\r]
ws				{delim}+
invalid			(1*(01*01*)+)|(0*(10*10*)+)
valid			(0*1*)+
%%
{ws}			{ ;}
{invalid}		{return INVALID;}
{valid}			{return VALID;}
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