#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

using namespace std;
//Definindo Struct Para Armazenagem De Dados.
typedef struct listaMedico{
    int crm;
    char nome[100];
    char area[100];
    struct listaMedico*prox;
}medico;

typedef struct listaM{
    medico *inicio;
    medico *fim;
}MLista;

typedef struct listaPaciente{
    int idade;
    int caso;
    int cpf;
    char sexo;
    char nome[100];
    char ende[100];
    struct listaPaciente*prox;
}paciente;

typedef struct listaP{
    paciente *inicio;
    paciente *fim;
}PLista;

typedef struct listaFila{
    int item;
    int cpf;
    struct listaFila*prox;
}fila;

typedef struct listaF{
    fila *inicio;
    fila *fim;
    int tamanho;
}FLista;

typedef struct listaHospital{
    int nummedico;
    int paciente;
    int medico;
    int atendidos;
    struct listaHospital*prox;
}hospital;

typedef struct listaH{
    hospital *inicio;
}HLista;
//Funcoes Utilizadas.
void inicioM(MLista *lista);

void inicioP(PLista *lista);

void inicioF(FLista *lista);

void inicioH(HLista *lista);

void menu();

void CadMedico(MLista *lista, int x);

int triagem();

int CadPaciente(PLista *lista, int x);

void salvar(MLista *lista);

int carregar(MLista *lista);

void CadFila(FLista *lista, int caso, int x);

void mostraM(MLista *lista);

void mostraF(FLista *lista);

void mostraH(HLista *lista);

void prioridade(int caso);

int segundo(int x);

void salvarhospital(HLista *lista);

void carregarhospital(HLista *lista);

#endif
