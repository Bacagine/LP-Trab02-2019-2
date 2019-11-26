/**************************************************************************
 * fonte.c: *
 *                                                                        *
 *                                                                        *
 * Programa criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com> *
 *                                                                        *
 * Data: dd/mm/aaaa                                                       *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>    // Biblioteca usada para o system("clear")
#include "clientes.h" /* --> Biblioteca com os 
                         prototipos das funções do cliente */
#include "compras.h" /* --> Biblioteca com os 
                         prototipos das funções das compras */

int main(void){
	
    int op;
    
    system("clear"); // Limpa o terminal ao executar o programa
    do{	
        printf("*****************MENU*****************\n");
        printf("* 1) Cadastrar Cliente               *\n");
        printf("* 2) Listar Clientes                 *\n");
        printf("* 3) Consultar Clientes              *\n");
        printf("* 4) Cadastrar Compras               *\n");
        printf("* 5) Listar Compras por Data         *\n");
        printf("* 6) Listar Compras por Cliente      *\n");
        printf("* 0) Sair                            *\n");
        printf("**************************************\n");
        scanf("%d", &op);
        
        switch(op){
			case 1:
                cadastrar_cliente();
                break;
            case 2:
                listar_clientes();
                break;
/*            case 3:
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
                break; */
            case 7:
                break;
            default:
                printf("\nErro! Opcao invalida!\n");
		}
		
	} while(op != 0);
	
	return 0;
}
