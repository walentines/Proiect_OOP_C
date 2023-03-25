//
// Created by Valentin Serban on 08.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_MEDICAMENT_H
#define ADMINISTRAREFARMACIE_MEDICAMENT_H

struct medicament{
    int cod_unic;
    char nume_medicament[256];
    float concentratie;
    int cantitate_disponibila;
};

int cmpfunc_cresc(const void* a, const void* b);

int cmpfunc_desc(const void* a, const void* b);

void afisare_medicament(struct medicament med);

int num_cifre(int x);

#endif //ADMINISTRAREFARMACIE_MEDICAMENT_H
