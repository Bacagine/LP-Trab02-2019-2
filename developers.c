/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * developers.c: arquivo contendo o nome e email do desenvolvedores da aplicação  *
 *                                                                                *
 * Versão: 1.0                                                                    *
 *                                                                                *
 * Desenvolvidores: Gustavo Bacagine          <gustavobacagine@gmail.com>         *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 02/12/2019                                                     *
 * Data da última modificação: 26/03/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "clear_buffer.h" /* --> Biblioteca para poder usar 
                                 a função clear_buffer() */
#include "developers.h" /* --> Biblioteca para poder usar a função
                              developers() */ 

void developers(void){
    setlocale(LC_ALL, "Portuguese");

    system("clear");
    
    fprintf(stdout, "*************************DESENVOLVEDORES*************************\n");    
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* FATEC        -          CARAPICUÍBA            -         2019 *\n");
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *\n");
    fprintf(stdout, "* Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *\n");
    fprintf(stdout, "* Caio Elias Emerick Regino <caioregino.147@gmail.com>          *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Programa desenvolvimo como 2º Trabalho de ADSM para a materia *\n");
    fprintf(stdout, "* de Línguagem de Programação (Profº Ciro Cirne Trindade)       *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
    
    getchar();         /* Pausa a mensagem que está definida em
                        * BUY_SUCESS no terminal */
    clear_buffer();
    system("clear"); // Limpa o terminal antes de voltar para o menu
}
