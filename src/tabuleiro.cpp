#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "tabuleiro.h"
#include "palavra.h"
#include "cores.h"
#include <algorithm>
#include <vector>
#include "excecoes.h"
#include <exception>

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

Color::Modifier yellow(Color::FG_BRIGHT_YELLOW);
Color::Modifier green(Color::FG_BRIGHT_GREEN);
Color::Modifier red(Color::FG_BRIGHT_RED);
Color::Modifier def(Color::FG_DEFAULT);

using namespace std;

//Todas as palavras no jogo tem 6 letras.
int tamanho_palavra = 5;


Tabuleiro::Tabuleiro(){
    tentativas = 6;
}

Tabuleiro::Tabuleiro(int tentativas)
{
    this->tentativas = tentativas;

    for (int i = 0; i <= 4 * tentativas; i++)
    {
        historico.push_back("     ");
    }
}

void Tabuleiro::preenche(string guess, int tentativas_realizadas, bool tab1, bool tab2, bool tab3, bool tab4, int num_chutes)
{   
    //Essa lógica serve para implementarmos os 4 tabuleiros utilizando um só histórico. 
    for (int i = 0; i < 4; i++)
    {
        if ((!tab1 && (i == 0)) || (!tab2 && (i == 1)) || (!tab3 && (i == 2)) || (!tab4 && (i == 3)))
        {
            historico[(i * num_chutes) + tentativas_realizadas].replace(historico[(i * num_chutes) + tentativas_realizadas].begin(), historico[(i * num_chutes) + tentativas_realizadas].end(), guess);
        }
    }
}
//Essa função é o coração do jogo, ela avalia se para cada posição de letra do palpite ela está presente ou não e se está no lugar certo ou não,
// se estiver certo ela pinta de verde, se não de amarelo, e se nem estiver presente permanece branco. 
//São quatro loops pois cada tabuleiro é independente entre si, temos que separar para poder avaliar cada palavra. 

void Tabuleiro::imprime_atual(vector<string> palavras_chaves, int tentativas_realizadas, int modo)
{
    Palavra palavrinha;

    for (int i = 0; i < tentativas; i++)
    {

        for (int j = 0; j < tamanho_palavra; j++)
        {
            size_t found = palavras_chaves[0].find(historico[i].at(j));

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
        if (modo == 1)
        {
            cout << endl;
        }
        // Caso for dueto ou quarteto
        int tam = 6;
        if (modo > 1)
        {

            switch (modo)
            {
            case 2:
                tam = 7;
                break;
            case 3:
                tam = 9;
                break;
            default:
                break;
            }
            cout << "     ";

            for (int j = 0; j < tamanho_palavra; j++)
            {
                size_t found = palavras_chaves[1].find(historico[i + tam].at(j));

                if (palavras_chaves[1].at(j) == historico[i + tam].at(j))
                {
                    cout << green << UNDERLINE << historico[i + tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else if (found != string::npos)
                {
                    cout << yellow << UNDERLINE << historico[i + tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else
                {
                    cout << def << UNDERLINE << historico[i + tam].at(j) << CLOSEUNDERLINE << " ";
                }
            }
            if (modo == 2)
            {
                cout << endl;
            }
        }
        if (modo > 2)
        {
            cout << "     ";

            for (int j = 0; j < tamanho_palavra; j++)
            {
                size_t found = palavras_chaves[2].find(historico[i + 2 * tam].at(j));

                if (palavras_chaves[2].at(j) == historico[i + 2 * tam].at(j))
                {
                    cout << green << UNDERLINE << historico[i + 2 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else if (found != string::npos)
                {
                    cout << yellow << UNDERLINE << historico[i + 2 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else
                {
                    cout << def << UNDERLINE << historico[i + 2 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
            }
        }
        if (modo > 2)
        {
            cout << "     ";

            for (int j = 0; j < tamanho_palavra; j++)
            {
                size_t found = palavras_chaves[3].find(historico[i + 3 * tam].at(j));

                if (palavras_chaves[3].at(j) == historico[i + 3 * tam].at(j))
                {
                    cout << green << UNDERLINE << historico[i + 3 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else if (found != string::npos)
                {
                    cout << yellow << UNDERLINE << historico[i + 3 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
                else
                {
                    cout << def << UNDERLINE << historico[i + 3 * tam].at(j) << CLOSEUNDERLINE << " ";
                }
            }
            cout << endl;
        }
    }
    // Dar os espaços para uma nova "Tela". 
    cout << endl
         << endl
         << endl;
}

bool Tabuleiro::endgame(int acertos, vector<string> palavras_chaves, int modo, int tentativas, int num_chutes, bool tab1, bool tab2, bool tab3, bool tab4)
{
    if (((modo == 3 && acertos == 4)) || (((modo == 2) && (tab1 == true) && (tab2 == true) && (acertos == 2))) || ((modo == 1) && (tab1 == true)))
    {
        cout << "Você ganhou!" << endl;
        return true;
    }
    else if (tentativas == num_chutes)
    {
        switch (modo)
        {
        case 1:
            cout << "Game over! - A palavra correta era: " << green << palavras_chaves[0] << def << "." << endl;
            break;
        case 2:
            cout << "Game over! - As palavras corretam eram: " << green << palavras_chaves[0] << def << " e " << green << palavras_chaves[1] << "." << endl;
            break;

        case 3:
            cout << "Game over! - As palavras corretam eram: " << green << palavras_chaves[0] << def << ", " << green << palavras_chaves[1] << def << ", " << green << palavras_chaves[2] << def << " e " << green << palavras_chaves[1] << def << "." << endl;
            break;
        default:
            break;
        }
        return false;
    }
    else
        return false;
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

int Tabuleiro::selecionar_modo()
{

    int modo;

    cout << "Modos de jogo: " << endl;
    cout << "1. Termo   2. Dueto  3. Quarteto" << endl;
    cin >> modo;
    cout << "Modo selecionado: " << modo << endl;
    cout << "Iniciando jogo: " << endl;

    return modo;
}

bool Tabuleiro::jogar_novamente()
{
    string decisao;
    cout << "Deseja jogar novamente? (Y/N)" << endl;

  try
    {
        cin >> decisao;
        if(decisao.size() > 2){
            throw OpcaoInvalidaExcecao();
        }
    }
    catch (OpcaoInvalidaExcecao const& e)    {
        std::cerr << e.what() << endl;
    }
    
    if (decisao == "Y")
    {
        return true;
    }
    else
        return false;
}

int Tabuleiro::get_tentativas(){
    return tentativas;
}
