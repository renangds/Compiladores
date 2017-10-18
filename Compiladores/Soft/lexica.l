%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
BOOLEANO [true|false]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
BOOL {BOOLEANO}+
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
VAR  ({LETRA}+|{REAL}+|{BOOL}|{CHAR})

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"fun"		{return TK_FUNCTIONS;}
	
"int"		{return TK_TYPE_INT;
			yylval.t_var = yytext;}

"double"	{return TK_DOUBLE;}

"short"		{return TK_SHORT;}

"string"	{return STRING;}

"char"		{yylval.t_var = yytext;
			return TK_TYPE_CHAR;}

"float"		{yylval.t_var = yytext;
			return TK_TYPE_FLOAT;}

"bool"		{return TK_TYPE_BOOL;}

"var"		{return TK_TYPE_VAR;}

"case"		{return CASE;}

"continue"	{return CONTINUE;}

"begin"		{return TK_BEGIN;}

"if"		{return IF;}

"else"		{return ELSE;}

"elif"		{return ELIF;}

"switch"	{return SWITCH;}

"while"		{return WHILE;}

"for"		{return FOR;}

"do"		{return DO;}

"until"		{return UNTIL;}

"break"		{return BREAK;}

"super"		{return SUPER;}

"params"	{return PARAMS;}

"end"		{return TK_END;}

"jump"		{return TK_JUMP;}

"to"		{return TK_TO;}

"sum"		{return TK_SUM;}

"and"		{return AND;}

"or"		{return OR;}

"nand"		{return NAND;}

"ori"		{return ORI;}

"(float)"|"(int)"	{yylval.cast = yytext;
					return TK_CAST;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

{BOOL}		{yylval.traducao = yytext;
			yylval.t_var = "bool";
			return TK_BOOL;}

{CHAR}		{yylval.traducao = yytext;
			yylval.t_var = "char";
			return TK_CHAR;}

{NUM}		{ yylval.traducao = yytext;
			yylval.t_var = "int";
			return TK_INT; }

{REAL}		{yylval.traducao = yytext; 
			yylval.t_var = "float";
			return TK_FLOAT;}

{ID}		{ yylval.label = yytext; 
			return TK_ID; }

{VAR}		{yylval.traducao = yytext;
			yylval.t_var = "var";
			return TK_VAR;}

.			{ *yytext; }

%%
