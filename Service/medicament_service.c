//
// Created by Valentin Serban on 08.03.2023.
//

#include <stdio.h>
#include "medicament_service.h"
#include "../Validator/validate.h"
/// Functie pentru initializarea service-ului
/// \return medicamente_service (struct medicament_service*)
struct medicament_service* initializare_service(){
    struct medicament_repo *medicamente = initializare();
    struct medicament_service* medicamente_service = (struct medicament_service*)malloc(sizeof(struct medicament_service));
    medicamente_service -> medicamente = medicamente;
    medicamente_service -> undo = constructor_undo(medicamente);
    return medicamente_service;
}
/// Functie pentru a adauga un medicament in array-ul de medicamente
/// Afiseaza o eroare corespunzatoare daca vreunul din campurile medicamentului nu este valid.
/// \param m (struct medicament_service*)
/// \param new_m (struct medicament)
void adauga_medicament_service(struct medicament_service *m, struct medicament new_m){
    make_copy_repo(m->undo);
    struct medicament_repo *medicamente = m -> medicamente;
    struct errors* erori = validate_medicament(new_m);
    for(int i = 0; i < erori -> len_err; ++i){
        printf("%s\n", erori -> err[i]);
    }
    if(erori -> len_err > 0){
        for(int i = 0; i < 4; ++i){
            free(erori -> err[i]);
        }
        free(erori -> err);
        free(erori);
        delete_copy_repo(m->undo);
        return;
    }
    for(int i = 0; i < 4; ++i){
        free(erori -> err[i]);
    }
    free(erori -> err);
    free(erori);
    apply_copy_repo(m->undo);
    adauga_medicament(medicamente, new_m);
}
/// Functie pentru actualizarea numelui si a concentratiei unui medicament
/// Se afiseaza eroare corespunzatoare daca vreuna dintre datele de intrare nu este valida
/// \param m (struct medicament_service*)
/// \param medicament_id (int)
/// \param nume (char*)
/// \param concentratie (float)
/// \return Se returneaza functia actualizare_medicament din repo
int actualizare_medicament_service(struct medicament_service *m, int medicament_id, char nume[], float concentratie){
    make_copy_repo(m->undo);
    struct medicament_repo *medicamente = m -> medicamente;
    int ok = 0;
    if(!validate_concentratie(concentratie)){
        printf("Introdu o concentratie valida!\n");
        ok = 1;
    }
    if(!validate_nume(nume)){
        printf("Introdu un nume valid!\n");
        ok = 1;
    }
    if(!validate_cod_unic(medicament_id)){
        printf("Introdu un cod unic valid!\n");
        ok = 1;
    }
    if(ok){
        delete_copy_repo(m->undo);
        return 0;
    }
    ok = actualizare_medicament(medicamente, medicament_id, nume, concentratie);
    if(ok)
        apply_copy_repo(m->undo);
    else
        delete_copy_repo(m->undo);
    return ok;
}
/// Functie pentru stergerea cantitatii unui medicament.
/// \param m (struct medicament_service*)
/// \param medicament_id (int)
/// \return Se returneaza functia stergere_cantitate din repo
int stergere_cantitate_service(struct medicament_service *m, int medicament_id){
    make_copy_repo(m->undo);
    struct medicament_repo *medicamente = m -> medicamente;
    int ok = 0;
    if(!validate_cod_unic(medicament_id)){
        printf("Introdu un cod unic valid!\n");
        ok = 1;
    }
    if(ok){
        delete_copy_repo(m->undo);
        return 0;
    }
    ok = stergere_cantitate(medicamente, medicament_id);
    if(ok)
        apply_copy_repo(m->undo);
    else
        delete_copy_repo(m->undo);
    return ok;
}
/// Functie pentru dealocarea memoriei alocate dinamic in functia initializare_service
/// \param m (struct medicament_service*)
void destructor_service(struct medicament_service *m){
    destructor(m -> medicamente);
    destructor_undo(m->undo);
    free(m);
}

/// Functie pentru sortarea medicamentelor crescator conform functiei din repo
/// \param m (struct medicament_service*)
void vizualizare_medicamente_cresc_s(struct medicament_service* m){
    struct medicament_repo *medicament = m -> medicamente;
    vizualizare_medicamente_cresc(medicament);
}
/// Functie pentru sortarea medicamentelor descrescator conform functiei din repo
/// \param m (struct medicament_service*)
void vizualizare_medicamente_desc_s(struct medicament_service* m){
    struct medicament_repo *medicament = m -> medicamente;
    vizualizare_medicamente_desc(medicament);
}
/// Functie pentru filtrarea medicamentelor corespunzator functiei din repo
/// \param m (struct medicament_service*)
/// \param threshold (int)
/// \return medicamente_f_s (struct medicamente_filtrate*)
struct medicamente_filtrate* medicamente_filtrate_stoc_service(struct medicament_service *m, int threshold){
    struct medicament_repo *medicamente = m -> medicamente;
    struct medicamente_filtrate *medicamente_f_s = medicamente_filtrate_stoc(medicamente, threshold);

    return medicamente_f_s;
}
/// Functie pentru filtrarea medicamentelor corespunzator functiei din repo
/// \param m (struct medicament_service*)
/// \param letter (char)
/// \return medicamente_f_l (struct medicamente_filtrate*)
struct medicamente_filtrate* medicamente_filtrate_litera_service(struct medicament_service *m, char letter){
    struct medicament_repo *medicamente = m -> medicamente;
    struct medicamente_filtrate *medicamente_f_l = medicamente_filtrate_litera(medicamente, letter);

    return medicamente_f_l;
}

int undo_service(struct medicament_service *m_service) {
    return make_undo(m_service->undo);
}

struct medicamente_filtrate * medicamente_filtrate_concentratie_service(struct medicament_service *m, float concentratie) {
    struct medicament_repo *medicamente = m -> medicamente;
    struct medicamente_filtrate *medicamente_f_c = medicamente_filtrate_concentratie(medicamente, concentratie);

    return medicamente_f_c;
}
