#include "jogador.h"
#include <string>
#include <iostream>

using namespace std;

Jogador::Jogador(int pontuacao)
{
    _pontuacao = pontuacao;
}
string Jogador::jogada()
{

    string jogada;
    cin >> jogada;
    // cout << jogada << endl;

    return jogada;
}
string Jogador::get_guess()
{
    return _guess;
}

void Jogador::atualiza_pontuacao()
{
    _pontuacao += 1;
}

int Jogador::get_pontuacao()
{
    return _pontuacao;
}