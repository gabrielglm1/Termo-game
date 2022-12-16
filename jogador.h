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
        Jogador(int pontuacao);
        /**
        * @brief Realiza um novo palpite.
        */
        string jogada();
        /**
        * @brief Retorna o palpite realizado.
        */
        string get_guess();
};

#endif