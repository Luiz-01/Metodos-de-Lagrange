//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <conio.h>

//funcoes
double Formula_Lagrange(int n, int k,double val);
double IT(int n,double x);//Calcula o ponto de interpolacao

//Funções de Alocação dinamica de Memoria
double* fx;
double* x;

//Main
int main()
{
	//Variaveis
	int qtd,op,resp,i;
	double pi;//ponto de interpolacao
	
	do{
		
	printf("-------------------------Metodos Numericos Computacionais:Lagrange---------------------\n\n");
	do{
	//Entrada dos parametros de X e F(X)

	 
	printf("Digite os numeros de pontos da tabela de X e F(X):");
	
    scanf("%d",&qtd);//entrada de dados
    
    }while(qtd <= 0);//Nao permite que o usuario digite o numero de pontos igual ou menor que 0
    
    system("cls");//limpa  a tela a cima
    
   //Alocação dinamica de Memoria para x e f(x)
   
    fx = (double *) malloc(sizeof(double) * qtd);
    x = (double *) malloc(sizeof(double) * qtd);
    
    for(i = 0; i < qtd; i++)
    {
    	printf("x (%d):", i);
        scanf("%lf", &x[i]);
        printf("fx(%d):", i);
        scanf("%lf", &fx[i]);
        printf("------\n");
	}
	
	do 
	{
		printf("-------------------------Interpolacao usando metodo de Lagrange---------------------\n\n");
        printf("\nPor favor digite o ponto a ser interpolado:\n");
        scanf("%lf", &pi);
        printf("\nO resultado de f(%4.2lf) é igual a %5.4lf\n", pi, IT(qtd, pi));
        printf("\nDeseja interpolar outro ponto?\n(1)Sim (2)Nao\n\n");
        scanf("%i",&resp);
    } while(resp==1);
	
        
	do 
	{
        printf("\n Escolha uma das opções:\n(1)Repetir o programa (2)Fechar o programa\n");
        scanf("%i", &op);
        
    } while (op < 1 || op > 2);
        
	 if (op == 1) 
	 {
        printf("REINICIANDO O PROGRAMA");
        printf("\nPresssione qualquer tecla para continuar...");
        getch();
        system("cls");
        } 
		else 
		{
        exit(1);
        }
    } while (op==1);


	return 0;
}

  double Formula_Lagrange(int n, int k, double val)
{
    int i;
    double resultado = 1;
    for (i = 0; i < n; i++)
    {
        if (i!=k)
            resultado = resultado * (double)((val - x[i]) / (x[k] - x[i]));
    }
    return resultado;
}
  double IT(int n,double x)
{
    int i;
    double p = 0;
    double *L = (double*)malloc(sizeof(double)*n);
    for (i = 0; i < n; i++)
    {
        L[i] = Formula_Lagrange(n, i, x);
        p += fx[i] * L[i];
        printf("\n------\nL(%d) = %5.3lf\n", i, L[i]);
    }
}
