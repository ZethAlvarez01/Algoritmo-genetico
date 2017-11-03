#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<math.h>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/Restricciones.h"
#include"import/imprimir.h"
#include"import/Bits.h"
#include"import/vectores.h"
#include"import/main.h"
#include"import/valorVariables.h"
#include"import/mutacion.h"

using namespace std;

int mutacionGX(int x,int numero){
	int aux;
	aux=Binario(x,numero);
	return aux;
}