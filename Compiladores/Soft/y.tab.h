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
    TK_TYPE_CHAR = 258,
    TK_TYPE_FLOAT = 259,
    TK_TYPE_BOOL = 260,
    TK_TYPE_INT = 261,
    TK_TYPE_VAR = 262,
    TK_NUM = 263,
    TK_FLOAT = 264,
    TK_DOUBLE = 265,
    TK_SHORT = 266,
    TK_CHAR = 267,
    TK_VAR = 268,
    STRING = 269,
    TK_INT = 270,
    TK_BOOL = 271,
    TK_MAIN = 272,
    TK_ID = 273,
    TK_FIM = 274,
    TK_ERROR = 275,
    TK_BEGIN = 276,
    TK_END = 277,
    TK_FUNCTIONS = 278,
    FOR = 279,
    WHILE = 280,
    DO = 281,
    CONTINUE = 282,
    BREAK = 283,
    TK_JUMP = 284,
    TK_TO = 285,
    IF = 286,
    ELSE = 287,
    ELIF = 288,
    SWITCH = 289,
    UNTIL = 290,
    CASE = 291,
    PARAMS = 292,
    SUPER = 293,
    VAR = 294,
    TK_SUM = 295,
    AND = 296,
    OR = 297,
    ORI = 298,
    NAND = 299,
    TK_CAST = 300
  };
#endif
/* Tokens.  */
#define TK_TYPE_CHAR 258
#define TK_TYPE_FLOAT 259
#define TK_TYPE_BOOL 260
#define TK_TYPE_INT 261
#define TK_TYPE_VAR 262
#define TK_NUM 263
#define TK_FLOAT 264
#define TK_DOUBLE 265
#define TK_SHORT 266
#define TK_CHAR 267
#define TK_VAR 268
#define STRING 269
#define TK_INT 270
#define TK_BOOL 271
#define TK_MAIN 272
#define TK_ID 273
#define TK_FIM 274
#define TK_ERROR 275
#define TK_BEGIN 276
#define TK_END 277
#define TK_FUNCTIONS 278
#define FOR 279
#define WHILE 280
#define DO 281
#define CONTINUE 282
#define BREAK 283
#define TK_JUMP 284
#define TK_TO 285
#define IF 286
#define ELSE 287
#define ELIF 288
#define SWITCH 289
#define UNTIL 290
#define CASE 291
#define PARAMS 292
#define SUPER 293
#define VAR 294
#define TK_SUM 295
#define AND 296
#define OR 297
#define ORI 298
#define NAND 299
#define TK_CAST 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
