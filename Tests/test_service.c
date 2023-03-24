//
// Created by Valentin Serban on 11.03.2023.
//

#include <assert.h>
#include "test_service.h"
#include "../Service/medicament_service.h"
#include <string.h>

struct medicament_service* test_initializare_s(){
    struct medicament_service* medicament_test_s = initializare_service();

    assert(medicament_test_s -> medicamente -> numar_medicamente == 0);
    assert(medicament_test_s -> medicamente -> final_memorie == 1);
    return medicament_test_s;
}

void test_adaugare_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    assert(medicament_test_s -> medicamente -> medicamente[0].cantitate_disponibila == 1);
    assert(medicament_test_s -> medicamente -> medicamente[0].cod_unic == 0);
    assert(medicament_test_s -> medicamente -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[0].nume_medicament, "Nurofen") == 0);
    struct medicament medicament_prost = {-1, "Ibuprofen", 1, 1};
    adauga_medicament_service(medicament_test_s, medicament_prost);
    assert(medicament_test_s -> medicamente -> numar_medicamente == 1);
    destructor_service(medicament_test_s);

}

void test_actualizare_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    int cod_unic = 0;
    char nume[256];
    float concentratie = 5;
    strcpy(nume, "Parasinus");

    int ok = actualizare_medicament_service(medicament_test_s, cod_unic, nume, concentratie);

    assert(ok == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[0].nume_medicament, nume) == 0);
    assert(concentratie == medicament_test_s -> medicamente -> medicamente[0].concentratie);
    ok = actualizare_medicament_service(medicament_test_s, -1, "", -1);
    assert(ok == 0);
    destructor_service(medicament_test_s);

}

void test_stergere_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    int cod_unic = 0;

    int ok = stergere_cantitate_service(medicament_test_s, cod_unic);

    assert(ok == 1);
    assert(medicament_test_s -> medicamente -> medicamente[0].cantitate_disponibila == 0);
    ok = stergere_cantitate_service(medicament_test_s, -1);
    assert(ok == 0);
    destructor_service(medicament_test_s);

}

void test_filtrare_stoc_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    int threshold = 4;

    struct medicamente_filtrate* filtrat = medicamente_filtrate_stoc_service(medicament_test_s, threshold);

    assert(filtrat -> medicamente[0].cod_unic == 0);
    assert(strcmp(filtrat -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(filtrat -> medicamente[0].concentratie == 1);
    assert(filtrat -> medicamente[0].cantitate_disponibila == 1);
    destructor_service(medicament_test_s);
    free(filtrat -> medicamente);
    free(filtrat);
}

void test_filtrare_litera_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    char litera = 'N';

    struct medicamente_filtrate* filtrat = medicamente_filtrate_litera_service(medicament_test_s, litera);

    assert(filtrat -> medicamente[0].cod_unic == 0);
    assert(strcmp(filtrat -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(filtrat -> medicamente[0].concentratie == 1);
    assert(filtrat -> medicamente[0].cantitate_disponibila == 1);
    destructor_service(medicament_test_s);
    free(filtrat -> medicamente);
    free(filtrat);
}

void test_sortare_cresc_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    struct medicament m_test2 = {1, "Obuprofen", 1, 2};

    adauga_medicament_service(medicament_test_s, m_test2);

    vizualizare_medicamente_cresc_s(medicament_test_s);

    assert(medicament_test_s -> medicamente -> medicamente[0].cantitate_disponibila == 1);
    assert(medicament_test_s -> medicamente -> medicamente[0].cod_unic == 0);
    assert(medicament_test_s -> medicamente -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(medicament_test_s -> medicamente -> medicamente[1].cantitate_disponibila == 2);
    assert(medicament_test_s -> medicamente -> medicamente[1].cod_unic == 1);
    assert(medicament_test_s -> medicamente -> medicamente[1].concentratie == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[1].nume_medicament, "Obuprofen") == 0);
    destructor_service(medicament_test_s);

}

void test_sortare_desc_s(){
    struct medicament_service* medicament_test_s = initializare_service();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament_service(medicament_test_s, m_test);

    struct medicament m_test2 = {1, "Obuprofen", 1, 2};

    adauga_medicament_service(medicament_test_s, m_test2);

    vizualizare_medicamente_desc_s(medicament_test_s);

    assert(medicament_test_s -> medicamente -> medicamente[0].cantitate_disponibila == 2);
    assert(medicament_test_s -> medicamente -> medicamente[0].cod_unic == 1);
    assert(medicament_test_s -> medicamente -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[0].nume_medicament, "Obuprofen") == 0);
    assert(medicament_test_s -> medicamente -> medicamente[1].cantitate_disponibila == 1);
    assert(medicament_test_s -> medicamente -> medicamente[1].cod_unic == 0);
    assert(medicament_test_s -> medicamente -> medicamente[1].concentratie == 1);
    assert(strcmp(medicament_test_s -> medicamente -> medicamente[1].nume_medicament, "Nurofen") == 0);
    destructor_service(medicament_test_s);

}

void testeaza_tot_s(){
    struct medicament_service* medicament_test_s = test_initializare_s();
    destructor_service(medicament_test_s);
    test_actualizare_s();
    test_adaugare_s();
    test_stergere_s();
    test_filtrare_litera_s();
    test_filtrare_stoc_s();
    test_sortare_desc_s();
    test_sortare_cresc_s();
}