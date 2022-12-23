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
        //Aqui iniciamos um tabuleirinho auxiliar, e depois todas as variáveis que serão necessárias para o funcionamento do jogo, 
        //temos 4 tabuleiros um para cada palavra que por ventura venha a ser utilziada. Eles são setados como falsos pois inicialmente
        //não sabemos a palavra, mas assim que se acerta, eles viram true e então param de ser preenchidos. 
        //guardamos as palavras chave num vector, para ficar mais fácil de manusear. 
        
        Tabuleiro tabuleirinho;
        int tentativas_realizadas = 0, acertos = 0;
        Palavra palavra;
        vector<string> palavras_chaves = palavra.get_palavra();
        bool tab1 = false, tab2 = false, tab3 = false, tab4 = false;

        // Utilizado somente para debug: 
        // cout << "A palavra1 é: " << palavras_chaves[0] << endl;
        // cout << "A palavra2 é: " << palavras_chaves[1] << endl;
        // cout << "A palavra3 é: " << palavras_chaves[2] << endl;
        // cout << "A palavra4 é: " << palavras_chaves[3] << endl;

        tabuleirinho.menu_principal();


        //O modo por padrão é 1, mas a seguir temos um menu onde o usuário pode escolher qual deseja jogar. 
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
        //Agora criamos o verdadeiro tabuleiro onde será jogado, com o modo selecionado pelo usuário. 
        Tabuleiro tabuleiro(num_chutes);

        tabuleiro.imprime_atual(palavras_chaves, tentativas_realizadas, modo);
        cout << "Faça a primeira jogada: " << endl;

        while (1)
        {
            //O jogador faz uma jogada e a palavra verifica se é válida, caso não seja, o usuário tem a opção de adicionar ela ao banco 
            //de palavras e melhorar a experiência de jogo. 
            //Caso esteja presente, o tabuleiro irá executar a função preenche, que mostra as dicas para o usuário, de acordo com a cor.
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
            //Após preencher, as tentativas são computadas, e se as palavras forem acertadas, os acertos também, assim
            //a depender do modo escolhido o tabuleiro saberá se o usuário venceu ou não. Pedindo um novo palpite enquanto não tiver
            //ganho ou esgotado as tentativas. 
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
            //A função endgame faz todo o trabalho de verificar para cada modo se o jogador ganhou ou não. 
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
        //No fim, o jogador pode decidir se quer jogar de novo ou não. 
        if (!tabuleiro.jogar_novamente()){
            cout << "Placar final: " << jogador.get_pontuacao() << endl;
            break;
        }
    }
    return 0;
}