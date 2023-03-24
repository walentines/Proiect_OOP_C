//
// Created by Valentin Serban on 08.03.2023.
//

#include "medicament_ui.h"
#include "../Utils/useful_functions.h"
#include <stdio.h>

/// Functie pentru afisarea meniului.
void afisare_meniu(){
    printf("Farmacia Inimii Catena!\n");
    printf("1.Adauga medicament\n");
    printf("2.Sterge medicament\n");
    printf("3.Modifica medicament\n");
    printf("4.Afisare medicamente\n");
    printf("5.Afisare medicamente crescator\n");
    printf("6.Afisare medicamente descrescator\n");
    printf("7.Filtrare medicamente stoc\n");
    printf("8.Filtrare medicamente litera\n");
    printf("9.Iesire\n");
}

void afisare_medicamente_tabel_ui(struct medicament_ui *m){
    struct medicament_service *m_s = m -> medicamente;
    afisare_medicamente(m_s -> medicamente);
}

void afisare_medicamente_consola(struct medicament_ui* m)
/**
 * functia de printare oferte disponibile (salvate deja)
 * afiseaza un mesaj specific daca nu exista nicio oferta
 * @param ptr_consola pointer spre structul de tip consola cu care se lucreaza
 */
{
//    if (get_numar_oferte_service(ptr_consola->service) == 0){
//        printf("Lista de oferte este vida!\n");
//        return;
//    }
    int numar_medicamente = m -> medicamente -> medicamente -> numar_medicamente;
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<14; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
//    for(int j=0; j<5; j++)
//        printf("-");
//    printf("+");
    printf("\n");
    printf("|");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("ID");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<5; j++)
        printf(" ");
    printf("NUME");
    for(int j=0; j<5; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<5; j++)
        printf(" ");
    printf("CONCENTRATIE");
    for(int j=0; j<5; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<2; j++)
        printf(" ");
    printf("STOC");
    for(int j=0; j<2; j++)
        printf(" ");
    printf("|");
//    for(int j=0; j<3; j++)
//        printf(" ");
//    printf("PRETUL");
//    for(int j=0; j<3; j++)
//        printf(" ");
    printf("\n");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<14; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
//    for(int j=0; j<12; j++)
//        printf("-");
//    printf("+");
    printf("\n");
    // pentru ID am 8
    // pnetru TIP am 13
    // pentru Destinatie am 20
    // pentru Data de plecare am 19
    // pentru pret am 12
    for(int i = 0; i<numar_medicamente; i++)
    {
        char* afisarea_ofertei;
        afisarea_ofertei = afisare_oferta(&(m -> medicamente -> medicamente -> medicamente[i]));
        printf("%s", afisarea_ofertei);
        free(afisarea_ofertei);
        printf("+");
        for(int j=0; j<8; j++)
            printf("-");
        printf("+");
        for(int j=0; j<14; j++)
            printf("-");
        printf("+");
        for(int j=0; j<22; j++)
            printf("-");
        printf("+");
        for(int j=0; j<8; j++)
            printf("-");
        printf("+");
//        for(int j=0; j<12; j++)
//            printf("-");
//        printf("+");
        printf("\n");
    }
}
/// Functie pentru initializarea ui-ului
/// \return medicamente_ui (struct medicament_ui*)
struct medicament_ui* initializare_ui(){
    struct medicament_service* medicamente = initializare_service();
    struct medicament_ui *medicamente_ui = (struct medicament_ui*)malloc(sizeof(struct medicament_ui));
    medicamente_ui -> medicamente = medicamente;

    return medicamente_ui;
}
/// Functie pentru adaugarea unui medicament
/// \param m (struct medicament_ui*)
void adauga_medicament_ui(struct medicament_ui *m){
    struct medicament_service *medicamente = m -> medicamente;
    struct medicament new_m;
    char string[20], *ptr;
    printf("Introdu codul unic al medicamentului: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    new_m.cod_unic = (int)strtol(string, &ptr, 10);
    printf("Introdu numele medicamentului: ");
    scanf("%s", new_m.nume_medicament);
    printf("Introdu cantitatea disponibila: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    new_m.cantitate_disponibila = (int)strtol(string, &ptr, 10);
    printf("Introdu concentratia: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    new_m.concentratie = (float)strtof(string, &ptr);
    adauga_medicament_service(medicamente, new_m);
}
/// Funcit pentru actualizarea concentratiei si numelui unui medicament
/// \param m (struct medicament_ui*)
/// \return
int actualizare_medicament_ui(struct medicament_ui* m){
    struct medicament_service* medicamente = m -> medicamente;
    int medicament_id;
    float concentratie;
    char nume[256];
    char string[20], *ptr;
    printf("Introdu codul unic al medicamentului: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    medicament_id = (int)strtol(string, &ptr, 10);
//    scanf("%d", &medicament_id);
    printf("Introdu numele medicamentului: ");
    scanf("%s", nume);
    printf("Introdu concentratia: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    concentratie = (float)strtof(string, &ptr);
//    scanf("%f", &concentratie);
    return actualizare_medicament_service(medicamente, medicament_id, nume, concentratie);
}
/// Functie pentru stergerea cantitatii unui medicament
/// \param m (struct medicament_ui*)
/// \return Functia returneaza functia corespunzatoare din service
int stergere_cantitate_ui(struct medicament_ui* m){
    struct medicament_service* medicamente = m -> medicamente;
    int medicament_id;
    printf("Introdu codul unic al medicamentului: ");
    char string[20];
    char *ptr;
    fflush(stdin);
    fgets(string, 19, stdin);
    medicament_id = (int)strtol(string, &ptr, 10);
//    scanf("%d", &medicament_id);
    return stergere_cantitate_service(medicamente, medicament_id);
}
/// Functie pentru dealocarea memoriei alocate in functia initializare_ui
/// \param m (struct medicament_ui*)
void destructor_ui(struct medicament_ui *m){
    destructor_service(m -> medicamente);
    free(m);
}
/// Functie pentru afisarea medicamentelor
/// \param m (struct medicament_ui*)
//void afisare_medicamente_ui(struct medicament_ui* m){
//    struct medicament_service* medicamente = m -> medicamente;
//    afisare_medicamente_service(medicamente);
//}
/// Functie pentru sortarea medicamentelor crescator dupa nume si cantitate
/// \param m (struct medicament_ui*)
void vizualizare_medicamente_cresc_ui(struct medicament_ui *m){
    struct medicament_service *medicamente = m -> medicamente;
    vizualizare_medicamente_cresc_s(medicamente);
    afisare_medicamente(medicamente -> medicamente);
}
/// Functie pentru sortarea medicamentelor descrescator dupa nume si cantitate
/// \param m (struct medicament_ui*)
void vizualizare_medicamente_desc_ui(struct medicament_ui *m){
    struct medicament_service *medicamente = m -> medicamente;
    vizualizare_medicamente_desc_s(medicamente);
    afisare_medicamente(medicamente -> medicamente);
}
/// Functie pentru filtrarea medicamentelor cu stocul mai mic decat un stoc dat
/// \param m (struct medicament_ui*)
void medicamente_filtrate_stoc_ui(struct medicament_ui *m){
    struct medicament_service *medicamente = m -> medicamente;
    int threshold;
    char string[20], *ptr;
    printf("Introdu stocul: ");
    fflush(stdin);
    fgets(string, 19, stdin);
    threshold = (int)strtol(string, &ptr, 10);
    struct medicamente_filtrate *medicamente_f_s = medicamente_filtrate_stoc_service(medicamente, threshold);

//    for(int i = 0; i < medicamente_f_s -> numar_medicamente; ++i){
//        printf("COD UNIC: %d\n", medicamente_f_s -> medicamente[i].cod_unic);
//        printf("NUME MEDICAMENT: %s\n", medicamente_f_s -> medicamente[i].nume_medicament);
//        printf("CONCENTRATIE: %f\n", medicamente_f_s -> medicamente[i].concentratie);
//        printf("STOC: %d\n", medicamente_f_s -> medicamente[i].cantitate_disponibila);
//    }
    afisare_medicamente_filtrate(medicamente_f_s);
    free(medicamente_f_s -> medicamente);
    free(medicamente_f_s);
}
/// Functie pentru filtarea medicamentelor a caror nume incepe cu o litera data.
/// \param m (struct medicament_ui*)
void medicamente_filtrate_litera_ui(struct medicament_ui *m){
    struct medicament_service *medicamente = m -> medicamente;
    char letter[2];
    printf("Introdu litera: ");
    scanf("%s", letter);
    struct medicamente_filtrate *medicamente_f_l = medicamente_filtrate_litera_service(medicamente, letter[0]);

//    for(int i = 0; i < medicamente_f_l -> numar_medicamente; ++i){
//        printf("COD UNIC: %d\n", medicamente_f_l -> medicamente[i].cod_unic);
//        printf("NUME MEDICAMENT: %s\n", medicamente_f_l -> medicamente[i].nume_medicament);
//        printf("CONCENTRATIE: %f\n", medicamente_f_l -> medicamente[i].concentratie);
//        printf("STOC: %d\n", medicamente_f_l -> medicamente[i].cantitate_disponibila);
//    }
    afisare_medicamente_filtrate(medicamente_f_l);


    free(medicamente_f_l -> medicamente);
    free(medicamente_f_l);
}
/// Functie pentru rularea aplicatiei
void run(){
    afisare_meniu();
    struct medicament_ui *medicamente = initializare_ui();
    while(1){
        int comanda, ok = 0;
        char string[20], *ptr;
        printf("Introduceti comanda pe care o doriti: ");
        fflush(stdin);
        fgets(string, 19, stdin);
        comanda = (int)strtol(string, &ptr, 10);
        switch (comanda) {
            case 1:
                adauga_medicament_ui(medicamente);
                break;
            case 2:
                stergere_cantitate_ui(medicamente);
                break;
            case 3:
                actualizare_medicament_ui(medicamente);
                break;
            case 4:
//                afisare_medicamente_tabel_ui(medicamente);
                afisare_medicamente_consola(medicamente);
                break;
            case 5:
                vizualizare_medicamente_cresc_ui(medicamente);
                break;
            case 6:
                vizualizare_medicamente_desc_ui(medicamente);
                break;
            case 7:
                medicamente_filtrate_stoc_ui(medicamente);
                break;
            case 8:
                medicamente_filtrate_litera_ui(medicamente);
                break;
            default:
                ok = 1;
                break;
        }
        if(ok){
            break;
        }
    }
    destructor_ui(medicamente);
}
