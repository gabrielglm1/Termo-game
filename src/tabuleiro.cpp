#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "tabuleiro.h"
#include "palavra.h"
#include "cores.h"
#include <algorithm> 
#include <vector>


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

    for (int i = 0; i <= 4*tentativas; i++)
    {
        historico.push_back("     ");
    }
}

void Tabuleiro::preenche(string guess, int tentativas_realizadas, bool tab1, bool tab2, bool tab3, bool tab4)
{   
    guess = caps_lock(guess);

   // historico.insert(historico.begin(), guess);
    for (int i = 0; i < 4; i++){
    if ((!tab1 && (i == 0)) || (!tab2 && (i == 1)) || (!tab3 && (i == 2)) || (!tab4 && (i == 3))){
    //historico.insert(historico.begin() + (6*i) + tentativas_realizadas, guess);
    historico[(i*6)+tentativas_realizadas].replace(historico[(i*6)+tentativas_realizadas].begin(),historico[(i*6)+tentativas_realizadas].end(),guess);
    }
    //historico.erase(historico.end());   
    }

}

void Tabuleiro::imprime_atual(vector <string> palavras_chaves, int tentativas_realizadas, int modo)
{   Palavra palavrinha;

    for (int i = 0; i < tentativas; i++)
    {
        
        for (int j = 0; j < tam; j++)
        {
         size_t found = palavras_chaves[0].find(historico[i].at(j));

        //checa se tá na pos correta


            if (palavras_chaves[0].at(j) == historico[i].at(j))
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
        if (modo == 1 ){
                cout << endl;
            }
        // Caso for dueto ou quarteto

        if(modo > 1){
        cout << "     " ;

         for (int j = 0; j < tam; j++)
        {
         size_t found = palavras_chaves[1].find(historico[i+6].at(j));

        //checa se tá na pos correta

        
            if (palavras_chaves[1].at(j) == historico[i+6].at(j))
            {
                
                cout << green << UNDERLINE << historico[i+6].at(j) << CLOSEUNDERLINE << " ";
            }
                else if (found != string::npos)
            {
                cout << yellow << UNDERLINE << historico[i+6].at(j) << CLOSEUNDERLINE << " ";
            }
            else 
            {
                cout << def << UNDERLINE << historico[i+6].at(j) << CLOSEUNDERLINE << " ";
            }

        
        }
    if (modo == 2 ){
                cout << endl;
            }
    }
    if(modo > 2){
        cout << "     " ;
  
         for (int j = 0; j < tam; j++)
        {
         size_t found = palavras_chaves[2].find(historico[i+12].at(j));

        //checa se tá na pos correta

        
            if (palavras_chaves[2].at(j) == historico[i+12].at(j))
            {
                
                cout << green << UNDERLINE << historico[i+12].at(j) << CLOSEUNDERLINE << " ";
            }
                else if (found != string::npos)
            {
                cout << yellow << UNDERLINE << historico[i+12].at(j) << CLOSEUNDERLINE << " ";
            }
            else 
            {
                cout << def << UNDERLINE << historico[i+12].at(j) << CLOSEUNDERLINE << " ";
            }

        
        }

    }
    if(modo > 2){
        cout << "     " ;
 
         for (int j = 0; j < tam; j++)
        {
         size_t found = palavras_chaves[3].find(historico[i+18].at(j));

        //checa se tá na pos correta

        
            if (palavras_chaves[3].at(j) == historico[i+18].at(j))
            {
                
                cout << green << UNDERLINE << historico[i+18].at(j) << CLOSEUNDERLINE << " ";
            }
                else if (found != string::npos)
            {
                cout << yellow << UNDERLINE << historico[i+18].at(j) << CLOSEUNDERLINE << " ";
            }
            else 
            {
                cout << def << UNDERLINE << historico[i+18].at(j) << CLOSEUNDERLINE << " ";
            }

        
        }
        cout << endl;
    }
    }
    
    cout << endl
         << endl
         << endl;
}

bool Tabuleiro::endgame(int acertos, vector<string> palavras_chaves, int modo, int tentativas)
{
    if((modo == 3 && acertos == 4) || (modo == 2 && acertos == 2) || (modo == 1 && acertos == 1)){
    cout << "Você ganhou!" << endl;
    return true;
    }
    else if (tentativas ==  6){
        switch (modo)
        {
        case 1:
            cout << "Game over! - A palavra correta era: " << green << palavras_chaves[0] << def << "." << endl;
            break;
        case 2:
            cout << "Game over! - As palavras corretam eram: " << green << palavras_chaves[0] << def << " e " << green << palavras_chaves[1] << "."<< endl;
            break;

        case 3:
            cout << "Game over! - As palavras corretam eram: " << green << palavras_chaves[0] << def << ", " << green << palavras_chaves[1] << def << ", " << green << palavras_chaves[2] << def << " e " << green << palavras_chaves[1] << def << "." <<endl;
            break;
        default:
            break;
        }
    return false;
    } else return false;
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

