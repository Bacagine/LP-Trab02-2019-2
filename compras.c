/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * compras.c: arquivo com o desenvolvimento dos prototipos das funções da biblio- *
 * teca compras.h                                                                 *
 *                                                                                *
 * Versão: 0.1                                                                    *
 *                                                                                *
 * Desenvolvidores: Gustavo Bacagine          <gustavobacagine@gmail.com>         *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 21/11/2019                                                     *
 * Data da última modificação: 02/12/2019                                         * **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>          // Biblioteca para poder usar a função system("clear")
#include <locale.h>         // Biblioteca para poder usar a função setlocale
#include "clear_buffer.h"  /* --> Biblioteca para poder usar 
                                  a função clear_buffer() */
#include "clientes.h"    /* --> Biblioteca com os 
                                prototipos das funções do cliente */
#include "compras.h"   /* --> Biblioteca com os 
                              prototipos das funções das compras */

#define BUY_SUCESS "Compra cadastrada com sucesso!" /* Mensagem a ser 
                                                       mostrada após o 
                                                       cadastro da compra */

#define NOT_BUY "Erro! Não há nenhuma compra cadastrada!" /* Mensagem a ser 
                                                             mostrada caso 
                                                             não haja nenhuma
                                                             compra cadastrada */
FILE *arq;         // Declarando uma variavel de arquivo
compra buy;       // Declarando uma estrutura do tipo compra
data date;       // Declarando uma estrutura do tipo data
cliente client; //  Declarando uma estrutura do tipo cliente

void cadastrar_compra(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    if((arq = fopen(ARQ_COMPRA, "ab")) == NULL) {
        //system("cls");       // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo compras.dat!\n");
        clear_buffer();     // Limpa o buffer
        getchar();         // Pausa a mensagem de erro no terminal
        //system("cls");  // Limpa o terminal antes de voltar para o menu no Windows
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    buy.numero_compra = ftell(arq) / sizeof(compra) + 1; // Pega o número atual de compras cadastradas e soma + 1
//     system("cls");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras no Windows
    system("clear");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras
    fprintf(stdout, "********Nova Compra********\n");
	fprintf(stdout, "Número da compra: %d\n", buy.numero_compra); // Mostra o Número da compra que será cadastrada
	fprintf(stdout, "Código do cliente: ");
    scanf("%d", &buy.codigo_cliente);
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
//         system("cls");      // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo compras.dat!\n");
        clear_buffer();     // Limpa o buffer
        getchar();         // Pausa a mensagem de erro no terminal
//         system("cls"); // Limpa o terminal antes de voltar para o menu
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    while (fread(&client, sizeof(cliente), 1, arq) > 0) {
        if(buy.codigo_cliente == client.codigo_cliente){
            /* NÃO SEI O QUE FAZER AQUI */
        }
	}
    
    fprintf(stdout, "Valor da compra: ");
	scanf("%f", &buy.valor);
    printf("Data\n");
    printf("Dia:");
    scanf("%d", &buy.dt_compra.dia);
    printf("Mês: ");
    scanf("%d", &buy.dt_compra.mes);
    printf("Ano: ");
    scanf("%d", &buy.dt_compra.ano);
    
    fwrite(&buy, sizeof(compra), 1, arq);
	fclose(arq);             // Fecha o arquivo compras.dat
    
//  system("cls");         // Limpa o prompt após o termino do cadastrado da compra no Windows
    system("clear");      // Limpa o terminal após o termino do cadastrado da compra
	puts(BUY_SUCESS);    // Mostra a mensagem que foi definida em BUY_SUCESS
    clear_buffer();     // Limpa o buffer
    getchar();         /* Pausa a mensagem que está definida em
                        * BUY_SUCESS no terminal */
//  system("cls");  // Limpa o terminal antes de voltar para o menu
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void listar_compras_data(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
//      system("cls");          // Limpa o terminal ao entrar aqui
        system("clear");       // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);        // Mostra a mensagem que foi definida em NOT_BUY
        clear_buffer();      // Limpa o buffer
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_BUY no terminal */
//      system("cls");    // Limpa o terminal antes de voltar para o menu
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
//  system("cls");
    system("clear");
    fprintf(stdout, "********Consultar Compra por Data********\n");
    fprintf(stdout, "Digite a data da compra: ");
    scanf("%d", &buy.dt_compra);
    /*
    datas_iguais(); // Preciso usar essa função para \
                       encontrar as datas dentro do arquivo
    */
    
    clear_buffer();       // Limpa o buffer
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
//  system("cls");  // Limpa o terminal antes de voltar para o menu
    system("clear");  // Limpa o terminal antes de voltar para o menu

}

/*
bool datas_iguais(data, data){ // DESENVOLVER ESSA FUNÇÃO
    // NÃO COMO FAZER ISSO AQUI
}
*/

void listar_compras_cliente(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    system("clear");
    fprintf(stdout, "********Consultar Compra por Cliente********\n");
    fprintf(stdout, "Digite o código do cliente: ");
    scanf("%d", &buy.codigo_cliente);
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);       // Mostra a mensagem que foi definida em NOT_BUY
        clear_buffer();     // Limpa o buffer
        getchar();         /* Pausa a mensagem que está definida em
                            * NOT_BUY no terminal */
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    // Lê o arquivo e busca pelo nome digitado
    while(fread(&buy, sizeof(compra), 1, arq) > 0){
        if(buy.codigo_cliente == client.codigo_cliente){
            /* Não sei o que fazer aqui */
        }
        else{
            fprintf(stdout, "ERRO! Não há nenhum cliente cadastrado com esse código");
        }
    }
    /* Tentativa de buscar cliente
    fprintf(stdout, "Digite o nome do cliente: ");
    scanf(" %50[^\n]", nome_cliente);
    fseek(arq, (nome_cliente - 1) * sizeof(cliente), SEEK_SET);
    fread(&client, sizeof(cliente), 1, arq)
    */
    
    fclose(arq);            // Fecha o arquivo compras.dat
    
    clear_buffer();       // Limpa o buffer
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    system("clear");  // Limpa o terminal antes de voltar para o menu
    
}
