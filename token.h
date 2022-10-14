/*
Jacob Drew
CS 4280
token.h
*/

#ifndef TOKEN_H
#define TOKEN_H
#include <stdio.h>
#include <string>
using namespace std;



//begin end do while whole label return input output program warp if then pick declare assign func 
//Operators and delimiters group (all single character except ==  := != || && )
//=  <  > == != : :=  +  -  *  /   ^  . (  ) , { } ; [ ] || &&

//enum of Token ID's
enum TokenID {
    EOF_TK, 
    IDENT_tk, 
    NUM_TK, 
    BEGIN_TK, 
    END_TK, 
    DO_TK, 
    WHILE_TK, 
    WHOLE_TK, 
    LABEL_TK,
    RETURN_TK,
    INPUT_TK,
    OUTPUT_TK,
    PROGRAM_TK,
    WARP_TK,
    IF_TK,
    THEN_TK,
    PICK_TK,
    DECLARE_TK,
    ASSIGN_TK,
    FUNC_TK,
    OP_EQUALS, 
    OP_LESS_THAN, 
    OP_GREATER_THAN, 
    OPERATOR_DOUBLE_EQUALS, 
    OPERATOR_EXCLAMATION_POINT_EQUALS, 
    OP_COLON,
    OP_COLON_EQUALS, 
    OP_PLUS, 
    OP_MINUS, 
    OP_ASTERISK,
    OP_SLASH, 
    OP_CARROT,
    OP_PERIOD,
    DELIM_LEFT_PARENTHESIS, 
    DELIM_RIGHT_PARENTHESIS, 
    DELIM_COMMA,
    DELIM_LEFT_CURLY_BRACE, 
    DELIM_RIGHT_CURLY_BRACE, 
    DELIM_SEMICOLON,
    DELIM_LEFT_SQUARE_BRACKET, 
    DELIM_RIGHT_SQUARE_BRACKET, 
    OP_AND,
    OP_OR
};

// Token triplet struct 
struct Token
{
    TokenID tokenID;
    string tokenInstance;
    int lineNumber;
}typedef Token;

#endif