//
// Created by Valentin Serban on 08.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_MEDICAMENT_UI_H
#define ADMINISTRAREFARMACIE_MEDICAMENT_UI_H

#include "../Service/medicament_service.h"

struct medicament_ui{
    struct medicament_service* medicamente;
};

struct medicament_ui* initializare_ui();

void afisare_meniu();

void afisare_medicamente_tabel_ui(struct medicament_ui *m);

void adauga_medicament_ui(struct medicament_ui *m);

int actualizare_medicament_ui(struct medicament_ui* m);

int stergere_cantitate_ui(struct medicament_ui* m);

//void afisare_medicamente_ui(struct medicament_ui* m);

void destructor_ui(struct medicament_ui *m);

void vizualizare_medicamente_cresc_ui(struct medicament_ui *m);

void vizualizare_medicamente_desc_ui(struct medicament_ui *m);

void medicamente_filtrate_stoc_ui(struct medicament_ui *m);

void medicamente_filtrate_litera_ui(struct medicament_ui *m);

void run();

#endif //ADMINISTRAREFARMACIE_MEDICAMENT_UI_H
