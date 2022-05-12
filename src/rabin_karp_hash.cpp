#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <alloca.h>
#include <cstring>
using namespace std;

class RabinKarpAlgo{
    public:
        static void rabin_karp( char* palabra, char* linea, int numero_linea){
            //
        }

        static void readFileAndFindWord(char* word, string file){
            char ch;
            int lineNumber = 0;
            string l; //temporal string to append characters

            fstream fin(file, fstream::in);

            while(fin >> noskipws >> ch){
                l += ch;
                if(ch == '\n'){   // detects the end of the line
                    char* line;

                    line = (char *)alloca(l.size() + 1); // allocates memory on stack and copies string
                    memcpy(line, l.c_str(), l.size() + 1);

                    lineNumber++;

                    rabin_karp(word, line, lineNumber);

                    l = "";
                }
            }
            fin.close();
        }
    private:
        int hashFunction(char c){
            return 0;
        }
}

int main(){
    return 0;
}
