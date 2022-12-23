#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "cores.h"
#include <vector>
#define TERMO 6
#define DUETO 7
#define QUARTETO 9

Color::Modifier verm(Color::FG_BRIGHT_RED);

using namespace std;

int main(){

    cout << "Bem-vindo ao" << verm << " Termo" << endl;

    Jogador jogador;

    while (1)
    {

        Tabuleiro tabuleirinho;
        int tentativas_realizadas = 0, acertos = 0;
        Palavra palavra;
        vector<string> palavras_chaves = palavra.get_palavra();
        bool tab1 = false, tab2 = false, tab3 = false, tab4 = false;

        cout << "A palavra1 é: " << palavras_chaves[0] << endl;
        cout << "A palavra2 é: " << palavras_chaves[1] << endl;
        cout << "A palavra3 é: " << palavras_chaves[2] << endl;
        cout << "A palavra4 é: " << palavras_chaves[3] << endl;

        tabuleirinho.menu_principal();

        char opcao;
        int modo = 1; 
        cin >> opcao;

        switch (opcao)
        {
        case '1':
            tabuleirinho.imprime_tutorial();
        case '2':
            modo = tabuleirinho.selecionar_modo();
            break;
        default:
            break;
        }

        int num_chutes = TERMO;
        switch (modo)
        {
        case 2:
            num_chutes = DUETO;
            break;
        case 3:
            num_chutes = QUARTETO;
            break;
        default:
            break;
        }

        Tabuleiro tabuleiro(num_chutes);

        tabuleiro.imprime_atual(palavras_chaves, tentativas_realizadas, modo);
        cout << "Faça a primeira jogada: " << endl;

        while (1)
        {

            string guess = jogador.jogada();

            if (!palavra.verifica_palavra(guess))
            {

                tabuleiro.imprime_atual(palavras_chaves, tentativas_realizadas, modo);
                cout << "Palavra inválida" << endl;
                palavra.add_palavra(guess);
            }
            else
            {
                tabuleiro.preenche(guess, tentativas_realizadas, tab1, tab2, tab3, tab4, num_chutes);
                tabuleiro.imprime_atual(palavras_chaves, tentativas_realizadas, modo);
                tentativas_realizadas = tabuleiro.computa_tentativas(tentativas_realizadas);
            }

            cout << "Tentativas realizadas: " << tentativas_realizadas << endl;

            for (int i = 0; i < 4; i++)
            {
                if (palavra.acertou(guess, palavras_chaves[i]) && (tentativas_realizadas <= num_chutes))
                {   
                    acertos += 1;
                    switch (i)
                    {
                    case 0:
                        tab1 = true;
                        break;
                    case 1:
                        tab2 = true;
                        break;
                    case 2:
                        tab3 = true;
                        break;
                    case 3:
                        tab4 = true;
                    default:
                        break;
                    }
                }
            }
            
            if (tabuleiro.endgame(acertos, palavras_chaves, modo, tentativas_realizadas, num_chutes, tab1, tab2, tab3, tab4))
            {
                jogador.atualiza_pontuacao();
                cout << "Placar: " << jogador.get_pontuacao() << endl;
                break;
            }

            if (tentativas_realizadas == num_chutes){
                cout << "Placar: " << jogador.get_pontuacao() << endl;
                break;
            }

            cout << "Faça uma nova tentativa: " << endl;
        }

        if (!tabuleiro.jogar_novamente()){
            cout << "Placar final: " << jogador.get_pontuacao() << endl;
            break;
        }
    }
    return 0;
}