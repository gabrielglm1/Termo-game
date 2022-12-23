#ifndef TABUELEIRO_H
#define TABUELEIRO_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"

using namespace std;

/**
 * @brief Classe responsavel por tratar todas as informações
 * e interagir com o usuário. Armazena as jogadas em um vector
 * onde serão buscadas para realizar as demais operações. Imprime as dicas e acertos e avalia a condição de vitória.
 * @param tentativas Número de chutes que o jogador pode realizar, inicia como 6 na forma padrão. 
 */
class Tabuleiro
{
private:
    int tentativas;
    vector<string> historico;

public:
    /**
     * @brief Construtor padrão da classe.
     */
    Tabuleiro();
    /**
     * @brief Construtor da classe, recebe um número de tentativas.
     */
    Tabuleiro(int tentativas);
    /**
     * @brief Adiciona a palavra escrita pelo usuário a um container.
     * @param guess palavra que o usuário chutou.
     * @param tentativas_realizadas Nº de tentativas que já foram feitas.
     * @param tab Recebe 4 variáveis booleanas que indicam se o respectivo tabuleiro já foi acertado ou não.
     */
    void preenche(string guess, int tentativas_realizadas, bool tab1, bool tab2, bool tab3, bool tab4, int num_chutes);
    /**
     * @brief Inicializa o menu, onde o usuário pode escolher entre ler um tutorial ou iniciar o jogo.
     *
     */
    void menu_principal();
    /**
     * @brief Verifica a posição de cada letra da palavra que o usuário chutou e colore com as dicas.
     * @param palavras_chaves Vetor com as soluções do jogo.
     * @param modo Modo de jogo atual.
     * @param tentativas_realizadas Nº de tentativas que já foram feitas.
     *
     */
    void imprime_atual(vector <string> palavras_chaves, int tentativas_realizadas, int modo);
    
    /**
     * @brief Avalia se o jogador venceu ou perdeu, com base no modo de jogo, se for derrota, irá revelar as respostas. 
     * @param acertos É o número de palavras que o usuário acertou na partida atual.
     * @param palavras_chaves Vetor com as soluções do jogo.
     * @param modo É um número que indica qual o modo de jogo atual.
     * @param tentativas Número de palpites possíveis que depende do modo.
     * @param num_chutes Número de palpites já realizados.
     * @param tab Recebe os 4 tabuleiros.
     */
    bool endgame(int acertos, vector<string> palavras_chaves, int modo, int tentativas, int  num_chutes, bool tab1, bool tab2, bool tab3, bool tab4);
    /**
     * @brief Atualiza as tentativas realizadas.
     * @param n_tentativas Tentativas realizadas até o momento.
     *
     */
    int computa_tentativas(int n_tentativas);

    /**
     * @brief Imprime um pequeno tutorial do jogo.
     */
    void imprime_tutorial();

    /**
     * @brief Faz a seleção dentre os modos de jogo possíveis.
     */
    int selecionar_modo();

    /**
     * @brief Retorna true se o usuário deseja iniciar um novo jogo.
     */
    bool jogar_novamente();

    /**
     * @brief Converte textos para caixa alta.
     *
     */
    string caps_lock(std::string &str);
    /**
     * @brief Retorna o número de tentativas do tabuleiro atual.
     *
     */
    int get_tentativas();
};

#endif