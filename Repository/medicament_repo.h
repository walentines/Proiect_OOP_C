//
// Created by Valentin Serban on 08.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_MEDICAMENT_REPO_H
#define ADMINISTRAREFARMACIE_MEDICAMENT_REPO_H

#include <stdlib.h>
#include <ctype.h>
#include "../Domain/medicament.h"

struct medicament_repo{
    struct medicament *medicamente;
    int numar_medicamente;
    int final_memorie;
};

struct medicamente_filtrate{
    struct medicament *medicamente;
    int numar_medicamente;
};

struct medicament_repo* initializare();

void adauga_medicament(struct medicament_repo *m, struct medicament new_m);

int actualizare_medicament(struct medicament_repo* m, int medicament_id, char nume[], float concentratie);

int stergere_cantitate(struct medicament_repo* m, int medicament_id);

void destructor(struct medicament_repo *m);

void vizualizare_medicamente_cresc(struct medicament_repo* m);

void vizualizare_medicamente_desc(struct medicament_repo* m);

struct medicamente_filtrate* medicamente_filtrate_stoc(struct medicament_repo* m, int threshold);

struct medicamente_filtrate* medicamente_filtrate_litera(struct medicament_repo* m, char letter);

#endif //ADMINISTRAREFARMACIE_MEDICAMENT_REPO_H
