/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * main.c: arquivo principal da aplicação Lojinha_do_Berg                         *
 *                                                                                *
 * Versão: 1.0                                                                    *
 *                                                                                *
 * Desenvolvidores: Gustavo Bacagine          <gustavobacagine@gmail.com>         *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 21/11/2019                                                     *
 * Data da última modificação: 26/03/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "clear_buffer.h"  /* --> Biblioteca para poder usar 
                                  a função clear_buffer() */
#include "developers.h"  /* --> Biblioteca para poder usar a função
                                developers() */
#include "clientes.h"  /* --> Biblioteca com os 
                              prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                            prototipos das funções das compras */

#define ERROR "Erro! Opção inválida!" /* Mensagem de erro caso 
                                         o usuario digite uma 
                                         opção inválida */

int main(void){
    setlocale(LC_ALL, "Portuguese");
    
    int op; // Opção a ser escolhida pelo usuário
    
    system("clear"); // Limpa o terminal ao executar o programa
    do{
        printf("**********************MENU**********************\n");
        printf("* 1) Cadastrar Cliente                         *\n");
        printf("* 2) Listar Clientes                           *\n");
        printf("* 3) Consultar Clientes                        *\n");
        printf("* 4) Cadastrar Compras                         *\n");
        printf("* 5) Listar Compras por Data    (em andamento) *\n");
        printf("* 6) Listar Compras por Cliente                *\n");
        printf("* 7) Desenvolvedores                           *\n");
        printf("* 8) Sair                                      *\n");
        printf("************************************************\n");
        printf(">> ");
        scanf("%d", &op);
        
        switch(op){
            case 1:
                cadastrar_cliente();                // Cadastra um cliente
                break;
            case 2:
                listar_clientes();                // Lista os clientes cadastrados
                break;
             case 3:
                 consultar_cliente();           // Consulta os clientes cadastrados
                 break;
            case 4:
                cadastrar_compra();           // Cadastra uma compra
                break;
            case 5:
                listar_compras_data();      // Lista as compras cadastradas pela data
                break;
            case 6:
                listar_compras_cliente(); // Lista as compras cadastradas por cliente
                break;
            case 7:
                developers();
                break;
            case 8:
                system("clear");
                puts("Saindo...");
                printf("\n\n");
                break;
            default:
                system("clear");      // Limpa o terminal ao entrar aqui
                puts(ERROR);         // Mostra uma mensagem de erro para o usuário
                getchar();          // Semelhante ao system("pause"); do Windows
                clear_buffer();
                system("clear"); // Limpa o terminal antes de voltar para o menu
        }

    } while(op != 8);         // Sai do programa quando o usuario digitar 8
    
    return 0;
}
