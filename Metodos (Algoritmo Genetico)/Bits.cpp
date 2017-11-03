#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/main.h"
#include"import/Restricciones.h"
#include"import/imprimir.h"


using namespace std;

int numero(int num,int pres){
	float n,x;
	int naux;
	n=num*pow(10,pres);
	n=log(n)/log(2);
	naux=n;
	x=n-naux;
	if(x>0){
		naux++;
	}
	return naux;
}

void bits(int **vect,int var,int pres, int *nbits){
	int n;
	cout<<endl<<"\t\tDeterminar # de bits(cromosomas)"<<endl;
	
	for(int i=0;i<var;i++){
		if(i==0){
			cout<<"\t\tPara X"<<endl;
			n=numero(vect[1][0]-vect[0][0],pres);
			cout<<"\t\t"<<"2^"<<n-1<<" <= "<<(vect[1][0]-vect[0][0])*pow(10,pres)<<" <="<<" 2^"<<n<<endl;
			nbits[0]=n;
		}
		if(i==1){
			cout<<"\t\tPara Y"<<endl;
			n=numero(vect[1][1]-vect[0][1],pres);
			cout<<"\t\t"<<"2^"<<n-1<<" <= "<<(vect[1][1]-vect[0][1])*pow(10,pres)<<" <="<<" 2^"<<n<<endl;
			nbits[1]=n;
		}
		if(i==2){
			cout<<"\t\tPara Z"<<endl;
			n=numero(vect[1][2]-vect[0][2],pres);
			cout<<"\t\t"<<"2^"<<n-1<<" <= "<<(vect[1][2]-vect[0][2])*pow(10,pres)<<" <="<<" 2^"<<n<<endl;
			nbits[2]=n;
		}
		if(i==3){
			cout<<"\t\tPara W"<<endl;
			n=numero(vect[1][3]-vect[0][3],pres);
			cout<<"\t\t"<<"2^"<<n-1<<" <= "<<(vect[1][3]-vect[0][3])*pow(10,pres)<<" <="<<" 2^"<<n<<endl;
			nbits[3]=n;
		}
	}
}