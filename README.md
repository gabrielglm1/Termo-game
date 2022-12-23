# Termo-game

O objetivo desse projeto é desenvolver uma versão do jogo Termo,
ou "Wordle", em C++, como um projeto da disciplina de Programação
e Desenvolvimento de Software II.

Os contribuidores do projeto são:

Gabriel Mendonça <br>
Julliano Midore <br>
Lucas Vasconcelos <br>

<h4 align="center">
:construction: Projeto em construção :construction:
</h4>

<h4 align="center">
:construction: USER STORIES :construction:
</h4>

  1- como jogador do Termo quero que o jogo me dê dicas para eu poder acertar as palavras.
  Critério de aceitação: Quando o usuário digitar dica, ela deve aparecer. 
  
  2- Gostaria de que, como usuário do jogo, as palavras chave sempre sejam aleatorias, para que se torne mais desafiador e um padrão não seja encontrado.
  Critério de aceitação: As palavras selecionadas do dicionário devem ser selecionadas com base num número aleatorio entre zero e o número de linhas do dicionário. 
  
  3- Como jogador quero que tenha como selecionar o modo de jogo, para ter mais variedade de opções no jogo.
  Critério de aceitação: Ao iniciar o jogo, deve haver uma pergunta para o usuário e ele escreve qual dos modos deseja, relativo ao número de palavras para adivinhar.
  
  4- Como um usuário do termo, quero que eu tenha a opção de acionar uma palavra caso essa não exista no dicionario.
  Critério de aceitação: Deve haver uma opção para adicionar a palavra ao dicionario caso ele não a possua.
  
  5- como jogador do termo, quero que o jogo tenha um tutorial para que eu não fique perdido
  Critério de aceitação: Logo no início do jogo o usuário deve ser perguntado se deseja ler um tutorial do jogo, ele pode confirmar pressionando enter.
  
  6- como um jogador, quero que o jogo me forneça uma pontuação para poder compartilhar com meus amigos
  Critério de aceitação: Após acertar/errar o placar será atualizado e exibido na tela. 
  

<h4 align="center">
:construction: Detalhamento do Projeto :construction:
</h4>

Começamos o projeto conhecendo o jogo termo, que consiste de tentar acertar uma palavra com chutes e dicas como num jogo de forca. Para fazer isso, criamos as classe "palavra", classe "tabuleiro" , classe "jogador". 

Classe "palavra.h ": responsável por ler um arquivo .txt formado por linhas com uma palavra de cinco letras e manipula-lo a nossa escolha. A classe possue as seguintes funções:

vector <string> get_palavra(): Essa função retorna um vector, e é responsável por gerar 4 números aleatorios de 0 ao número de linhas do dicionário, escolher as 4 linhas correspondentes aos valores aleatorios e adiociona-las ao vector.

bool verifica_palavra(string word): Essa função recebe uma string "word" que é a palavra que o jogador insere e verifica se essa palavra está no dicionário, caso esteja retorna true, caso contrario false.

bool acertou(string guess, string palavra_chave): Essa função recebe uma string "guess" que é a palavra que o jogador insere e uma string "palavra_chave" que é a palavra chave do tabuleiro e verifica se essas palavra são iguais, caso sejam retorna true, caso contrario false.

void add_palavra(string ausente): Essa função recebe uma string "ausente" que é uma palavra que jogador inseriu e não existe no dicionário, a função adiciona a palavra ao dicionário caso o usuario queira.

Classe "jogador": Responsável por criar um jogador com uma pontuação e uma jogada. A classe possue as seguintes funções.
     
        string jogada(): retorna uma string que é gerada atravez de um cin.
      
        void atualiza_pontuacao(): soma 1 a um inteiro chamado pontuação.
       
        int get_pontuacao(); retorna a pontuação do jogador.


Classe "Tabuleiro": A principal classe do nosso jogo, responsável pela logica de dicas, escrita do tabuleiro e dos "chutes" do jogador. Essa classe possue o número de tentativas possiveis para o jogador e um vector de strings chamado historico, o qual armazena todos os chutes para que possam ser impressos na tela.


     
        string jogada(): retorna uma string que é gerada atravez de um cin.
      
        void atualiza_pontuacao(): soma 1 a um inteiro chamado pontuação.
       
        int get_pontuacao(); retorna a pontuação do jogador.

Tabuleiro();
    
    Tabuleiro(int tentativas){}
    
    void preenche(string guess, int tentativas_realizadas, bool tab1, bool tab2, bool tab3, bool tab4, int num_chutes);
    
    void menu_principal();
   
    void imprime_atual(vector <string> palavras_chaves, int tentativas_realizadas, int modo);
    
    
    bool endgame(int acertos, vector<string> palavras_chaves, int modo, int tentativas, int  num_chutes, bool tab1, bool tab2, bool tab3, bool tab4);
    
    int computa_tentativas(int n_tentativas);

    void imprime_tutorial();

    int selecionar_modo();

    bool jogar_novamente();

    int get_tentativas();