
#include "UI/medicament_ui.h"
#include "Tests/test_repo.h"
#include "Tests/test_service.h"

/// Functie pentru rularea testelor si pornirea aplicatiei
void start_program(){
    testeaza_tot();
    testeaza_tot_s();

    run();
}

int main() {

    start_program();

    return 0;
}
