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
 * onde serão buscadas para realizar as demais operações.
 */
class Tabuleiro
{
private:
    int tentativas;
    vector<string> historico;

public:
    /**
     * @brief Construtor da classe, recebe um número de tentativas.
     */
    Tabuleiro(int tentativas);
    /**
     * @brief Adiciona a palavra escrita pelo usuário a um container.
     * @param guess palavra que o usuário chutou.
     * @param tentativas_realizadas Nº de tentativas que já foram feitas.
     *
     */
    void preenche(string guess, int tentativas_realizadas);
    /**
     * @brief Inicializa o menu.
     *
     */
    void menu_principal();
    /**
     * @brief Verifica a posição de cada letra da palavra que o usuário chutou e colore com as dicas.
     * @param palavra_chave Palavra a ser descoberta.
     * @param tentativas_realizadas Nº de tentativas que já foram feitas.
     *
     */
    void imprime_atual(string palavra_chave, int tentativas_realizadas);
    /**
     * @brief Converte textos para caixa alta.
     *
     */
    string caps_lock(std::string &str);
    /**
     * @brief Avalia se o jogador venceu ou perdeu.
     * @param win_condition Se a palavra foi adivinhada corretamente.
     * @param game_over Se as tentativas se esgotaram.
     * @param palavra_chave Se o usuário perdeu, informa qual era a resposta.
     *
     */
    void endgame(bool win_condiditon, string palavra_chave);
    /**
     * @brief Atualiza as tentativas realizadas.
     * @param n_tentativas Tentativas realizadas até o momento.
     *
     */
    int computa_tentativas(int n_tentativas);

    // void dicas(string palavra_chave, string guess);

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

    void limpa_tabuleiro();
    
};

#endif