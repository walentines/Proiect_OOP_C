//
// Created by Valentin Serban on 08.03.2023.
//

#include "medicament.h"
#include <string.h>
#include <stdio.h>

//#include <stdio.h>
/// Functie de comparare pentru sortare crescatoare
/// \param a (const void*)
/// \param b (const void*)
/// \return True/False
int cmpfunc_cresc(const void* a, const void* b){
    const struct medicament* a_ = a;
    const struct medicament* b_ = b;
    if(strcmp(a_ -> nume_medicament, b_ -> nume_medicament) == 0){
        return a_ -> cantitate_disponibila > b_ -> cantitate_disponibila;
    }

    return strcmp(a_ -> nume_medicament, b_ -> nume_medicament) > 0;
}
/// Functie de comparare pentru sortare descrescatoare
/// \param a (const void*)
/// \param b (const void*)
/// \return True/False
int cmpfunc_desc(const void* a, const void* b){
    const struct medicament* a_ = a;
    const struct medicament* b_ = b;
    if(strcmp(a_ -> nume_medicament, b_ -> nume_medicament) == 0){
        return a_ -> cantitate_disponibila < b_ -> cantitate_disponibila;
    }

    return strcmp(a_ -> nume_medicament, b_ -> nume_medicament) < 0;
}
/// Functie pentru afisarea unui medicament
/// \param med
void afisare_medicament(struct medicament med){
    printf("COD UNIC: %d\n", med.cod_unic);
    printf("NUME MEDICAMENT: %s\n", med.nume_medicament);
    printf("CONCENTRATIE: %f\n", med.concentratie);
    printf("STOC: %d\n", med.cantitate_disponibila);
}
