/*
Jacob Drew
CS 4280
scanner.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "scanner.h"
#include "token.h"
using namespace std;

// begin end do while whole label return input output program warp if then pick declare assign func
// Operators and delimiters group (all single character except ==  := != || && )
//=  <  > == != : :=  +  -  *  /   ^  . (  ) , { } ; [ ] || &&

// array of strings corresponding to enums
string *tokenNames = new string[44]{"EOF_TK",
                                    "IDENT_tk",
                                    "NUM_TK",
                                    "BEGIN_TK",
                                    "END_TK",
                                    "DO_TK",
                                    "WHILE_TK",
                                    "WHOLE_TK",
                                    "LABEL_TK",
                                    "RETURN_TK",
                                    "INPUT_TK",
                                    "OUTPUT_TK",
                                    "PROGRAM_TK",
                                    "WARP_TK",
                                    "IF_TK",
                                    "THEN_TK",
                                    "PICK_TK",
                                    "DECLARE_TK",
                                    "ASSIGN_TK",
                                    "FUNC_TK",
                                    "OP_EQUALS",
                                    "OP_LESS_THAN",
                                    "OP_GREATER_THAN",
                                    "OPERATOR_DOUBLE_EQUALS",
                                    "OPERATOR_EXCLAMATION_POINT_EQUALS",
                                    "OP_COLON",
                                    "OP_COLON_EQUALS",
                                    "OP_PLUS",
                                    "OP_MINUS",
                                    "OP_ASTERISK",
                                    "OP_SLASH",
                                    "OP_CARROT",
                                    "OP_PERIOD",
                                    "DELIM_LEFT_PARENTHESIS",
                                    "DELIM_RIGHT_PARENTHESIS",
                                    "DELIM_COMMA",
                                    "DELIM_LEFT_CURLY_BRACE",
                                    "DELIM_RIGHT_CURLY_BRACE",
                                    "DELIM_SEMICOLON",
                                    "DELIM_LEFT_SQUARE_BRACKET",
                                    "DELIM_RIGHT_SQUARE_BRACKET",
                                    "OP_AND",
                                    "OP_OR"};

// begin end do while whole label return input output program warp if then pick declare assign func
string *keywordArray = new string[17]{"begin", "end", "do", "while", "whole", "label", "return", "input", "output", "program", "warp", "if", "then", "pick", "declare", "assign", "func"};
//=  <  > == != : :=  +  -  *  /   ^  . (  ) , { } ; [ ] || &&
string *OP_DELIM_array = new string[23]{"=", "<", ">", "==", "!=", ":", ":=", "+", "-", "*", "/", "^", ".", "(", ")", ",", "{", "}", ";", "[", "]", "||", "&&"};

void scanner(string outputFileNameString)
{
    Token nextToken;
    int lineNumber = 0;
    ifstream inputStream;
    inputStream.open(outputFileNameString.c_str());
    string data;
    string line;
    int i = 0;
    while (getline(inputStream, line))
    {
        lineNumber++;
        int commentFlag = 0;
        if (line[0] == '#')
        {
            commentFlag = 1;
        }

        if (line[0] == '#' && line[line.length() - 1] != '#')
        {
            cout << "errorr at lineNumber: " << lineNumber << endl;
            perror("scanner error");
            abort();
        }
        cout << line << endl;

        if (commentFlag == 0)
        {
            istringstream ss(line);
            while (ss >> data)
            {
                nextToken.tokenInstance = "";
                // convert data into token
                // map the string to a tokenID

                if (isdigit(data[0]))
                {
                    nextToken.tokenID = NUM_TK;
                    nextToken.tokenInstance = data;
                    nextToken.lineNumber = lineNumber;
                    printToken(nextToken);
                }

                int keywordflag = 0;
                if (islower(data[0]))
                {
                    // check against array of keywords
                    for (i = 0; i < 17; i++)
                    {
                        if (keywordArray[i].find(data, 0) != string::npos)
                        {
                            // data is a keyword
                            // convert the keyword array to a tokenID enum

                            nextToken.tokenID = TokenID(i + 3);
                            nextToken.tokenInstance = data;
                            nextToken.lineNumber = lineNumber;
                            printToken(nextToken);
                            keywordflag = 1;
                        }
                    }
                    if (keywordflag != 1)
                    {
                        // data is not a keyword but it is an identifier
                        nextToken.tokenID = IDENT_tk;
                        nextToken.tokenInstance = data;
                        nextToken.lineNumber = lineNumber;
                        printToken(nextToken);
                    }
                }

                // else the token is a delim or operator
                for (i = 0; i < 23; i++)
                {
                    // equal token edgecase
                    if (data == "=")
                    {
                        nextToken.tokenID = TokenID(i + 20);
                        nextToken.tokenInstance = data;
                        nextToken.lineNumber = lineNumber;
                        printToken(nextToken);
                        break;
                    }
                    else if (OP_DELIM_array[i].find(data, 0) != string::npos)
                    {
                        // convert the OP_DELIM array to a tokenID enum
                        nextToken.tokenID = TokenID(i + 20);
                        nextToken.tokenInstance = data;
                        nextToken.lineNumber = lineNumber;
                        printToken(nextToken);
                    }
                }

                if (nextToken.tokenInstance == "")
                {
                    cout << "errorr at lineNumber: " << lineNumber << endl;
                    perror("Unknown token");
                    abort();
                }
            }
        }
    }

    // after the file has been processed the last token would be an EOF
    nextToken.tokenID = EOF_TK;
    nextToken.tokenInstance = "";
    nextToken.lineNumber = lineNumber;
    printToken(nextToken);
    inputStream.close();
}

void printToken(struct Token currentToken)
{
    string currentTokenID = tokenNames[currentToken.tokenID];
    cout << "Token Id: " << currentTokenID << " Token Instance: " << currentToken.tokenInstance << " Line Number: " << currentToken.lineNumber << endl;
}