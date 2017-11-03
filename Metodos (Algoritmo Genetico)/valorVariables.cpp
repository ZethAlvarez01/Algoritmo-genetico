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

void valorX(int aux,int **resVector,int *nbits,int **indivVector,int ind,float **tabla){
	float x=0;
	int gen=aux;
		//cout<<endl;
		//cout<<resVector[0][0]<<" "<<gen<<" "<<resVector[1][0]<<" "<<resVector[0][0]<<" "<<pow(2,nbits[0])-1;
		x=resVector[0][0]+(gen*((resVector[1][0]-resVector[0][0])/(pow(2,nbits[0])-1)));
		//cout<<x<<" "<<ind;
		tabla[ind][0]=x;
}

void valorY(int aux,int **resVector,int *nbits,int **indivVector,int ind,float **tabla){
	float x=0;
	int gen=aux;
		//cout<<endl;
		//cout<<resVector[0][0]<<" "<<gen<<" "<<resVector[1][0]<<" "<<resVector[0][0]<<" "<<pow(2,nbits[0])-1;
		x=resVector[0][1]+(gen*((resVector[1][1]-resVector[0][1])/(pow(2,nbits[1])-1)));
		//cout<<x<<" "<<ind;
		tabla[ind][1]=x;

}

void valorZ(int aux,int **resVector,int *nbits,int **indivVector,int ind,float **tabla){
	float x=0;
	int gen=aux;
		//cout<<endl;
		//cout<<resVector[0][0]<<" "<<gen<<" "<<resVector[1][0]<<" "<<resVector[0][0]<<" "<<pow(2,nbits[0])-1;
		x=resVector[0][2]+(gen*((resVector[1][2]-resVector[0][2])/(pow(2,nbits[2])-1)));
		//cout<<x<<" "<<ind;
		tabla[ind][2]=x;
}

void valorW(int aux,int **resVector,int *nbits,int **indivVector,int ind,float **tabla){
	float x=0;
	int gen=aux;
		//cout<<endl;
		//cout<<resVector[0][0]<<" "<<gen<<" "<<resVector[1][0]<<" "<<resVector[0][0]<<" "<<pow(2,nbits[0])-1;
		x=resVector[0][3]+(gen*((resVector[1][3]-resVector[0][3])/(pow(2,nbits[3])-1)));
		//cout<<x<<" "<<ind;
		tabla[ind][3]=x;
}

void valorVariables(int **indivVector,float **tabla,int *nbits,int var,int individuos,int aux2,int **resVector){
int aux=0;
int bin[10]={1,2,4,8,16,32,64,128,256,512};

int k=0,u=0,l=0,vari=0;

	for(int i=0;i<individuos;i++){
		k=0;
		u=0;
		vari=0;
		for(int j=0;j<aux2;j++){
			u++;
			if(indivVector[i][j]==1){
				aux=aux+bin[l];
				l++;
			}else if(indivVector[i][j]==0){
				l++;
			}
			if(u==nbits[k]){
				u=0;
				vari++;
				//cout<<aux<<" ";
				if(vari==1){
					valorX(aux,resVector,nbits,indivVector,i,tabla);
				}
				if(vari==2){
					valorY(aux,resVector,nbits,indivVector,i,tabla);
				}
				if(vari==3){
					valorZ(aux,resVector,nbits,indivVector,i,tabla);
				}
				if(vari==4){
					valorW(aux,resVector,nbits,indivVector,i,tabla);
				}
				l=0;
				aux=0;
				k++;
			}
		}
	}	


}