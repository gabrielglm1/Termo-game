#ifndef JOGADOR_H
#define JOGADOR_H  

#include <string>

using namespace std;

class Jogador{
    private:
        int _pontuacao;
        string _guess;
    public:
        Jogador(int pontuacao);

        string jogada();

        string get_guess();

};

#endif