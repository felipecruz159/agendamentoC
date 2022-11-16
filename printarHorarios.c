#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * PRINTAR HORAS
 * @return int horaEscolhida
*/
int printarHorarios(){

    int hora[6][4], i = 0, j = 0, contador = 1;

    while (contador <= 24) {
        if (contador != 24){
            hora[i][j] = contador;
        }
        else{
            hora[i][j] = 0;
        }
        contador++;
        i++;

        if ( i == 6 ){
            j++;
            i = 0;
        }
    }

    printf("\nEscolha uma opcao:\n");
    contador = 1;
    for ( i = 0; i < 6; i++ ){
        for ( j = 0; j < 4; j++ ){            
            if ( j == 0 ){
                if ( contador < 10 ){
                    printf(" %d - 0%dh", contador+0, hora[i][j]);
                }
                else {
                    printf("%d - %dh", contador+0, hora[i][j]);
                }
            }
            else if ( j == 1 ){
                if ( contador+6 < 10 ){
                    printf(" %d - 0%dh", contador+6, hora[i][j]);
                }
                else {
                    printf("%d - %dh", contador+6, hora[i][j]);
                }
            }
            else if (j == 2){
                printf("%d - %dh", contador+12, hora[i][j]); 
            }
            else {
                if (contador+18 == 24){
                    printf("%d - 0%dh", contador+18, hora[i][j]);
                }
                else {
                    printf("%d - %dh", contador+18, hora[i][j]); 
                }
            }
            printf("\t");       
        }
        contador++;
        printf("\n");
    }

    int horaEscolhida;
    do{
        scanf("%d", &horaEscolhida);
    } while (horaEscolhida < 1 || horaEscolhida > 24);

    if (horaEscolhida == 24){
        horaEscolhida = 0;
    }

    return horaEscolhida;
}
    
