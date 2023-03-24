//
// Created by Valentin Serban on 23.03.2023.
//

#include "useful_functions.h"
#include <stdio.h>
#include <string.h>

void afisare_medicamente(struct medicament_repo* m) {
    int num = m -> numar_medicamente;
    printf("COD_UNIC     |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre(m -> medicamente[i].cod_unic);
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cod_unic);
        var /= 2;
        if(var > 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cod_unic)) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cod_unic);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var + 1; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cod_unic);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%d", m -> medicamente[i].cod_unic);
    }
    printf("\n");

    printf("NUME         |");
    for(int i = 0; i < num; ++i){
        printf("%s", m -> medicamente[i].nume_medicament);
        printf("|");
    }
    printf("\n");

    printf("CONCENTRATIE |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre((int)m -> medicamente[i].concentratie) - 1;
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre((int)m -> medicamente[i].concentratie) - 3;
        var /= 2;
        if(var >= 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre((int)m -> medicamente[i].concentratie) - 3) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%.2f", m -> medicamente[i].concentratie);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%.2f", m -> medicamente[i].concentratie);
                for(int j = 0; j <= var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%.2f", m -> medicamente[i].concentratie);
        printf("|");
    }
    printf("\n");

    printf("STOC         |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre(m -> medicamente[i].cantitate_disponibila);
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cantitate_disponibila);
        var /= 2;
        if(var > 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cantitate_disponibila)) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cantitate_disponibila);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cantitate_disponibila);
                for(int j = 0; j < var + 1; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%d", m -> medicamente[i].cantitate_disponibila);
        printf("|");
    }
    printf("\n");
}

void afisare_medicamente_filtrate(struct medicamente_filtrate *m){
    int num = m -> numar_medicamente;
    printf("COD_UNIC     |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre(m -> medicamente[i].cod_unic);
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cod_unic);
        var /= 2;
        if(var > 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cod_unic)) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cod_unic);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var + 1; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cod_unic);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%d", m -> medicamente[i].cod_unic);
    }
    printf("\n");

    printf("NUME         |");
    for(int i = 0; i < num; ++i){
        printf("%s", m -> medicamente[i].nume_medicament);
        printf("|");
    }
    printf("\n");

    printf("CONCENTRATIE |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre((int)m -> medicamente[i].concentratie) - 1;
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre((int)m -> medicamente[i].concentratie) - 3;
        var /= 2;
        if(var >= 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre((int)m -> medicamente[i].concentratie) - 3) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%.2f", m -> medicamente[i].concentratie);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%.2f", m -> medicamente[i].concentratie);
                for(int j = 0; j <= var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%.2f", m -> medicamente[i].concentratie);
        printf("|");
    }
    printf("\n");

    printf("STOC         |");
    for(int i = 0; i < num; ++i){
        //int var = (int)strlen(m -> medicamente[i].nume_medicament) / 2 - num_cifre(m -> medicamente[i].cantitate_disponibila);
        int var = (int)strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cantitate_disponibila);
        var /= 2;
        if(var > 0){
            if((strlen(m -> medicamente[i].nume_medicament) - num_cifre(m -> medicamente[i].cantitate_disponibila)) % 2 == 0){
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cantitate_disponibila);
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("|");
            }
            else{
                for(int j = 0; j < var; ++j){
                    printf(" ");
                }
                printf("%d", m -> medicamente[i].cantitate_disponibila);
                for(int j = 0; j < var + 1; ++j){
                    printf(" ");
                }
                printf("|");
            }
            continue;
        }
        printf("%d", m -> medicamente[i].cantitate_disponibila);
        printf("|");
    }
    printf("\n");
}

int nr_cifre_ceva(int n)
/**
 * afla numarul de cifre ale nr-ul n primit
 * @param n numar intreg
 * @return numarul de cifre
 */
{
    int i = 0;
    while(n > 0){
        i++;
        n/=10;
    }
    return i;
}

int num_cifre(int n)
/**
 * afla numarul de cifre ale nr-ul n primit
 * @param n numar intreg
 * @return numarul de cifre
 */
{
    int i = 0;
    while(n > 0){
        i++;
        n/=10;
    }
    return i;
}


char *afisare_oferta(struct medicament* med)
/**
 * functia de afisare a unei oferte
 * @param pointer_oferta pointer catre structul de tip oferta cu care se lucreaza
 */
{
    char *printare;     // nu da return la asta ca asa o zis istvan
    printare = (char *)malloc(110 * sizeof(char));
    char concentratie_str[10];
    char id_str[10];
    char cantitate_str[10];
    int cifre_id;
    int nr_spatiu_1;
    int nr_spatiu_2;
    int i;
    // pentru ID am 8
    // pnetru TIP am 13
    // pentru Destinatie am 20
    // pentru Data de plecare am 19
    // pentru pret am 12
    sprintf(id_str, "%d", med->cod_unic);
    sprintf(concentratie_str, "%.2f", med->concentratie);
    sprintf(cantitate_str, "%d", med -> cantitate_disponibila);
    cifre_id = nr_cifre_ceva(med->cod_unic);
    cifre_id = 8 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    strcpy(printare, "|");
    for(i = 1; i<=nr_spatiu_1; i++)
        strcat(printare, " ");
    strcat(printare, id_str);
    for(i = 1; i<=nr_spatiu_2; i++)
        strcat(printare, " ");

    strcat(printare, "|");

    cifre_id = (int)strlen(med->nume_medicament);
    cifre_id = 14 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }

    for(i = 1; i<=nr_spatiu_1; i++)
        strcat(printare, " ");
    strcat(printare, med->nume_medicament);
    for(i = 1; i<=nr_spatiu_2; i++)
        strcat(printare, " ");
    strcat(printare, "|");
    
    cifre_id = (int)strlen(concentratie_str);
    cifre_id = 22 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    for(i = 1; i<=nr_spatiu_1; i++)
        strcat(printare, " ");
    strcat(printare, concentratie_str);
    for(i = 1; i<=nr_spatiu_2; i++)
        strcat(printare, " ");

    cifre_id = (int)strlen(cantitate_str);
    cifre_id = 8 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    strcat(printare, "|");
    for(i = 1; i<=nr_spatiu_1; i++)
        strcat(printare, " ");
    strcat(printare, cantitate_str);
    for(i = 1; i<=nr_spatiu_2; i++)
        strcat(printare, " ");

    strcat(printare, "|\n");
    return printare;
}