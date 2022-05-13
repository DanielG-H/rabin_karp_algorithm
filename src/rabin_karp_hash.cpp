#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <alloca.h>
#include <cstring>
using namespace std;

class RabinKarpAlgo{
    private:
        static int hash_function(char* palabra, int length_palabra){
            const int prime = 11;
            const int number_of_ascii_chars = 95;
            int hash = 0;
            int weight_char = 0;
            
            return 0;
        }
        
    public:
        static void rabin_karp( char* palabra, char* linea, int numero_linea){
            const int length_palabra = strlen(palabra);
            const int length_linea = strlen(linea);
            
            cout << hash_function(palabra, length_palabra);
        }
        
        static void findWordMatches(char* word, string file){
            char ch;
            int lineNumber = 0;
            string l;
            fstream fin(file, fstream::in);
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
};

int main(){
    return 0;
}
