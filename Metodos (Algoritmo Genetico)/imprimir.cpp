#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/main.h"
#include"import/Restricciones.h"
#include"import/imprimir.h"

using namespace std;

void imprimir(int *funcion,int **vect,int var,int poblaciones,int individuos,int pres,int min){
	titulo();
	int x,y,z,w;
	x=funcion[0];
	y=funcion[1];
	z=funcion[2];
	w=funcion[3];
	if(min==0){
		cout<<"\t\tFuncion objetivo Minimizar(-z)"<<endl;
	}else{
		cout<<"\t\tFuncion objetivo Maximizar(z)"<<endl;
	}

	cout<<"\t\t\tZ= ";
	
	for(int i=0;i<var;i++){
		if(i==0){
			if(x<0){
				if(x==-1){
					cout<<"-x";
				}else{
					cout<<x<<"x";
				}
			}else{
				if(x==1){
					cout<<"x";
				}else{
					cout<<"+"<<x<<"x";
				}
			}
		}
		if(i==1){
			if(y<0){
				if(y==-1){
					cout<<"-y";
				}else{
					cout<<y<<"y";
				}
			}else{
				if(y==1){
					cout<<"+"<<"y";
				}else{
					cout<<"+"<<y<<"y";
				}
			}
		}
		if(i==2){
			if(z<0){
				if(z==-1){
					cout<<"-z";
				}else{
					cout<<z<<"z";
				}
			}else{
				if(z==1){
					cout<<"+"<<"z";
				}else{
					cout<<"+"<<z<<"z";
				}
			}
		}
		if(i==3){
			if(w<0){
				if(w==-1){
					cout<<"-w";
				}else{
					cout<<w<<"w";
				}
			}else{
				if(w==1){
					cout<<"+"<<"w";
				}else{
					cout<<"+"<<w<<"w";
				}
			}
		}
	}

	cout<<endl<<"\t\t\ts.a"<<endl;
	for(int i=0;i<var;i++){
		if(i==0){
			cout<<"\t\t\t\tX de ["<<vect[0][0]<<","<<vect[1][0]<<"]"<<endl;
		}
		if(i==1){
			cout<<"\t\t\t\tY de ["<<vect[0][1]<<","<<vect[1][1]<<"]"<<endl;	
		}
		if(i==2){
			cout<<"\t\t\t\tZ de ["<<vect[0][2]<<","<<vect[1][2]<<"]"<<endl;	
		}
		if(i==3){
			cout<<"\t\t\t\tW de ["<<vect[0][3]<<","<<vect[1][3]<<"]"<<endl;	
		}
	}

	cout<<endl<<endl<<"\t\t\t"<<poblaciones<<" Poblaciones de "<<individuos<<" cada una."<<endl;
	cout<<endl<<"\t\t\tBits de precision: "<<pres<<endl;
}