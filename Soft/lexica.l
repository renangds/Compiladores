%{
	#include <string>
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
BOOL [true|false]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
STRING \"({LETRA}|{NUM})+\"
ID {LETRA}({LETRA}|{NUM})*
VAR ({CHAR}|{REAL})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"begin"		{return TK_BEGIN;}

"end"		{return TK_END;}

"fun"		{FUN function;
			if(pilha.empty()){
 				function.name = "main";
 				function.next = NULL;
				pilha.push(function); 
				esc_global = &pilha.top();
			} else{
				function.next = &pilha.top();
				pilha.push(function);
			}
			return TK_FUNCTION;}

"int"|"float"|"char"|"bool"|"var"|"string"		{yylval.var_tipo = yytext;
												return TK_TYPES;}

"while"		{yylval.label = create_loop_names();
			FUN function;
			function.next = &pilha.top();
			pilha.push(function);
			return TK_WHILE;}

"do"		{return TK_DO;}

"for"		{yylval.label = create_loop_names();
			FUN function;
			function.next = &pilha.top();
			pilha.push(function);
			return TK_FOR;}

"until"		{yylval.label = create_loop_names();
			return TK_UNTIL;}

"if"		{return TK_IF;}

"else"		{return TK_ELSE;}

"elif"		{return TK_ELIF;}

"switch"	{return TK_SWITCH;}

"case"		{return TK_CASE;}

"break"		{return TK_BREAK;}

"continue"	{return TK_CONTINUE;}

"println"	{return TK_PRINTLN;}

"get"		{return TK_GET;}

"true"		{yylval.valor = "1";
			yylval.label = create_temp_names();
			yylval.var_tipo = "bool";
			return TK_TRUE;}

"false"		{yylval.valor = "0";
			yylval.label = create_temp_names();
			yylval.var_tipo = "bool";
			return TK_FALSE;}

"global"	{return TK_GLOBAL;}

"%"			{}

"<"|">"|"<="|">="|"!="|"=="|"||"|"&&"	{yylval.op = yytext;
										yylval.var_tipo = "bool";
										return TK_OPL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"++"				{yylval.op = yytext;
					return TK_ADD1;}

"--"				{yylval.op = yytext;
					return TK_SUB1;}

"+="				{yylval.op = yytext;
					return TK_ADDI;}

"-="				{yylval.op = yytext;
					return TK_SUBI;}

{NUM}		{ yylval.valor = yytext; 
			yylval.label = create_temp_names();
			yylval.var_tipo = "int";
			return TK_INT; }

{CHAR}		{yylval.valor = yytext;
			yylval.label = create_temp_names();
			yylval.var_tipo = "char";
			return TK_CHAR;}

{STRING}	{yylval.valor = yytext;
			yylval.label = create_temp_names();
			yylval.var_tipo = "char*";
			return TK_STRING;}

{REAL}		{yylval.valor = yytext;
			yylval.label = create_temp_names();
			yylval.var_tipo = "float";
			return TK_FLOAT;}

{VAR}		{yylval.valor = yytext;
			yylval.label = yytext;
			yylval.var_tipo = "?";
			return TK_VAR;}

{ID}		{yylval.nome = yytext; 
			yylval.var_tipo = "id";
			return TK_ID; }


"(int)"|"(float)"|"(char)"	{yylval.cast = yytext;
							yylval.label = create_temp_names();
							return TK_CAST;}

.			{ *yytext; }

%%
