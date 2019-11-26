/********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                        *
 *                                                                              *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de         *
 * departamentos do Berg                                                        *
 *                                                                              *
 * clientes.c: arquivo principal da aplicação Lojinha_do_Berg                   *
 *                                                                              *
 * Versão: 0.1                                                                  *
 *                                                                              *
 * Desenvolvidores: Gustavo S. Bacagine	<gustavobacagine@gmail.com>             *
 * 		  			Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>  *
 *                                                                              *
 * Data: 21/11/2019                                                             *
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>    // Biblioteca usada para o system("clear")
#include "clientes.h" /* --> Biblioteca com os 
                         prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                         prototipos das funções das compras */

void cadastrar_cliente(){
    
    FILE *arq;
    cliente client;
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        return;
    }
    fseek(arq, 0, SEEK_END);
    client.codigo_cliente = ftell(arq) / sizeof(cliente) + 1;
    printf("\n********Novo Cliente********\n");
	printf("Codigo do cliente: %d\n", client.codigo_cliente);
	printf("Nome do cliente: ");
    scanf(" %50[^\n]", client.nome_cliente);
    printf("Numero de telofone: ");
	scanf(" %14[^\n]", client.telefone);
	
    fwrite(&client, sizeof(cliente), 1, arq);
	fclose(arq);
    
	printf("Cliente cadastrado com sucesso!\n");
}

void listar_clientes(){
    
    FILE *arq;
    cliente client;
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        fprintf(stderr, "Erro! Não ha nenhum cliente cadastrado!\n");
        return;
    }
    
    printf("\n\n\t\tClientes Cadastrados\n");
	printf("************************************************\n");
	printf("#Codigo Nome do Cliente              Telefone\n");
	printf("************************************************\n");
	while (fread(&client, sizeof(cliente), 1, arq) > 0) {
		printf("%d %s %s\n", client.codigo_cliente, /* Consertar print 
                                                       mais tarde */
                             client.nome_cliente, 
                             client.telefone);
	}
	printf("************************************************\n");
	fclose(arq);
}
