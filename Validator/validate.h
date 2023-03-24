//
// Created by Valentin Serban on 11.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_VALIDATE_H
#define ADMINISTRAREFARMACIE_VALIDATE_H

#include "../Domain/medicament.h"

struct errors{
    char** err;
    int len_err;
};

int validate_nume(char nume[]);

int validate_cod_unic(int cod_unic);

int validate_stoc(int stoc);

int validate_concentratie(float concentratie);

struct errors* validate_medicament(struct medicament m);

#endif //ADMINISTRAREFARMACIE_VALIDATE_H
