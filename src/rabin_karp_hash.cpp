#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <malloc.h>
#include <cstring>
#include <math.h>

using namespace std;

class RabinKarpAlgo{
    private:
        static const int PRIME = 331;
        static const int NUM_OF_ASCII_CHARS = 95;
        static const int NUM_TO_SUBSTRCT_TO_GET_WEIGHT = 31;
        
    public:
        static void rabin_karp( char* palabra, char* linea, int numero_linea){
            const int LENGTH_PALABRA = strlen(palabra);
            const int LENGTH_LINEA = strlen(linea);
            int hashed_palabra = 0;
            int hashed_window = 0; // window is the initial substring to be compared with word
            int left_slider = 0; // index where substring starts and possible index of match
            int right_slider = LENGTH_PALABRA-1; // index where substring ends
            bool line_end = false, match_found = false;
            
            int weight_char = 0;
            int weight_char_2 = 0;
            int power = 0;
            
            for (int i = 0; i < LENGTH_PALABRA; i++){
                weight_char = (int)palabra[i]-NUM_TO_SUBSTRCT_TO_GET_WEIGHT;
                hashed_palabra = hashed_palabra + weight_char * pow(NUM_OF_ASCII_CHARS, LENGTH_PALABRA-(i+1));

                weight_char = (int)linea[i]-NUM_TO_SUBSTRCT_TO_GET_WEIGHT;
                hashed_window = hashed_window + weight_char * pow(NUM_OF_ASCII_CHARS, LENGTH_PALABRA-(i+1));
            }
            hashed_palabra = hashed_palabra % PRIME;
            hashed_window = hashed_window % PRIME;

            cout << hashed_palabra << endl;
            cout << hashed_window << endl << endl;
            
            while(!line_end && !match_found){
                if(hashed_palabra == hashed_window){
                    match_found = true;
                    cout << endl << left_slider;
                }else{
                    left_slider++;
                    right_slider++;
                    weight_char = (int)linea[left_slider]-NUM_TO_SUBSTRCT_TO_GET_WEIGHT;
                    weight_char_2 = (int)linea[right_slider]-NUM_TO_SUBSTRCT_TO_GET_WEIGHT;
                    power =  pow(NUM_OF_ASCII_CHARS, LENGTH_PALABRA-1);
                    hashed_window = (hashed_window - (weight_char * power  % PRIME)) * NUM_OF_ASCII_CHARS + weight_char_2;
                    cout << hashed_window << endl;

                    if(right_slider == LENGTH_LINEA-1) line_end = true;
                }
            } 

            
        }
        
        static void find_word_matches(char* word, string file){
            char ch;
            int lineNumber = 0;
            string l;

            fstream fin(file, fstream::in);

            while(fin >> noskipws >> ch){
                l += ch;
                if(ch == '\n') {   // detects the end of the line
                    char* line;

                    line = (char *)alloca(l.size() + 1); // allocates memory on the stack and copies string to char*
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
    RabinKarpAlgo::rabin_karp("br","Cumbres",1);
    return 0;
}
