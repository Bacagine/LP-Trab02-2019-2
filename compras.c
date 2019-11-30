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
 * Desenvolvidores: Gustavo S. Bacagine       <gustavobacagine@gmail.com>         *
 * 		  			Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 21/11/2019                                                     *
 * Data da última modificação: 30/11/2019                                         * **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>         // Biblioteca para poder usar a função system("clear")
#include "clear_buffer.h"  // Biblioteca para poder usar a função clear_buffer()
#include "clientes.h" /* --> Biblioteca com os 
                         prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                         prototipos das funções das compras */

#define BUY_SUCESS "Compra cadastrada com sucesso!" /* Mensagem a ser 
                                                       mostrada após o 
                                                       cadastro da compra */

#define NOT_BUY "Erro! Não ha nenhuma compra cadastrada!" /* Mensagem a ser 
                                                             mostrada caso 
                                                             não haja nenhuma
                                                             compra cadastrada */
FILE *arq;   // Declarando uma variavel de arquivo
compra buy; //  Declarando uma estrutura do tipo compra
data date; //  Declarando uma estrutura do tipo data

void cadastrar_compra(void){
        
    if((arq = fopen(ARQ_COMPRA, "ab")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo compras.dat!\n");
        clear_buffer();
        getchar();
//         getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END);
    
    buy.numero_compra = ftell(arq) / sizeof(compra) + 1; // Pega o número atual de compras cadastradas e soma + 1
    system("clear");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras
    fprintf(stdout, "********Nova Compra********\n");
	fprintf(stdout, "Número da compra: %d\n", buy.numero_compra); // Mostra o Número da compra que será cadastrada
	fprintf(stdout, "Codigo do cliente: ");   
    scanf("%d", &buy.codigo_cliente);
    fprintf(stdout, "Valor da compra: ");
	scanf("%f", &buy.valor);
    fprintf(stdout, "Data: ");
    scanf("%d", &buy.dt_compra);
    
    /*
    printf("Data\n");
    printf("Dia:");
    scanf("%d", &date.dia);
    printf("Mes: ");
    scanf("%d", &date.mes);
    printf("Ano: ");
    scanf("%d", &date.ano);
	*/
    
    fwrite(&buy, sizeof(compra), 1, arq);
	fclose(arq); // Fecha o arquivo compras.dat
    
    system("clear"); // Limpa o terminal após o termino do cadastrado da compra
	puts(BUY_SUCESS);
    clear_buffer();
    getchar();
//     getchar();
    system("clear");
}

void listar_compras_data(void){
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
        system("clear");
        puts(NOT_BUY);
        clear_buffer();
        getchar();
//         getchar();
        system("clear");
        return;
    }
    
    fprintf(stdout, "Digite a data da compra: ");
    scanf("%s", &buy.dt_compra);
    /*
    datas_iguais(); // Preciso usar essa função para \
                       encontrar as datas dentro do arquivo
    */
    /* ISSO ESTÁ ERRADO
    system("clear");
    printf("\t\tCompras Cadastrados\n");
	printf("**********************************************************\n");
	printf("#Numero     Codigo do cliente     Valor            Data\n");
	printf("**********************************************************\n");
	while (fread(&buy, sizeof(compra), 1, arq) > 0) {
		printf("%06d      %06d                %.2f           %d\n", buy.numero_compra,
                                                buy.codigo_cliente, 
                                                buy.valor,
                                                buy.dt_compra);
	}
	printf("**********************************************************\n");
	fclose(arq); // Fecha o arquivo compras.dat

    */
    
    clear_buffer();
    getchar();
//     getchar();
    system("clear"); // Limpa o terminal antes de voltar para o menu

}

/*
bool datas_iguais(data, data){
    // NÃO COMO FAZER ISSO AQUI
}
*/

void listar_compras_cliente(void){
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
        system("clear"); // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);
        clear_buffer();
        getchar();
//         getchar();
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    
    
    fclose(arq);
    
}
