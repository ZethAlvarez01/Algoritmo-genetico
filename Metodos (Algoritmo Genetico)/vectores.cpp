#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/main.h"
#include"import/Restricciones.h"
#include"import/imprimir.h"
#include"import/vectores.h"

using namespace std;


void vectores(int **indivVector,int aux2,int *nbits, int individuos){
	for(int i=0;i<individuos;i++){
		for(int j=0;j<aux2;j++){
			if(i==0){
				indivVector[i][j]=1;
			}else if(i==(individuos-1)){
				indivVector[i][j]=0;
			}else{
				indivVector[i][j]=rand()%2;
			}
		}
	}	
	
}
