%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <vector>
	#include <stack>
	#include "stdlib.h"

	#define YYSTYPE atributos

	using namespace std;
	
	int yylex(void);
	void yyerror(string);
	
	static int vars = 0;
	static int temps = 0;
	static int loops = 0;

	typedef struct atributos
	{
		string label;
		string nome;
		string traducao;
		string var_tipo;
		string valor;
		string cast;
		string op;
	}ATR;

	typedef struct var{
		string type;
		string name;
		string value;
		string id;
	}VAR;

	typedef struct fun{
		string name;
		string type_return;
		struct fun* next;
		vector <VAR> map_vars;
	}FUN;

	vector <VAR> map_vars;
	stack <FUN> pilha;
	FUN* esc_global;

	string create_var_names();
	string create_temp_names();
	string create_loop_names();
	string format_boolean(ATR* $$);
	string to_string(int num);
	VAR* get_var(string name);
	void set_var(string type, string name, string value, string id);
	void explicit_cast(ATR* $$, string type_cast);
	void implicit_cast(ATR* v1, ATR* v2, ATR* var_op);
	void implicit_return(ATR* v, ATR* r);
	bool search_var(string name);
	void print_stack();
	void format_variable(ATR* $$);
	void format_declarations(ATR* $$);


	void explicit_cast(ATR* $$, string type_cast){
		if($$->var_tipo == "bool") yyerror("Booleano não pode ser convertido para outros tipos");
		if(type_cast == "bool") yyerror("Tipos não podem ser convertidos para booleanos");

		ATR new_atr;
		new_atr.label = create_temp_names();

		if(type_cast == "(float)"){
			new_atr.var_tipo = "float";
			new_atr.valor = "(float)"+$$->label;
		} else if (type_cast == "(char)"){
			new_atr.var_tipo = "char";
			new_atr.valor = "(char)"+$$->label;
		} else{
			new_atr.var_tipo = "int";
			new_atr.valor = "(int)"+$$->label;
		}

		new_atr.traducao = "\t" + new_atr.label + " = " + new_atr.valor + ";\n";
		$$->traducao = new_atr.traducao;
		$$->label = new_atr.label;
		$$->var_tipo = new_atr.var_tipo;
		set_var(new_atr.var_tipo, "temp", new_atr.valor, new_atr.label);
	}

	void implicit_cast(ATR* v1, ATR* v2, ATR* var_op){
		if((v1->var_tipo == "bool" && v2->var_tipo != "bool") || (v2->var_tipo == "bool" && v1->var_tipo != "bool")){
			yyerror("Conversão não permitida para o tipo booleano");
		}

		if(var_op->op == "+" || var_op->op == "-" || var_op->op == "*" || var_op->op == "/"){
			if(v1->var_tipo == "int" && v2->var_tipo != "int"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v1->traducao;
			} else if(v1->var_tipo != "int" && v2->var_tipo == "int"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if(v1->var_tipo == "float" && v2->var_tipo == "char"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if(v1->var_tipo == "char" && v2->var_tipo == "float"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			}
		} else if (var_op->op == "==" || var_op->op == "!=" || var_op->op == "<=" || var_op->op == ">=" || var_op->op == "<" || var_op->op == ">"){
			if(v1->var_tipo == "int" && v2->var_tipo != "int"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->traducao = var_op->traducao + v1->traducao;
			} else if (v1->var_tipo != "int" && v2->var_tipo == "int"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if (v1->var_tipo == "float" && v2->var_tipo == "char"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if (v1->var_tipo == "char" && v2->var_tipo == "float"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			}
		}
	}

	void implicit_return(ATR* v, ATR* r){
		if((v->var_tipo == "int" && r->var_tipo != "int") || (v->var_tipo != "int" && r->var_tipo == "int")){
			string temp = r->traducao;
			explicit_cast(r, "("+v->var_tipo+")");
			r->traducao = temp + r->traducao;
		} else if ((v->var_tipo != "bool" && r->var_tipo == "bool") || (v->var_tipo == "bool" && r->var_tipo != "bool")){
			yyerror("Variáveis booleanas apenas aceitam booleanas");
		}
	}

	VAR* get_var(string name){
		FUN* temp = &pilha.top();

		if(pilha.size() > 1){
			for( ; temp; temp = temp->next){
				for(int i=0; i<temp->map_vars.size(); i++){
					if(temp->map_vars[i].name == name) return &temp->map_vars[i];
				}
			}
		} else{
			for(int i=0; i<temp->map_vars.size(); i++){
				if(temp->map_vars[i].name == name) return &temp->map_vars[i];
			}	
		}

		return NULL;
	}

	void set_var(string type, string name, string value, string id){
		VAR new_atr;

		new_atr.type = type;
		new_atr.name = name;
		new_atr.id = id;
		new_atr.value = value;

		if(pilha.size() > 1){
			VAR temp_atr;
			temp_atr.type = type;
			temp_atr.name = "temp";
			temp_atr.id = id;
			temp_atr.value = value;
			esc_global->map_vars.push_back(temp_atr);
		}

		pilha.top().map_vars.push_back(new_atr);
	}

	bool search_var(string name){
		FUN* temp = &pilha.top();

		if(pilha.size() > 1){
			for( ; temp; temp = temp->next){
				for(int i=0; i<temp->map_vars.size(); i++){
					if(temp->map_vars[i].name == name) return true;
				}
			}
		} else{
			for(int i=0; i<temp->map_vars.size(); i++){
				if(temp->map_vars[i].name == name) return true;
			}	
		}

		return false;
	}
	
	void print_stack(){
		FUN* temp = &pilha.top();

		cout << "Tipo" << "\t" << "Nome" << "\t" << "Valor" << "\t" << "ID" << endl;

		for(int i=0; i<temp->map_vars.size(); i++){
			cout << temp->map_vars[i].type << "\t" << temp->map_vars[i].name << "\t" << temp->map_vars[i].value << "\t" << temp->map_vars[i].id << endl;
		}
	}

	string format_boolean(ATR* $$){
		if($$->var_tipo == "bool"){
			string format = "int";

			return format;
		}else{
			return $$->var_tipo;
		}
	}

	void format_variable(ATR* $$){
		$$->traducao = "\t" + $$->label + " = " + $$->valor + ";\n"; 
	}

	void format_declarations(ATR* $$){
		FUN* temp = &pilha.top();
		string total_declarations;

		for(int i=0; i<temp->map_vars.size(); i++){
			if(temp->map_vars[i].type == "bool"){
				string tipo_bool = "int";
				total_declarations += "\t" + tipo_bool + " " + temp->map_vars[i].id + ";\n";
			} else if (temp->map_vars[i].type == "none"){
				continue;
			} else{
				total_declarations += "\t" + temp->map_vars[i].type + " " + temp->map_vars[i].id + ";\n";
			}
		}

		$$->traducao = total_declarations + "\n" + $$->traducao;
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

	string create_loop_names(){
		string loop = "loop"+to_string(loops);
		loops++;
		return loop;
	}
%}

	%token TK_CAST 
	%token TK_OPL TK_OPA TK_TRUE TK_FALSE TK_ADD1 TK_SUB1 TK_ADDI TK_SUBI
	%token TK_MAIN TK_ID TK_CHAR TK_STRING TK_INT TK_FLOAT TK_BOOL TK_TYPES TK_GLOBAL TK_VAR
	%token TK_FIM TK_ERROR
	%token TK_BEGIN TK_END TK_FUNCTION
	%token TK_WHILE TK_FOR TK_DO TK_BREAK TK_CONTINUE TK_UNTIL
	%token TK_IF TK_ELSE TK_ELIF TK_CASE TK_SWITCH
	%token TK_PRINTLN TK_GET

	%start S

	%left '='
	%left "||" "&&"
	%left "==" "!="
	%left '<' '>' ">=" "<="
	%left '%'
	%left '+' '-'
	%left '/' '*'

%%

S 			: TK_FUNCTION TK_MAIN '(' ')' BLOCO
			{
				cout << "\n#include <iostream>\nusing namespace std;\n#include <stdio.h>\n#include <stdlib.h>\n\nint main (){" << endl;
				cout << "\n" << $5.traducao << "\n\treturn 0;\n}" << endl;
			}
			;

BLOCO		: TK_BEGIN COMANDOS TK_END
			{
				$$.traducao = $2.traducao;
				if(pilha.size() == 1) format_declarations(&$$);
				pilha.pop();
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			|
			;

COMANDO 	:	DECLARACOES ';'
			|	OPERACOES ';'
			|	LOGICO ';'
			|	PRINT ';'
			| 	WHILE
			|	FOR
			|	UNTIL
			|	CONIF
			|	BREAK ';'
			|	CONTINUE ';'
			;

BREAK 		:	TK_BREAK
			{
				$$.traducao = "\t" + get_var("label_begin")->value;
			}
			;

CONTINUE	:	TK_CONTINUE
			{
				$$.traducao = "\t" + get_var("label_end")->value;
			}
			;

DECLARACOES	:	TK_TYPES TK_ID EXPR
			{
				if(search_var($2.nome)) yyerror("Variável já existe");
				$$.label = create_var_names();
				$$.var_tipo = $1.var_tipo;
				implicit_return(&$$, &$3);
				set_var($1.var_tipo, $2.nome, $3.valor, $$.label);
				$$.traducao = $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
			}
			|	TK_TYPES TK_ID TERM
			{
				if(search_var($2.nome)) yyerror("Variável já existe");
				$$.label = create_var_names();
				$$.var_tipo = $1.var_tipo;
				implicit_return(&$$, &$3);
				set_var($1.var_tipo, $2.nome, $3.valor, $$.label);
				$$.traducao = $3.traducao + "\t" + $$.label + " = " + $3.label + ";";
			}
			|	TK_TYPES TK_ID
			{
				if(search_var($2.nome)) yyerror("Variável já existe");
				$$.label = create_var_names();
				set_var($1.var_tipo, $2.nome, " ", $$.label);
			}
			|	GET
			;

OPERACOES	:	TK_ID TERM
			{
				if(!search_var($1.nome)) yyerror("Variável não existe");
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$2);
				$$.traducao = $2.traducao + "\t" + get_var($1.nome)->id + " = " + $2.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID EXPR
			{
				if(!search_var($1.nome)) yyerror("Variável não existe");
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$2);
				$$.traducao = $2.traducao + "\n \t" + get_var($1.nome)->id + " = " + $2.label + ";\n";
				$2.traducao = " ";
			}
			;

EXPR		:	'(' EXPR ')' 
			{
				$$ = $2;
			}
			|	EXPR '+' EXPR
			{
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror("Operação inválida com booleano");
				$$.op = "+";
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
				implicit_cast(&$1, &$3, &$$);
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao += "\t" + $$.label + " = " + $1.label + '+' + $3.label + ";\n";
				$$.valor = $$.label;
			}
			|	EXPR '-' EXPR
			{
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror("Operação inválida com booleano");
				$$.op = "-";
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
				implicit_cast(&$1, &$3, &$$);
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao += "\t" + $$.label + " = " + $1.label + '-' + $3.label + ";\n";
				$$.valor = $$.label;
			}
			|	EXPR '*' EXPR
			{
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror("Operação inválida com booleano");
				$$.op = "*";
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
				implicit_cast(&$1, &$3, &$$);
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao += "\t" + $$.label + " = " + $1.label + '*' + $3.label + ";\n";
				$$.valor = $$.label;
			}
			|	EXPR '/' EXPR
			{
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror("Operação inválida com booleano");
				$$.op = "/";
				$$.label = create_temp_names();
				$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
				implicit_cast(&$1, &$3, &$$);
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao += "\t" + $$.label + " = " + $1.label + '/' + $3.label + ";\n";
				$$.valor = $$.label;
			}
			|	TK_ADD1
			{
				if(!search_var($1.nome)) yyerror("Variável não existe");
				if(get_var($1.nome)->type == "bool" || get_var($1.nome)->type == "char") yyerror("Operação só permitida com float e int");
				$$.label = create_temp_names();
				$$.var_tipo = get_var($1.nome)->type;
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao = "\t" + $$.label + " = "+ get_var($1.nome)->id + "+1;";
			}
			|	TK_SUB1
			{
				if(!search_var($1.nome)) yyerror("Variável não existe");
				if(get_var($1.nome)->type == "bool" || get_var($1.nome)->type == "char") yyerror("Operação só permitida com float e int");
				$$.label = create_temp_names();
				$$.var_tipo = get_var($1.nome)->type;
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao = "\t" + $$.label + " = "+ get_var($1.nome)->id + "-1;";
			}
			|	LOGICO
			{
				$$ = $1;
			}
			|	CAST
			{
				$$ = $1;
			}
			|	TERM
			{
				$$ = $1; 
			}
			;

LOGICO		:	EXPR TK_OPL EXPR
			{
				$$.label = create_temp_names();
				$$.op = $2.op;
				$$.var_tipo = "bool";
				$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
				implicit_cast(&$1, &$3, &$$);
				set_var(format_boolean(&$$), "temp", $$.valor, $$.label);
				$$.traducao += "\t" + $$.label + " = " + $1.label + $2.op + $3.label + ";\n";
				$$.valor = $1.valor + $2.op + $3.valor;
			}
			;

WHILE 		:	TK_WHILE '(' EXPR ')' BLOCO
			{
				if($3.var_tipo != "bool") yyerror("A condição do While só permite booleano como retorno");
				string l_end = create_loop_names();
				set_var("none", "label_begin", $1.label, "none");
				set_var("none", "label_end", l_end, "none");
				$$.traducao = "\t" + $1.label + ":" + "\n" + $3.traducao + "\n\tif(!" + $3.label + ") goto " + l_end + ";\n" + $5.traducao + "\tgoto "+ $1.label + ";\n\t" + l_end + ":\n\t";
			}
			|	TK_DO BLOCO TK_WHILE '(' LOGICO ')'
			{
				string l_end = create_loop_names();
				$$.traducao = "\t" + $3.label + ":" + "\n" + $2.traducao + $4.traducao + "\tif(!" + $5.label + ") goto " + $3.label + ";\n";
			}
			;

UNTIL 		:	TK_UNTIL '(' '!' LOGICO ')' BLOCO
			{
				string l_end = create_loop_names();
				$$.traducao = "\t" + $$.label + ":" + "\n" + $4.traducao + "\tif(" + $4.label + ") goto " + l_end + ";\n" + $5.traducao + "\tgoto "+ $$.label + ";\n\t" + l_end + ":\n\t";
			}
			;

FOR 		:	TK_FOR '(' DECLARACOES ';' LOGICO ';' EXPR ')' BLOCO
			{
				string l_end = create_loop_names();
				$$.traducao = $3.traducao + "\n" + $4.traducao + "\tif(!" + $4.label + ") goto " + l_end + ";\n" + $8.traducao + "\tgoto " + $1.label + ";\n\t" + l_end + ":\n\t";
				// $$.traducao = $3.traducao + "\n" + $4.traducao + "\tif(!" + $4.label + ") goto " + l_end + ";\n" + $6.traducao + "\tgoto " + $1.label + ";\n\t" + l_end + ":\n\t";
			}

CAST 		:	TK_CAST TERM
			{
				if(search_var($2.nome)){
					$$.traducao = $2.traducao;
					explicit_cast(&$2, $1.cast);
					$$.traducao += $2.traducao;
					$$.label = $2.label;
					$$.var_tipo = $2.var_tipo;
				}else{
					$$.traducao = $2.traducao;
					explicit_cast(&$2, $1.cast);
					$$.traducao += $2.traducao;
					$$.label = $2.label;
					$$.var_tipo = $2.var_tipo;
				}
			}
			;

CONIF 		:	TK_IF '(' LOGICO ')' BLOCO
			{

			}
			;

TERM		:	TK_ID
			{
				if(search_var($$.nome)){
					$$.var_tipo = get_var($$.nome)->type;
					$$.label = get_var($$.nome)->id;
				}else{
					yyerror("Variável não existe!");
				}
			}
			|	TK_TRUE
			{
				$$ = $1;
				format_variable(&$$);
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			|	TK_FALSE	
			{
				$$ = $1;
				format_variable(&$$);
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			|	TK_INT
			{
				$$ = $1;
				format_variable(&$$);
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			|	TK_CHAR 
			{
				$$ = $1;
				format_variable(&$$);
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			|	TK_FLOAT
			{
				$$ = $1;
				format_variable(&$$);
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			|	TK_STRING
			{
				$$ = $1;
				format_variable(&$$);
			}
			;

GET 		:	TK_GET "()"
			{
			}

PRINT 		:	TK_PRINTLN '(' PARAM ')'
			{
				$$.traducao = "\tcout" + $3.traducao + " << endl;\n";
			}
			;

PARAM 		:	TERM
			{
				$$.traducao = " << " + $1.label;
			}
			|	TERM '+' PARAM
			{
				$1.traducao = " << " + $1.valor;
				$$.traducao = $1.traducao + $3.traducao;
			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	// FUN global;
	// pilha.push(global);
	yyparse();

	//return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
