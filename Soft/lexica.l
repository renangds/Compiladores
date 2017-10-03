%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"fun"		{return TK_FUNCTIONS;}
	
"int"		{return TK_INT;}

"float"		{return TK_FLOAT;}

"double"	{return TK_DOUBLE;}

"short"		{return TK_SHORT;}

"char"		{return TK_CHAR;}

"string"	{return STRING;}

"bool"		{return TK_BOOL;}

"var"		{return TK_VAR;}

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

">="		{return GE;}

"<="		{return LE;}

"=="		{return EQ;}

"!="		{return NE;}

"<"			{return ME;}

">"			{return MA;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

{NUM}		{ yylval.traducao = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
