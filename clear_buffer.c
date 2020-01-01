/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2                          *
 *                                                                                *
 * Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de           *
 * departamentos do Berg                                                          *
 *                                                                                *
 * clear_buffer.c: arquivo com o desenvolvimento do prototipo da função           *
 * clear_buffer da biblioteca buffer.h                                            *
 *                                                                                *
 * OBS: Essa função não foi desenvolvida por nós. Percebi que muitos              *
 * programadores se utilizam dessa função e passamos a usa-lá em nosso programa   *
 *                                                                                *
 * Versão: 1.0                                                                    *
 *                                                                                *
 * Desenvolvidores: Gustavo Bacagine          <gustavobacagine@gmail.com>         *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Data de inicio: 30/11/2019                                                     *
 * Data da última modificação: 01/12/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include "clear_buffer.h"  /* --> Biblioteca para poder usar 
                                  a função clear_buffer() */

void clear_buffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
