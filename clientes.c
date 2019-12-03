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
FILE *arq;       // Declarando uma variavel de arquivo
cliente client; //  Declarando uma estrutura do tipo cliente

void cadastrar_cliente(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    int i;
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        system("clear");     // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        clear_buffer();    // Limpa o buffer
        getchar();        // Pausa a mensagem de erro no terminal
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
    
    /* VALIDAR O TELEFONE
    for(i = 0;client.telefone[i] != '\0'; i++);
    while (i > 14 || i < 12){
        fprintf(stderr, "Erro! Telefone invalido!\n");
        printf("Numero de telefone: ");
        scanf(" %14[^\n]", client.telefone);
        for(i = 0;client.telefone[i] != '\0'; i++);
    }
    */
    
    fwrite(&client, sizeof(cliente), 1, arq);
	fclose(arq);            // Fecha o arquivo clientes.dat
    
    system("clear");      // Limpa o terminal ao termino do cadastro do cliente
	puts(CLIENT_SUCESS); // Mostra a mensagem que foi definida em CLIENT_SUCESS
    clear_buffer();     // Limpa o buffer
    getchar();         /* Pausa a mensagem que está definida em
                        * CLIENT_SUCESS no terminal */
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void listar_clientes(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        clear_buffer();     // Limpa o buffer
        getchar();         /* Pausa a mensagem que está definida em
                            * NOT_CLIENT no terminal */
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
    
    clear_buffer();       // Limpa o buffer
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    system("clear");  // Limpa o terminal antes de voltar para o menu
}

void consultar_cliente(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
                        /* Não sei se isso é
                         * realmente necessário */
    char nome_cliente[51], linha[121];
    
    system("clear"); // Limpa o terminal ao entrar aqui
    
    fprintf(stdout, "********Consultar Cliente********\n");
    fprintf(stdout, "Digite o nome do cliente: ");
    scanf(" %50[^\n]", nome_cliente);
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        clear_buffer();     // Limpa o buffer
        getchar();         /* Pausa a mensagem que está definida em
                            * NOT_CLIENT no terminal */
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
 /* PROVAVELMENTE ISSO ESTÁ MUITO ERRADO MAIS EU NÃO SEI O QUE FAZER
  * VOU DEIXAR ASSIM POR ENQUANTO */
    // Busca o nome digitado no arquivo clientes.dat
    while (fread(&client, sizeof(cliente), 1, arq) > 0){
        while (fscanf(arq, " %120[^\n]", linha) > 0){ 
//         while (fgets(linha, 121, arq) != NULL){
//             if (strstr(linha, nome_cliente) != NULL){
            if (strstr(linha, nome_cliente) != NULL){
//                 fputs(linha, stdout);
                printf("%s\n", linha);
            }
            else{
                fprintf(stdout, "ERRO! Não há nenhum cliente cadastrado com esse nome");
            }
        }
        
	}
	
    fclose(arq);            // Fecha o arquivo clientes.dat
    
    clear_buffer();       // Limpa o buffer
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    system("clear");  // Limpa o terminal antes de voltar para o menu
    
}
