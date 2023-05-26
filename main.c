#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef double elemento;

#include"tad_pilha2.h"

int ehNumero(char* operando);
double calcula(double op1, double op2, char operador);
int verificaOperador(char exp);
char setarOperador(char exp);
tipo_pilha p;

double calcula(double op1,double op2, char operador){

    switch(operador){
        case '+':
            return (double)op1+op2;
        case '-':
            return (double)op1-op2;
        case '*':
            return (double)op1*op2;
        case '/':
            return (double)op1/op2;
    }
    return 0;
}
int verificaOperador(char exp){
    if(exp=='+' || exp == '-' || exp == '*' || exp=='/'){
        return 1;
    }else{
        return 0;
    }
}
char setarOperador(char exp){
    if(exp == '+'){
        return '+';
    }else if(exp == '-'){
        return '-';
    }else if(exp=='*'){
        return '*';
    }else if(exp=='/'){
        return '/';
    }
}
int ehNumero(char operando[]){
    if(atof(operando) || atoi(operando)){
        return 1;
    }else{
        return 0;
    }
}

float avaliarExpressao(char expressao[]){
    double op1, op2;
    char* auxExp;
    float aux;
    printf("expressao:%s\n",expressao);
    auxExp = strtok(expressao," ");

    while(auxExp!=NULL){
        printf("%s\n",auxExp);
        if(ehNumero(auxExp)){
            aux = atof(auxExp);
            empilharElemento(&p,aux);
        }else if(verificaOperador(auxExp[0])==1){
            desempilharElemento(&p,&op2);
            desempilharElemento(&p,&op1);
            empilharElemento(&p,calcula(op1,op2,auxExp[0]));
        }
        auxExp = strtok(NULL," ");
    }
    desempilharElemento(&p,&op1);
    printf("Resultado:%.2f\n",op1);
    return op1;
}
int main(){

    char expressao[100];
    printf("Use um espaço para separar os operandos dos operadores!\n");
    printf("Insira a expressão pós-fixa:\n");
    fgets(expressao,100,stdin);
    avaliarExpressao(expressao);

    return 0;
}
