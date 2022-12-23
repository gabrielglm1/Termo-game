#include "jogador.h"
#include <string>
#include <iostream>
#include "excecoes.h"

using namespace std;
Jogador::Jogador()
{
    _pontuacao = 0;
}

string Jogador::jogada()
{

    string jogada;


    cin >> jogada;
    if(jogada.size() > 5){
        throw EntradaInvalidaExcecao();
    }
    
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