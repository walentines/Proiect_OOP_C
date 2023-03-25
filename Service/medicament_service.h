//
// Created by Valentin Serban on 08.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_MEDICAMENT_SERVICE_H
#define ADMINISTRAREFARMACIE_MEDICAMENT_SERVICE_H

#include "../Repository/medicament_repo.h"
#include "../Undo/undo.h"

struct medicament_service{
    PtrUndo undo;
    struct medicament_repo* medicamente;
};


void afisare_medicamente_filtrate(struct medicamente_filtrate *m);

struct medicament_service* initializare_service();

void adauga_medicament_service(struct medicament_service *m, struct medicament new_m);

int actualizare_medicament_service(struct medicament_service *m, int medicament_id, char nume[], float concentratie);

int stergere_cantitate_service(struct medicament_service *m, int medicament_id);

void destructor_service(struct medicament_service *m);

void vizualizare_medicamente_cresc_s(struct medicament_service *m);

void vizualizare_medicamente_desc_s(struct medicament_service *m);

void afisare_medicamente_service(struct medicament_service *m);

struct medicamente_filtrate* medicamente_filtrate_stoc_service(struct medicament_service *m, int threshold);

struct medicamente_filtrate* medicamente_filtrate_litera_service(struct medicament_service *m, char letter);

int undo_service(struct medicament_service *m_service);



#endif //ADMINISTRAREFARMACIE_MEDICAMENT_SERVICE_H
