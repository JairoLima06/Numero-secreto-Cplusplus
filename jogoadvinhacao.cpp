#include<iostream>
#include<stdlib.h> //para poder usar o abs//
#include<cstdlib> //biblioteca com a função rand//
#include<ctime> //biblioteca com as funções de time//
using namespace std;

int main () {

    cout <<  "*************************************" << endl;
    cout <<  "* Bem-vindos ao jogo da adivinhacao *" << endl;
    cout <<  "*************************************" << endl;

    cout << "Escolha seu nível de diculdade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

//Sistema de dificuldade//
    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M') {
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }
    /////////////

    srand(time(NULL)); //função que escolhe uma seed aleatoria para o numero//
    const int NUMERO_SECRETO = rand() %100; //rand, é uma função para aleatoriedade//

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){  
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout <<"Qual seu chute? ";
        cin >> chute;

        //sistema de pontuação//
        double pontos_perdidos = abs (chute - NUMERO_SECRETO)/2.0; //2.0 para deixar a conta com virgula, sem numeros inteiros//
        pontos = pontos - pontos_perdidos;
        ///////////////////////
        cout << "o valor do seu chute e: " << chute << endl;

        //variaveis//
        bool acertou = chute == NUMERO_SECRETO; //chute é igual ao numero secreto//
        bool maior = chute > NUMERO_SECRETO; //chute é maior que o numero secreto//
        //variaveis//

        if (acertou) {
            cout <<"Parabens! voce acertou o numero secreto" << endl;
            nao_acertou = false;
            break; //para quebrar o laço (for)//
        }
        else if (maior) {
            cout << "Seu chute foi maior que o numero secreto" << endl;

        }
        else {
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }

    }
    
    cout << "Fim de jogo" << endl;
    if(nao_acertou){
        cout << "Voce perdeu. Tente novamente :(" << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2); //quantas casas queremos//
        cout << fixed; //para a virgula ficar fixa//
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }

}

