#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/Restricciones.h"
#include"import/imprimir.h"
#include"import/valorVariables.h"
#include"import/Bits.h"
#include"import/vectores.h"


using namespace std;

void titulo(){
system("cls");
	cout<<"\t\t************************************"<<endl;
	cout<<"\t\t******** Algoritmo genetico ********"<<endl;
	cout<<"\t\t************************************"<<endl<<endl;
}

int main(){
	int aut,aux=0;
	int restricciones;
	int funcion[6]={0,0,0,0,0,0};
	int x,y,z,w;
	char correcto;
	int poblaciones;
	int individuos;	
	int pres;
	int nbits[4]={0,0,0,0};
	int ind=0;

	do{
		funcionObjetivo(funcion);
	}while(funcion[4]!=1);
	
	x=funcion[0];
	y=funcion[1];
	z=funcion[2];
	w=funcion[3];
	int var=funcion[5];
	
	int **resVector;
	resVector = (int**) malloc(var * sizeof(int));
 	 for(int i=0; i<2; i++) {
      	resVector[i] = (int *) malloc(2 * sizeof(int));
 	 }

	for(int i=0;i<var;i++){
		for(int j=0;j<2;j++){
			resVector[j][i]=0;
		}
	}

	Restricciones(resVector,var);
	int min=0;
	do{
		titulo();

		cout<<"\t\t¿Cuantas poblaciones va a requerir?"<<endl<<"\t\t";
		cin>>poblaciones;
		
		titulo();
		cout<<"\t\t¿Cuantos individuos por poblacion?"<<endl<<"\t\t";
		cin>>individuos;

		titulo();
		cout<<"\t\t¿Bits de precision?"<<endl<<"\t\t";
		cin>>pres;

		titulo();
		cout<<"\t\t\tDeseas..."<<endl<<endl;
		cout<<"\t\t\t\tMinimizar [0]"<<endl;
		cout<<"\t\t\t\tMaximizar [1]"<<endl<<endl<<"\t\t\tOpcion: ";
		cin>>min;

		titulo();

		cout<<"\t\tPoblacion: "<<poblaciones<<endl;
		cout<<endl<<"\t\tIndividios por poblacion: "<<individuos<<endl;
		cout<<endl<<"\t\tBits de precision: "<<pres;


		bits(resVector,var,pres,nbits);
		cout<<endl<<endl<<"\t\t¿Datos de poblacionales correctos? [S/N]"<<endl<<"\t\t\t\t";
		cin>>correcto;

		if(correcto=='S' || correcto=='s'){
			aux=1;
		}
		

	}while(aux!=1);

	if(min==0){
		funcion[0]=funcion[0]*-1;
		funcion[1]=funcion[1]*-1;
		funcion[2]=funcion[2]*-1;
		funcion[3]=funcion[3]*-1;
	}

	x=funcion[0];
	y=funcion[1];
	z=funcion[2];
	w=funcion[3];

	
	imprimir(funcion,resVector,var,poblaciones,individuos,pres,min);
	
	cout<<"\n\n\t\tPara iniciar presione ENTER...";
	getch();
	
	
	int aux2=0;

	for(int i=0;i<var;i++){
		//cout<<nbits[i]<<endl;
		aux2=aux2+nbits[i];
	}	
	

	int **indivVector;
	indivVector = (int**) malloc(individuos * sizeof(int));
 	 for(int i=0; i<individuos; i++) {
      	indivVector[i] = (int *) malloc(aux2 * sizeof(int));
 	 }

	//cout<<endl<<individuos<<endl<<aux2<<endl;

	titulo();	
	float **tabla;
	tabla = (float**) malloc(individuos * sizeof(float));
 	 for(int i=0; i<individuos; i++) {
      	tabla[i] = (float *) malloc((var+5) * sizeof(float));
 	 }

	//cout<<endl;
	for(int i=0;i<individuos;i++){
		for(int j=0;j<(var+5);j++){
			tabla[i][j]=0;
			//cout<<tabla[i][j];
		}
		//cout<<endl;
	}

	vectores(indivVector,aux2,nbits,individuos);
	int u=0,l=0;

	for(int p=0;p<poblaciones;p++){
		cout<<endl<<endl;
		cout<<"Poblacion N"<<(char)167<<p+1<<endl<<endl;
	
		for(int j=0;j<individuos;j++){
			u=0;
			l=0;
			cout<<"V"<<j+1<<" ";
			for(int k=0;k<aux2;k++){
				u++;
				cout<<indivVector[j][k];
				if(u==nbits[l]){
					u=0;
					cout<<"|";
					l++;
				}
			}
			cout<<endl;
		}
		
		valorVariables(indivVector,tabla,nbits,var,individuos,aux2,resVector);

		for(int i=0;i<individuos;i++){
			for(int j=0;j<var;j++){
				if(j==0){
					tabla[i][var]=(tabla[i][0]*x);
				
				}if(j==1){
					tabla[i][var]=(tabla[i][0]*x)+(tabla[i][1]*y);
				}
				if(j==2){
					tabla[i][var]=(tabla[i][0]*x)+(tabla[i][1]*y)+(tabla[i][2]*z);
				}
				if(j==3){
					tabla[i][var]=(tabla[i][0]*x)+(tabla[i][1]*y)+(tabla[i][2]*z)+(tabla[i][3]*w);
				}
			}
		}


		float sumatoria=0;
	
		for(int i=0;i<individuos;i++){
			sumatoria=sumatoria+tabla[i][var];
			//cout<<endl<<tabla[i][var];
		}	
		//Porcentaje y porcentaje acumulado	

		float porcentaje;
		float acum=0;
		for(int i=0;i<individuos;i++){
			porcentaje=0;
			porcentaje=tabla[i][var]*100;
			porcentaje=porcentaje/sumatoria;
			//cout<<endl<<porcentaje;
			tabla[i][var+1]=porcentaje/100;
			acum+=porcentaje;
			//cout<<endl<<"***"<<acum;
			tabla[i][var+2]=acum/100;
		}
	
		double aleatorio;
	
		// #Aleatorio		

		for(int i=0;i<individuos;i++){
			aleatorio=rand()%100;
			aleatorio=aleatorio/100;
			tabla[i][var+3]=aleatorio;
			//cout<<endl<<"alea: "<<aleatorio;
		}
		
		//Vector Repetido
		
		cout<<endl<<endl<<"Tabla"<<endl;

		for(int i=0;i<individuos;i++){
			//cout<<tabla[i][var+2]<<"  "<<tabla[i][var+3];
			//cout<<endl;
			for(int j=0;j<individuos;j++){
				if(tabla[i][var+3]<tabla[j][var+2]){
					tabla[i][var+4]=j+1;
					j=individuos;
				}
			}
		}
		

		//Imprimri tabla
		int aux3;
		cout<<endl;
		for(int i=0;i<individuos;i++){
			for(int j=0;j<(var+5);j++){
				cout<<tabla[i][j]<<"     ";
			}
			cout<<endl;
		}
		cout<<endl<<"             Suma: "<<sumatoria<<endl;
		
		

		//Acomodar vectores fuertes
		
		int control[individuos];
		int aux4=0;

		for(int i=0;i<individuos;i++){
			control[i]=0;
		}	
			
		for(int i=0;i<individuos;i++){
			aux4=(tabla[i][var+4])-1;
			control[aux4]=(control[aux4])+1;	
		}
		
		int control2[individuos][2];

		for(int i=0;i<individuos;i++){
			control2[i][0]=control[i];
			control2[i][1]=i;
		}

		/*for(int i=0;i<individuos;i++){
			for(int j=0;j<2;j++){
				cout<<control2[i][j];
			}
			cout<<endl;
		}*/

		int aux5=0,aux6=0;
		for(int i=0;i<individuos;i++){
			for(int j=0;j<individuos-1;j++){
				if(control2[j][0]<control2[j+1][0]){
					aux5=control2[j][0];
					control2[j][0]=control2[j+1][0];
					control2[j+1][0]=aux5;

					aux6=control2[j][1];
					control2[j][1]=control2[j+1][1];
					control2[j+1][1]=aux6;
				}
			}
		}
		
	int **indivAux;
	indivAux = (int**) malloc(individuos * sizeof(int));
 	 for(int i=0; i<individuos; i++) {
      	indivAux[i] = (int *) malloc(aux2 * sizeof(int));
 	 }
		
		for(int i=0;i<individuos;i++){
			for(int j=0;j<aux2;j++){
				indivAux[i][j]=indivVector[i][j];
			}
		}	

		/*cout<<endl;
		for(int i=0;i<individuos;i++){
			for(int j=0;j<2;j++){
				cout<<control2[i][j];
			}
			cout<<endl;
		}*/
		int aux7=0,conta=0;
		for(int i=0;i<individuos;i++){
			if(control2[i][0]!=0){
				aux7=control2[i][1];
				for(int j=0;j<aux2;j++){
					indivVector[i][j]=indivAux[aux7][j];
				}
			}else{
				conta++;
			}
		}
		//cout<<endl<<individuos-conta<<endl;
		int sangreN,sangre2,sangre3;	

		int emergencia1=0;
		int emergencia2=0;
		int dif=0;
		int auxVec[aux2];

		for(int i=0;i<aux2;i++){
			auxVec[i]=indivVector[0][1];
		}
	
		for(int i=0;i<individuos;i++){
			for(int j=0;j<aux2;j++){
				if(auxVec[j]!=indivVector[i][j]){
					dif++;
				}
			}
		}

		if(dif!=0){
			for(int i=1;i<individuos;i++){
				for(int j=0;j<aux2;j++){
					indivVector[i][j]=rand()%2;
				}
			}
		}
		
		if(conta==0){
			for(int i=0;i<individuos;i++){
				do{
					emergencia1=rand()%aux2;
					emergencia2=rand()%aux2;
				}while(emergencia1==emergencia2);

				for(int j=0;j<aux2;j++){
					if(j==emergencia2){
						if(indivVector[i][j]==1){
							indivVector[i][j]=0;
						}else{
							indivVector[i][j]=1;
						}
					}else if(j==emergencia1){
							if(indivVector[i][j]==1){
								indivVector[i][j]=0;
							}else{
								indivVector[i][j]=1;
							}
					}
				}
			}
		}
	


		if((individuos-conta)==1){
			for(int i=0;i<individuos;i++){
				if(control2[i][0]==0){
					sangreN=control2[i][1];
					for(int j=0;j<aux2;j++){
						indivVector[sangreN][j]=rand()%2;
					}					
				}
			}
		}

		int mutacion1,mutacion2;
		int p1[aux2];
		int p2[aux2];

		if((individuos-conta)==2){
			for(int i=0;i<individuos;i++){
				if(control2[i][0]!=0){
					sangre2=control2[i][1];
					for(int j=0;j<aux2;j++){
						p1[j]=indivVector[sangre2][j];
					}				
				}
			}
		}	

		if((individuos-conta)==2){
			for(int i=0;i<individuos;i++){
				if(control2[i][0]!=0 && control2[i][1]!=sangre2){
					sangre3=control2[i][1];
					for(int j=0;j<aux2;j++){
						p2[j]=indivVector[sangre3][j];
					}				
				}
			}
			int puntoX=rand()%aux2;
			//cout<<endl<<puntoX<<endl;
			int hijo[aux2];
			for(int i=0;i<individuos;i++){
				if(control2[i][0]==0){
					ind=control2[i][1];
				}
			}
			for(int i=0;i<aux2;i++){
				if(i<=puntoX){
					hijo[i]=p2[i];
				}else{
					hijo[i]=p1[i];
				}
			}
			//cout<<endl;
			for(int i=0;i<aux2;i++){
				if(hijo[i]!=0 || hijo[i]!=1){
					hijo[i]=rand()%2;
				}	
			}		
			cout<<endl;
			int mut1=rand()%aux2;
			int mut2=rand()%aux2;
			//cout<<endl<<mut1<<" "<<mut2<<endl;
			
			for(int i=0;i<aux2;i++){
				if(i==mut1){
					if(hijo[i]==1){
						hijo[i]=0;
					}else{		
						hijo[i]=1;
					}
				}
				if(i==mut2){
					if(hijo[i]==1){
						hijo[i]=0;
					}else{		
						hijo[i]=1;
					}
				}
			}
			for(int i=0;i<aux2;i++){
				indivVector[ind][i]=hijo[i];
			}
		}
		


		int res=0;
		if(min==0){
			res=control2[0][1];
			switch(var){
				case 1:
					cout<<endl<<"Minimo: "<<"\n\tX: "<<tabla[res][0]<<endl;
				break;
				case 2:
					cout<<endl<<"Minimo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<endl;
				break;
				case 3:
					cout<<endl<<"Minimo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<"\n\tZ: "<<tabla[res][2]<<endl;
				break;
				case 4:
					cout<<endl<<"Minimo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<"\n\tZ: "<<tabla[res][2]<<"\n\tW: "<<tabla[res][3]<<endl;
				break;

			}
		}else{
			res=control2[0][1];
			switch(var){
				case 1:
					cout<<endl<<"Maximo: "<<"\n\tX: "<<tabla[res][0]<<endl;
				break;
				case 2:
					cout<<endl<<"Maximo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<endl;
				break;
				case 3:
					cout<<endl<<"Maximo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<"\n\tZ: "<<tabla[res][2]<<endl;
				break;
				case 4:
					cout<<endl<<"Maximo: "<<"\n\tX: "<<tabla[res][0]<<"\n\tY: "<<tabla[res][1]<<"\n\tZ: "<<tabla[res][2]<<"\n\tW: "<<tabla[res][3]<<endl;
				break;

			}
			cout<<endl<<endl;
		}	
		

	}
	

}