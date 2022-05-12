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
    int lineNumber = 0;
    string l;
    fstream fin("file/sample.txt", fstream::in);
    while(fin >> noskipws >> ch){
        l += ch;
        if(ch == '\n') {   // detects the end of the line
            cout << l;
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
