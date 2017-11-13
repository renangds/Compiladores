/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_CAST = 258,
    TK_OPL = 259,
    TK_OPA = 260,
    TK_TRUE = 261,
    TK_FALSE = 262,
    TK_ADD1 = 263,
    TK_SUB1 = 264,
    TK_ADDI = 265,
    TK_SUBI = 266,
    TK_MAIN = 267,
    TK_ID = 268,
    TK_CHAR = 269,
    TK_STRING = 270,
    TK_INT = 271,
    TK_FLOAT = 272,
    TK_BOOL = 273,
    TK_TYPES = 274,
    TK_GLOBAL = 275,
    TK_VAR = 276,
    TK_FIM = 277,
    TK_ERROR = 278,
    TK_BEGIN = 279,
    TK_END = 280,
    TK_FUNCTION = 281,
    TK_WHILE = 282,
    TK_FOR = 283,
    TK_DO = 284,
    TK_BREAK = 285,
    TK_CONTINUE = 286,
    TK_UNTIL = 287,
    TK_IF = 288,
    TK_ELSE = 289,
    TK_ELIF = 290,
    TK_CASE = 291,
    TK_SWITCH = 292,
    TK_PRINTLN = 293,
    TK_GET = 294
  };
#endif
/* Tokens.  */
#define TK_CAST 258
#define TK_OPL 259
#define TK_OPA 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_ADD1 263
#define TK_SUB1 264
#define TK_ADDI 265
#define TK_SUBI 266
#define TK_MAIN 267
#define TK_ID 268
#define TK_CHAR 269
#define TK_STRING 270
#define TK_INT 271
#define TK_FLOAT 272
#define TK_BOOL 273
#define TK_TYPES 274
#define TK_GLOBAL 275
#define TK_VAR 276
#define TK_FIM 277
#define TK_ERROR 278
#define TK_BEGIN 279
#define TK_END 280
#define TK_FUNCTION 281
#define TK_WHILE 282
#define TK_FOR 283
#define TK_DO 284
#define TK_BREAK 285
#define TK_CONTINUE 286
#define TK_UNTIL 287
#define TK_IF 288
#define TK_ELSE 289
#define TK_ELIF 290
#define TK_CASE 291
#define TK_SWITCH 292
#define TK_PRINTLN 293
#define TK_GET 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
