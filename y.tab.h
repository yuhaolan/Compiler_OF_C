/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     INT = 259,
     VOID = 260,
     WHILE = 261,
     IF = 262,
     THEN = 263,
     ELSE = 264,
     READ = 265,
     WRITE = 266,
     FOR = 267,
     RETURN = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NE = 272,
     ID = 273,
     UMINUS = 274
   };
#endif
/* Tokens.  */
#define NUM 258
#define INT 259
#define VOID 260
#define WHILE 261
#define IF 262
#define THEN 263
#define ELSE 264
#define READ 265
#define WRITE 266
#define FOR 267
#define RETURN 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define ID 273
#define UMINUS 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 66 "lab5cminustruncate.y"
{
      int value;
      char * string;
      ASTnode * node;  /* so we can build an AST */
      enum OPERATORS operator;
      
}
/* Line 1529 of yacc.c.  */
#line 95 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

