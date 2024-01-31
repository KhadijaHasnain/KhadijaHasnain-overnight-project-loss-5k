/*
 * Copyright (C) Rida Bazzi
 *
 * Do not share this file with anyone
 */
#ifndef __LEXER__H__
#define __LEXER__H__

#include <vector>
#include <string>

#include "inputbuf.h"

// ------- token types -------------------

typedef enum { END_OF_FILE = 0,
    IF, WHILE, DO, THEN, PRINT, HASH,
    SYMBOL, CHAR, INPUT_TEXT,
    PLUS, MINUS, DIV, STAR,
    EQUAL, COLON, COMMA, SEMICOLON, UNDERSCORE,
    LBRAC, RBRAC, LPAREN, RPAREN, OR,
    NOTEQUAL, GREATER, LESS, LTEQ, GTEQ,
    DOT, NUM, ID, ERROR, REALNUM, BASE08NUM, BASE16NUM // TODO: Add labels for new token types here
} TokenType;

class Token {
  public:
    void Print();

    std::string lexeme;
    TokenType token_type;
    int line_no;
};

class LexicalAnalyzer {
  public:
    Token GetToken();
    TokenType UngetToken(Token);
    LexicalAnalyzer();

  private:
    std::vector<Token> tokens;
    int line_no;
    Token tmp;
    InputBuffer input;

    bool SkipSpace();
    bool IsKeyword(std::string);
    TokenType FindKeywordIndex(std::string);
    Token ScanIdOrKeyword();
    Token ScanNumber();
    Token ScanRealNumber(std::string);
    Token Scan08Decimal(std::string);
    Token ScanInput();
    Token ScanSymbol();
    Token Base16Num();
};

#endif  //__LEXER__H__
