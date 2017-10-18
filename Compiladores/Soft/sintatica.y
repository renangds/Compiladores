%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <map>
	#include <stdlib.h>
	#include <errno.h>	

	#define MAX_TABLE_SIZE 100
	#define YYSTYPE atributos

	using namespace std;

	void yyerror(string MSG);
	void i_casting(string v1, string v2, string op, struct atributos* $$);
	void e_casting(struct atributos* a1);
	void print_matrix();
	void insert_variable(string tipo, string id, string value);	
	void change_type_variable(string id, string type);
	string find_type(string id);
	bool find_variable(string id);
	string to_string(int num);
	string create_var_names();
	string create_temp_names();

	/*
		Estrutura a ser adotada na sprint 2

		Lembrete a ser implementado: A estrutura das funções serão colocadas em uma pilha,
		onde cada instância deverá ter um ponteiro para as demais instâncias das funções
		criadas.

		struct function{
			string tabf[MAX_TABLE_SIZE][3];
			vector<string>atb;
			struct* function;
		};
	*/

	struct atributos
	{
		string label;
		string traducao;
		string t_var;
		string id_var;
		string cast;
	};

	string tabela_v[MAX_TABLE_SIZE][3];
	static int vars = 0;
	static int temps = 0;
	static int total_var = 0;

	void i_casting(string v1, string v2, string op, struct atributos* $$){
		string a1 = find_type(v1);
		string a2 = find_type(v2);

		if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%"){
			if(a1 == "bool" || a2 == "bool"){
				yyerror("Operação não suporta tipo booleano");
			} else if ((a1 == "int" || a2 == "float") || (a1 == "float" || a2 == "int")){
				$$->t_var = "float";
			}
		} else if (op == "==" || op == "!=" || op == ">" || op == "<" || op == "<=" || op == ">="){
			if((a1 == "bool" && a2 != "bool") || (a1 != "bool" && a2 == "bool")){
				yyerror("Operação não permitida");
			}
		}
	}

	void error_module(struct atributos* a1, struct atributos* a2){
		if(a1->t_var == "float" || a1->t_var == "float"){
			yyerror("Operação não infere os tipos float!");
		}
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

	string find_type(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return tabela_v[i][0];
			}
		}
		return NULL;
	}

	string get_value_variable(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return tabela_v[i][2];
			}
		}
	}

	struct atributos* get_variable(string id){
		struct atributos* temp = (struct atributos*)malloc(sizeof(struct atributos));

		if(!temp){
			exit(0);
		}

		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				temp->label = id;
				temp->t_var = tabela_v[i][0];
				temp->traducao = tabela_v[i][2];
				return temp;
			}
		}
		return NULL;
	}

	bool find_variable(string id){
		for(int i=0; i<total_var; i++){
			if(id == tabela_v[i][1]){
				return true;
			}
		}
		return false;
	}

	void change_type_variable(string id, string type){
		int i = 0;
		while(i<total_var){
			if(id == tabela_v[i][1]){
				tabela_v[i][0] = type;
				break;
			}
		}
	}

	void change_value_variable(string id, string var, string value){
		struct atributos* temp = get_variable(var);

		int i = 0;
		while(i<total_var){
			if(id == tabela_v[i][1]){
				tabela_v[i][2] = value;
				break;
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
	%token TK_TYPE_CHAR TK_TYPE_FLOAT TK_TYPE_BOOL TK_TYPE_INT TK_TYPE_VAR
	%token TK_NUM TK_FLOAT TK_DOUBLE TK_SHORT TK_CHAR TK_VAR STRING TK_INT TK_BOOL
	%token TK_MAIN TK_ID 
	%token TK_FIM TK_ERROR
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
	%token TK_CAST

	%start S

	%right '='
	%left "||" "&&"
	%left "==" "!="
	%left '<' '>' ">=" "<="
	%left '+' '-'
	%left '*' '/'

%%

S 			:	TK_FUNCTIONS TK_MAIN '(' ')' BLOCO
			{
				cout << "Conheça a Soft, a linguagem sopa de macaco, uma delícia!" << endl;
				cout << "Begin:" << endl << $5.traducao << "End" << endl;
				print_matrix();
			}
			;

BLOCO		:	TK_BEGIN COMANDOS TK_END
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	:	COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			|
			;

COMANDO 	:	TK_TYPE_INT TK_ID E ';'
			{
				if(find_variable($2.label)) yyerror("Variável já existe!");
				if($3.cast == "float") $3.t_var = "float";
				insert_variable($3.t_var, $2.label, $3.traducao); //Insere na tabela de símbolos
				$$.traducao = "\t" + $3.t_var + " " + $2.label + " = " + $3.traducao;
			}
			|	TK_TYPE_FLOAT TK_ID E ';'
			{
				if(find_variable($2.label)) yyerror("Variável já existe!");
				if($3.t_var == "int") $3.t_var = "float";
				insert_variable($3.t_var, $2.label, $3.traducao);
				$$.traducao = "\t" + $3.t_var + " " + $2.label + " = " + $3.traducao;
			}
			|	TK_TYPE_BOOL TK_ID E ';'
			{
				if(find_variable($2.label)) yyerror("Variável já existe!");
				insert_variable($3.t_var, $2.label, $3.traducao);
				$$.traducao = "\t" + $3.t_var + " " + $2.label + " = " + $3.traducao;
			}
			|	TK_TYPE_CHAR TK_ID E ';'
			{
				if(find_variable($2.label)) yyerror("Variável já existe!");
				insert_variable($3.t_var, $2.label, $3.traducao);
				$$.traducao = "\t" + $3.t_var + " " + $2.label + " = " + $3.traducao;
			}
			|	TK_TYPE_VAR TK_ID E ';'
			{
				if(find_variable($2.label)) yyerror("Variável já existe!");
				insert_variable($3.t_var, $2.label, $3.traducao);
				$$.traducao = "\t" + $3.t_var + " " + $2.label + " = " + $3.traducao;
			}
			|	E ';'
			;

E			:	'(' E ')' 
			{
				$$.traducao = $2.traducao;
			}
			|	E '+' E
			{
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				$$.label = create_temp_names();
				$$.traducao = $$.label + " = " + $1.label + " + " + $3.label + "\n";
				i_casting($1.label, $3.label, "+", &$$);
			}
			|	E '-' E
			{
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "-", &$$);
			}
			| 	E '*' E
			{
				$$.label = create_temp_names();
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				i_casting($1.label, $3.label, "*", &$$);
			}
			|	E '/' E
			{
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				$$.label = create_temp_names();
			}
			|	E '+' '+'
			{
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				$$.label = create_temp_names();
			}
			|	E '-' '-'
			{
				if(!find_variable($1.label) || !find_variable($3.label)) yyerror("Variável não existe!");
				$$.label = create_temp_names();
			}
			|	E '>' E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, ">", &$$);
			}
			|	E '<' E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "<", &$$);
			}
			|	E ">=" E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, ">=", &$$);
			}
			|	E "<=" E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "<=", &$$);
			}
			|	E "==" E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "==", &$$);
			}
			|	E "||" E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "||", &$$);
			}
			|	E "!=" E
			{
				$$.label = create_temp_names();
				i_casting($1.label, $3.label, "!=", &$$);
			}
			|	E '=' E
			{
				$$ = $1;
			}
			|	T
			{
				$$ = $1;
			}
			|	C
			{
				$$ = $1;
			}
			;

C 			:	TK_CAST V
			{
				if(!find_variable($2.label)) yyerror("Variável não existe!");
				if($1.cast == "(float)"){
					$$.cast = "float";
				}else{
					$$.cast = "int";
				}
				$$.traducao = get_value_variable($2.label);
			}
			;

V 			:	TK_ID
			{
				$$ = $1;
			}
			;

T 			:	TK_ID
			{
				$$ = $1;
			}
			|	TK_INT
			{
				$$ = $1;
			}
			|	TK_FLOAT
			{
				$$ = $1;
			}
			|	TK_BOOL
			{
				$$ = $1;
			}
			|	TK_CHAR
			{
				$$ = $1;
			}
			|	TK_VAR
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
