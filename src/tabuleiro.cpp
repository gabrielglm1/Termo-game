#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "tabuleiro.h"
#include "palavra.h"
#include "cores.h"
#include <algorithm> 


#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

Color::Modifier yellow(Color::FG_BRIGHT_YELLOW);
Color::Modifier green(Color::FG_BRIGHT_GREEN);
Color::Modifier red(Color::FG_BRIGHT_RED);
Color::Modifier def(Color::FG_DEFAULT);

using namespace std;

int tam = 5;

string Tabuleiro::caps_lock(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

Tabuleiro::Tabuleiro(int tentativas)
{
    this->tentativas = tentativas;

    for (int i = 0; i <= tentativas; i++)
    {
        historico.push_back("     ");
    }
}

void Tabuleiro::preenche(string guess, int tentativas_realizadas)
{   
    guess = caps_lock(guess);

   // historico.insert(historico.begin(), guess);
    historico.insert(historico.begin() + tentativas_realizadas, guess);
    historico.erase(historico.end());
}

void Tabuleiro::imprime_atual(string palavra_chave, int tentativas_realizadas)
{   
    for (int i = 0; i < tentativas; i++)
    {
        for (int j = 0; j < tam; j++)
        {
         size_t found = palavra_chave.find(historico[i].at(j));

        //checa se tá na pos correta


            if (palavra_chave.at(j) == historico[i].at(j))
            {
                
                cout << green << UNDERLINE << historico[i].at(j) << CLOSEUNDERLINE << " ";
            }
                else if (found != string::npos)
            {
                cout << yellow << UNDERLINE << historico[i].at(j) << CLOSEUNDERLINE << " ";
            }
            else 
            {
                cout << def << UNDERLINE << historico[i].at(j) << CLOSEUNDERLINE << " ";
            }

        
        }
        cout << endl;
    }
    
    cout << endl
         << endl
         << endl;
}

void Tabuleiro::endgame(bool ganhou, string palavra_chave)
{
    if(ganhou){
    cout << "Você acertou!" << endl;
    
    }
    else
    cout << "Game over! - A palavra correta era: " << green << palavra_chave << def << endl;

}

int Tabuleiro::computa_tentativas(int tentativas)
{   
    tentativas = tentativas + 1;
    return tentativas;
}

void Tabuleiro::imprime_tutorial()
{

    cout << def << "Ao iniciar o jogo, uma palavra aleatória será gerada. ";
    cout << "Seu objetivo é acertar ela antes que suas tentativas ";
    cout << "se esgotem. Para isso, o jogo irá fornecer dicas. " << endl;
    cout << "A cor de uma letra é uma dica que significa: ";
    cout << green << "VERDE" << def << ", se a letra está presente na palavra e também ";
    cout << "está na posição correta. " << yellow << "AMARELA" << def << ", se a letra está presente" << endl;
    cout << "na palavra mas na posição errada, e BRANCA ";
    cout << "se não está presente." << endl;
    cout << "Agora selecione um modo de jogo para começar." << endl;
    cout << "-----------------------------------------------------------" << endl;


}



void Tabuleiro::menu_principal()
{   
    cout << def << "-----------------------------------------------------------" << endl;
    cout << "Menu principal" << endl;
    cout << "Selecione uma opção: " << endl;
    cout << "1. Ver tutorial" << endl;
    cout << "2. Selecionar modo e iniciar jogo" << endl;
    cout << "-----------------------------------------------------------" << endl;

}

int Tabuleiro::selecionar_modo(){
    
    int modo;

    cout << "Modos de jogo: " << endl;
    cout << "1. Termo   2. Dueto  3. Quarteto" << endl;
    cin >> modo;
    cout << "Modo selecionado: " << modo << endl;
    cout << "Iniciando jogo: " << endl;

    
    return modo;
}

bool Tabuleiro::jogar_novamente(){
    char decisao;
    cout << "Deseja jogar novamente? (Y/N)" << endl; 
    cin >> decisao;

    if(decisao == 'Y'){
        return true;
    }
    else
        return false;
}

