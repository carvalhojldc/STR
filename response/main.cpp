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

const int LED = GPIO_44;
const int BOTAO_ACAO = GPIO_26;

const int STA = GPIO_66;
const int STB = GPIO_69;
const int STC = GPIO_45;
const int STD = GPIO_23;
const int STE = GPIO_47;
const int STF = GPIO_27;						
const int STG =	GPIO_22;
const int PTO = GPIO_60;

void geraNumero(int m, bool ponto) {
		if(m == 0) {
			GPIO_setStatus(STG,DOWN);     
        } else if(m == 1) {
			GPIO_setStatus(STA,DOWN);
			GPIO_setStatus(STD,DOWN);
			GPIO_setStatus(STE,DOWN);
			GPIO_setStatus(STF,DOWN);
			GPIO_setStatus(STG,DOWN);			
		} else if(m == 2) {			
			GPIO_setStatus(STF,DOWN);
			GPIO_setStatus(STC,DOWN);
		} else if(m == 3) {
			GPIO_setStatus(STF,DOWN);
			GPIO_setStatus(STE,DOWN);
		} else if(m == 4) {			
			GPIO_setStatus(STA,DOWN);
			GPIO_setStatus(STD,DOWN);
			GPIO_setStatus(STE,DOWN);      				
		} else if(m == 5) {			 		
			GPIO_setStatus(STB,DOWN);
			GPIO_setStatus(STE,DOWN);
		} else if(m == 6) {			
			GPIO_setStatus(STB,DOWN);		
		} else if(m == 7) {			 		
			GPIO_setStatus(STF,DOWN);
			GPIO_setStatus(STG,DOWN);
			GPIO_setStatus(STE,DOWN);      				
			GPIO_setStatus(STD,DOWN);      								
		} else if(m == 8) {			

		} else if(m == 9) {			 		
			GPIO_setStatus(STE,DOWN);      				
		}
		
		if(ponto) {
			GPIO_setStatus(PTO,UP);    
		} else {
			GPIO_setStatus(PTO,DOWN); 
		}
		
}

void full7s() {
	GPIO_setStatus(STA,UP);
	GPIO_setStatus(STB,UP);
	GPIO_setStatus(STC,UP);
	GPIO_setStatus(STD,UP);			
	GPIO_setStatus(STE,UP);
	GPIO_setStatus(STF,UP);
	GPIO_setStatus(STG,UP);
	GPIO_setStatus(PTO,UP);  
}

void clear7s() {
	GPIO_setStatus(STA,DOWN);
	GPIO_setStatus(STB,DOWN);
	GPIO_setStatus(STC,DOWN);
	GPIO_setStatus(STD,DOWN);			
	GPIO_setStatus(STE,DOWN);
	GPIO_setStatus(STF,DOWN);
	GPIO_setStatus(STG,DOWN);
	GPIO_setStatus(PTO,DOWN);
}

int main() {



    int tempoRand = 0;

    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::milliseconds milliseconds;

    srand((unsigned) time(NULL));

    GPIO_setMode(LED,OUTPUT);
    GPIO_setMode(BOTAO_ACAO,INPUT);
    
    GPIO_setMode(STA,OUTPUT);
    GPIO_setMode(STB,OUTPUT);
    GPIO_setMode(STC,OUTPUT);
    GPIO_setMode(STD,OUTPUT);
    GPIO_setMode(STE,OUTPUT);
    GPIO_setMode(STF,OUTPUT);
    GPIO_setMode(STG,OUTPUT);
        GPIO_setMode(PTO,OUTPUT);
    
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
        float seg = ms.count() / 1000.;
		cout << "Reação em " << seg << " s" << endl;


        int m = (int)seg;
        
		int ms2 = ((seg - m)*10);
        
		full7s();        
        geraNumero(m, true);
        sleep(2);
        full7s();
        geraNumero(ms2, false);
        sleep(2);
        clear7s();
    }
    
    return 0;
}
