%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define MAX_TABLE_SIZE 100
#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string t_var;
};

map <string, string>tab;
static int vars = 0;

void insert_variable(string tipo, string id){
	// tab.insert();
}

string to_string(int num){
	ostringstream temp;
	temp << num;
	return temp.str();
}

string create_var_names(){
	string var = "var_"+to_string(vars);
	vars++;
	return var;
}

int yylex(void);
void yyerror(string);
%}

%token TK_NUM
%token TK_MAIN TK_ID 
%token TK_FIM TK_ERROR
%token TK_FLOAT TK_DOUBLE TK_SHORT TK_CHAR TK_VAR STRING TK_INT TK_BOOL
%token TK_BEGIN
%token TK_END
%token TK_FUNCTIONS
%token FOR WHILE DO CONTINUE BREAK TK_JUMP TK_TO
%token IF ELSE ELIF SWITCH UNTIL CASE
%token PARAMS
%token SUPER
%token VAR
%token TK_SUM
%token AND OR ORI NAND

%start S

%left GE LE EQ NE ME MA
%left '+' '-'
%left '*' '/'

%%

S 			: TK_FUNCTIONS TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador Soft! It's begin!*/\n" 
				<< "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" 
				<< $5.traducao << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		: TK_BEGIN COMANDOS TK_END
			{
				$$.traducao = $2.traducao;
				// cout << $2.traducao << endl;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	: TK_INT TK_ID E ';'
			{
				$$.label = create_var_names();
				$$.traducao = $$.label + $2.label + '=' + $3.traducao;
			}
			|
			TK_FLOAT TK_ID E ';'
			{
				$$.label = create_var_names();
			}
			|
			TK_BOOL TK_ID E ';'
			{
				$$.label = create_var_names();
			}
			|
			E ';'
			;

E 			: '(' E ')' 
			{
				$$.label = create_var_names();
				$$.traducao = $2.traducao;
			}
			|
			E '+' E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
				" = " + $1.label + " + " + $3.label + ";\n";
			}
			|
			E '-' E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
				" = " + $1.label + " - " + $3.label + ";\n";
			}
			|
			E '*' E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
				" = " + $1.label + " * " + $3.label + ";\n";
			}
			|
			E '/' E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
				" = " + $1.label + " / " + $3.label + ";\n";
			}
			|
			E '+' '+'
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label + " + " + $1.label + ";\n";
			}
			|
			E '-''-'
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label + " - " + $1.label + ";\n";	
			}
			|
			E ME E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + " < " + $3.label + ";\n";
			}
			|
			E MA E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + " > " + $3.label + ";\n";
			}
			|
			E GE E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + ">=" + $3.label + ";\n";
			}
			|
			E LE E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + "<=" + $3.label + ";\n";
			}
			|
			E EQ E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + "==" + $3.label + ";\n";
			}
			|
			E NE E
			{
				$$.label = create_var_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "=" + $1.label + "!=" + $3.label + ";\n";
			}
			|
			T
			{
				$$ = $1;
			}
			/*| TK_NUM
			{
				$$.label = create_var_names();
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
			}
			| TK_ID
			{
				// $$.label = $1.label;
				// $$.label = create_var_names();
				$$ = $1;
			}
			| C
			{
				$$ = $1;
			}*/
			;

D 			: TK_INT
			{

			}
			|
			TK_FLOAT
			{

			}
			|
			TK_BOOL
			{

			}
			;

T 			: TK_NUM
			{
				$$ = $1;
			}
			|
			TK_FLOAT
			{
				$$ = $1;
			}
			|
			TK_BOOL
			{
				$$ = $1;
			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] ) 
{
	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
