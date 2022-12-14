#include "doctest.h"
#include "tabuleiro.h"


TEST_CASE("Testando o construtor"){

    Tabuleiro Tabuleiro_Teste = Tabuleiro();
    CHECK(Tabuleiro_Teste.get_tentativas() == 6);

    Tabuleiro Tabuleiro_Teste2 = Tabuleiro(10);
    CHECK(Tabuleiro_Teste2.get_tentativas() == 10);

    CHECK_THROWS(Tabuleiro(-3));
}

TEST_CASE("Testando a função computa_tentativas"){

    Tabuleiro Tabuleiro_Teste4 = Tabuleiro();
    CHECK(Tabuleiro_Teste4.computa_tentativas(6) == 7);

    Tabuleiro Tabuleiro_Teste5 = Tabuleiro(9);
    CHECK_FALSE(Tabuleiro_Teste5.computa_tentativas(-3));

    Tabuleiro Tabuleiro_Teste6 = Tabuleiro();
    CHECK_FALSE(Tabuleiro_Teste6.computa_tentativas(2) == 1);

}
