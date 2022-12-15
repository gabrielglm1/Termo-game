#ifndef TABUELEIRO_H
#define TABUELEIRO_H  

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"

using namespace std;

class Tabuleiro{
    private: 
        int tentativas;
        vector<string> historico;
        
    public:

        Tabuleiro(int tentativas);

        void preenche(string guess);
        int get_tentativas();
        void imprime_atual();

        void imprime_tutorial();
};

#endif