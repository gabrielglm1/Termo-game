#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"

using namespace std;

int main(){

    int n_tentativas = 0;
    Jogador jogadorzinho(0);
    Tabuleiro tabuleirinho(6);

    Palavra palavrinha;
    string palavra_chaves = palavrinha.get_palavra();
    cout << palavra_chaves << endl;

    //cout << palavrinha.get_palavra()<< endl;

    

    while(1){

        string guess = jogadorzinho.jogada();
        if (!palavrinha.verifica_palavra(guess)){
            cout << "palavra invalida" << endl;
            tabuleirinho.imprime_atual();
            }
        else{
            tabuleirinho.preenche(guess);
            tabuleirinho.imprime_atual();
            // tabuleirinho.computa_tentativas();
        }
        
        if (palavrinha.acertou(guess, palavra_chaves) || tabuleirinho.computa_tentativas(n_tentativas)){

            tabuleirinho.endgame();
            break;
        }
    }


    


return 0;
}