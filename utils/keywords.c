#include "keywords.h"

string* s_type_keywords;

string* s_keywords;

void type_keywords_construct(void)
{
  s_type_keywords = malloc(sizeof(string)*TYPE_KEYWORDS_COUNT);
  string_construct_v(&s_type_keywords[0], "ident\0");
  string_construct_v(&s_type_keywords[1], "number \0");
  string_construct_v(&s_type_keywords[2], "strnliteral\0");
  string_construct_v(&s_type_keywords[3], "charliteral\0");
  string_construct_v(&s_type_keywords[4], "lparen\0");
  string_construct_v(&s_type_keywords[5], "rparen\0");
  string_construct_v(&s_type_keywords[6], "times\0");
  string_construct_v(&s_type_keywords[7], "slash\0");
  string_construct_v(&s_type_keywords[8], "plus\0");
  string_construct_v(&s_type_keywords[9], "minus\0");
  string_construct_v(&s_type_keywords[10], "eql\0");
  string_construct_v(&s_type_keywords[11], "neq\0");
  string_construct_v(&s_type_keywords[12], "lss\0");
  string_construct_v(&s_type_keywords[13], "leq\0");
  string_construct_v(&s_type_keywords[14], "gtr\0");
  string_construct_v(&s_type_keywords[15], "geq\0");
  string_construct_v(&s_type_keywords[16], "funcsym\0");
  string_construct_v(&s_type_keywords[17], "semicolon\0");
  string_construct_v(&s_type_keywords[18], "ifsym\0");
  string_construct_v(&s_type_keywords[19], "whilesym\0");
  string_construct_v(&s_type_keywords[20], "constsym\0");
  string_construct_v(&s_type_keywords[21], "varsym\0");
  string_construct_v(&s_type_keywords[22], "comma\0");
  string_construct_v(&s_type_keywords[23], "dot\0");
  string_construct_v(&s_type_keywords[24], "begin\0");
  string_construct_v(&s_type_keywords[25], "end\0");
  string_construct_v(&s_type_keywords[26], "defsym\0");
  string_construct_v(&s_type_keywords[27], "structsym\0");
  string_construct_v(&s_type_keywords[28], "returnsym\0");
  string_construct_v(&s_type_keywords[29], "elsesym\0");
  string_construct_v(&s_type_keywords[30], "assign\0");
}

void keywords_construct(void)
{
  s_keywords = malloc(sizeof(string) * KEYWORDS_COUNT);
  string_construct_v(&s_keywords[0], "function\0");
  string_construct_v(&s_keywords[1], "if\0");
  string_construct_v(&s_keywords[2], "else\0");
  string_construct_v(&s_keywords[3], "return\0");
  string_construct_v(&s_keywords[4], "while\0");
  string_construct_v(&s_keywords[5], "byte\0");
  string_construct_v(&s_keywords[6], "def\0");
  string_construct_v(&s_keywords[7], "struct\0");
  string_construct_v(&s_keywords[8], "int\0");
  string_construct_v(&s_keywords[9], "float\0");
  string_construct_v(&s_keywords[10], "const\0");
}

string* type_keywords_get(void)
{
  if(!s_type_keywords) type_keywords_construct();
  return s_type_keywords;
}

string* keywords_get(void)
{
  if(!s_keywords) keywords_construct();
  return s_keywords;
}

const char type_keyword[31][11] =
{
    "ident", "number",
    "strnliteral", "charliteral",
    "lparen", "rparen",
    "times", "slash",
    "plus", "minus",
    "eql", "neq",
    "lss", "leq",
    "gtr", "geq",
    "funcsym", "semicolon",
    "ifsym", "whilesym",
    "constsym", "varsym",
    "comma", "dot",
    "begin", "end",
    "defsym", "structsym",
    "returnsym", "elsesym", "assign"
};

const char keywords[11][9] =
{
"function\0",
"if",
"else",
"return",
"while",
"byte",
"def",
"struct",
"int",
"float",
"const"
};
