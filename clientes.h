/* cliente.h */

#ifndef _CLIENTE_H
#define _CLIENTE_H

/* Nome do arquivo aonde os clientes são cadastrados */
#define ARQ_CLIENTE "clientes.dat"

/* Estrutura que representa um cliente */
typedef struct {
	int codigo_cliente;
	char nome_cliente[51];
	char telefone[15];
} cliente;

/* função que cadastra um novo cliente no arquivo */
void cadastrar_cliente(void);

/* função que exibe uma listagem no formato de tabela
 * mostrando o código, nome e telefone de todos os
 * clientes cadastrados */
void listar_clientes(void);

/* função que consulta os clientes por nome */
void consultar_cliente(void);

#endif
