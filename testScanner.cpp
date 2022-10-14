/*
Jacob Drew
CS 4280
testScanner.cpp
*/


#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"
#include "token.h"
#include "scanner.h"
#include <iostream>
using namespace std;

// driver to test the scanner function
void testScanner(string outputFileNameString) {
	//set output file filename
	//FILE *outputFile = fopen(inorderOutputString.c_str(), "w");
	// Token nextToken;
	
	// while ((nextToken = scanner()).tokenID != EOF_TK){
	// 	 printToken(nextToken);

	// }
     
    // printToken(nextToken);

	//close the file


	/*
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
	*/
	scanner(outputFileNameString);

}