%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <vector>
	#include <stack>
	#include "stdlib.h"

	#define YYSTYPE atributos
	#include "operationsSoft.h"
%}

	%token TK_CAST
	%token TK_OPL 
	%token TK_OPA
	%token TK_TRUE 
	%token TK_FALSE 
	%token TK_ADD1 
	%token TK_SUB1 
	%token TK_ADDI 
	%token TK_SUBI
	%token TK_INVERT
	%token TK_MAIN 
	%token TK_ID 
	%token TK_CHAR 
	%token TK_STRING 
	%token TK_INT 
	%token TK_FLOAT 
	%token TK_BOOL 
	%token TK_TYPES 
	%token TK_GLOBAL 
	%token TK_VAR
	%token TK_FIM 
	%token TK_ERROR
	%token TK_BEGIN 
	%token TK_END 
	%token TK_FUNCTION
	%token TK_FUNCTIONS
	%token TK_PROCEDURE
	%token TK_WHILE 
	%token TK_FOR 
	%token TK_DO 
	%token TK_BREAK 
	%token TK_CONTINUE 
	%token TK_UNTIL 
	%token TK_DEFAULT
	%token TK_IF 
	%token TK_ELSE 
	%token TK_ELIF 
	%token TK_CASE 
	%token TK_SWITCH
	%token TK_READLN 
	%token TK_WRITELN
	%token TK_RETURN
	%token TK_POW
	%token TK_MULTI
	%token TK_DIVI
	%token TK_FACTORIAL
	%token TK_IN
	%token TK_FOREACH
	%token TK_NOT
	%token TK_AS

	%start S

	%left '='
	%left "||" "&&"
	%left "==" "!="
	%left '<' '>' ">=" "<="
	%left '%'
	%left '+' '-'
	%left '/' '*'

%%

S			:	MAINS
			{
				$$.traducao = $1.traducao;
			}
			;

MAINS		:	MAIN MAINS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			;

MAIN 		: 	TK_FUNCTION TK_MAIN '(' ')' BLOCO
			{
				cout << "\n#include <iostream>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <string>\nusing namespace std;\n\nint main (){" << endl;
				cout << "\n" << "\n" << $5.traducao << "\n\treturn 0;\n}" << endl;
			}
			|	FUN
			{
				$$.traducao = " ";
			}
			|	PROCEDURE
			{
				$$.traducao = " ";
			}
			|	DECLARACOES ';'
			{
				declaracoes_globais += $$.traducao;
				$$.traducao = $1.traducao;
			}
			;

FUN 	:	TK_FUNCTION TK_ID '(' DECS ')' ':' TK_TYPES TK_BEGIN COMANDOS TK_RETURN TERM ';' TK_END
			{
				pilha.top().type_return = $7.var_tipo;
				pilha.top().name_return = $11.label;
				pilha.top().name = $2.nome;
				pilha.top().body = $9.traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
			;

PROCEDURE 	: 	TK_PROCEDURE TK_ID '(' DECS ')' TK_BEGIN COMANDOS TK_END
			{
				pilha.top().type_return = "none";
				pilha.top().name_return = "procedure";
				pilha.top().name = $2.nome;
				pilha.top().body = $7.traducao;
				funs.push_back(pilha.top());
				pilha.pop();
			}
			;

DECS	:	DEC_FUN
		|	DEC_FUN ',' DECS
		|
		;

DEC_FUN		:	TK_TYPES TK_ID
			{
				$$.label = create_param_names();
				set_parameters($1.var_tipo, $2.nome, "none", $$.label);
				set_var($1.var_tipo, $2.nome, "none", $$.label);
			}
			|	TK_TYPES TK_ID TERM
			{
				$$.label = create_param_names();
			}
			;

BLOCO		: TK_BEGIN COMANDOS TK_END
			{
				$$.traducao = $2.traducao;
				if(pilha.size() == 2){
						format_declarations(&$$);
						/*free_all(&$$);*/
				}
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
			|	WHILE
			|	FOR
			|	UNTIL
			|	CONIF
			|	SWITCH
			|	FOREACH
			|	BREAK ';'
			|	CONTINUE ';'
			|	EXPR ';'
			|	WRITE ';'
			|	SLICE ';'
			|	GLOBAL ';'
			;

BREAK 		:	TK_BREAK
			{
				if(pilha.top().name == "switch"){
					$$.traducao = "goto: switch"+to_string(switches);
				} else{
					$$.traducao = "\tgoto loop" + to_string(loops) + ";\n";
				}
			}
			;

CONTINUE	:	TK_CONTINUE
			{
				int l = loops;
				l--;
				$$.traducao = "\tgoto loop" + to_string(l) + ";\n";
			}
			;

GLOBAL 		: 	TK_GLOBAL TK_ID
			{
				for(int i=0; i < first_exestack->map_vars.size(); i++){
					if(first_exestack->map_vars[i].name == $2.nome){
						$$.traducao = "\n\t" + first_exestack->map_vars[i].id + " = " + first_exestack->map_vars[i].value + ";\n";
						break;
					}
					if(i+1 == first_exestack->map_vars.size()) yyerror(in_line() + " Variável global não declarada!");
				}
			}
			;

DECLARACOES	:	TK_TYPES TK_ID EXPR
			{
				if(search_var($2.nome)) yyerror(in_line() + " Variável" + $2.nome + "já existe");
				if(get_vector($2.nome)){
					yyerror(in_line() + " Existe um vetor " + $2.nome + " declarado.");
				}
				$$.label = create_var_names();
				$$.var_tipo = $1.var_tipo;
				implicit_return(&$$, &$3);
				set_var($1.var_tipo, $2.nome, $3.valor, $$.label);
				$$.traducao = $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
			}
			|	TK_TYPES TK_ID TERM
			{
				if(search_var($2.nome)) yyerror(in_line() + " Variável " + $2.nome + " já existe");
				if(get_vector($2.nome)){
					yyerror(in_line() + " Existe um vetor " + $2.nome + " declarado.");
				}
				$$.label = create_var_names();
				$$.var_tipo = $1.var_tipo;
				implicit_return(&$$, &$3);
				set_var($1.var_tipo, $2.nome, $3.valor, $$.label);
				$$.traducao = $3.traducao + "\t" + $$.label + " = " + $3.label + ";";
			}
			|	TK_TYPES TK_ID
			{
				if(search_var($2.nome)) yyerror(in_line() + " Variável" + $2.nome + "já existe");
				if(get_vector($2.nome)){
					yyerror(in_line() + " Existe um vetor " + $2.nome + " declarado.");
				}
				$$.label = create_var_names();
				set_var($1.var_tipo, $2.nome, " ", $$.label);
			}
			|	TK_GLOBAL TK_ID
			{

			}
			|	VECTOR_MATRIX
			;

VECTOR_MATRIX	:	TK_TYPES TK_ID '[' VECTOR_MATRIX ']'
				{
					//cout << "entrou1" << endl;
					error_indextype($4.var_tipo);

					$$.label = create_vectors_names();
					$$.var_tipo = $1.var_tipo;

					$$.traducao = $4.traducao + "\t" + $$.label + " = (" + $$.var_tipo 
					+ "*)malloc(" + $4.label + "*sizeof(" + $1.var_tipo + "));\n";

					set_vector($$.var_tipo, $2.nome, $4.label, "0", $$.label);
				}
				|	TK_TYPES TK_ID '[' VECTOR_MATRIX ']' '[' VECTOR_MATRIX ']'
				{
					//cout << "entrou2" << endl;
					error_indextype($4.var_tipo);
					error_indextype($7.var_tipo);

					$$.label = create_vectors_names();
					$$.var_tipo = $1.var_tipo;

					$$.traducao = $4.traducao + $7.traducao + "\t" + $$.label + " = (" + $$.var_tipo 
					+ "*)malloc(" + $4.label + "*" + $7.label + "*sizeof(" + $1.var_tipo + "));\n";

					set_vector($$.var_tipo, $2.nome, $4.label, $7.label, $$.label);
				}
				|	TK_TYPES TK_ID '[' VECTOR_MATRIX ']' '{' TERMS '}'
				{
					//cout << "entrou3" << endl;
				}
				|	TK_TYPES TK_ID '[' VECTOR_MATRIX ']' '[' VECTOR_MATRIX ']' '{' TERMS '}'
				{
					//cout << "entrou4" << endl;
				}
				|	EXPR
				{
	
				}
				;

TERMS	:	TERM
		{
			$$.traducao = $1.traducao;
			VAR temp;
			temp.type = $1.var_tipo;
			temp.name = $1.label;
			vec_att.push_back(temp);
		}
		|	TERM ',' TERMS
		{
			$$.traducao = $1.traducao + $3.traducao;
			VAR temp;
			temp.type = $1.var_tipo;
			temp.name = $1.label;
			vec_att.push_back(temp);
		}
		;

VECTOR_MATRIX_OPERATIONS	:	TK_ID '[' VECTOR_MATRIX_OPERATIONS ']' VECTOR_MATRIX_OPERATIONS
							{
								//cout << "entrou5" << endl;
								error_indextype($4.var_tipo);
								VECTORS* temp = get_vector($1.nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + $1.nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								$$.label = temp->id + "[" + temp->row + "]";
								$$.var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" <<endl;";

								string condition = "\n\tif(" + $3.label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&$$, &$5);

								$$.traducao += $3.traducao + $5.traducao + condition + "\n\t" + jump 
								+ ":\n\t" + temp->id + "[" + $3.label + "] = " + $5.label + ";\n";

							}
							|	TK_ID '[' VECTOR_MATRIX_OPERATIONS ']' '[' VECTOR_MATRIX_OPERATIONS ']' VECTOR_MATRIX_OPERATIONS
							{
								//cout << "entrou6" << endl;
								error_indextype($4.var_tipo);
								error_indextype($7.var_tipo);
								VECTORS* temp = get_matrix($1.nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + $1.nome + " não existe!");
								}  else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								$$.label = temp->id + "[" + $3.label + "*" + temp->row + "+" + $6.label + "]";
								$$.var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da matriz excedido\"<<endl;";

								string condition = "\n\tif(" + $3.label + "<" + temp->row + ") goto " 
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n";

								condition += "\n\t" + jump1 + ":\n\tif(" + $6.label + "<" + temp->column + ") goto " 
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n";

								implicit_return(&$$, &$5);

								$$.traducao += $3.traducao + $6.traducao + $8.traducao + condition + "\n\t" + jump2 
								+ ":\n\t" + $$.label + " = " + $8.label + ";\n";

							}
							|	TK_ID '[' VECTOR_MATRIX_OPERATIONS ']'
							{
								//cout << "entrou7" << endl;
								error_indextype($4.var_tipo);
								VECTORS* temp = get_vector($1.nome);

								if(!temp){
									yyerror(in_line() + "Vetor " + $1.nome + " não existe!");
								} else if (temp->column != "0"){
									yyerror(in_line() + "Você procura uma tabela seu malakoi");
								}

								$$.label = temp->id + "[" + temp->row + "]";
								$$.var_tipo = temp->type;

								string jump = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite do vetor excedido\" << endl;";

								string condition = $3.traducao + "\n\tif(" + $3.label + "<" + temp->row + ") goto " 
								+ jump + ";\n" + error_msg + "\n\texit(1);\n\t" + jump + ":\n";

								$$.traducao = condition;
							}
							|	TK_ID '[' VECTOR_MATRIX_OPERATIONS ']' '[' VECTOR_MATRIX_OPERATIONS ']'
							{
								//cout << "entrou8" << endl;
								error_indextype($4.var_tipo);
								error_indextype($7.var_tipo);
								VECTORS* temp = get_matrix($1.nome);

								if(!temp){
									yyerror(in_line() + "Matriz " + $1.nome + " não existe!");
								}

								$$.label = temp->id + "[" + $3.label + "*" + temp->row + "+" + $6.label + "]";
								$$.var_tipo = temp->type;

								string jump1 = create_jump_names();
								string jump2 = create_jump_names();
								string error_msg = "\n\tcout << " + in_line() + "<< \"limite da Matriz excedido\" <<endl;";

								string condition = $3.traducao + "\n\tif(" + $3.label + "<" + temp->row + ") goto "
								+ jump1 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump1 + ":\n";

								condition += $6.traducao + "\n\tif(" + $3.label + "<" + temp->row + ") goto "
								+ jump2 + ";\n" + error_msg + "\n\texit(1);\n\t" + jump2 + ":\n";

							}
							|	EXPR
							{	
								//cout << "entrou9" << endl;
								$$ = $1;
							}
							;

SLICE	:	TK_ID '[' SLICE ':' SLICE ']'
		{

		}
		|	EXPR
		{

		}
		;

OPERACOES	:	TK_ID TERM
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$2);
				$$.traducao = $2.traducao + "\t" + get_var($1.nome)->id + " = " + $2.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID EXPR
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$2);
				$$.traducao = $2.traducao + "\n \t" + get_var($1.nome)->id + " = " + $2.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID TK_ADDI EXPR
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$3);
				$$.traducao = $3.traducao + "\n \t" + get_var($1.nome)->id + " += " + get_var($1.nome)->id + "+" + $3.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID TK_SUBI EXPR
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$3);
				$$.traducao = $3.traducao + "\n \t" + get_var($1.nome)->id + " = " + get_var($1.nome)->id + "-" + $3.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID TK_MULTI EXPR
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$3);
				$$.traducao = $3.traducao + "\n \t" + get_var($1.nome)->id + " = " + get_var($1.nome)->id + "*" + $3.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID TK_DIVI EXPR
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.var_tipo = get_var($1.nome)->type;
				implicit_return(&$$, &$3);
				$$.traducao = $3.traducao + "\n \t" + get_var($1.nome)->id + " = " + get_var($1.nome)->id + "/" + $3.label + ";\n";
				$2.traducao = " ";
			}
			|	TK_ID TK_INVERT TK_ID
			{
				if(!get_var($1.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}

				if(!get_var($3.nome)){
					$$.label = create_var_names();
					set_var($2.var_tipo, $1.nome, $2.valor, $$.label);
				}
				$$.label = create_temp_names();
				$$.var_tipo = get_var($3.nome)->type;
				set_var($$.var_tipo, "temp", $3.valor, $$.label);
				$$.traducao += "\n\t" + $$.label + " = " + get_var($3.nome)->id + "\n\t" + get_var($3.nome)->id + " = " + get_var($1.nome)->id + "\n\t" + get_var($1.nome)->id + " = " + $$.label + ";\n";
			}
			|	TK_ID TK_POW TERM
			{
				string loop = create_loop_names();
				string control = create_temp_names();
				string box = create_temp_names();

				set_var("int", "", "0", control);

				VAR* temp = get_var($1.nome);

				set_var(temp->type, "", "0", box);

				if(!temp){
					yyerror(in_line() + " Variável não existe, operação requer que já exista");
				}

				$$.traducao = $3.traducao + "\n\t" + loop + ":\n\t" + box + " = " + temp->id + " * " + temp->id + ";\n\t"
				+ temp->id + " = " + box + ";\n\t" + control + " = " + control + " + 1;\n\tif(" + control + " < "
				+ $3.label + ") goto " + loop + ";\n";

			}
			|	TK_ID TK_FACTORIAL
			{
				string loop = create_loop_names();
				string control = create_temp_names();

				VAR* temp = get_var($1.nome);

				$$.label = temp->id;
				$$.var_tipo = temp->type;

				if(!temp){
					yyerror(in_line() + " Variável não existe, operação requer que já exista");
				}

				if($$.var_tipo != "int"){
					yyerror(in_line() + "Operação permitida somente com inteiros!");
				}

				set_var("int", "", "0", control);

				$$.traducao = "\n\t" + control + " = " + $$.label + ";\n";
				$$.traducao += "\t" + loop + ":\n\t" + control + " = " + control + " - 1;\n\t"
				+ $$.label + " *= " + control + ";\n\t" + "if(" + control + " != 1) goto " + loop + ";\n";
			}
			|	VECTOR_MATRIX_OPERATIONS
			;

EXPR		:	'(' EXPR ')'
			{
				$$ = $2;
			}
			|	EXPR '+' EXPR
			{
				if($1.var_tipo == "string" || $3.var_tipo == "string"){
					$$.label = create_temp_names();
					$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
					implicit_string(&$1, &$3, &$$);
					set_var($$.var_tipo, "temp", $$.valor, $$.label);
				} else{
					if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
					$$.op = "+";
					$$.label = create_temp_names();
					$$.traducao = $1.traducao + "\n" + $3.traducao + "\n";
					implicit_cast(&$1, &$3, &$$);
					set_var($$.var_tipo, "temp", $$.valor, $$.label);
					$$.traducao += "\t" + $$.label + " = " + $1.label + '+' + $3.label + ";\n";
					$$.valor = $$.label;
				}
			}
			|	EXPR '-' EXPR
			{
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
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
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
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
				if($1.var_tipo == "bool" || $3.var_tipo == "bool") yyerror(in_line () + "Operação inválida com booleano");
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
				if(!get_var($1.nome)) yyerror(in_line() + "Variável " + $1.nome +  "não existe");
				if(get_var($1.nome)->type == "bool" || get_var($1.nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
				$$.label = create_temp_names();
				$$.var_tipo = get_var($1.nome)->type;
				set_var($$.var_tipo, "temp", $$.valor, $$.label);
				$$.traducao = "\t" + $$.label + " = "+ get_var($1.nome)->id + "+1;";
			}
			|	TK_SUB1
			{
				if(!get_var($1.nome)) yyerror(in_line() + "Variável " + $1.nome +  "não existe");
				if(get_var($1.nome)->type == "bool" || get_var($1.nome)->type == "char") yyerror(in_line () + "Operação só permitida com float e int");
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
			|	CALL_FUN
			{
				$$ = $1;
			}
			;

CALL_FUN 	:	TK_ID '(' FUN_PARAMS ')'
			{
				FUN* function = get_function($1.nome);

				if(!function){
					yyerror(in_line() + " A função requisitada não existe ou está declarada abaixo do escopo.");
				}

				set_vars_functions(function);

				$$.var_tipo = function->type_return;
				$$.label = function->name_return;
				
				if(params.size() < function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros menor do que o esperado");
				}

				if(params.size() > function->map_parameters.size()){
					yyerror(in_line() + " Passagem de parâmetros maior do que o esperado");
				}

				int j = params.size()-1;

				if($$.var_tipo == "none"){
					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) $$.traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						
						implicit_return(&parametro, &passagem);

						$$.traducao += passagem.traducao;
						$$.traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}
				} else{
					for(int i=0; i<params.size(); i++){
						ATR passagem;
						ATR parametro;

						passagem.label = params[j].id;
						passagem.var_tipo = params[j].type;
						passagem.nome = params[j].name;
						parametro.label = function->map_parameters[i].id;
						parametro.var_tipo = function->map_parameters[i].type;

						if(!get_var(passagem.nome)) $$.traducao += "\n\t" + passagem.label + " = " + params[j].value + ";\n";
						
						implicit_return(&parametro, &passagem);

						$$.traducao += passagem.traducao;
						$$.traducao += "\n\t" + parametro.label + " = " + passagem.label + ";\n";
						j--;
					}
				}

				params.clear();
				
				$$.traducao += function->body;
			}
			;

FUN_PARAMS	:	FUN_PARAM
			{
				$$.traducao = $1.traducao;
				VAR temp;
				temp.value = $1.valor;
				temp.type = $1.var_tipo;
				temp.id = $1.label;
				temp.name = $1.nome;
				params.push_back(temp);
			}
			|	FUN_PARAM ',' FUN_PARAMS
			{
				$$.traducao = $1.traducao;
				VAR temp;
				temp.value = $1.valor;
				temp.type = $1.var_tipo;
				temp.id = $1.label;
				temp.name = $1.nome;
				params.push_back(temp);
			}
			|
			;

FUN_PARAM	:	TERM
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
				if($3.var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				string l_end = create_loop_names();
				$$.traducao = "\t" + $1.label + ":" + "\n" + $3.traducao + "\n\tif(!" + $3.label + ") goto " + l_end + ";\n" + $5.traducao + "\tgoto "+ $1.label + ";\n\t" + l_end + ":\n\t";
			}
			| TK_DO BLOCO TK_WHILE '(' EXPR ')'
			{
				if($5.var_tipo != "bool") yyerror(in_line () + "A condição do While só permite booleano como retorno");
				$$.traducao = "\t" + $1.label + ":" + "\n" + $2.traducao + $5.traducao + "\tif(" + $5.label + ") goto " + $1.label + ";\n";
				pilha.pop();
			}
			;

UNTIL 		:	TK_UNTIL '(' LOGICO ')' BLOCO
			{
				if($3.var_tipo != "bool") yyerror(in_line () + "A condição do Until só permite booleano como retorno");
				string l_end = create_loop_names();
				$$.traducao = "\t" + $1.label + ":" + "\n" + $3.traducao + "\n\tif(" + $3.label + ") goto " + l_end + ";\n" + $5.traducao + "\tgoto "+ $1.label + ";\n\t" + l_end + ":\n\t";
			}
			;

FOR 		:	TK_FOR '(' DECLARACOES ';' LOGICO ';' OPERACOES ')' BLOCO
			{
				string l_end = create_loop_names();
				if($5.traducao == ""){
					$$.traducao = $3.traducao + "\n\t" + $1.label + ":\n\t" + $7.traducao + $9.traducao + "goto " + $1.label + ";\n\t" + l_end + ":\n\t";
				}else{
					$$.traducao = $3.traducao + "\n\t" + $1.label + ":\n\t" + $5.traducao + "\tif(!" + $5.label + ") goto " + l_end + ";\n" + $7.traducao + $9.traducao + "\tgoto " + $1.label + ";\n\t" + l_end + ":\n\t";
				}
			}
			;

FOREACH		:	TK_FOREACH '(' TERM TK_IN TK_ID TK_AS TK_ID ')' BLOCO
			{
				VECTORS* temp = get_vector($5.nome);
				
				if(!temp){
					temp = get_matrix($5.nome);
				}

				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();

				$7.label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, $7.nome, "", $7.label);

				$$.traducao = "\n\t" + total_loop + " = " + temp->row + " + " + temp->column + ";\n";
				$$.traducao += $3.traducao + "\n\t" + control + " = " + "0;\n\tstart_foreach:\n\t" + $7.label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + $7.label + " != " + $3.label + ") goto middle_foreach;\n\t" 
				+ "\n" + $9.traducao + "\n\tmiddle_foreach:\n\t" + "if(" + control + "<" + total_loop + ") goto start_foreach;\n";
			}
			|	TK_FOREACH '(' TERM TK_IN TK_NOT TK_ID TK_AS TK_ID ')' BLOCO
			{
				VECTORS* temp = get_vector($5.nome);

				if(!temp) yyerror(in_line() + "Estrutura não existe");

				string control = create_temp_names();
				string total_loop = create_temp_names();

				$8.label = create_temp_names();

				set_var("int", "", "", control);
				set_var("int", "", "", total_loop);
				set_var(temp->type, $8.nome, "", $8.label);

				$$.traducao = "\n\t" + total_loop + " = " + temp->row + " + " + temp->column + ";\n";
				$$.traducao += $3.traducao + "\n\t" + control + " = " + "0;\n\tstart_foreach:\n\t" + $8.label + " = " + temp->id + '[' + control
				+ "];\n\t" + control + " = " + control + " + 1;\n\t" + "if(" + $8.label + " == " + $3.label + ") goto middle_foreach;\n\t" 
				+ "\n" + $10.traducao + "\n\tmiddle_foreach:\n\t" + "if(" + control + "<" + total_loop + ") goto start_foreach;\n";
			}
			;

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
				$$.label = create_jump_names();
				$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $$.label + ";\n" + $5.traducao + "\n\t" + "goto global_end;\n\t" + $$.label + ":\n";
			}
			|	TK_IF '(' LOGICO ')' BLOCO CONIF_NO_MATCHED
			{
				$$.label = create_jump_names();
				$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $$.label + ";\n" + $5.traducao + "\n\t" + "goto global_end;\n\t" + $$.label + ":\n" + $6.traducao + "\n\t" + "global_end:\n";
			}
			|	TK_IF '(' LOGICO ')' BLOCO CONIF_MATCHED
			{
				$$.label = create_jump_names();
				$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $6.label + ";\n" + $5.traducao + "\tgoto " + $$.label + ";\n\t" + $6.label + ":\n" + $6.traducao + "\n\t" + "goto global_end;\n\t" + $$.label + ":\n\t" + "global_end:\n";
			}
			;

CONIF_NO_MATCHED :	TK_ELIF '(' LOGICO ')' BLOCO CONIF_NO_MATCHED
				{
					$$.label = create_jump_names();
					$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $$.label + ";\n" + $5.traducao + "\t" + "goto global_end;\n\t" + $$.label + ":\n" + $6.traducao;
				}
				|	TK_ELIF '(' LOGICO ')' BLOCO CONIF_MATCHED
				{
					$$.label = create_jump_names();
					$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $6.label + ";\n" + $5.traducao + "\tgoto " + $$.label + ";\n\t" + $6.label + ":\n" + $6.traducao + "\n\t" + "goto global_end;\n\t" + $$.label + ":";
				}
				|	TK_ELIF '(' LOGICO ')' BLOCO
				{
					$$.label = create_jump_names();
					$$.traducao = $3.traducao + "\tif(!" + $3.label + ") goto " + $$.label + ";\n" + $5.traducao + "\n\t" + $$.label + ":\n";
				}
				;

CONIF_MATCHED :	TK_ELSE BLOCO
				{
					$$.label = create_jump_names();
					$$.traducao = $2.traducao;
				}
				;

SWITCH 	: TK_SWITCH '(' EXPR ')' TK_BEGIN CASES TK_END
		{
			set_var($3.var_tipo, "", $3.label, $1.label);
			$$.label = create_switch_names();
			$$.traducao = "\n" + $3.traducao + "\n\t" + $3.var_tipo + " " + $1.label + ";\n\t" + $1.label + " = " + $3.label + ";\n\t" + $6.traducao + "\n\t" + $$.label + ":\n";
			pilha.pop();
		}
		| TK_SWITCH '(' TERM ')' TK_BEGIN CASES TK_END
		{
			//$$.traducao = $6.traducao + $3.traducao;
			//pilha.pop();
		}
		;

CASES	:	CASE CASES
		{
			$$.traducao = $1.traducao + "\n" + $2.traducao;
		}
		|
		;

CASE 		: TK_CASE TERM ':' COMANDOS
			{
				int swt = switches;
				swt--;
				$$.label = create_jump_names();
				$$.traducao = "\n" + $2.traducao + "\n\tif(!switch" + to_string(swt) + " == " + $2.label + ")\n\t" + $4.traducao; 
				$2.traducao = " ";
 			}
			| TK_CASE TERM ':' COMANDOS TK_BREAK ';'
			{
				//$$.label = create_jump_names();
				int swt = switches;
				swt--;
				$$.label = create_jump_names();
				$$.traducao = "\n" + $2.traducao + "\n\tif(!switch" + to_string(swt) + " == " + $2.label + ")\n\t"; 
			}
			;

TERM		:	TK_ID
			{
				VAR* temp = get_var($1.nome);

				if(!temp){
					yyerror(in_line() + "Variável " + $1.nome +  " não existe");
				}else{
					$$.var_tipo = temp->type;
					$$.label = temp->id;
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
				set_var($1.var_tipo, "temp", $1.valor, $1.label);
			}
			/*	TK_ID '[' EXPR ']'
			{
				cout << "entrou7 de temp" << endl;
				VECTORS* temp = get_vector($1.nome);

				if(!temp){
					yyerror(in_line() + "Vetor " + $1.nome + " não existe!");
				}

				$$.label = temp->id + "[" + temp->row + "]";
				$$.var_tipo = temp->type;

				string jump = create_jump_names();
				string error_msg = "\n\tcout << " + in_line() + "<< limite do vetor excedido;";

				string condition = $3.traducao + "\n\tif(" + $3.label + "<" + temp->row + ") goto " 
				+ jump + ";\n" + error_msg + "\n\texit(1);\n\t" + jump + ":\n";

				$$.traducao = condition;
			}*/
			;

WRITE		:	TK_WRITELN '(' TK_ID ')'
			{
				if(!search_var($3.nome)){
					yyerror(in_line () + "Variável não existe");
				}

				VAR* temp = get_var($3.nome);

				if(temp->type != "string"){
					$$.label = create_temp_names();
					$$.var_tipo = temp->type;
					$$.traducao = "\t\"cin >> " + temp->id + "\";\n";
					$$.traducao += "\n\t" + $$.label + " = " + "(" + temp->type + ")";
				} else{
					string word = create_temp_names();
					string lenght = create_temp_names();
					
				}
			}

PRINT 		:	TK_READLN '(' PARAMS ')'
			{
				$$.traducao = "\tcout" + $3.traducao + " << endl;\n";
			}
			;

PARAMS	:	PARAM
		{
			$$.traducao = " << " + $1.traducao;
		}
		|	PARAM '+' PARAMS
		{
			$$.traducao = " << " + $1.traducao + $3.traducao;
		}
		|
		;

PARAM	:	TK_ID
		{
			if(!get_var($$.nome)){
				yyerror(in_line() + "Variável " + $1.nome +  " não existe");
			}else{
				$$.traducao = get_var($$.nome)->id;
			}
		}
		|	TK_ID '[' EXPR ']'
		{
			if(!get_vector($1.nome)) yyerror(in_line () + "Vetor não existe");

			VECTORS* temp = get_vector($1.nome);
		}
		|	TK_ID '[' EXPR ']' '[' EXPR ']'
		{

		}
		|	TK_STRING
		{
			$$.traducao = $1.valor;
		}
		;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	FUN function;
	function.next = NULL;
	pilha.push(function);
	first_exestack = &pilha.top();

	yyparse();

	pilha.pop();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}
