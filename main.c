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
 * 		  			Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 21/11/2019                                                     *
 * Data da última modificação: 30/11/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>         // Biblioteca usada para o system("clear")
#include "clear_buffer.h"  // Biblioteca para poder usar a função clear_buffer()
#include "clientes.h" /* --> Biblioteca com os 
                         prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                         prototipos das funções das compras */

#define ERROR "Erro! Opcao invalida!" /* Mensagem de erro caso 
                                         o usuario digite uma 
                                         opção inválida */

int main(void){
	
    int op; // Opção a ser escolhida pelo usuário
    
    system("clear"); // Limpa o terminal ao executar o programa
    do{
        fprintf(stdout, "*************************MENU*************************\n");
        fprintf(stdout, "* 1) Cadastrar Cliente                               *\n");
        fprintf(stdout, "* 2) Listar Clientes                                 *\n");
        fprintf(stdout, "* 3) Consultar Clientes         (em fase de testes)  *\n");
        fprintf(stdout, "* 4) Cadastrar Compras          (em fase de testes)  *\n");
        fprintf(stdout, "* 5) Listar Compras por Data    (em andamento)       *\n");
        fprintf(stdout, "* 6) Listar Compras por Cliente (em andamento)       *\n");
        fprintf(stdout, "* 0) Sair                                            *\n");
        fprintf(stdout, "******************************************************\n");
        fprintf(stdout, ">> ");
        scanf("%d", &op);
        
        switch(op){
			case 1:
                cadastrar_cliente();
                break;
            case 2:
                listar_clientes();
                break;
             case 3:
                 consultar_cliente();
                 break;
            case 4:
                cadastrar_compra();
                break;
            case 5:
                listar_compras_data();
                break;
            case 6:
                listar_compras_cliente();
                break;
            case 0:
                break;
            default:
                system("clear"); // Limpa o terminal ao entrar aqui
                puts(ERROR);    // Mostra uma mensagem de erro para o usuário
                clear_buffer();
                getchar();     // Semelhante ao system("pause"); do Windows
                system("clear"); // Limpa o terminal antes de voltar para o menu
		}
		
	} while(op != 0);
	
	return 0;
}
