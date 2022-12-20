#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"

using namespace std;

int main(){

    while(1){
        
        Jogador jogador(0);
        Tabuleiro tabuleiro(6);
        int n_tentativas = 0;
        Palavra palavra;
        string palavra_chave = palavra.get_palavra();


        tabuleiro.menu_principal();

        char opcao; 
        cin >> opcao;
        int modo;
        
        switch (opcao){
                
        case '1':
            tabuleiro.imprime_tutorial();
        case '2':
         break;
     }
      modo = tabuleiro.selecionar_modo();
        tabuleiro.imprime_atual(palavra_chave, n_tentativas);
        cout << "Faça a primeira jogada " << endl;

        while(1){
        
        string guess = jogador.jogada();
        
        if (!palavra.verifica_palavra(guess)){

            tabuleiro.imprime_atual(palavra_chave, n_tentativas);
            cout << "Palavra inválida" << endl;
            }
        else{
            tabuleiro.preenche(guess, n_tentativas);
            tabuleiro.imprime_atual(palavra_chave, n_tentativas);
            n_tentativas = tabuleiro.computa_tentativas(n_tentativas);
            // tabuleiro.computa_tentativas();
        }
        
        cout << "Tentativas realizadas: " << n_tentativas << endl;
        //n_tentativas = tabuleiro.computa_tentativas(n_tentativas);

        bool win = palavra.acertou(guess, palavra_chave);
        bool game_over = (n_tentativas == 6);

        if(win){
            jogador.atualiza_pontuacao();
        }

        if (win || game_over){
            cout << "Placar: " << jogador.get_pontuacao() << endl;
            tabuleiro.endgame(win, game_over, palavra_chave);

            break;
        }

        }
        tabuleiro.jogar_novamente();
    }


return 0;
}