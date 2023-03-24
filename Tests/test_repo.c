//
// Created by Valentin Serban on 11.03.2023.
//

#include "test_repo.h"
#include "../Repository/medicament_repo.h"
#include <assert.h>
#include <string.h>

struct medicament_repo* test_initializare(){
    struct medicament_repo *medicament_test = initializare();
    assert(medicament_test -> numar_medicamente == 0);
    assert(medicament_test -> final_memorie == 1);
    return medicament_test;
}

void test_adaugare(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};
    adauga_medicament(medicament_test, m_test);
    assert(medicament_test -> medicamente[0].cantitate_disponibila == 1);
    assert(medicament_test -> medicamente[0].cod_unic == 0);
    assert(medicament_test -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[0].nume_medicament, "Nurofen") == 0);
    struct medicament m_test_2 = {0, "Ibuprofen", 1, 30};
    adauga_medicament(medicament_test, m_test_2);
    assert(medicament_test -> medicamente[0].cantitate_disponibila == 30);
    struct medicament m_test_3 = {1, "Ibuprofen", 1, 30};
    adauga_medicament(medicament_test, m_test_3);
    assert(medicament_test -> numar_medicamente == 2);
    free(medicament_test -> medicamente);
    free(medicament_test);
}

void test_actualizare(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    int cod_unic = 0;
    char nume[256];
    float concentratie = 5;
    strcpy(nume, "Parasinus");

    int ok = actualizare_medicament(medicament_test, cod_unic, nume, concentratie);

    assert(ok == 1);
    assert(strcmp(medicament_test -> medicamente[0].nume_medicament, nume) == 0);
    assert(concentratie == medicament_test -> medicamente[0].concentratie);
    ok = actualizare_medicament(medicament_test, 1, "Samsar", (float)3.4);
    assert(ok == 0);
    free(medicament_test -> medicamente);
    free(medicament_test);
}

void test_stergere(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    int cod_unic = 0;

    int ok = stergere_cantitate(medicament_test, cod_unic);

    assert(ok == 1);
    assert(medicament_test -> medicamente[0].cantitate_disponibila == 0);
    ok = stergere_cantitate(medicament_test, 1);
    assert(ok == 0);
    free(medicament_test -> medicamente);
    free(medicament_test);
}

void test_filtrare_stoc(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    int threshold = 4;

    struct medicamente_filtrate* filtrat = medicamente_filtrate_stoc(medicament_test, threshold);

    assert(filtrat -> medicamente[0].cod_unic == 0);
    assert(strcmp(filtrat -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(filtrat -> medicamente[0].concentratie == 1);
    assert(filtrat -> medicamente[0].cantitate_disponibila == 1);
    free(medicament_test -> medicamente);
    free(medicament_test);

    free(filtrat -> medicamente);
    free(filtrat);
}

void test_filtrare_litera(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    char litera = 'N';

    struct medicamente_filtrate* filtrat = medicamente_filtrate_litera(medicament_test, litera);

    assert(filtrat -> medicamente[0].cod_unic == 0);
    assert(strcmp(filtrat -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(filtrat -> medicamente[0].concentratie == 1);
    assert(filtrat -> medicamente[0].cantitate_disponibila == 1);
    free(medicament_test -> medicamente);
    free(medicament_test);

    free(filtrat -> medicamente);
    free(filtrat);
}

void test_sortare_cresc(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    struct medicament m_test2 = {1, "Obuprofen", 1, 2};

    adauga_medicament(medicament_test, m_test2);

    struct medicament m_test3 = {2, "Nurofen", 1, 3};

    adauga_medicament(medicament_test, m_test3);

    vizualizare_medicamente_cresc(medicament_test);

    assert(medicament_test -> medicamente[0].cantitate_disponibila == 1);
    assert(medicament_test -> medicamente[0].cod_unic == 0);
    assert(medicament_test -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[0].nume_medicament, "Nurofen") == 0);
    assert(medicament_test -> medicamente[1].cantitate_disponibila == 3);
    assert(medicament_test -> medicamente[1].cod_unic == 2);
    assert(medicament_test -> medicamente[1].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[1].nume_medicament, "Nurofen") == 0);
    assert(medicament_test -> medicamente[2].cantitate_disponibila == 2);
    assert(medicament_test -> medicamente[2].cod_unic == 1);
    assert(medicament_test -> medicamente[2].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[2].nume_medicament, "Obuprofen") == 0);
    free(medicament_test -> medicamente);
    free(medicament_test);
}

void test_sortare_desc(){
    struct medicament_repo *medicament_test = test_initializare();
    struct medicament m_test = {0, "Nurofen", 1, 1};

    adauga_medicament(medicament_test, m_test);

    struct medicament m_test2 = {1, "Obuprofen", 1, 2};

    adauga_medicament(medicament_test, m_test2);

    struct medicament m_test3 = {2, "Nurofen", 1, 3};
    adauga_medicament(medicament_test, m_test3);

    vizualizare_medicamente_desc(medicament_test);

    assert(medicament_test -> medicamente[0].cantitate_disponibila == 2);
    assert(medicament_test -> medicamente[0].cod_unic == 1);
    assert(medicament_test -> medicamente[0].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[0].nume_medicament, "Obuprofen") == 0);
    assert(medicament_test -> medicamente[1].cantitate_disponibila == 3);
    assert(medicament_test -> medicamente[1].cod_unic == 2);
    assert(medicament_test -> medicamente[1].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[1].nume_medicament, "Nurofen") == 0);
    assert(medicament_test -> medicamente[2].cantitate_disponibila == 1);
    assert(medicament_test -> medicamente[2].cod_unic == 0);
    assert(medicament_test -> medicamente[2].concentratie == 1);
    assert(strcmp(medicament_test -> medicamente[2].nume_medicament, "Nurofen") == 0);
    free(medicament_test -> medicamente);
    free(medicament_test);
}

void testeaza_tot(){
    struct medicament_repo* medicament_test = test_initializare();
    destructor(medicament_test);
    test_actualizare();
    test_adaugare();
    test_stergere();
    test_filtrare_litera();
    test_filtrare_stoc();
    test_sortare_desc();
    test_sortare_cresc();
}