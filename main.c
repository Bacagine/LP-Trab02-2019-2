/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * main.c: arquivo principal da aplicação Lojinha_do_Berg                         *
 *                                                                                *
 * Versão: 0.1                                                                    *
 *                                                                                *
 * Desenvolvidores: Gustavo S. Bacagine       <gustavobacagine@gmail.com>         *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 21/11/2019                                                     *
 * Data da última modificação: 01/12/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>          // Biblioteca usada para o system("clear")
#include <locale.h>         // Biblioteca para poder usar a função setlocale
#include "clear_buffer.h"  /* --> Biblioteca para poder usar 
                                  a função clear_buffer() */
#include "clientes.h"    /* --> Biblioteca com os 
                                prototipos das funções do cliente */
#include "compras.h"   /* --> Biblioteca com os 
                             prototipos das funções das compras */

#define ERROR "Erro! Opção inválida!" /* Mensagem de erro caso 
                                         o usuario digite uma 
                                         opção inválida */

int main(void){

    int op; // Opção a ser escolhida pelo usuário
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    system("clear"); // Limpa o terminal ao executar o programa
    do{
        printf("*************************MENU*************************\n");
        printf("* 1) Cadastrar Cliente                               *\n");
        printf("* 2) Listar Clientes                                 *\n");
        printf("* 3) Consultar Clientes         (em fase de testes)  *\n");
        printf("* 4) Cadastrar Compras          (em fase de testes)  *\n");
        printf("* 5) Listar Compras por Data    (em andamento)       *\n");
        printf("* 6) Listar Compras por Cliente (em andamento)       *\n");
        printf("* 0) Sair                                            *\n");
        printf("******************************************************\n");
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
            case 0:
                break;
            default:
                system("clear");     // Limpa o terminal ao entrar aqui
                puts(ERROR);        // Mostra uma mensagem de erro para o usuário
                clear_buffer();    // Limpa o buffer
                getchar();        // Semelhante ao system("pause"); do Windows
                system("clear"); // Limpa o terminal antes de voltar para o menu
        }

    } while(op != 0);
    
    return 0;
}
