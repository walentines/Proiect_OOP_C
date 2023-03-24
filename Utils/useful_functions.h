
// Created by Valentin Serban on 23.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_USEFUL_FUNCTIONS_H
#define ADMINISTRAREFARMACIE_USEFUL_FUNCTIONS_H
#include "../Repository/medicament_repo.h"

void afisare_medicamente(struct medicament_repo* m);

void afisare_medicamente_filtrate(struct medicamente_filtrate* m);

int num_cifre_ceva(int x);

char* afisare_oferta(struct medicament* m);

#endif //ADMINISTRAREFARMACIE_USEFUL_FUNCTIONS_H
