#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"

using namespace std;

int main(){
    
    Jogador jogadorzinho(0);
    Tabuleiro tabuleirinho(6);

    Palavra palavrinha;

    //cout << palavrinha.get_palavra()<< endl;

    string palavreta = jogadorzinho.jogada();

    if (palavrinha.verifica_palavra(palavreta)){
        //cout << "OK";
        tabuleirinho.preenche(palavreta);
        tabuleirinho.imprime_atual();


    }


return 0;
}