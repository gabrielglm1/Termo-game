#include "doctest.h"
#include "jogador.h"

TEST_CASE("Testando o construtor, função de atualizar e o get"){

    Jogador jogador;
    CHECK_EQ(jogador.get_pontuacao(), 0);

    jogador.atualiza_pontuacao(); 
    CHECK_EQ(jogador.get_pontuacao(), 1);

}