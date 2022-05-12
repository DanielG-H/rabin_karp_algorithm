#include<iostream>
#include<string>
#include <fstream>
#include <alloca.h>
#include <cstring>
using namespace std;

void rabin_karp( char* palabra, char* linea, int numero_linea){
    //
}

void readFileAndFindWord(char* word){
    char ch;
    int lineNumber = 0;
    string l;
    fstream fin("file/sample.txt", fstream::in);
    while(fin >> noskipws >> ch){
        l += ch;
        if(ch == '\n') {   // detects the end of the line
            char* line;

            line = (char *)alloca(l.size() + 1);
            memcpy(line, l.c_str(), l.size() + 1);

            lineNumber++;

            rabin_karp(word, line, lineNumber);

            l = "";
        }
    }
    fin.close();
}

int main()
{
    return 0;
}
