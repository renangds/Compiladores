all:
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl
		./glf < exemplo.soft

exec:
			./glf < exemplo.soft > teste.cpp
			g++ teste.cpp
			./a.out