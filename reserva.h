#ifndef RESERVAS_H
#define RESERVAS_H

#define MAX_VOOS 100
#define MAX_RESERVAS 100
#define MAX_ASSENTOS 120

// Struct para voo
typedef struct {
    int numero;
    char origem[50];
    char destino[50];
    char data[11];
    char hora_partida[6];
    char hora_chegada[6];
} Voo;

// Struct para reserva
typedef struct {
    int numero_voo;
    char nome[50];
    char documento[15];
    char assento[5];
} Reserva;

// Variáveis globais
extern Voo voos[MAX_VOOS];
extern Reserva reservas[MAX_RESERVAS];
extern int qtd_voos;
extern int qtd_reservas;

// Funções
void cadastrarVoo();
void exibirVoos();
void pesquisarVoos();
void fazerReserva();
void exibirReservas();
int verificarint();
void mostrarAssentos();
void salvarVoos();
void carregarVoos();
void salvarReservas();
void carregarReservas();

#endif
