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
 * Data da última modificação: 27/11/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>    // Biblioteca usada para o system("clear")
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
                getchar();     // Semelhante ao system("pause"); do Windows
                getchar();
                system("clear"); // Limpa o terminal antes de voltar para o menu
		}
		
	} while(op != 0);
	
	return 0;
}
