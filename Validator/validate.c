//
// Created by Valentin Serban on 11.03.2023.
//

#include "validate.h"
#include <string.h>
#include <stdlib.h>

/// Functie pentru validarea numelui unui medicament
/// \param nume (char*)
/// \return True (valid) / False (invalid)
int validate_nume(char nume[]){
    if(strlen(nume) > 0){
        return 1;
    }

    return 0;
}
/// Functie pentru validarea codului unic unui medicament
/// \param cod_unic (int)
/// \return True (valid)/ False (invalid)
int validate_cod_unic(int cod_unic){
    if(cod_unic >= 0){
        return 1;
    }

    return 0;
}
/// Functie pentru validarea stocului unui medicament
/// \param stoc (int)
/// \return True (valid) / False (invalid)
int validate_stoc(int stoc){
    if(stoc >= 0){
        return 1;
    }

    return 0;
}
/// Functie pentru validarea concentratiei unui medicament
/// \param concentratie (float)
/// \return True (valid) / False (invalid)
int validate_concentratie(float concentratie){
    if(concentratie >= 0){
        return 1;
    }

    return 0;
}
/// Functie pentru validarea unui intreg medicament
/// \param m (struct medicament m)
/// \return errs (struct errors*) i.e un struct format dintr-un string care contine erorile corespunzatoare si lungimea stringului
struct errors* validate_medicament(struct medicament m){
    struct errors *errs = (struct errors*)malloc(sizeof(struct errors));
    errs -> err = (char**)malloc(4 * sizeof(char*));
    errs -> len_err = 0;
    for(int i = 0; i < 4; ++i){
        errs -> err[i] = (char*)malloc(256 * sizeof(char));
    }
    if(!validate_cod_unic(m.cod_unic)){
        strcpy(errs -> err[errs -> len_err++], "Introdu un cod unic valid!");
    }
    if(!validate_nume(m.nume_medicament)){
        strcpy(errs -> err[errs -> len_err++], "Introdu un nume valid!");
    }
    if(!validate_stoc(m.cantitate_disponibila)){
        strcpy(errs -> err[errs -> len_err++], "Introdu un stoc valid!");
    }
    if(!validate_concentratie(m.concentratie)){
        strcpy(errs -> err[errs -> len_err++], "Introdu o concentratie valida!");
    }

    return errs;
}