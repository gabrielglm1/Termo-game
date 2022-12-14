#include <fstream>
#include <string>
#include <iostream>
#include "jogador.h"
#include "palavra.h"

using namespace std;

int main(){
    
    Jogador jogadorzinho(0);
   

    Palavra palavrinha;

    //cout << palavrinha.get_palavra()<< endl;

    string palavreta = jogadorzinho.jogada();
    if (palavrinha.verifica_palavra(palavreta)){
        cout << "OK";
    }


return 0;
}