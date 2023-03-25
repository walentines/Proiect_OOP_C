//
// Created by Andrei on 24.03.2023.
//

#ifndef ADMINISTRAREFARMACIE_UNDO_H
#define ADMINISTRAREFARMACIE_UNDO_H
#include "../Repository/medicament_repo.h"
typedef struct Undo{
    struct medicament_repo* repo;
    struct medicament* lista_provizorie;
    int lungime_provizorie;
    void* undo_stack;
    int length;
    int capacitate;
    int* lengths_stack;

}Undo, *PtrUndo;
PtrUndo constructor_undo(struct medicament_repo* ptr_repo);
void make_copy_repo(PtrUndo ptr_undo);
void delete_copy_repo(PtrUndo ptr_undo);
int apply_copy_repo(PtrUndo ptr_undo);
int make_undo(PtrUndo ptr_undo);
void destructor_undo(PtrUndo ptr_undo);

void redim(PtrUndo undo);
#endif //ADMINISTRAREFARMACIE_UNDO_H
