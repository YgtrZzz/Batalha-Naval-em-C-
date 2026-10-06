#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
void limpatela (){

system ("CLS");

}

void iniciatabuleiro(  char tabuleiro [10][10], char mascara[10][10] ){

    int linha, coluna;

for (linha=0;linha<10;linha++){

    for(coluna=0;coluna<10;coluna++){

     tabuleiro[linha][coluna]='A';
     mascara[linha][coluna]='*';


           }


     }
}
void menuincial();


void exibemapa(){

        int cont;

 for (cont=0;cont<10;cont++){
if (cont==0){

    cout <<"     ";


}
    cout<< cont <<" ";

 }
 cout <<"\n";

         for (cont=0;cont<10;cont++){
        if (cont==0){

        cout <<"     ";


    }
        cout<<"| ";


    }

 cout <<"\n";




}

void exibetabuleiro(  char tabuleiro [10][10], char mascara[10][10], bool mostragabarito){

char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };



int linha,coluna;

for (linha=0;linha<10;linha++){
cout <<linha<<" - ";
    for(coluna=0;coluna<10;coluna++){


            switch(mascara[linha][coluna] ){

        case 'A':
      cout<<blue<< " " <<mascara[linha][coluna]<< normal;
            break;

        case 'P':
             cout<<green<< " " <<mascara[linha][coluna]<< normal;


            break;

        default:

            cout<< " " <<mascara[linha][coluna];


            break;


            }


       }

            cout<<"\n";

   }

    if (mostragabarito==false){



        for (linha=0;linha<10;linha++){
        cout <<linha<<" - ";
            for(coluna=0;coluna<10;coluna++){


                   cout<< " " <<tabuleiro[linha][coluna];
                    }

                cout<<"\n";

               }




       }





}


void posicionabarcos(char tabuleiro [10][10]){

int linhabarco, colunabarco, quantidadeposicionada=0, cont, quantidade=10;

//verifica se ja posicionou os barcos
while(quantidadeposicionada<quantidade){


     linhabarco= rand()%10;
    colunabarco=rand()%10;

    if (tabuleiro[linhabarco][colunabarco]=='A'){

           tabuleiro[linhabarco][colunabarco]='P';

            quantidadeposicionada++;


        }



 }



}


void verificatiro(char tabuleiro[10][10], int linhajogada, int colunajogada, int *pontos, string *mensagem){

         switch(tabuleiro[linhajogada][colunajogada]){

 case 'P':

        *pontos=*pontos+10;
        *mensagem="Voce acertou um barco pequeno!";

    break;

 case 'A':

    *mensagem="Voce acertou a Agua!";

    break;

       }

}




void jogo (string nomedojogador){
///variaveis gerais
    char tabuleiro [10][10], mascara [10][10];

int linha, coluna,linhajogada,colunajogada;
int estadodejogo=1;
int pontos=0;
int tenativas=0, maxdetentativas=20;
int opcaofim;
string mensagem= "Bem vindo ao jogo";



         //jogo=jogoacontecendo; jogo=0 sem jogo
iniciatabuleiro(tabuleiro,mascara);

//posiciona barcos aleatoriamente

posicionabarcos(tabuleiro);

while (tenativas<maxdetentativas){


        limpatela();
        exibemapa();

exibetabuleiro(tabuleiro, mascara, true);

cout<<"\nPontos: "<<pontos <<"   Tentativas Restantes: "<<maxdetentativas-tenativas;

cout<<"\n"<< mensagem;

linhajogada=-1;

colunajogada=-1;

while((linhajogada<0 || colunajogada<0) ||   (linhajogada >9 || colunajogada>9) ){


    cout<<"\n"<<nomedojogador<< ", Digite uma Linha: ";
    cin>>linhajogada;
    cout<<"\nDigite uma coluna: ";
     cin>>colunajogada;
}
     verificatiro(tabuleiro, linhajogada, colunajogada, &pontos, &mensagem );





mascara[linhajogada][colunajogada]= tabuleiro[linhajogada][colunajogada];


        tenativas++;

     }

     limpatela();


     cout<<"Fim de Jogo!!  o que deseja fazer??\n";
     cout<<"\n1-Jogar Novamente";
     cout<<"\n2- ir para o menu";
     cout<<"\n3-Sair\n ";

     cin>>opcaofim;

     switch (opcaofim){

 case 1:


     jogo(nomedojogador);


    break;

      case 2:
limpatela();
  menuincial();


    break;


      case 3:


    break;

     }


  }

void menuincial(){

int opcao=0;

string nomedojogador;

while (opcao<1||opcao>3){

    cout<<"Bem vindo ao Jogo de Batalha Naval!";
    cout<<"\n1 - Jogar";
    cout<<"\n2 - Sobre";
    cout<<"\n3 - Sair";
    cout<<"\n Escolha uma opcao e tecle ENTER: ";
    cin>>opcao;


switch(opcao){

case 1:
      cout<<"Qual seu nome?? ";
      cin>>nomedojogador;
jogo(nomedojogador);


    break;
 case 2:
     cout<<"Informacoes do jogo";




    break;
case 3:



    break;

        }

    }

}


int main(){
//opcao escolhida pelo usurario


srand((unsigned)time(NULL));


menuincial();







return 0;
}
