#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/main.h"

using namespace std;

void funcionObjetivo(int *funcion){
	int variables;
	int x=0,y=0,z=0,w=0;
	char correcto;
	int aut;

do{
	x=0;y=0;z=0;w=0;
	titulo();
	cout<<"\t\t¿Cuantas variables tiene tu funcion?"<<endl<<"\t\t";
	cin>>variables;
	
	}while(variables>4 || variables<1);

	int aux=0;
	titulo();
	cout<<"\t\tIngresa el coeficiente cada una de las "<<variables<<" variables"<<endl<<"\t\t";
	char letra='X';
	for(int i=0;i<variables;i++){
		if(letra+i==91){
			cout<<"\t\tW: ";
			cin>>w;
			funcion[3]=w;
		}
		if(letra+i==88){
			cout<<"X: ";
			cin>>x;
			funcion[0]=x;
		}
		if(letra+i==89){
			cout<<"\t\tY: ";
			cin>>y;
			funcion[1]=y;
		}
		if(letra+i==90){
			cout<<"\t\tZ: ";
			cin>>z;
			funcion[2]=z;
		}
	}

	titulo();
	
	cout<<"\t\t\tZ= ";
	
	for(int i=0;i<variables;i++){
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
	cout<<endl<<endl<<"\t\t¿Funcion correcta? [S/N]"<<endl<<"\t\t\t\t";
	cin>>correcto;
	if(correcto=='S' || correcto=='s'){
		funcion[4]=1;
	}
	funcion[5]=variables;
}