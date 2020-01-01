/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * compras.c: arquivo com o desenvolvimento dos prototipos das funções da biblio- *
 * teca compras.h                                                                 *
 *                                                                                *
 * Versão: 1.0                                                                    *
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
                                                             
#define NOT_CLIENT "Erro! Não há nenhum cliente cadastrado!" /* Mensagem a ser 
                                                                mostrada caso 
                                                                não haja nenhum
                                                                cliente cadastrado */

void cadastrar_compra(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq_cliente, *arq_compra;         // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    compra buy;       // Declarando uma estrutura do tipo compra
    data date;       // Declarando uma estrutura do tipo data
    int count;
    
    if((arq_compra = fopen(ARQ_COMPRA, "ab")) == NULL) {
        //system("cls");       // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo compras.dat!\n");
        getchar();          // Pausa a mensagem de erro no terminal
        clear_buffer();    // Limpa o buffer
        //system("cls");  // Limpa o terminal antes de voltar para o menu no Windows
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq_compra, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    buy.numero_compra = ftell(arq_compra) / sizeof(compra) + 1; /* Pega o número atual de 
                                                          * compras cadastradas em bytes
                                                          * divide pelo tamanho da estrutura 
                                                          * compra em bytes e soma + 1 */
//     system("cls");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras no Windows
    system("clear");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras
    fprintf(stdout, "********Nova Compra********\n");
	fprintf(stdout, "Número da compra: %d\n", buy.numero_compra); // Mostra o Número da compra que será cadastrada
	fprintf(stdout, "Código do cliente: ");
    scanf("%d", &buy.codigo_cliente);
    
    if((arq_cliente = fopen(ARQ_CLIENTE, "rb")) == NULL) {
//         system("cls");      // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não nenhum cliente cadastrado!\n");
        getchar();          // Pausa a mensagem de erro no terminal
        clear_buffer();    // Limpa o buffer
//         system("cls"); // Limpa o terminal antes de voltar para o menu
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    
    while (fread(&client, sizeof(cliente), 1, arq_cliente) > 0){
        if(client.codigo_cliente == buy.codigo_cliente){
            printf("\n%s\n\n", client.nome_cliente);
            printf("Data da compra\n");
            printf("--------------\n");
            printf("Dia: ");
            scanf("%d", &buy.dt_compra.dia);
            printf("Mês: ");
            scanf("%d", &buy.dt_compra.mes);
            printf("Ano: ");
            scanf("%d", &buy.dt_compra.ano);
            printf("Valor da compra: R$ ");
            scanf("%f", &buy.valor);
            
            while(buy.valor <= 0){
                fprintf(stderr, "Valor inválido!\n");
                fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                printf("\nValor da compra: R$ ");
                scanf("%f", &buy.valor); 
            }
            
            fwrite(&buy, sizeof(compra), 1, arq_compra);
            fclose(arq_compra);             // Fecha o arquivo compras.dat
            //  system("cls");         // Limpa o prompt após o termino do cadastrado da compra no Windows
            system("clear");      // Limpa o terminal após o termino do cadastrado da compra
            puts(BUY_SUCESS);    // Mostra a mensagem que foi definida em BUY_SUCESS
            getchar();         /* Pausa a mensagem que está definida em
                                * BUY_SUCESS no terminal */
            clear_buffer();     // Limpa o buffer
        //  system("cls");  // Limpa o terminal antes de voltar para o menu
            system("clear"); // Limpa o terminal antes de voltar para o menu
//             menu();
        }
    }
    if(client.codigo_cliente != buy.codigo_cliente){
            system("clear");
            printf("Não existe nenhum cliente com esse código\n");
            printf("Compra interrompida!\n");
//             fclose(arq_cliente);
            getchar();
            clear_buffer();
//             menu();
           system("clear");
    }
    
    fclose(arq_cliente);
    
}

//
void listar_compras_data(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;         // Declarando uma variavel de arquivo
    compra buy;       // Declarando uma estrutura do tipo compra
    data date;       // Declarando uma estrutura do tipo data
    cliente client; //  Declarando uma estrutura do tipo cliente
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
//      system("cls");          // Limpa o terminal ao entrar aqui
        system("clear");       // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);        // Mostra a mensagem que foi definida em NOT_BUY
        getchar();           /* Pausa a mensagem que está definida em
                              * NOT_BUY no terminal */
        clear_buffer();    // Limpa o buffer
//      system("cls");    // Limpa o terminal antes de voltar para o menu
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
//  system("cls");
    system("clear");
    fprintf(stdout, "********Consultar Compra por Data********\n");
    fprintf(stdout, "Digite a data:\n");
    fprintf(stdout, " Dia: ");
    scanf("%d", &date.dia);
    fprintf(stdout, "Mês: ");
    scanf("%d", &date.mes);
    fprintf(stdout, "Ano: ");
    scanf("%d", &date.ano);
    //datas_iguais(date, dtcompra); /* O QUE FAZER AQUI? */

    /* CONTEUDO COM AS COMPRAS CADASTRADAS
    system("clear"); // Limpa o terminal antes de mostrar os clientes cadastrados
    fprintf(stdout, "\t\t\tCompras Cadastrados\n");
	fprintf(stdout, "*****************************************************************************\n");
	fprintf(stdout, "#Número da compra     Código do Cliente           Valor              Data\n");
	fprintf(stdout, "*****************************************************************************\n");
	while (fread(&buy, sizeof(compra), 1, arq) > 0) {
		fprintf(stdout, "%06d                %06d                      %.2f            %02d/%02d/%02d\n",
                buy.numero_compra, buy.codigo_cliente, buy.valor, buy.dt_compra.dia,buy.dt_compra.mes, 
                buy.dt_compra.ano);
	}
	fprintf(stdout, "*****************************************************************************\n");
	fclose(arq);            // Fecha o arquivo compras.dat
    */
    getchar();            // Pausa o arquivo de cadastros 
//                            * no terminal para que o usuario
//                            * possa ver as compras cadastradas 
    clear_buffer();    // Limpa o buffer
    system("clear");  // Limpa o terminal antes de voltar para o menu
    
    
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    clear_buffer();     // Limpa o buffer
//  system("cls");  // Limpa o terminal antes de voltar para o menu
    system("clear");  // Limpa o terminal antes de voltar para o menu

}


bool datas_iguais(data date, data dt_compra){ // DESENVOLVER ESSA FUNÇÃO
    
    bool TorF = true;
    
    if(date.dia == dt_compra.dia && date.mes == dt_compra.mes && date.ano == dt_compra.ano){
        return TorF;
    }
    else{
        return TorF = false;
    }
    
}

void listar_compras_cliente(void){ // ARRUMAR ESSA FUNÇÃO
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;         // Declarando uma variavel de arquivo
    compra buy;       // Declarando uma estrutura do tipo compra
    
    int cod_cliente;
    int count;
    
    system("clear");
    fprintf(stdout, "********Consultar Compra por Cliente********\n");
    fprintf(stdout, "Digite o código do cliente: ");
    scanf("%d", &cod_cliente);
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);       // Mostra a mensagem que foi definida em NOT_BUY
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_BUY no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    system("clear");
	fprintf(stdout, "*******************************************************************************\n");
	fprintf(stdout, "#Número da compra     Código do Cliente           Valor              Data\n");
	fprintf(stdout, "*******************************************************************************\n");
    // Lê o arquivo e busca pelo nome digitado
    count = 0;
    while(fread(&buy, sizeof(compra), 1, arq) > 0){
        if((buy.codigo_cliente == cod_cliente) != 0){
            fprintf(stdout, "%06d                %06d                      %.2f\
             %02d/%02d/%02d\n", buy.numero_compra, buy.codigo_cliente, buy.valor,
                                buy.dt_compra.dia,buy.dt_compra.mes, buy.dt_compra.ano);
            
            count++;
        }
    }
    fprintf(stdout, "*******************************************************************************\n");
    
    if(count == 0){
        system("clear");
        fprintf(stdout, "ERRO! Não há nenhuma compra realizada por esse cliente\n");
    }
    
    fclose(arq);            // Fecha o arquivo compras.dat
    
    getchar();            /* Pausa o arquivo de cadastros 
                           * no terminal para que o usuario
                           * possa ver as compras cadastradas */
    clear_buffer();    // Limpa o buffer
    system("clear");  // Limpa o terminal antes de voltar para o menu
    
}
