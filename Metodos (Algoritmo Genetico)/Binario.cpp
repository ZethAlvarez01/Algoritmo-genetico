#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"import/Binario.h"

using namespace std;

int Binario(int x,int numero){
	cout<<endl<<"---------";
	int vector[numero];
	//cout<<x;
	for(int i=0;i<numero;i++){
		vector[i]=0;
	}

	int z=0;

	do{
		vector[z]=x%2;
		z++;
		x=x/2;
	}while(x>=1);
	
	cout<<endl<<"gen malo: "<<x<<endl;

	for(int i=0;i<numero;i++){
		cout<<vector[i]<<" ";
	}
	
	int puntoM=0;
	int puntoM2=0;

	puntoM=rand()%numero;
	puntoM2=rand()%numero;
	
	if(vector[puntoM]==1){
		vector[puntoM]=0;
	}else{
		vector[puntoM]=1;
	}

	if(vector[puntoM2]==1){
		vector[puntoM2]=0;
	}else{
		vector[puntoM2]=1;
	}
	cout<<endl;
	for(int i=0;i<numero;i++){
		cout<<vector[i]<<" ";
	}
	
	int bin[10]={1,2,4,8,16,32,64,128,256,512};
	int aux=0;
	int j=0;
	for(int i=0;i<numero;i++){
		if(vector[i]==1){
			aux=aux+bin[j];
		}
		j++;
	}
	cout<<endl<<aux;
	cout<<endl<<"---------";
	return aux;
}