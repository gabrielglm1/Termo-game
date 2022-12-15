#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "tabuleiro.h"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"


using namespace std;
int tam = 5;

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

        // if (i < tentativas){

        
        for(int j = 0; j < tam; j++){
    cout << UNDERLINE << historico[i].at(j) << CLOSEUNDERLINE<< " ";
} 
    cout << endl;
}
    // else{
    // cout << UNDERLINE << "" << CLOSEUNDERLINE<< " ";
    // }
    
}



int Tabuleiro::get_tentativas(){}
void Tabuleiro::imprime_tutorial(){}
