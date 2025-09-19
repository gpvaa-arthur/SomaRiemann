#include <stdio.h>
#include <math.h>
#include <locale.h>

void clean_buffer();
double somaRiemann(double *Px, double b, int n);

void clean_buffer(){
    int c;
    while((c= getchar() != '\n') && c != EOF){}
}

double somaRiemann(double *Px, double b, int n){
    double DeltaX = (b-*Px)/n;
    int i = 1;
    double funcao, soma = 0;
    *Px += DeltaX/2;

    while(i<= n){
        /*    x^2 == pow(*Px,2)
              x^3+4x-3 == pow(*Px,3)+4* (*Px)-3
              \sin(x) == sin(*Px);
              x cos(x^2)==  *Px *cos(pow(*Px,2))
              3x e^x; == 3* (*Px) * exp(*Px)
              \ln (2x) == log(2* (*Px))
        */
        funcao = pow(*Px,2);
        soma += funcao *DeltaX;

        *Px += DeltaX;
        i++;
    }
    return soma;
}

int main(){
    setlocale(LC_ALL,"");
    double a, b;
    int n;

    printf("\nDigite o limite inferior da integral (a)\n");
    scanf("%lf", &a);
    clean_buffer();

    printf("Digite o limite superior da integral (b)\n");
    scanf("%lf", &b);
    clean_buffer();

    printf("Digite um número inteiro de partições de Riemann (n)\n");
    scanf("%d", &n);
    clean_buffer();

    double x = a, soma;

    soma = somaRiemann(&x, b, n);

    printf("%O valor da soma é %lf", soma);
}
