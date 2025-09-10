#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "reserva.h"

Voo voos[MAX_VOOS];
Reserva reservas[MAX_RESERVAS];
int qtd_voos = 0;
int qtd_reservas = 0;

// Função auxiliar para checar se string está vazia
int estaVazia(const char *str) {
    return str[0] == '\0';
}

int verificarint(){
	int op;
	
	while(1){
		printf("Escolha uma opção: ");
		scanf("%d", &op);
		
		if(op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 0){
			return op;
		} else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			return 6;
		}		
	}	
}

// Cadastrar novo voo
void cadastrarVoo() {
    setlocale(LC_ALL,"portuguese");
    int c;

    if (qtd_voos >= MAX_VOOS) {
        printf("Limite máximo de voos atingido!\n");
        return;
    }

    Voo novo;
    printf("\n=== CADASTRAR VOO ===\n");

    // Número do voo
	while (1) {
	    printf("N° DO VOO: ");
	    if (scanf("%d", &novo.numero) == 1 && novo.numero > 0) {
	        while ((c = getchar()) != '\n' && c != EOF); // limpar buffer
	
	        // Verificar se já existe voo com esse número
	        int duplicado = 0;
	        for (int i = 0; i < qtd_voos; i++) {
	            if (voos[i].numero == novo.numero) {
	                duplicado = 1;
	                break;
	            }
	        }
	        if (duplicado) {
	            printf("Já existe um voo cadastrado com esse número! Digite outro.\n");
	        } else {
	            break; // número válido e único
	        }
	    } else {
	        printf("\nValor inválido! Digite um número maior que zero.\n");
	        while ((c = getchar()) != '\n' && c != EOF); // limpar buffer
	    }
	}
	
   printf("ORIGEM: ");
       while (1) {
           fgets(novo.origem, 100, stdin);
           novo.origem[strcspn(novo.origem, "\n")] = 0;
           if (estaVazia(novo.origem)){
               printf("O campo origem é obrigatório!\nORIGEM: ");
           } else break;
       }
   
    printf("DESTINO: ");
       while (1) {
           fgets(novo.destino, 100, stdin);
           novo.destino[strcspn(novo.destino, "\n")] = 0;
           if (estaVazia(novo.destino)){
               printf("O campo destino é obrigatório!\nDESTINO: ");
           } else break;
       }

    // Data
    while (1) {
        printf("DATA: ");
        fgets(novo.data, 100, stdin);
        novo.data[strcspn(novo.data, "\n")] = 0;

        if (strlen(novo.data) == 10 &&
            novo.data[2] == '/' && novo.data[5] == '/' &&
            novo.data[0] >= '0' && novo.data[0] <= '9' &&
            novo.data[1] >= '0' && novo.data[1] <= '9' &&
            novo.data[3] >= '0' && novo.data[3] <= '9' &&
            novo.data[4] >= '0' && novo.data[4] <= '9' &&
            novo.data[6] >= '0' && novo.data[6] <= '9' &&
            novo.data[7] >= '0' && novo.data[7] <= '9' &&
            novo.data[8] >= '0' && novo.data[8] <= '9' &&
            novo.data[9] >= '0' && novo.data[9] <= '9') {

            int dia = (novo.data[0]-'0')*10 + (novo.data[1]-'0');
            int mes = (novo.data[3]-'0')*10 + (novo.data[4]-'0');

            if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12) {
                break; // data válida
            } else {
                printf("\nData inválida! Dia ou mês fora do intervalo.\n");
            }
        } else {
            printf("\nFormato inválido! Use dd/mm/aaaa.\n");
        }
    }

    // Hora de partida
    while (1) {
        printf("HORA DE PARTIDA: ");
        fgets(novo.hora_partida, 100, stdin);
        novo.hora_partida[strcspn(novo.hora_partida, "\n")] = 0;

        if (strlen(novo.hora_partida) == 5 &&
            novo.hora_partida[2] == ':' &&
            novo.hora_partida[0] >= '0' && novo.hora_partida[0] <= '2' &&
            novo.hora_partida[1] >= '0' && novo.hora_partida[1] <= '9' &&
            novo.hora_partida[3] >= '0' && novo.hora_partida[3] <= '5' &&
            novo.hora_partida[4] >= '0' && novo.hora_partida[4] <= '9') {

            int hora = (novo.hora_partida[0]-'0')*10 + (novo.hora_partida[1]-'0');
            int minuto = (novo.hora_partida[3]-'0')*10 + (novo.hora_partida[4]-'0');

            if (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59) {
                break; // hora válida
            } else {
                printf("\nHora inválida! Fora do intervalo.\n");
            }
        } else {
            printf("\nFormato inválido! Use hh:mm.\n");
        }
    }

    // Hora de chegada
    while (1) {
        printf("HORA DE CHEGADA: ");
        fgets(novo.hora_chegada, 100, stdin);
        novo.hora_chegada[strcspn(novo.hora_chegada, "\n")] = 0;

        if (strlen(novo.hora_chegada) == 5 &&
            novo.hora_chegada[2] == ':' &&
            novo.hora_chegada[0] >= '0' && novo.hora_chegada[0] <= '2' &&
            novo.hora_chegada[1] >= '0' && novo.hora_chegada[1] <= '9' &&
            novo.hora_chegada[3] >= '0' && novo.hora_chegada[3] <= '5' &&
            novo.hora_chegada[4] >= '0' && novo.hora_chegada[4] <= '9') {

            int hora = (novo.hora_chegada[0]-'0')*10 + (novo.hora_chegada[1]-'0');
            int minuto = (novo.hora_chegada[3]-'0')*10 + (novo.hora_chegada[4]-'0');

            if (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59) {
                break; // hora válida
            } else {
                printf("\nHora inválida! Fora do intervalo.\n");
            }
        } else {
            printf("\nFormato inválido! Use hh:mm.\n");
        }
    }

    voos[qtd_voos++] = novo;
    printf("\nVoo cadastrado com sucesso!\n");
    
    salvarVoos();
}

// Exibir todos os voos
void exibirVoos() {
	setlocale(LC_ALL,"portuguese");
	
    printf("\n=== LISTA DE VOOS ===\n");
    if (qtd_voos == 0) {
        printf("Nenhum voo cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd_voos; i++) {
            printf("\n+-----INFORMAÇÕES DO VOO %d-----+", voos[i].numero);
			printf("\n|N° DO VOO: %d                    ", voos[i].numero);
			printf("\n|ORIGEM: %s                       ", voos[i].origem);
			printf("\n|DESTINO: %s                      ", voos[i].destino);
			printf("\n|DATA: %s                         ", voos[i].data);
			printf("\n|PARTIDA: %s                      ", voos[i].hora_partida);
			printf("\n|CHEGADA: %s                      ", voos[i].hora_chegada);
			printf("\n+-------------------------------+\n");
              
       }     	   
   }

void pesquisarVoos() {
    setlocale(LC_ALL, "portuguese");
    carregarVoos();
    int c;

    printf("\n=== PESQUISAR VOO POR ORIGEM, DESTINO E DATA ===\n");

    char origem[100], destino[100], data[100];
    
    while ((c = getchar()) != '\n' && c != EOF);

    // ORIGEM
	while (1) {
	    printf("ORIGEM: ");
	    fgets(origem, 100, stdin);
	    origem[strcspn(origem, "\n")] = 0;
	    if (estaVazia(origem)) {
	        printf("O campo origem é obrigatório!\n");
	    } else break;
	}
	
	// DESTINO
	while (1) {
	    printf("DESTINO: ");
	    fgets(destino, 100, stdin);
	    destino[strcspn(destino, "\n")] = 0;
	    if (estaVazia(destino)) {
	        printf("O campo destino é obrigatório!\n");
	    } else break;
	}
	    
    // DATA
    while (1) {
        printf("DATA: ");
        fgets(data, 100, stdin);
        data[strcspn(data, "\n")] = 0;

        if (strlen(data) == 10 &&
            data[2] == '/' && data[5] == '/' &&
            data[0] >= '0' && data[0] <= '9' &&
            data[1] >= '0' && data[1] <= '9' &&
            data[3] >= '0' && data[3] <= '9' &&
            data[4] >= '0' && data[4] <= '9' &&
            data[6] >= '0' && data[6] <= '9' &&
            data[7] >= '0' && data[7] <= '9' &&
            data[8] >= '0' && data[8] <= '9' &&
            data[9] >= '0' && data[9] <= '9') {

            int dia = (data[0] - '0') * 10 + (data[1] - '0');
            int mes = (data[3] - '0') * 10 + (data[4] - '0');

            if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12) {
                break; // data válida
            } else {
                printf("Data inválida! Dia ou mês fora do intervalo.\n");
            }
        } else {
            printf("Formato inválido! Use dd/mm/aaaa.\n");
        }
    }

    // PESQUISA
    int encontrados = 0;
    for (int i = 0; i < qtd_voos; i++) {
        if (strcmp(voos[i].origem, origem) == 0 &&
            strcmp(voos[i].destino, destino) == 0 &&
            strcmp(voos[i].data, data) == 0) {

            printf("\n+-----INFORMAÇÕES DO VOO %d-----+", voos[i].numero);
            printf("\n|N° DO VOO: %d                   ", voos[i].numero);
            printf("\n|ORIGEM: %s                      ", voos[i].origem);
            printf("\n|DESTINO: %s                     ", voos[i].destino);
            printf("\n|DATA: %s                        ", voos[i].data);
            printf("\n|PARTIDA: %s                     ", voos[i].hora_partida);
            printf("\n|CHEGADA: %s                     ", voos[i].hora_chegada);
            printf("\n+-------------------------------+\n");
            encontrados = 1;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum voo encontrado com os critérios informados.\n");
    }
}

void fazerReserva() {
    setlocale(LC_ALL, "portuguese");
    int c;

    if (qtd_reservas >= MAX_RESERVAS) {
        printf("Limite máximo de reservas atingido!\n");
        return;
    }

    int numero_voo;
    char nome[50], documento[20], assento_str[5];

    printf("\n=== FAZER RESERVA ===\n");

    // Número do voo
    while (1) {
        printf("N° DO VOO: ");
        if (scanf("%d", &numero_voo) == 1 && numero_voo > 0) {
            while ((c = getchar()) != '\n' && c != EOF); // limpar buffer
            break;
        } else {
            printf("\nValor inválido! Digite um número maior que zero.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    // Verificar se voo existe
    int voo_encontrado = 0;
    for (int i = 0; i < qtd_voos; i++) {
        if (voos[i].numero == numero_voo) {
            voo_encontrado = 1;
            break;
        }
    }

    if (!voo_encontrado) {
        printf("Voo não encontrado.\n");
        return;
    }

    mostrarAssentos(numero_voo, 0);

    // Entrada e validação de assento
	while (1) {
	    printf("ASSENTO: ");
	    fgets(assento_str, sizeof(assento_str), stdin);
	    assento_str[strcspn(assento_str, "\n")] = 0;
	
	    int len = strlen(assento_str);
	
	    // Verifica se o primeiro caractere é entre A e F
	    if (len < 2 || len > 3 || assento_str[0] < 'A' || assento_str[0] > 'F') {
	        printf("Formato de assento inválido. Use formato como A1 até F20.\n");
	        continue;
	    }
	
	    // Extrair o número (parte depois da letra)
	    int numero_assento = atoi(&assento_str[1]);
	
	    // Validar se número está entre 1 e 20
	    if (numero_assento < 1 || numero_assento > 20) {
	        printf("Número do assento inválido. Use valores de 1 a 20.\n");
	        continue;
	    }
	
	    // Verifica se os caracteres depois da letra são todos dígitos
	    int digitos_validos = 1;
	    for (int i = 1; i < len; i++) {
	        if (assento_str[i] < '0' || assento_str[i] > '9') {
	            digitos_validos = 0;
	            break;
	        }
	    }
	    if (!digitos_validos) {
	        printf("Formato inválido. Use letras A-F e números 1 a 20.\n");
	        continue;
	    }
	
	    // Verificar se assento já está ocupado no voo
	    int ocupado = 0;
	    for (int i = 0; i < qtd_reservas; i++) {
	        if (reservas[i].numero_voo == numero_voo && strcmp(reservas[i].assento, assento_str) == 0) {
	            ocupado = 1;
	            break;
	        }
	    }
	
	    if (ocupado) {
	        printf("Erro: O assento %s já está ocupado neste voo.\n", assento_str);
	    } else {
	        break; // assento válido e disponível
	    }
	}
	
	// Converter o assento_str para índice (1 a 120)
	int letra_index = assento_str[0] - 'A';  // 0 a 5
	int numero_assento = atoi(&assento_str[1]);  // 1 a 20
	int indice_assento = letra_index * 20 + (numero_assento - 1) + 1; // +1 para passar no padrão da função
	
	mostrarAssentos(numero_voo, indice_assento);

    // Nome
    while (1) {
        printf("NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;

        if (estaVazia(nome)) {
            printf("Erro: o nome é obrigatório.\n");
        } else {
            break;
        }
    }

    // Documento
    while (1) {
        printf("DOCUMENTO: ");
        fgets(documento, sizeof(documento), stdin);
        documento[strcspn(documento, "\n")] = 0;

        int valido = 1;
        if (estaVazia(documento)) {
            printf("Erro: o documento é obrigatório.\n");
            valido = 0;
        } else if (strlen(documento) > 11) {
            printf("Erro: o documento deve ter no máximo 11 dígitos.\n");
            valido = 0;
        } else {
            for (int i = 0; documento[i] != '\0'; i++) {
                if (documento[i] < '0' || documento[i] > '9') {
                    printf("Erro: o documento deve conter apenas números.\n");
                    valido = 0;
                    break;
                }
            }
        }
        if (valido) break;
    }

    // Verificar conflito de reserva
    for (int i = 0; i < qtd_reservas; i++) {
        if (reservas[i].numero_voo == numero_voo && strcmp(reservas[i].documento, documento) == 0) {
            printf("Já existe reserva para esse passageiro neste voo!\n");
            return;
        }
    }

    Reserva nova;
    nova.numero_voo = numero_voo;
    strcpy(nova.nome, nome);
    strcpy(nova.documento, documento);
    strcpy(nova.assento, assento_str);

    reservas[qtd_reservas++] = nova;
    printf("Reserva feita com sucesso!\n");

    salvarReservas();
}

// Exibir reservas
void exibirReservas() {
	setlocale(LC_ALL,"portuguese");
	
    printf("\n=== LISTA DE RESERVAS ===\n");
   	if (qtd_reservas == 0) {
    	printf("Nenhuma reserva cadastrada.\n");
    return;
   	}	
   		for (int i=0; i<qtd_reservas; i++) {
      	printf("\n+--------RESERVAS VOO %d--------+", voos[i].numero);
		printf("\n|N° DO VOO: %d                   ", reservas[i].numero_voo);
		printf("\n|NOME: %s                        ", reservas[i].nome);
		printf("\n|DOCUMENTO: %s                   ", reservas[i].documento);
		printf("\n|ASSENTO: %s                     ", reservas[i].assento);
		printf("\n+-------------------------------+\n");
   	}	     		 	
 }
 
void mostrarAssentos(int numero_voo, int novo_assento_destacado) {
    int assentos_ocupados[120] = {0};

    // Marca os assentos ocupados pelas reservas existentes
    for (int i = 0; i < qtd_reservas; i++) {
        if (reservas[i].numero_voo == numero_voo) {
            char *assento = reservas[i].assento;
            int letra_index = assento[0] - 'A';  // de 0 a 5 (A-F)

            // Extrair número do assento a partir do 2º caractere
            int numero_assento = atoi(&assento[1]);

            if (letra_index >= 0 && letra_index < 6 && numero_assento >= 1 && numero_assento <= 20) {
                int indice = letra_index * 20 + (numero_assento - 1);
                assentos_ocupados[indice] = 1;
            }
        }
    }

    // Se novo_assento_destacado for diferente de 0, marcar ele como ocupado também
    if (novo_assento_destacado != 0) {
        int letra_index = (novo_assento_destacado - 1) / 20;  // só funciona se novo_assento_destacado for índice no formato 1 a 120
        int numero_assento = ((novo_assento_destacado - 1) % 20) + 1;
        int indice = letra_index * 20 + (numero_assento - 1);
        if (indice >= 0 && indice < 120) {
            assentos_ocupados[indice] = 1;
        }
    }

    printf("\n=== MAPA DE ASSENTOS DO VOO %d ===\n", numero_voo);
    printf("(X = ocupado, código = livre)\n\n");

    for (int i = 0; i < 120; i++) {
        char letra = 'A' + (i / 20);
        int numero = (i % 20) + 1;

        if (assentos_ocupados[i])
            printf(" X   ");
        else
            printf(" %c%-2d ", letra, numero);

        if ((i + 1) % 20 == 0)
            printf("\n");
    }

    printf("\n");
}

void salvarVoos() {
    FILE *f = fopen("voos.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo de voos para escrita!\n");
        return;
    }
    for (int i = 0; i < qtd_voos; i++) {
        fprintf(f, "%d|%s|%s|%s|%s|%s\n",
                voos[i].numero,
                voos[i].origem,
                voos[i].destino,
                voos[i].data,
                voos[i].hora_partida,
                voos[i].hora_chegada);
    }
    fclose(f);
}

void carregarVoos() {
    FILE *f = fopen("voos.txt", "r");
    if (f == NULL) {
        // Se não existir, tudo bem (não mostra erro)
        return;
    }
    qtd_voos = 0;
    while (fscanf(f, "%d|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^\n]\n",
                  &voos[qtd_voos].numero,
                  voos[qtd_voos].origem,
                  voos[qtd_voos].destino,
                  voos[qtd_voos].data,
                  voos[qtd_voos].hora_partida,
                  voos[qtd_voos].hora_chegada) == 6) {
        qtd_voos++;
        if (qtd_voos >= MAX_VOOS) break;
    }
    fclose(f);
}

void salvarReservas() {
    FILE *f = fopen("reservas.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo de reservas para escrita!\n");
        return;
    }
    for (int i = 0; i < qtd_reservas; i++) {
        fprintf(f, "%d|%s|%s|%s\n",
                reservas[i].numero_voo,
                reservas[i].nome,
                reservas[i].documento,
                reservas[i].assento);
    }
    fclose(f);
}

void carregarReservas() {
    FILE *f = fopen("reservas.txt", "r");
    if (f == NULL) {
        return;
    }
    qtd_reservas = 0;
    while (fscanf(f, "%d|%49[^|]|%19[^|]|%4[^\n]\n",
                  &reservas[qtd_reservas].numero_voo,
                  reservas[qtd_reservas].nome,
                  reservas[qtd_reservas].documento,
                  reservas[qtd_reservas].assento) == 4) {
        qtd_reservas++;
        if (qtd_reservas >= MAX_RESERVAS) break;
    }
    fclose(f);
}
