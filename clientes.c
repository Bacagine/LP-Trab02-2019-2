/***********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                           *
 *                                                                                 *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de            *
 * departamentos do Berg                                                           *
 *                                                                                 *
 * clientes.c: arquivo com o desenvolvimento dos prototipos das funções da biblio- *
 * teca clientes.h                                                                 *
 *                                                                                 *
 * Versão: 1.0                                                                     *
 *                                                                                 *
 * Desenvolvidores: Gustavo Bacagine          <gustavobacagine@gmail.com>          *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>  *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>           *
 *                                                                                 *
 * Data de inicio: 21/11/2019                                                      *
 * Data da última modificação: 02/12/2019                                          *
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>            // Biblioteca para poder usar a função system("clear")
#include <locale.h>           // Biblioteca para poder usar a função setlocale()
#include <string.h>          // Biblioteca para poder usar a função strstr()
#include "clear_buffer.h"   /* --> Biblioteca para poder usar 
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

void cadastrar_cliente(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        system("clear");     // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        getchar();         // Pausa a mensagem de erro no terminal
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    client.codigo_cliente = ftell(arq) / sizeof(cliente) + 1; /* Pega o número atual de 
                                                               * clientes cadastradas em bytes
                                                               * divide pelo tamanho da estrutura 
                                                               * clientes em bytes e soma + 1 */
    system("clear"); // Limpa o terminal quando o usuario escolhe a opção Cadastrar Clientes
    fprintf(stdout, "********Novo Cliente********\n");
	fprintf(stdout, "Codigo do cliente: %d\n", client.codigo_cliente); // Mostra o código do cliente que será cadastrado
	fprintf(stdout, "Nome do cliente: ");
    scanf(" %50[^\n]", client.nome_cliente);
    fprintf(stdout, "Número de telefone: ");
	scanf(" %14[^\n]", client.telefone);
    
    fwrite(&client, sizeof(cliente), 1, arq);
	fclose(arq);            // Fecha o arquivo clientes.dat
    
    system("clear");      // Limpa o terminal ao termino do cadastro do cliente
	puts(CLIENT_SUCESS); // Mostra a mensagem que foi definida em CLIENT_SUCESS
    getchar();          /* Pausa a mensagem que está definida em
                         * CLIENT_SUCESS no terminal */
    clear_buffer();   // Limpa o buffer
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void listar_clientes(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_CLIENT no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }

    /* CONTEUDO COM OS CLIENTES CADASTRADOS */
    system("clear"); // Limpa o terminal antes de mostrar os clientes cadastrados
    fprintf(stdout, "\t\t\tClientes Cadastrados\n");
	fprintf(stdout, "*****************************************************************************\n");
	fprintf(stdout, "#Código     Nome do Cliente                                     Telefone\n");
	fprintf(stdout, "*****************************************************************************\n");
	while (fread(&client, sizeof(cliente), 1, arq) > 0) {
		fprintf(stdout, "%06d      %-50.50s %+14.14s\n", client.codigo_cliente,
                                                         client.nome_cliente,
                                                         client.telefone);
	}
	fprintf(stdout, "*****************************************************************************\n");
	fclose(arq);            // Fecha o arquivo clientes.dat
    
    getchar();            /* Pausa o arquivo de cadastros 
                           * no terminal para que o usuario
                           * possa ver as compras cadastradas */
    clear_buffer();    // Limpa o buffer
    system("clear");  // Limpa o terminal antes de voltar para o menu
}

void consultar_cliente(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    int count;
    
    char nome_cliente[51];
    
    system("clear"); // Limpa o terminal ao entrar aqui
    
    fprintf(stdout, "********Consultar Cliente********\n");
    fprintf(stdout, "Digite o nome do cliente: ");
    scanf(" %50[^\n]", nome_cliente);
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_CLIENT no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    system("clear"); // Limpa o terminal
    fprintf(stdout, "*****************************************************************************\n");
    fprintf(stdout, "#Código     Nome do Cliente                                     Telefone\n");
    fprintf(stdout, "*****************************************************************************\n");
    // Busca o nome digitado no arquivo clientes.dat
    count = 0;
    while(fread(&client, sizeof(cliente), 1, arq) > 0){
        if(strstr(client.nome_cliente, nome_cliente) != NULL){ //Compara o nome digitado com os que existem no arquivo
            //for(i = 0; nome_cliente[i] == ' '; i++){    
                fprintf(stdout, "%06d      %-50.50s %+14.14s\n", client.codigo_cliente,
                                                                 client.nome_cliente,
                                                                 client.telefone);
                count++;
            //}
        }
    }
    fprintf(stdout, "*****************************************************************************\n");
    
    // MENSAGEM DE ERRO CASO NÃO TENHA UM CLIENTE COM O NOME DIGITADO
    if(count == 0){
        system("clear");       // Limpa o terminal ao entrar aqui
        fprintf(stdout, "ERRO! Não há nenhum cliente cadastrado com esse nome\n");
    }
    
    fclose(arq);           // Fecha o arquivo clientes.dat
    
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    clear_buffer();   // Limpa o buffer 
    system("clear"); // Limpa o terminal antes de voltar para o menu
    
}
