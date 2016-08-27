/*
	Compile: g++ main.cpp -std=c++11 -o name
*/

#include <iostream>
#include <chrono>
#include <time.h>
#include <unistd.h>

#include "bbbgpio.h"

using std::cout;
using std::endl;

int main() {

	const int LED = GPIO_44;
	const int BOTAO_ACAO = GPIO_26;

    int tempoRand = 0;

    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::milliseconds milliseconds;

    srand((unsigned) time(NULL));

    GPIO_setMode(LED,OUTPUT);
    GPIO_setMode(BOTAO_ACAO,INPUT);

	cout << "Fique de prontidão..." << endl;
    while(1) {
    	
        tempoRand = rand()%4 + 2;
        sleep(tempoRand);

        GPIO_setStatus(LED,UP); /* Liga o led */
        
        Clock::time_point t0 = Clock::now();

        while(!GPIO_status(BOTAO_ACAO)); /* Esperando o botao ser pressionado */

        Clock::time_point t1 = Clock::now();

        GPIO_setStatus(LED,DOWN); /* Desliga o led */

        milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
		cout << "Reação em " << ms.count() / 1000. << " s" << endl;
    }
    cout << "Programa encerrado..." << endl;
    
    return 0;
}
