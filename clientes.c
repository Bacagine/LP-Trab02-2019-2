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
 * Data da última modificação: 30/11/2019                                          *
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>         // Biblioteca para poder usar a função system("clear")
#include <locale.h>        // Biblioteca para poder usar a função setlocale \
                              usada para colocar acentuação nas palavras
#include "clear_buffer.h"  /* --> Biblioteca para poder usar 
                                  a função clear_buffer() */
#include "clientes.h"     /* --> Biblioteca com os 
                                 prototipos das funções do cliente */
#include "compras.h"    /* --> Biblioteca com os 
                               prototipos das funções das compras */

#define CLIENT_SUCESS "Cliente cadastrado com sucesso!" /* Mensagem a ser 
                                                           mostrada após o 
                                                           cadasto do cliente */

#define NOT_CLIENT "Erro! Não há nenhum cliente cadastrado!" /* Mensagem a ser 
                                                                mostrada caso 
                                                                não haja nenhum
                                                                cliente cadastrado */
FILE *arq;       // Declarando uma variavel de arquivo
cliente client; //  Declarando uma estrutura do tipo cliente

void cadastrar_cliente(void){
    
    setlocale(LC_ALL, "Portuguese");
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        clear_buffer(); // Limpa o buffer
        getchar();
//         getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END);  // desloca o indicador de posição para o final do arquivo
    
    client.codigo_cliente = ftell(arq) / sizeof(cliente) + 1; // Pega o número atual de clientes cadastrados e soma + 1
    system("clear"); // Limpa o terminal quando o usuario escolhe a opção Cadastrar Clientes
    fprintf(stdout, "********Novo Cliente********\n");
	fprintf(stdout, "Codigo do cliente: %d\n", client.codigo_cliente); // Mostra o código do cliente que será cadastrado
	fprintf(stdout, "Nome do cliente: ");
    scanf(" %50[^\n]", client.nome_cliente);
    fprintf(stdout, "Número de telefone: ");
	scanf(" %14[^\n]", client.telefone);
    
    /* TENTATIVA DE VALIDAR TELEFONE
	if(client.telefone > 15 || client.telefone < 12){
        fprintf(stderr, "Erro! Telefone invalido!");
        printf("Numero de telefone: ");
        scanf(" %14[^\n]", client.telefone);
    }
    */
    
    fwrite(&client, sizeof(cliente), 1, arq);
	fclose(arq); // Fecha o arquivo clientes.dat
    
    system("clear");
	puts(CLIENT_SUCESS); // Printa no terminal a mensagem: "Cliente cadastrado com sucesso!"
    clear_buffer(); // Limpa o buffer
    getchar();
//     getchar();
    system("clear");
}

void listar_clientes(void){
    
    setlocale(LC_ALL, "Portuguese");
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);
        clear_buffer(); // Limpa o buffer
        getchar();
//         getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }

    system("clear"); // Limpa o terminal antes de mostrar os clientes cadastrados
    fprintf(stdout, "\t\t\tClientes Cadastrados\n");
	fprintf(stdout, "*****************************************************************************\n");
	fprintf(stdout, "#Código     Nome do Cliente                                    Telefone\n");
	fprintf(stdout, "*****************************************************************************\n");
	while (fread(&client, sizeof(cliente), 1, arq) > 0) {
		fprintf(stdout, "%06d      %-50.50s %-14.14s\n", client.codigo_cliente,
                                                client.nome_cliente,
                                                client.telefone);
	}
	fprintf(stdout, "*****************************************************************************\n");
	fclose(arq); // Fecha o arquivo clientes.dat
    
    clear_buffer(); // Limpa o buffer
    getchar();
//     getchar();
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void consultar_cliente(void){
    
    setlocale(LC_ALL, "Portuguese");
    
    char pesq_nome[51], pesq_nome_lido[51];
    
    system("clear");
    
    fprintf(stdout, "********Consultar Cliente********\n");
    fprintf(stdout, "Digite o nome do cliente: ");
    /* Provavaelmente esse scanf deve estar errado,
     * mas eu vou deixar ele assim mesmo por enquanto */
    scanf("%s", client.nome_cliente);
    
/*    
    for(int i = 0; i < 50; i++){
        if(pesq_nome[i] == ' '){
            pesq_nome[i] = '_';
        }
    }
*/    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);
        clear_buffer(); // Limpa o buffer
        getchar();
//         getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
/*    fseek(arq, 0L, SEEK_END);
    int sz = ftell(arq);
    fseek(arq, 0L, SEEK_SET);*/

// TENTATIVA DE BUSCAR CLIENTE    
/*    
    while(!feof(ARQ_CLIENTE)){
        fcanf("%s %s\n", pesq_nome, pesq_nome_lido);
    }    
*/    

    fclose(arq);

    clear_buffer(); // Limpa o buffer
    getchar();
//     getchar();
    system("clear"); // Limpa o terminal antes de voltar para o menu
    
}
