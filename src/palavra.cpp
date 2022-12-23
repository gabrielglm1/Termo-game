#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "palavra.h"
#include "tabuleiro.h"
#include "excecoes.h"
#include <exception>

using namespace std;

Palavra::Palavra() {}

int TAM_DICIONARIO = 1000; 

vector<string> Palavra::get_palavra()
{
        int random1, random2, random3, random4;

    srand(time(0));

        while(1){
            random1 = rand() % TAM_DICIONARIO;
            random2 = rand() % TAM_DICIONARIO;
            random3 = rand() % TAM_DICIONARIO;
            random4 = rand() % TAM_DICIONARIO;

            if((random1 != random2 && random3 && random4) && (random2 != random3 && random4) && (random3 != random4)){
                break;
        } 
        }
        
    int num_linhas = 0;
    ifstream file("dicionario.txt");
    string line;

    string palavra_chave, palavra_chave2, palavra_chave3, palavra_chave4;
while(getline(file, line))
    {
    ++num_linhas;
    if(num_linhas == random1)
    {
        palavras_chave.push_back(line);
        }
    if(num_linhas == random2)
    {
        palavras_chave.push_back(line);
        }
    if(num_linhas == random3)
    {
       palavras_chave.push_back(line);
    }
    if(num_linhas == random4)

    {
        palavras_chave.push_back(line);
        }
    }
    return palavras_chave;
}

bool Palavra::verifica_palavra(string guess)
{
    ifstream file2("dicionario.txt");
    string line2;
    bool achou = false;

    while (getline(file2, line2))
    {
        if (!line2.empty() && line2[line2.length() - 1] == '\n')
        {
            line2.erase(line2.length() - 1);
        }

        if (line2 == guess)
        {
            achou = true;
            break;
        }
        else
        {
            achou = false;
        }
    }
    return achou;
}

bool Palavra::acertou(string guess, string palavra_chave)
{
    if (guess == palavra_chave){
        return true;

    } else return false;
}
void Palavra::add_palavra(string ausente)
{

    std::cout << "Deseja adicionar essa palavra ao banco de palavras? (Y/N)" << endl;

    string option;

    try
    {
        cin >> option;
    }
    catch (std::out_of_range const&)    {
        throw EntradaInvalidaExcecao();
    }
    
    
    if (option == "Y")
    {
        ofstream outfile;
        outfile.open("dicionario.txt", std::ios_base::app);
        ausente += "\n";
        outfile << ausente;
        cout << "Palavra adicionada com sucesso" << endl;
        //aumenta o tamanho do dicionário, pois quando for jogar novamente, haverá chances da nova palavra ser incluída no sorteio. 
        TAM_DICIONARIO++;
    }

    std::cout << "-----------------------------------------------------------" << endl;
}