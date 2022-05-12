#include<iostream>
#include<string>
#include <fstream>
using namespace std;

void rabin_karp( char* palabra, char* linea, int numero_linea){
    //
}

void printFile()
{
    char ch;
    char* line;
    int lineNumber = 1;
    string l;
    fstream fin("file/sample.txt", fstream::in);
    while(fin >> noskipws >> ch){
        l += ch;
        if(ch == '\n') {   // detects the end of the line
            line = &l[0];
            cout << *line;
            l = "";
            lineNumber++;
        }
    }
    fin.close();
}

int main()
{
    printFile();
    return 0;
}
