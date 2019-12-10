#include <iostream>	
#include <stdio.h>
#include<math.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

void leevec(int , float [100],char[10]);
void DifDivNewton(int ,float[100],float[100],float[100]);

void escmatriz(int,int,float[50][50],char[10]);
void escvec(int,float[50],char[10]);

//Para los valores evaluados en la derivada de mi funci�n
float ValorDerFact(int, float);
int factorial(int);

int main ()
{
int m,n;
float X[100],Y[100],A[100];
cout<<"programa de diferencias divididas"<<endl;
cout<<endl;
cout<< "ingrese cantidad de puntos (contar los repetidos si hay derivadas): ";
cin>>n;
cout<<"vector X"<<endl;
leevec(n,X,"X");
cout<<"vector Y"<<endl;
leevec(n,Y,"Y");
DifDivNewton(n,X,Y,A);
system("pause");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void leevec(int n,float X[100],char nom[10]){
int i;
 for ( i = 1; i <= n; i++)
 {
    cout<<nom<<"["<<i<<"]=";
    cin>>X[i]; ////////////////////////////////////
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void DifDivNewton(int n, float X[100],float Y[100],float A[100]){
	int i,j;
	float DD[50][50], P[50][50],VX[50][50],b[50];

	for (i = 1; i <= n; i++){
		//Ac� estoy colocando "las columnas"
		DD[i][1]=i-1; //Columna que numera mis n, desde 0 en adelante (cantidad de puntos)
		DD[i][2]=X[i]; //Esta columna posee los valores de X
		DD[i][3]=Y[i]; //Esta columna tiene los valores de Y(x)
	}
	
	//El primer for es para mantener fijo el llenado de una columna, para el caso, iniciando c�lculos en la columna 4
	for (j = 1; j <= n-1; j++){
		//Este for interno, me ayuda a ir llenado las filas, de la columna que mantengo fija..., pues sino fallar�a...
		for ( i = 1; i <= n-j; i++){
	    	/*Ahora, validar� con un IF el simple hecho de si hay filas consecutivas repetidas, puesto que si se da ese
	    	caso, necesitar� pedir al usuario un valor, que no es m�s que el valor de equis evaluado en la derivada de
	    	la funci�n correspondiente*/
	    	if(DD[i+1][j+2] == DD[i][j+2] && DD[i+j][2] == DD[i][2]){
	    		//Llamo una funci�n que pide el valor de la funci�n, a continuaci�n explico qu� hago en ella xd - mandar� el valor de equis
	    		float tempEquis = DD[i+j][2]; //Solo temporalmente mando equis, pa saber qu� valor en la derivada pido...
	    		//Ahora que ya les expliqu� que hac�a, almaeceno su valor de retorno en esa posici�n xdxd
	    		DD[i][j+3] = ValorDerFact(j+3, tempEquis);
			}else{
				//Caso contratio, contin�o llenando mi matriz con los valores calculados...
				DD[i][j+3] = ((DD[i+1][j+2])-(DD[i][j+2]))/((DD[i+j][2])-(DD[i][2]));	
			}
		}
	}

	escmatriz(n,n+2,DD,"DD");

	for(i = 1; i <= n; i++){
		b[i]=DD[1][i+2];
	}
	
	cout<<"valores de B"<<endl;
	escvec(n,b,"b");
	
	for ( i = 1; i <= n; i++){
		for ( j = 1; j <= n; j++){
	    	P[i][j]=0;
	    }
	}
	
	for ( i = 1; i <= n; i++){
		P[i][1]=1;
	}
	
	for ( i = 2; i <= n; i++){
	    for ( j = 2; j <= i; j++){
	        P[i][j]=((P[i-1][j-1])*(-1*X[i-1]))+P[i-1][j];
	    }
	}
}

//----------------DEFINICI�N DE FUNCIONES IMPORTANTES----------------------------

void escmatriz(int n,int m, float a[50][50],char nom[10]){
	int i,j;
	cout<<"MATRIZ"<<nom<<endl;
	for ( i = 1; i <= n; i++){
	    cout<<endl;
	    for ( j = 1; j <= m; j++){
	    	cout<<setprecision(10);
	        cout<<setw(10)<<a[i][j]<<"\t";
	    }
	}
	cout<<endl<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void escvec(int n, float X[50],char nom[10]){
int i=1;
for ( i = 1; i <=n; i++)
{
    cout<<endl;
    cout<<setprecision(10);
    cout<<nom<<"["<<i<<"]="<<X[i];
}
cout<<endl<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Recibo el valor de la columna, que me permitir� hacer un c�lculo f�cil de la derivada en la que me encuentro
float ValorDerFact(int j, float tempEquis){
	int numDerivada = j-3;
	float valorEquisDerivada;
	
	cout << "Ingresar el resultado de la equis actual, el cu�l es "<< tempEquis << " evaluado en la derivada " << numDerivada << endl;
	cin >> valorEquisDerivada;
	
	//Llamo una funci�n que me calula el factorial, pues necesito sacarlo seg�n sea el n�mero de la derivada...
	return valorEquisDerivada/(float)factorial(numDerivada);
}

//Funci�n para obtener el factorial de un n�mero xdxdxd
int factorial(int num){
	if(num < 0) return 0;
   	else if(num > 1) return num*factorial(num-1);
   	return 1;
}
