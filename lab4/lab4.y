%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
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

    /* alynne: Definicao dos tipos de variaveis   */

    #define 	NAOVAR		0
    #define 	INTEIRO		1
    #define 	LOGICO		2
    #define 	REAL		3
    #define 	CARACTERE	4

    /* alynne:  Definicao de outras constantes   */

    #define	NCLASSHASH	23
    #define	VERDADE		1
    #define	FALSO		0

    /* alynne: Strings para nomes dos tipos de identificadores  */

    char *nometipid[4] = {" ", "IDPROG", "IDVAR", "IDFUNC"};

    /* alynne: Strings para nomes dos tipos de variaveis  */

    char *nometipvar[5] = {"NAOVAR",
    	"INTEIRO", "LOGICO", "REAL", "CARACTERE"
    };

    /* alynne:  Definition of type of identifier   */

    #define 	IDGLOB		1
    #define 	IDVAR		2
    #define     IDFUNC      3
    #define     IDPROC      4
    #define     IDPROG      5

    /*alynne: Definição dos tipos de parametros   */

    #define     PARAMVAL    1
    #define     PARAMREF    2
    /* alynne: APAGAR ISSO ANTES DE ENVIAR MUITO IMPORTANTE PELO AMOR DE DEUS
    Não sei quanto é pra ser maxdims, vou cartear*/
    #define     MAXDIMS     10


    /*  Listas de simbolos  */

    typedef struct elemlistsimb elemlistsimb;
    typedef elemlistsimb *pontelemlistsimb;
    typedef elemlistsimb *listsimb;
    typedef struct celsimb celsimb;
    typedef celsimb *simbolo;
    struct elemlistsimb {
    	simbolo simb; 
    	pontelemlistsimb prox;
    };

    /* alynne:    Declaracoes para a tabela de simbolos     */
    //typedef struct celsimb celsimb;
    //typedef celsimb *simbolo;
    struct celsimb {
    	char *cadeia;
    	int tid, tvar, tparam; 
        int ndims, dims[MAXDIMS+1];
        int nparam;//alynne APAGAR criei pra dar certo 
    	char inic, ref, array, param;//no slide era parametro mudei porque imagino que ele errou sei la
        listsimb listvar, listparam, listfunc;
    	simbolo escopo, prox;
    };


    /* alynne: Variaveis globais para a tabela de simbolos e analise semantica */

    simbolo tabsimb[NCLASSHASH];
    simbolo simb;
    int tipocorrente;

    /* alynne: Additional auxiliar struct i dont know what to call*/

    typedef struct infolistexpr infolistexpr;
    /* alynne: apagar esse comentario, carteei o seguinte typedef*/
    /*typedef infolistexpr *pontexprtipo; 
    struct infolistexpr { pontexprtipo listtipo;  int nargs; };*/

    /*
    	alynne: Prototipos das funcoes para a tabela de simbolos
        	e analise semantica
     */

    void InicTabSimb (void);
    void ImprimeTabSimb (void);
    simbolo InsereSimb (char *, int, int, simbolo);
    int hash (char *);
    simbolo ProcuraSimb (char *, simbolo);
    void DeclaracaoRepetida (char *);
    void TipoInadequado (char *);
    void NaoDeclarado (char *);
    void VerificaInicRef (void);
    void Incompatibilidade (char *);
    void InsereListSimb (simbolo, listsimb);

    /*alynne: APAGAR nao sei se isso devia ser uma global, nao tinha instrucoes claras no slide*/

    int declparam;
    simbolo escopo;
    listsimb pontvardecl = NULL;
    listsimb pontfunc = NULL;
    listsimb pontparam = NULL;
%}


%union {
    char string[128];        // ID and STRING attribute
    int op;                 // For RELOP, ADOP and MULTOPs
    char charVal;           // CHARCT attribute
    int intVal;             // INTCT attribute
    float floatVal;         // FLOATCT attribute
    simbolo simb;           // alynne: For the symbol table 
    int tipoexpr;           // alynne: For the symbol table
    //infolistexpr infolexpr; // alynne: For the symbol table
}
//alynne: types
%type	    <simb>	        Variable
%type 	    <tipoexpr> 	    Expression  AuxExpr1  AuxExpr2
                            AuxExpr3   AuxExpr4   Term   Factor
%type       <infolexpr>     ExprList Arguments  
%type       <simb>          FuncCall                       
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
/* Producoes da gramatica:      */
Prog        :   {
                    InicTabSimb (); 
                    declparam = FALSO; 
                    escopo = simb = InsereSimb("##global", IDGLOB, NAOVAR, NULL);
                    pontvardecl = simb->listvar;
                    pontfunc = simb->listfunc;
                }  PROGRAM ID OPBRACE {
                    printf("program %s {\n\n", $3);
                    InsereSimb ($3, IDPROG, NAOVAR, escopo);
                } GlobDecls Functions CLBRACE {
                    printf("}\n"); 
                    VerificaInicRef ();
                    ImprimeTabSimb ();
                }

GlobDecls   :   | GLOBAL COLON {
                    print_tabs(); 
                    printf("global%c\n", ':'); 
                    ntabs++;
                } DeclList {
                    ntabs--; 
                    printf("\n");
                }

DeclList    :   Declaration | DeclList Declaration

Declaration :   {
                    print_tabs();
                } Type ElemList SCOLON {
                    printf(";\n");
                }

Type        :   INT {
                    printf("int");
                    tipocorrente = INTEIRO;
                }  
            |   FLOAT {
                    printf("float"); 
                    tipocorrente = REAL;
                }  
            |   CHAR {
                    printf("char");
                    tipocorrente = CARACTERE;
                }  
            |   LOGIC {
                    printf("logic");
                    tipocorrente = LOGICO;
                }  
            |   VOID {
                    printf("void");
                }
                
ElemList    :   Elem | ElemList COMMA {
                    printf(",");
                } Elem

Elem        :   ID {
                    printf(" %s", $1);
                        if (ProcuraSimb ($1, escopo)  !=  NULL)
                            DeclaracaoRepetida ($1);
                        else
                            InsereSimb ($1,  IDVAR,  tipocorrente, escopo);
                } Dims

Dims        :   | OPBRAK {
                    printf("[");
                } DimList CLBRAK {
                    printf("]");
                }

DimList     :   INTCT {
                    printf("%d", $1);
                }
                | DimList COMMA INTCT {
                    printf(", %d", $3);
                }

Functions   :   FUNCTIONS COLON {
                    print_tabs(); 
                    printf("functions%c\n", ':'); 
                    ntabs++;
                } FuncList {
                    ntabs--;
                }

FuncList    :   Function {
                    printf("\n");
                } 
                | FuncList Function {
                    printf("\n");
                }

Function    :   Header OPBRACE {
                    printf(" {\n");
                } LocDecls Stats CLBRACE {
                    print_tabs();
                     printf("}\n");
                }

Header      :   MAIN {
                    printf("main");
                } 
                | {
                    print_tabs();
                } Type ID {
                    escopo = simb =  InsereSimb ($3, IDFUNC, tipocorrente, escopo);
	                pontvardecl = simb->listvar;
	                pontparam = simb->listparam;
                } OPPAR {
                    printf(" %s(", $3); 
                    declparam = VERDADE;
                } Params CLPAR {
                    printf(")"); declparam = FALSO;
                }

Params      :   | ParamList

ParamList   :   Parameter | ParamList COMMA {
                    printf(", ");
                } Parameter

Parameter   :   Type ID {
                    printf(" %s", $2);
                }

LocDecls    :   | LOCAL COLON {
                    print_tabs();
                    printf("local%c\n", ':');
                    ntabs++;
                } DeclList {
                    ntabs--;
                }

Stats       :   STATEMENTS COLON {
                    print_tabs();
                    printf("statements%c\n", ':'); 
                    ntabs++;
                } StatList {
                    ntabs--;
                }

StatList    :   | StatList Statement

Statement   :   CompStat
                | {
                    print_tabs();
                } IfStat
                | {
                    print_tabs();
                } WhileStat
                | {
                    print_tabs();
                } DoStat
                | {
                    print_tabs();
                } ForStat
                | {
                    print_tabs();
                } ReadStat {
                    printf("\n");
                }
                | {
                    print_tabs();
                } WriteStat {
                    printf("\n");
                } 
                | {
                    print_tabs();
                } AssignStat {
                    printf("\n");
                }
                | {
                    print_tabs();
                } CallStat {
                    printf("\n");
                }
                | {
                    print_tabs();
                } ReturnStat {
                    printf("\n");
                }
                | {
                    print_tabs();
                } SCOLON {
                    printf("\n");
                }
                | {
                    print_tabs();
                } error {
                    printf("alynne\n"); // Voce nao eh um erro, flor. Tire isso daí.
                }
            
CompStat    :   OPBRACE {
                    ntabs--;
                    print_tabs(); 
                    ntabs++;
                    printf("{\n");
                } StatList CLBRACE {
                    ntabs--; 
                    print_tabs(); 
                    ntabs++; 
                    printf("}\n");
                }

IfStat      :   IF {
                    printf("if");
                } OPPAR {
                    printf(" (");
                } Expression CLPAR {
                    printf(")\n");
                ntabs++;
                } Statement {
                    ntabs--;
                } ElseStat

ElseStat    :   | ELSE {
                    print_tabs();
                    printf("else\n"); 
                    ntabs++;
                } Statement {
                    ntabs--;
                }

WhileStat   :   WHILE {
                    printf("while");
                } OPPAR {
                    printf(" (");
                } Expression CLPAR {
                    printf(")\n");
                    ntabs++;
                } Statement {
                    ntabs--;
                }

DoStat      :   DO {
                    printf("do\n"); 
                    ntabs++;
                } Statement WHILE OPPAR {
                    ntabs--;
                    print_tabs();
                    printf("while (");
                } 

Expression CLPAR SCOLON {printf(");\n");}

ForStat     :   FOR OPPAR {printf("for (");} Variable ASSIGN {printf(" <- ");} 
                Expression SCOLON {printf("; ");} Expression SCOLON {printf("; ");}
                Variable ASSIGN {printf(" <- ");} Expression CLPAR {printf(")\n"); ntabs++;} Statement {ntabs--;}

ReadStat    :   READ OPPAR {printf("read(");} ReadList CLPAR SCOLON {printf(");");}

ReadList    :   Variable | ReadList COMMA {printf(", ");} Variable

WriteStat   :   WRITE OPPAR {printf("write(");} WriteList CLPAR SCOLON {printf(");");}

WriteList   :   WriteElem | WriteList COMMA {printf(", ");} WriteElem

WriteElem   :   STRING {printf("%s", $1);} | Expression

CallStat    :   CALL {printf("call ");} FuncCall SCOLON {printf(";");}

FuncCall    :   ID OPPAR {
                    printf("%s(", $1);
                    simb = ProcuraSimb ($1, escopo->escopo);
		            if (! simb) NaoDeclarado ($1);
		            else if (simb->tid != IDFUNC)
			        TipoInadequado ($1);
		            $<simb>$ = simb;
                } Arguments CLPAR {printf(")");}

Arguments   :   | ExprList 

ReturnStat  :   RETURN SCOLON {printf("return;\n");} | RETURN {printf("return ");} Expression SCOLON {printf(";\n");}

AssignStat  :   Variable {
                    if  ($1 != NULL) 
                        $1->inic = $1->ref = VERDADE;
                }
                ASSIGN {printf(" <- ");} Expression SCOLON {printf(";\n");
                if ($1 != NULL)
                    if ((($1->tvar == INTEIRO || $1->tvar == CARACTERE) &&
                        ($5 == REAL || $5 == LOGICO)) ||
                        ($1->tvar == REAL && $5 == LOGICO) ||
                        ($1->tvar == LOGICO && $5 != LOGICO))
                        Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                }

ExprList    :   Expression | ExprList COMMA {printf(", ");} Expression

Expression  :   AuxExpr1 
            |   Expression OR {
                    printf(" || ");
                } AuxExpr1 {
                    if ($1 != LOGICO || $4 != LOGICO)
                        Incompatibilidade ("Operando improprio para operador or");
                    $$ = LOGICO;
            }

AuxExpr1    :   AuxExpr2 
            |   AuxExpr1 AND {
                    printf(" && ");
                } AuxExpr2 {
                    if ($1 != LOGICO || $4 != LOGICO)
                        Incompatibilidade ("Operando improprio para operador and");
                    $$ = LOGICO;
                }

AuxExpr2    :   AuxExpr3 
            |   NOT {
                    printf("!");
                } AuxExpr3 {
                    if ($3 != LOGICO)
                        Incompatibilidade ("Operando improprio para operador not");
                    $$ = LOGICO;
                }
            
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
                } AuxExpr4 {
                    switch ($2) {
                        case LT: case LEQ: case GT: case GEQ:
                            if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE 
                            || $4 != INTEIRO && $4 != REAL && $4 != CARACTERE)
                                Incompatibilidade	("Operando improprio para operador relacional");
                            break;
                        case EQ: case DIF:
                            if (($1 == LOGICO || $4 == LOGICO) && $1 != $4)
                                Incompatibilidade ("Operando improprio para operador relacional");
                            break;
                    }
                    $$ = LOGICO;
                }

AuxExpr4    :   Term 
            |   AuxExpr4 ADOP {
                    switch ($2) {
                        case PLUS:
                            printf(" + ");
                            break;
                        case MINUS:
                            printf(" - ");
                            break;
                    }
                } Term {
                    if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE || $4 != INTEIRO && $4!=REAL && $4!=CARACTERE)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if ($1 == REAL || $4 == REAL) $$ = REAL;
                        else $$ = INTEIRO;
                }

Term        :   Factor 
            |   Term MULTOP {
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
                } Factor {
                    switch ($2) {
                            case TIMES: case DIV:
                                if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE
                                    || $4 != INTEIRO && $4!=REAL && $4!=CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador aritmetico");
                                if ($1 == REAL || $4 == REAL) $$ = REAL;
                                else $$ = INTEIRO;
                                break;
                            case REM:
                                if ($1 != INTEIRO && $1 != CARACTERE
                                    ||  $4 != INTEIRO && $4 != CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador resto");
                                $$ = INTEIRO;
                                break;
                        }
                }

Factor      :   Variable {
                        if  ($1 != NULL)  {
                            $1->ref  =  VERDADE;
                            $$ = $1->tvar;
                        }
                    }
                |   INTCT {printf("%d", $1);$$ = INTEIRO;}
                |   FLOATCT {printf("%g", $1);$$ = REAL;}
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
                    printf("'"); $$ = CARACTERE;
                }
                |   TRUE {printf("true"); $$ = LOGICO;}
                |   FALSE {printf("false"); $$ = LOGICO;}
                |   NEG {
                        printf("~");
                    } Factor {
                        if ($3 != INTEIRO && $3 != REAL && $3 != CARACTERE)
                            Incompatibilidade  ("Operando improprio para menos unario");
                        if ($3 == REAL) $$ = REAL;
                        else $$ = INTEIRO;
                }
                |   OPPAR {
                    printf("(");
                } Expression CLPAR {
                    printf(")");
                    $$ = $3;
                }
                | FuncCall

Variable    :   ID {
                    printf("%s", $1);
                    simb = ProcuraSimb ($1, escopo);
                    if (simb == NULL)   NaoDeclarado ($1);
                    else if (simb->tid != IDVAR) TipoInadequado ($1);
                    $<simb>$ = simb;
                } Subscripts {$$ = $<simb>2;}

Subscripts  :    | OPBRAK {printf("[");} SubscrList CLBRAK {printf("]");}

SubscrList  :   AuxExpr4 | SubscrList COMMA {printf(", ");} AuxExpr4
            ;
%%

#include "lex.yy.c"

int yyerror ( char * msg ) {
    fprintf ( stdout, "%s erro aaaaaaaaaaa\n", msg ) ;
}

void print_tabs() {
    for (int i=0; i<ntabs; i++)
        printf("\t");
}

int main() {
	yyparse();
	return 0;
}

/* alynne: InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++)
		tabsimb[i] = NULL;
}

/*
	alynne: ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia, simbolo escopo) {
	simbolo s; int i;
	i = hash (cadeia);
	for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia)&& (s->escopo == escopo);
		s = s->prox);
	return s;
}

/*
	alynne: InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar, simbolo escopo) {
	int i; simbolo aux, s;
    /*alynne: Code in common for all identifiers*/
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
    s->prox = aux; s->tid = tid; s->tvar = tvar;
    s->escopo = escopo;
    /* alynne: Specific for parameters and global and local variables*/
    if (declparam) {
		s->inic = s->ref = s->param = VERDADE;
		if (s->tid == IDVAR)
			InsereListSimb (s, &pontparam); //to em duvida sobre esse if
		s->escopo->nparam++;//talvez o if pegue essa linha tambem, mas no slide tava assim
	}
    else {
        	s->inic = s->ref = s->param = FALSO;
            if (s->tid == IDVAR)
			    InsereListSimb (s, &pontvardecl);
    }
    /* alynne: For the global identifier or function name */
    if (tid == IDGLOB || tid == IDFUNC) {
		s->listvar = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listvar->prox = NULL;
	}
	if (tid == IDGLOB) {
		s->listfunc = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listfunc->prox = NULL;
	}
    /* alynne: also for function name*/
    if (tid == IDFUNC) {
		s->listparam = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listparam->prox = NULL;
		s->nparam = 0;
   		InsereListSimb (s, &pontfunc);
	}

	return s;
}
void InsereListSimb (simbolo s, listsimb pontfunc){
    /*alynne a ser implementada*/
}
/*
	alynne: hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}


/* alynne: ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR)
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
				printf(")\n");
			}
		}
}

void VerificaInicRef () {
	int i; simbolo s;

	printf ("\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i])
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if (s->tid == IDVAR) {
					if (s->inic == FALSO)
						printf ("%s: Nao Inicializada\n", s->cadeia);
					if (s->ref == FALSO)
						printf ("%s: Nao Referenciada\n", s->cadeia);
				}
}

/*void ChecArgumentos(pontexprtipo Ltiparg, listsimb Lparam){
    pontexprtipo p;  pontelemlistsimb q;
    p = Ltiparg->prox; q = Lparam->prox;
    while (p != NULL && q != NULL) {
		switch (q->simb->tvar) {
			case INTEIRO: case CARACTERE:
				if (p->tipo != INTEIRO && p->tipo != CARACTERE)
					Incompatibilidade("....");
				break;
			case REAL:
				if (p->tipo != INTEIRO &&  p->tipo != CARACTERE && 
								p->tipo != REAL)
					Incompatibilidade("....");						break;
			case LOGICO:
				if (p->tipo != LOGICO)
					Incompatibilidade("....");
				break;
			default:
				if (q->simb->tvar != p->tipo)
					Incompatibilidade("....");
				break;
		}
		p = p->prox; q = q->prox;
	}
}*/

/* alynne: Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

void Incompatibilidade (char *s) {
    printf ("\n\n***** Incompatibilidade: %s *****\n\n", s);
}

