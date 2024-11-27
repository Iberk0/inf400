/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_ONURALP_DESKTOP_ODEV_INF400_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_HOME_ONURALP_DESKTOP_ODEV_INF400_BUILD_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    REJECTED = 258,                /* REJECTED  */
    L_INTEGER = 259,               /* L_INTEGER  */
    L_STRING = 260,                /* L_STRING  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    KW_IMPORT = 262,               /* KW_IMPORT  */
    KW_FUNC = 263,                 /* KW_FUNC  */
    KW_IF = 264,                   /* KW_IF  */
    KW_WHILE = 265,                /* KW_WHILE  */
    KW_CLASS = 266,                /* KW_CLASS  */
    KW_LET = 267,                  /* KW_LET  */
    KW_ELSE = 268,                 /* KW_ELSE  */
    KW_RETURN = 269,               /* KW_RETURN  */
    OP_PLUS = 270,                 /* OP_PLUS  */
    OP_MINUS = 271,                /* OP_MINUS  */
    OP_MULT = 272,                 /* OP_MULT  */
    OP_DIVF = 273,                 /* OP_DIVF  */
    OP_ASSIGN = 274,               /* OP_ASSIGN  */
    OP_LPAREN = 275,               /* OP_LPAREN  */
    OP_RPAREN = 276,               /* OP_RPAREN  */
    OP_LBRACE = 277,               /* OP_LBRACE  */
    OP_RBRACE = 278,               /* OP_RBRACE  */
    OP_SCOLON = 279,               /* OP_SCOLON  */
    OP_COLON = 280,                /* OP_COLON  */
    OP_COMMA = 281,                /* OP_COMMA  */
    OP_DOT = 282,                  /* OP_DOT  */
    OP_LESS = 283,                 /* OP_LESS  */
    OP_LESSEQ = 284,               /* OP_LESSEQ  */
    OP_GREATER = 285,              /* OP_GREATER  */
    OP_GREATEREQ = 286,            /* OP_GREATEREQ  */
    OP_EQUAL = 287,                /* OP_EQUAL  */
    OP_NOT_EQUAL = 288             /* OP_NOT_EQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_ONURALP_DESKTOP_ODEV_INF400_BUILD_PARSER_HPP_INCLUDED  */
