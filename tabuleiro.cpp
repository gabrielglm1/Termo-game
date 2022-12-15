#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "tabuleiro.h"
#include "palavra.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"


using namespace std;
int tam = 5;
int n_tentativas = 0;

Tabuleiro::Tabuleiro(int tentativas){
    this->tentativas = tentativas;

    for (int i = 0; i <= tentativas; i++){
        historico.push_back("     ");
    }
}

void Tabuleiro::preenche(string guess){

    historico.push_back(guess);
    historico.erase(historico.begin());
}

void Tabuleiro::imprime_atual(){
    for (int i = tentativas; i > 0; i--){
        for(int j = 0; j < tam; j++){
    cout << UNDERLINE << historico[i].at(j) << CLOSEUNDERLINE<< " ";
} 
    cout << endl;
}
   
cout << endl << endl << endl;
}

void Tabuleiro::endgame(){
   
    cout << "acabou o jogo" << endl;
}

bool Tabuleiro::computa_tentativas(int n_tentativas){
    n_tentativas += 1;
    if(n_tentativas == 6){
        return true;
    }
    else{
        return false;
    }
}

