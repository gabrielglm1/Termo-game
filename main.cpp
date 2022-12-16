#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "cores.h"

using namespace std;

int main(){

    int n_tentativas = 0;

    Jogador jogadorzinho(0);
    Tabuleiro tabuleirinho(6);

    Palavra palavrinha;
    string palavra_chaves = palavrinha.get_palavra();
    
    
    cout << palavra_chaves << endl;

    cout << palavrinha.get_palavra()<< endl;

    //implementar o menu principal


    //  char opcao; 
    //  cin >> opcao;
    
    // tabuleirinho.menu_principal();

    //  switch (opcao)
    //  {
    //  case '1':
    //     //tabuleirinho.imprime_tutorial();
    //     break;
    //  case '2':

    //  default:
    //      break;
    //  }


    while(1){
        

        
        string guess = jogadorzinho.jogada();
        
        if (!palavrinha.verifica_palavra(guess)){

            cout << "Palavra inválida" << endl;
            tabuleirinho.imprime_atual(palavra_chaves, n_tentativas);
            }
        else{
            tabuleirinho.preenche(guess, n_tentativas);
            
            tabuleirinho.imprime_atual(palavra_chaves, n_tentativas);
            // tabuleirinho.computa_tentativas();
        }
        
        //cout << "tentativas : " << n_tentativas << endl;
        n_tentativas = tabuleirinho.computa_tentativas(n_tentativas);

        if (palavrinha.acertou(guess, palavra_chaves) || n_tentativas == 6){
            cout << n_tentativas << endl;
            tabuleirinho.endgame();
            break;
        }
    }


    


return 0;
}