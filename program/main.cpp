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
        
        Tabuleiro tabuleirinho(6);
        int n_tentativas = 0, acertos = 0;
        Palavra palavra;
        vector <string> palavras_chaves = palavra.get_palavra();
        bool tab1 = false, tab2 = false, tab3 = false, tab4 = false;
        

        cout << "A palavra1 é: " << palavras_chaves[0] <<endl;
        cout << "A palavra2 é: " << palavras_chaves[1] <<endl;
        cout << "A palavra3 é: " << palavras_chaves[2] <<endl;
        cout << "A palavra4 é: " << palavras_chaves[3] <<endl;

        tabuleirinho.menu_principal();

        char opcao; 
        cin >> opcao;

        int modo;
        
        switch (opcao){
                
        case '1':
            tabuleirinho.imprime_tutorial();
        case '2':

         break;
     }
        
        modo = tabuleirinho.selecionar_modo();
        int num_chutes = 6;
        switch (modo)
        {
        case 2:
            num_chutes = 7;
            break;
        case 3:
            num_chutes = 9;
            break;
        
        default:
            break;
        }
        Tabuleiro tabuleiro(num_chutes);

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
            tabuleiro.preenche(guess, n_tentativas, tab1, tab2, tab3, tab4, num_chutes);
            tabuleiro.imprime_atual(palavras_chaves, n_tentativas, modo);
            n_tentativas = tabuleiro.computa_tentativas(n_tentativas);

        }
        

        cout << "Tentativas realizadas: " << n_tentativas << endl;

    for (int i = 0; i < 4; i++){
            if (palavra.acertou(guess, palavras_chaves[i]) && (n_tentativas <= num_chutes)){
                acertos+=1; 
                if (i == 0){
                    tab1 = true;
                }  
                if (i == 1){
                    tab2 = true;
                }  
                if (i == 2){
                    tab3 = true;
                }  
                if (i == 3){
                    tab4 = true;
                }  
        }
        }
        if (tabuleiro.endgame(acertos, palavras_chaves, modo, n_tentativas, num_chutes)){
            jogador.atualiza_pontuacao();
            cout << "Placar: " << jogador.get_pontuacao() << endl;
            break;
        }

        if (n_tentativas == 6){
        cout << "Placar: " << jogador.get_pontuacao() << endl;
        break;
        }

        cout << "Faça uma nova tentativa: " << endl;
        }

        if(!tabuleiro.jogar_novamente()){
            cout << "Placar final: " << jogador.get_pontuacao() << endl;
            break;
        }
        
        
    }


return 0;
}