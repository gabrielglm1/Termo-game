#ifndef PALAVRA_H
#define PALAVRA_H

#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include <vector>

using namespace std;
        /**
         * @brief Classe responsável pelos atributos de uma palavra
         * como por exemplo, verificar se ela existe no dicionário 
         * ou se o jogador acertou o seu palpite.
         * 
         */
class Palavra
{
private:
    string palavra;
    vector <string> palavras_chave;

public:
    Palavra();
        /**
         * @brief Retorna a palavra atual.
         */
    vector<string> get_palavra();
        /**
         * @brief Verifica se a palavra que o usuário digitou existe no dicionário do jogo.
         */
    bool verifica_palavra(string word);
        /**
         * @brief Verifica se a palavra adivinhada é igual a que o jogador digitou.
         * @param guess O palpite do jogador.
         * @param palavra_chave A qual deve ser adivinhada.
         */
    bool acertou(string guess, string palavra_chave);

        /**
         * @brief Adiciona uma palavra ao dicionário, caso o usuário deseje.
         * @param ausente Palavra não encontrada no dicionário.
        */
    void add_palavra(string ausente);
};

#endif