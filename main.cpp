/* 
Jacob Drew
4280 P0
Main.c++
*/

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "testScanner.h"
#include "token.h"

using namespace std;

int main(int argc, char *argv[])
{
  // output file strings
  string outputFileNameString;

  FILE *redirectionFile;
  string line = "";
  redirectionFile = fopen("stdinInput.txt", "w");
  ifstream inputFileStream;
  FILE *inputFILE;

  // handle command args
  //  if the arg is two we read the file otherwise we have to deal with keyboard input / read from stdin
  if (argc == 2)
  {
    inputFileStream.open(argv[1]);
    if (!inputFileStream)
    {
      perror("ERROR! Bad File!"); // print out useful error message
    }
    outputFileNameString = argv[1];
    
    //outputFileNameString = outputFileNameString + ".output";
  }
  if (argc == 1)
  {
    fstream redirectionFstream;
    redirectionFstream.open("stdinInput.txt", ios::in | ios::out);
    cout << "Please input text for the tree. You can input multiple lines. Enter 'ctrl+D' when finished:" << endl;
    cout << "Input text:" << endl;
    while (cin >> line)
    {
      redirectionFstream << line << endl;
    }
    redirectionFstream.close();
    inputFileStream.open("stdinInput.txt");
    outputFileNameString = "output.txt";
  }

  //inputFILE = fopen(outputFileNameString.c_str(), "w");
  

  testScanner(outputFileNameString);

  // fclose(inputFILE);
  remove("stdinInput.txt");

  return 0;
}