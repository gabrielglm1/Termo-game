
#ifndef JOGADOR_H
#define JOGADOR_H  

#include <string>

using namespace std;
    /**
     * @brief Classe responsável pelos atributos do usuário, que é realizar uma jogada e ter um nº de pontos.
    */
class Jogador{
    private:
        int _pontuacao;
        string _guess;

    public:
        /**
        * @brief Construtor da classe.
        */
        Jogador();
        /**
        * @brief Realiza um novo palpite.
        */
        string jogada();
        /**
        * @brief Aumenta a pontuação do jogador em um quando ele acerta.
        */
        void atualiza_pontuacao();
        /**
        * @brief Retorna o placar atual do jogador.
        */
        int get_pontuacao();
};

#endif