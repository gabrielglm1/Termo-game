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
        void preenche(string guess, int tentativas_realizadas);
        void menu_principal();
        int get_tentativas();
        void imprime_atual(string palavra_chave, int tentativas_realizadas);
        void endgame();
        int computa_tentativas(int n_tentativas);
        void dicas(string palavra_chave, string guess);
        void imprime_tutorial();
        void get_tentativa(); 
};

#endif