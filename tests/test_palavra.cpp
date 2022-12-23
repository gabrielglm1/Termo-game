#include "doctest.h"
#include "palavra.h"

TEST_CASE("Testando funções da palavra"){


    Palavra palavra;

    CHECK(palavra.acertou("AMENO", "AMENO"));
    CHECK(palavra.verifica_palavra("AMENO"));
    CHECK_FALSE(palavra.acertou("AMENO", "TERMO"));
    CHECK_FALSE(palavra.acertou("CARNE", "TERMO"));
    CHECK_FALSE(palavra.acertou("PORTA", "AMENO"));
    CHECK(palavra.verifica_palavra("TURBA"));
    CHECK(palavra.verifica_palavra("BUGAR"));
    CHECK(palavra.verifica_palavra("SAIDO"));
    CHECK(palavra.verifica_palavra("PROSA"));
    CHECK(palavra.verifica_palavra("PAMPA"));
    CHECK(palavra.verifica_palavra("AVIDA"));
    CHECK(palavra.verifica_palavra("CISAO"));
    CHECK(palavra.verifica_palavra("DENSO"));
    CHECK(palavra.verifica_palavra("LEIGO"));

// Locais onde o usuário deve fornecer uma entrada tem o tratamento de exceções.

}
