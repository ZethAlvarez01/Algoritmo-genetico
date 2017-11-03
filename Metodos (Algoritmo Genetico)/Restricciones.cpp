#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"import/Binario.h"
#include"import/funcionObjetivo.h"
#include"import/main.h"
#include"import/Restricciones.h"

using namespace std;

void Restricciones(int **vect,int variables){
	int val=0;
	char correcto;
	int aux=0;
do{
do{
	titulo();
	
	cout<<"\t\tIngresa las restricciones para las "<<variables<<" variables"<<endl;
	cout<<"\t\t[Lim. inferior LI ][Lim.superior LS ]"<<endl<<endl;	

	if(val==1){
		cout<<"\t\tERROR! \tTienes un error en algun limite :D "<<endl<<endl;
		val=0;
	}

	for(int i=0;i<variables;i++){
		for(int j=0;j<2;j++){
			if(i==0){
				if(j==0){
					cout<<"\t\tX: "<<endl<<"\t\t\t[LI]= ";
					cin>>vect[j][i];
				}else{	
					cout<<"\t\t\t[LS]= ";
					cin>>vect[j][i];
					if(vect[j-1][i]>vect[j][i]){
						val=1;
					}					
				}
			}
			if(i==1){
				if(j==0){
					cout<<"\t\tY: "<<endl<<"\t\t\t[LI]= ";
					cin>>vect[j][i];
				}else{	
					cout<<"\t\t\t[LS]= ";
					cin>>vect[j][i];
					if(vect[j-1][i]>vect[j][i]){
						val=1;
					}
				}
			}
			if(i==2){
				if(j==0){
					cout<<"\t\tZ: "<<endl<<"\t\t\t[LI]= ";
					cin>>vect[j][i];
				}else{	
					cout<<"\t\t\t[LS]= ";
					cin>>vect[j][i];
					if(vect[j-1][i]>vect[j][i]){
						val=1;
					}
				}
			}
			if(i==3){
				if(j==0){
					cout<<"\t\tW: "<<endl<<"\t\t\t[LI]= ";
					cin>>vect[j][i];
				}else{	
					cout<<"\t\t\t[LS]= ";
					cin>>vect[j][i];
					if(vect[j-1][i]>vect[j][i]){
						val=1;
					}
				}
			}
		}
	}

}while(val!=0);

	titulo();
	
	for(int i=0;i<variables;i++){
		if(i==0){
			cout<<"\t\t\tX de ["<<vect[0][0]<<","<<vect[1][0]<<"]"<<endl;
		}
		if(i==1){
			cout<<"\t\t\tY de ["<<vect[0][1]<<","<<vect[1][1]<<"]"<<endl;	
		}
		if(i==2){
			cout<<"\t\t\tZ de ["<<vect[0][2]<<","<<vect[1][2]<<"]"<<endl;	
		}
		if(i==3){
			cout<<"\t\t\tW de ["<<vect[0][3]<<","<<vect[1][3]<<"]"<<endl;	
		}
	}

	cout<<endl<<endl<<"\t\t¿Intervalos correctos? [S/N]"<<endl<<"\t\t\t\t";
	cin>>correcto;

	if(correcto=='S' || correcto=='s'){
		aux=1;
	}

}while(aux!=1);
}