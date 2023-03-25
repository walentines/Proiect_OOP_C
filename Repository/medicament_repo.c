//
// Created by Valentin Serban on 08.03.2023.
//

#include <string.h>
#include <stdlib.h>
#include "medicament_repo.h"
/// Functie pentru initializarea repository-ului de medicamente
/// \return m (struct medicament_repo*)
struct medicament_repo* initializare(){
    struct medicament_repo *m = (struct medicament_repo*)malloc(sizeof(struct medicament_repo));
    m -> medicamente = (struct medicament*)malloc(sizeof(struct medicament));
    m -> numar_medicamente = 0;
    m -> final_memorie = 1;
    return m;
}
/// Functie pentru adaugarea unui medicament la array-ul de medicamente. Daca medicamentul deja exista
/// se updateaza cantitatea disponibila a acestuia
/// \param m (sturct medicament_repo*)
/// \param new_m (struct medicament)
void adauga_medicament(struct medicament_repo *m, struct medicament new_m){
    int num = m -> numar_medicamente;
    for(int i = 0; i < num; ++i){
        if(m -> medicamente[i].cod_unic == new_m.cod_unic){
            m -> medicamente[i].cantitate_disponibila = new_m.cantitate_disponibila;
            return;
        }
    }
    if(num == m -> final_memorie){
        struct medicament* new_p = (struct medicament*)malloc(2 * num * sizeof(struct medicament));
        for(int i = 0; i < num; ++i){
            new_p[i] = m -> medicamente[i];
        }
        free(m -> medicamente);
        m -> medicamente = new_p;
        m -> final_memorie = m -> final_memorie * 2;
    }
    m -> medicamente[num] = new_m;
    m -> numar_medicamente = m -> numar_medicamente + 1;
}
/// Functie pentru actualizarea numelui si a concentratiei unui medicament.
/// \param m (struct medicament_repo*)
/// \param medicament_id (int)
/// \param nume (char*)
/// \param concentratie (float)
/// \return True (Daca medicamentul a fost updatat cu succes) / False (Altfel)
int actualizare_medicament(struct medicament_repo* m, int medicament_id, char nume[], float concentratie){
    int num = m -> numar_medicamente;
    for(int i = 0; i < num; ++i){
        if(m -> medicamente[i].cod_unic == medicament_id){
            strcpy(m -> medicamente[i].nume_medicament, nume);
            m -> medicamente[i].concentratie = concentratie;
            return 1;
        }
    }

    return 0;
}
/// Functie pentru stergerea cantitatii unui medicament.
/// \param m (struct medicament_repo*)
/// \param medicament_id (int)
/// \return True (Daca stergerea a fost efectuata cu succes) / False (Altfel)
int stergere_cantitate(struct medicament_repo* m, int medicament_id){
    int num = m -> numar_medicamente;
    for(int i = 0; i < num; ++i){
        if(m -> medicamente[i].cod_unic == medicament_id){
            m -> medicamente[i].cantitate_disponibila = 0;
            return 1;
        }
    }

    return 0;
}
/// Elibereaza memoria alocata dinamic in functia de initializare
/// \param m (struct medicament_repo*)
void destructor(struct medicament_repo* m){
    free(m -> medicamente);
    free(m);
}
/// Functie care sorteaza medicamentele alfabetic dupa nume, apoi crescator dupa cantitatea disponibila
/// \param m (struct medicament_repo*)
void vizualizare_medicamente_cresc(struct medicament_repo *m){
    qsort(m -> medicamente, m -> numar_medicamente, sizeof(struct medicament), cmpfunc_cresc);
}
/// Functie care sorteaza medicamentele descrescator dupa nume si cantitatea disponibila
/// \param m (struct medicament_repo*)
void vizualizare_medicamente_desc(struct medicament_repo *m){
    qsort(m -> medicamente, m -> numar_medicamente, sizeof(struct medicament), cmpfunc_desc);
}

/// Functie pentru afisarea medicamentelor cu stocul mai mic decat un stoc dat.
/// \param m (struct medicament_repo*)
/// \param threshold (int)
/// \return medicamente_filtrate_s (struct medicamente_filtrate*)
struct medicamente_filtrate* medicamente_filtrate_stoc(struct medicament_repo* m, int threshold){
    int num = m -> numar_medicamente, k = 0;
    struct medicamente_filtrate *medicamente_filtrate_s = (struct medicamente_filtrate*)malloc(sizeof(struct medicamente_filtrate));
    medicamente_filtrate_s -> medicamente = (struct medicament*)malloc(num * sizeof(struct medicament));
    medicamente_filtrate_s -> numar_medicamente = k;

    for(int i = 0; i < num; ++i){
        if(threshold > m -> medicamente[i].cantitate_disponibila){
            medicamente_filtrate_s -> medicamente[medicamente_filtrate_s -> numar_medicamente++] = m -> medicamente[i];
        }
    }

    return medicamente_filtrate_s;
}
/// Functie pentru afisarea medicamentelor care incep cu litera data.
/// \param m (struct medicament_repo*)
/// \param letter (char)
/// \return medicamente_filtrate_l (struct medicamente_filtrate*)
struct medicamente_filtrate* medicamente_filtrate_litera(struct medicament_repo* m, char letter){
    int num = m -> numar_medicamente, k = 0;
    struct medicamente_filtrate *medicamente_filtrate_l = (struct medicamente_filtrate*)malloc(sizeof(struct medicamente_filtrate));
    medicamente_filtrate_l -> medicamente = (struct medicament*)malloc(num * sizeof(struct medicament));
    medicamente_filtrate_l -> numar_medicamente = k;

    for(int i = 0; i < num; ++i){
        if(tolower(letter) == tolower(m -> medicamente[i].nume_medicament[0])){
            medicamente_filtrate_l -> medicamente[medicamente_filtrate_l -> numar_medicamente++] = m -> medicamente[i];
        }
    }

    return medicamente_filtrate_l;
}

struct medicamente_filtrate *medicamente_filtrate_concentratie(struct medicament_repo *m, float concentratie) {
    int num = m ->numar_medicamente;
    int k = 0;
    struct medicamente_filtrate *medicamente_filtrate_conc = (struct medicamente_filtrate*) malloc(sizeof(struct medicamente_filtrate));
    medicamente_filtrate_conc -> medicamente = (struct medicament*) malloc(num * sizeof(struct medicament));
    medicamente_filtrate_conc -> numar_medicamente = k;

    for(int i = 0; i <num; i++){
        if(concentratie > m ->medicamente[i].concentratie){
            medicamente_filtrate_conc -> medicamente[medicamente_filtrate_conc -> numar_medicamente++] = m -> medicamente[i];
        }
    }
    return medicamente_filtrate_conc;
}


