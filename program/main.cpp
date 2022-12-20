#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "cores.h"

Color::Modifier verm(Color::FG_BRIGHT_RED);

using namespace std;


int main(){
    
    cout << "Bem-vindo ao" << verm << " Termo" << endl;

    Jogador jogador(0);
    
    while(1){
        
        Tabuleiro tabuleiro(6);
        int n_tentativas = 0;
        Palavra palavra;
        string palavra_chave = palavra.get_palavra();

        cout << "A palavra é: " << palavra_chave <<endl;

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
            palavra.add_palavra(guess);  
        }
        else{
            tabuleiro.preenche(guess, n_tentativas);
            tabuleiro.imprime_atual(palavra_chave, n_tentativas);
            n_tentativas = tabuleiro.computa_tentativas(n_tentativas);
        }
        
        cout << "Tentativas realizadas: " << n_tentativas << endl;
        cout << "Faça uma nova tentativa: " << endl;

        if (palavra.acertou(guess, palavra_chave) && (n_tentativas < 6)){
            cout << "Pontuação antes: " << jogador.get_pontuacao() << endl;
            jogador.atualiza_pontuacao();
            cout << "Placar: " << jogador.get_pontuacao() << endl;

            tabuleiro.endgame(true, palavra_chave);
            break;
            
        }   else if (n_tentativas == 6){
                tabuleiro.endgame(false, palavra_chave);
                cout << "Placar: " << jogador.get_pontuacao() << endl;
                break;
        }

        }

        if(!tabuleiro.jogar_novamente()){
            cout << "Placar final: " << jogador.get_pontuacao() << endl;
            break;
        }
        
        
    }


return 0;
}