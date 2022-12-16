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
    string palavra_chave = palavrinha.get_palavra();
    palavra_chave = tabuleirinho.caps_lock(palavra_chave);
    
    cout << palavra_chave << endl;

    //cout << palavrinha.get_palavra()<< endl;

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

            tabuleirinho.imprime_atual(palavra_chave, n_tentativas);
            cout << "Palavra inválida" << endl;
            }
        else{
            tabuleirinho.preenche(guess, n_tentativas);
            tabuleirinho.imprime_atual(palavra_chave, n_tentativas);
            n_tentativas = tabuleirinho.computa_tentativas(n_tentativas);
            // tabuleirinho.computa_tentativas();
        }
        
        cout << "Tentativas realizadas: " << n_tentativas << endl;
        //n_tentativas = tabuleirinho.computa_tentativas(n_tentativas);

        bool win = palavrinha.acertou(guess, palavra_chave);
        bool game_over = (n_tentativas == 6);

        if (win || game_over){
            //cout << n_tentativas << endl;

            tabuleirinho.endgame(win, game_over, palavra_chave);
            break;
        }
    }


    


return 0;
}