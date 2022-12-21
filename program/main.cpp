#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "cores.h"
#include <vector>

Color::Modifier verm(Color::FG_BRIGHT_RED);

using namespace std;


int main(){
    
    cout << "Bem-vindo ao" << verm << " Termo" << endl;

    Jogador jogador(0);
    
    while(1){
        
        Tabuleiro tabuleiro(6);
        int n_tentativas = 0;
        Palavra palavra;
        vector <string> palavras_chaves = palavra.get_palavra();
        

        cout << "A palavra1 é: " << palavras_chaves[0] <<endl;
        cout << "A palavra2 é: " << palavras_chaves[1] <<endl;
        cout << "A palavra3 é: " << palavras_chaves[2] <<endl;
        cout << "A palavra4 é: " << palavras_chaves[3] <<endl;

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

        tabuleiro.imprime_atual(palavras_chaves, n_tentativas, modo);
        cout << "Faça a primeira jogada " << endl;

        while(1){
        
        string guess = jogador.jogada();


        if (!palavra.verifica_palavra(guess)){

            tabuleiro.imprime_atual(palavras_chaves, n_tentativas, modo);
            cout << "Palavra inválida" << endl;
            palavra.add_palavra(guess);  
        }
        else{
            tabuleiro.preenche(guess, n_tentativas);
            tabuleiro.imprime_atual(palavras_chaves, n_tentativas, modo);
            n_tentativas = tabuleiro.computa_tentativas(n_tentativas);
        }
        
        cout << "Tentativas realizadas: " << n_tentativas << endl;
        cout << "Faça uma nova tentativa: " << endl;

        if (palavra.acertou(guess, palavras_chaves[0]) && (n_tentativas < 6)){
            cout << "Pontuação antes: " << jogador.get_pontuacao() << endl;
            jogador.atualiza_pontuacao();
            cout << "Placar: " << jogador.get_pontuacao() << endl;

            tabuleiro.endgame(true, palavras_chaves[0]);
            break;
            
        }   else if (n_tentativas == 6){
                tabuleiro.endgame(false, palavras_chaves[0]);
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