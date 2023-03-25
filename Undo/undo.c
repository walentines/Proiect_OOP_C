//
// Created by Andrei on 24.03.2023.
//

#include "undo.h"


PtrUndo constructor_undo(struct medicament_repo *ptr_repo) {
    PtrUndo undo = (PtrUndo) malloc(sizeof(Undo));
    undo->capacitate = 10;
    undo->lista_provizorie = NULL;
    undo->lungime_provizorie = 0;
    undo->undo_stack = malloc(sizeof(void*) * undo->capacitate);
    undo->lengths_stack = (int *) malloc(sizeof(int) * undo->capacitate);
    undo->repo = ptr_repo;
    undo->length = 0;
    return undo;
}


void redim(PtrUndo ptr_undo) {
    void *new_undo_stack;
    int *new_undo_lenghts_stack;
    new_undo_stack = (void *) malloc(sizeof(void *) * ptr_undo->capacitate * 2);
    new_undo_lenghts_stack = (int *) malloc(sizeof(int *) * ptr_undo->capacitate * 2);
    for(int i = 0; i < ptr_undo->length; i++){
        new_undo_lenghts_stack[i] = ptr_undo->lengths_stack[i];
        ((void **)new_undo_stack)[i] = ((void**)(ptr_undo->undo_stack))[i];
    }
    free(ptr_undo->lengths_stack);
    free(ptr_undo->undo_stack);
    ptr_undo->undo_stack = new_undo_stack;
    ptr_undo->lengths_stack = new_undo_lenghts_stack;
}

void make_copy_repo(PtrUndo ptr_undo) {
    ptr_undo->lista_provizorie = (struct medicament *) malloc(sizeof (struct medicament) * ptr_undo->repo->numar_medicamente);
    struct medicament* elemente_repo;
    elemente_repo = ptr_undo->repo->medicamente;
    //afisare_medicament(elemente_repo[0]);
    for(int i = 0; i < ptr_undo->repo->numar_medicamente; i++) {
        ptr_undo->lista_provizorie[i] = elemente_repo[i];
    }
    ptr_undo->lungime_provizorie = ptr_undo->repo->numar_medicamente;
    //afisare_medicament(ptr_undo->lista_provizorie[0]);
}

void delete_copy_repo(PtrUndo ptr_undo) {
    if(ptr_undo->lista_provizorie == NULL){
        ptr_undo->lungime_provizorie = 0;
        return;
    }
    free(ptr_undo->lista_provizorie);
    ptr_undo->lista_provizorie = NULL;
    ptr_undo->lungime_provizorie = 0;
}

int apply_copy_repo(PtrUndo ptr_undo) {
    if(ptr_undo->lista_provizorie == NULL)
        return 2;
    if(ptr_undo->capacitate == ptr_undo->length)
        redim(ptr_undo);
    ptr_undo->lengths_stack[ptr_undo->length] = ptr_undo->lungime_provizorie;
    ((struct medicament**)(ptr_undo->undo_stack))[ptr_undo->length] = ptr_undo->lista_provizorie;
    ptr_undo->length++;
    ptr_undo->lungime_provizorie = 0;
    ptr_undo->lista_provizorie = NULL;
    return 1;
}

int make_undo(PtrUndo ptr_undo) {
    if(ptr_undo->length == 0){
        return 2;
    }
    ptr_undo->length --;
    for(int i = 0 ; i < ptr_undo->lengths_stack[ptr_undo->length]; i++){
        ptr_undo->repo->medicamente[i] = ((struct medicament**)(ptr_undo->undo_stack))[ptr_undo->length][i];
    }
    ptr_undo->repo->numar_medicamente = ptr_undo->lengths_stack[ptr_undo->length];
    free(((void **)ptr_undo->undo_stack)[ptr_undo->length]);
    return 1;
}

void destructor_undo(PtrUndo ptr_undo) {
    for(int i = 0; i < ptr_undo->length; i++){
        free(((void**)(ptr_undo->undo_stack))[i]);
    }
    free(ptr_undo->undo_stack);
    free(ptr_undo->lengths_stack);
    free(ptr_undo);
}

