/***********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                           *
 *                                                                                 *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de            *
 * departamentos do Berg                                                           *
 *                                                                                 *
 * clientes.c: arquivo com o desenvolvimento dos prototipos das funções da biblio- *
 * teca clientes.h                                                                 *
 *                                                                                 *
 * Versão: 0.1                                                                     *
 *                                                                                 *
 * Desenvolvidores: Gustavo S. Bacagine       <gustavobacagine@gmail.com>          *
 * 		  			Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>  *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>           *
 *                                                                                 *
 * Data de inicio: 21/11/2019                                                      *
 * Data da última modificação: 27/11/2019                                          *
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>    // Biblioteca usada para o system("clear")
#include "clientes.h" /* --> Biblioteca com os 
                         prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                         prototipos das funções das compras */

#define CLIENT_SUCESS "Cliente cadastrado com sucesso!" /* Mensagem a ser 
                                                           mostrada após o 
                                                           cadasto do cliente */

#define NOT_CLIENT "Erro! Não ha nenhum cliente cadastrado!" /* Mensagem a ser 
                                                                mostrada caso 
                                                                não haja nenhum
                                                                cliente cadastrado */

void cadastrar_cliente(void){
    
    FILE *arq; // Declarando uma variavel de arquivo
    cliente client;
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        getchar();
        getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END);
    
    client.codigo_cliente = ftell(arq) / sizeof(cliente) + 1; // Pega o número atual de clientes cadastrados e soma + 1
    system("clear"); // Limpa o terminal quando o usuario escolhe a opção Cadastrar Clientes
    printf("********Novo Cliente********\n");
	printf("Codigo do cliente: %d\n", client.codigo_cliente); // Mostra o código do cliente que será cadastrado
	printf("Nome do cliente: ");
    scanf(" %50[^\n]", client.nome_cliente);
    printf("Numero de telefone: ");
	scanf(" %14[^\n]", client.telefone);
	
    fwrite(&client, sizeof(cliente), 1, arq);
	fclose(arq); // Fecha o arquivo clientes.dat
    
    system("clear");      // Limpa o terminal após o termino do cadastrado do cliente
	puts(CLIENT_SUCESS); // Printa no terminal a mensagem: "Cliente cadastrado com sucesso!"
    getchar();
    getchar();
    system("clear");  // Limpa o terminal antes de voltar para o menu
}

void listar_clientes(void){
    
    FILE *arq;
    cliente client;
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);
        getchar();
        getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    system("clear"); // Limpa o terminal antes de mostrar os clientes cadastrados
    printf("\t\tClientes Cadastrados\n");
	printf("***************************************************************************\n");
	printf("#Codigo     Nome do Cliente                                    Telefone\n");
	printf("***************************************************************************\n");
	while (fread(&client, sizeof(cliente), 1, arq) > 0) {
		printf("%06d      %-50.50s %-14.14s\n", client.codigo_cliente,
                                                client.nome_cliente,
                                                client.telefone);
	}
	printf("***************************************************************************\n");
	fclose(arq); // Fecha o arquivo clientes.dat
    
    getchar();
    getchar();
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void consultar_cliente(void){
    
    FILE *arq; // Declarando uma variavel de arquivo
    cliente client;
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);
        getchar();
        getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
}
