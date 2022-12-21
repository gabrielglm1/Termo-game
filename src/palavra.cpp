#include <fstream>
#include <string>
#include <iostream>
#include "palavra.h"
#include "tabuleiro.h"

using namespace std;

Palavra::Palavra(){}

vector<string> Palavra::get_palavra(){

srand(time(0));
auto random = rand() % 2935;
auto random2 = rand() % 2935;
auto random3 = rand() % 2935;
auto random4 = rand() % 2935;
int numOfLines = 0;


string palavra_chave, palavra_chave2, palavra_chave3, palavra_chave4;


ifstream file("dicionario.txt");
    string line;

while(getline(file, line))
    {
    ++numOfLines;
    if(numOfLines == random)
    {       
        palavras_chave.push_back(line);
        }
    if(numOfLines == random2)
    {       
        palavras_chave.push_back(line);
        }
    if(numOfLines == random3)
    {       
       palavras_chave.push_back(line);
    }
    if(numOfLines == random4)

    {   
        palavras_chave.push_back(line);
        }
    }
return palavras_chave;
}

bool Palavra::verifica_palavra(string word){

    Tabuleiro tabuleirinho(6);
        
    ifstream file2("dicionario.txt");
    string line2;
    bool poliglota = false;

    while(getline(file2, line2))
    {
        line2 = tabuleirinho.caps_lock(line2);
    if (!line2.empty() && line2[line2.length()-1] == '\n') {
        line2.erase(line2.length()-1);
    }
     
    if(line2 == word)
    {       
        poliglota = true;
        break;
    }
    else{
        poliglota = false;
        
    }

}
    return poliglota;   
}

bool Palavra::acertou(string guess, string palavra_chave){
    
    if (guess == palavra_chave){
        return true;
    }
    else
        return false;
}
    void Palavra::add_palavra(string ausente){

        std::cout << "Deseja adicionar essa palavra ao banco de palavras? (Y/N)" << endl;

        string option;
        std::cin >> option;
        
        if(option == "Y"){
    
            ofstream outfile;
            outfile.open("dicionario.txt", std::ios_base::app); // append instead of overwrite
            ausente += "\n";
            outfile << ausente ;
            cout << "Palavra adicionada com sucesso" << endl;

        }   

        std::cout << "-----------------------------------------------------------" << endl;

    }
    
