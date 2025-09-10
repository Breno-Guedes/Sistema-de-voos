#include <stdio.h>
#include <locale.h>
#include "reserva.h"

int main() {
	setlocale(LC_ALL,"portuguese");
	
	carregarVoos();
	carregarReservas();
	    
    int op;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cadastrar novo voo\n");
        printf("2. Exibir todos os voos\n");
        printf("3. Pesquisar voos\n");
        printf("4. Fazer reserva\n");
        printf("5. Exibir reservas\n");
        printf("0. Sair\n");
       
        op = verificarint();
        
        switch(op) {
            case 1: 
				cadastrarVoo(); 
			break;
			
            case 2:
				exibirVoos();
			break;
			
            case 3: 
				pesquisarVoos(); 
			break;
			
            case 4: 
				fazerReserva(); 
			break;
			
            case 5: 
				exibirReservas(); 
			break;
			
            case 0: 
				printf("Saindo do sistema...\n"); 
			break;		
            default: 
				printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}
