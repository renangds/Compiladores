%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <map>

	#define MAX_TABLE_SIZE 100
	#define YYSTYPE atributos

	using namespace std;
	void yyerror(string MSG);

	struct atributos
	{
		string label;
		string traducao;
		string t_var;
	};

	string tabela_v[MAX_TABLE_SIZE][3];
	static int vars = 0;
	static int temps = 0;
	static int total_var = 0;

	void casting(){

	}

	void print_matrix(){
		cout << "Tipo" << "\t" << "Id" << "\t" << "Valor" << endl;

		for(int i=0; i<total_var; i++){
			cout << tabela_v[i][0] << "\t" << tabela_v[i][1] << "\t" << tabela_v[i][2] << endl;
		}
	}

	void insert_variable(string tipo, string id, string value){
		tabela_v[total_var][0] = tipo;
		tabela_v[total_var][1] = id;
		tabela_v[total_var][2] = value;

		total_var++;
	}

	void find_variable(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				cout << "Variable" << " " << tabela_v[i][1];
				yyerror(" exist!\n");
			}
		}
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

	string create_temp_names(){
		string temp = "temp"+to_string(temps);
		temps++;
		return temp;
	}

	int yylex(void);
	void yyerror(string);
%}
	%token TK_TYPE_CHAR TK_TYPE_FLOAT TK_TYPE_BOOL TK_TYPE_INT
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

S 			:	TK_FUNCTIONS TK_MAIN '(' ')' BLOCO
			{
				cout << "Essa é a linguagem Soft, a linguagem sopa de macaco, uma delícia!" << endl;
				cout << "Begin:" << endl << $5.traducao << "End" << endl;
				//print_matrix();
			}
			;

BLOCO		:	TK_BEGIN COMANDOS TK_END
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	:	COMANDO COMANDOS
			{
				// $$.label = create_var_names();
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

COMANDO 	:	TK_TYPE_INT TK_ID E ';'
			{
				// $$.traducao = "\tint " + $3.label + " " + $2.label + " = " + $3.traducao + ";\n";
				$$.traducao = $3.traducao;
			}
			|	TK_TYPE_FLOAT TK_ID E ';'
			{
				$$.traducao = "\tfloat " + $3.label + " " + $2.label + " = " + $3.traducao + ";\n";
			}
			|	TK_BOOL TK_ID E ';'
			{
				$$.traducao = "\t" + $$.label + " " + $2.label + " = " + $3.traducao + ";\n";
			}
			|	TK_TYPE_CHAR TK_ID E ';'
			{
				$$.traducao = "\t" + $$.label + " " + $2.label + " = " + $3.traducao + ";\n";
			}
			|	TK_ID
			{
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			|	E ';'
			;

E			:	'(' E ')' 
			{
				$$.traducao = $2.traducao;
			}
			|	E '+' E
			{
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label 
				+ " = " + $1.label + " + " + $3.label + ";\n";
				cout << $1.traducao << endl;
				cout << $3.traducao << endl;
				cout << $1.label << endl;
				cout << $3.label << endl;
				cout << $$.traducao << endl;
			}
			|	E '-' E
			{
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label 
				+ " = " + $1.label + " + " + $3.label + ";\n";
			}
			| 	E '*' E
			{
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label 
				+ " = " + $1.label + " + " + $3.label + ";\n";
			}
			|	E '/' E
			{
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label 
				+ " = " + $1.label + " + " + $3.label + ";\n";
			}
			|	TK_ID
			{
				$$.label = $1.label;
				$$.traducao = $1.label;
			}
			/*| TK_NUM
			{
				$$.label = create_var_names();
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
			}*/
			|	T 
			{
				$$ = $1;
			}
			/*| B
			{
				// $$.label = $1.label;
				// $$.label = create_var_names();
				$$ = $1;
			}*/
			;

/*
B 			:	T '<' T
			{
				$$ = $1;
			}
			|	T '>' T
			{
				$$ = $1;
			}
			|	T '>=' T
			{
				$$ = $1;
			}
			|	
			;
*/


T 			:	TK_INT
			{
				find_variable($1.label);
				$$.label = create_var_names();
				$$.t_var = "int";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
				insert_variable($$.t_var, $1.label, $1.traducao);
			}
			|	TK_FLOAT
			{
				find_variable($1.label);
				$$.label = create_var_names();
				$$.t_var = "float";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
				insert_variable($$.t_var, $1.label, $1.traducao);
			}
			|	TK_CHAR
			{
				find_variable($1.label);
				$$.label = create_var_names();
				$$.t_var = "char";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
				insert_variable($$.t_var, $1.label, $1.traducao);
			}
			|	TK_BOOL
			{
				find_variable($1.label);
				$$.label = create_var_names();
				$$.t_var = "bool";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + $1.label + ";\n";
				insert_variable($$.t_var, $1.label, $1.traducao);
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
