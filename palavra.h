#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"


using namespace std;

class Palavra{
    private:

    string palavrao;

    public:

    Palavra();

    string get_palavra();

    bool verifica_palavra(string word);
};