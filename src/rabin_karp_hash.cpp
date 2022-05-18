#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <malloc.h>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

class RabinKarpAlgo{
    private:
        const int PRIME = 77777;
        const int BASE = 256;
    public:
         /*
            vector of tuples to store index of word in line and line number 
            where it was found
            */
        vector< tuple<int, int> > list_of_instances;
        
        void rabin_karp(char* palabra, char* linea, int numero_linea){
            const int LENGTH_PALABRA = strlen(palabra);
            const int LENGTH_LINEA = strlen(linea);
            tuple<int,int> indexes;
            int hash_pow = 1;
            int hashed_palabra = 0;
            int hashed_window = 0; // window is the initial substring to be compared with word
            int slider = 0; // index where substring starts and possible index of match
            bool line_end = false;
            
            // gets the exponents of hash (to not compute later)
            for (int i = 0; i < LENGTH_PALABRA-1; i++){
                hash_pow = (hash_pow*BASE) % PRIME;
            }
            
            // hashes the word and line 
            for (int j = 0; j < LENGTH_PALABRA; j++){
                hashed_palabra = (hashed_palabra*BASE + palabra[j]) % PRIME;
                hashed_window = (hashed_window*BASE + linea[j]) % PRIME;
            }
            
            // searches for word and switches window 
            while (!line_end){
                if (hashed_palabra == hashed_window){
                    indexes = make_tuple(slider, numero_linea);
                    list_of_instances.push_back(indexes);
                    cout << "index: " << slider << " " << "line: " << numero_linea;
                }
                
                hashed_window = hashed_window - (linea[slider] * hash_pow);
                hashed_window = hashed_window * BASE;
                hashed_window = (hashed_window + linea[slider+LENGTH_PALABRA]) % PRIME;
                    
                if (hashed_window < 0) hashed_window = hashed_window + PRIME;
                
                slider++;

                if (slider > LENGTH_LINEA-LENGTH_PALABRA) line_end = true;
            } 

            
        }
        
        void rabin_karp_implementation(char* word, string file){
            char ch;
            int lineNumber = 0;
            string l;

            fstream fin(file, fstream::in);

            while (fin >> noskipws >> ch){
                l += ch;
                if (ch == '\n' ) {   // detects the end of the line
                    char* line;

                    line = (char *)alloca(l.size() + 1); // allocates memory on the stack and copies string to char*
                    memcpy(line, l.c_str(), l.size() + 1);

                    lineNumber++;
                    if (strlen(line) >= strlen(word)) rabin_karp(word, line, lineNumber);

                    l = "";
                }
            }
            fin.close();
        }
};

int main(){
    RabinKarpAlgo rk;

    // arguments for rabin_karp_implementation that reads files: word, file
    rk.rabin_karp_implementation("Pink","sample.txt");
    
    // arguments for rabin_karp: word, line, line_number
    // rk.rabin_karp("","",0);
    
    return 0;
}
