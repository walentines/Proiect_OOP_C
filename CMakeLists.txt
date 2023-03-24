cmake_minimum_required(VERSION 3.25)
project(AdministrareFarmacie C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(AdministrareFarmacie main.c Domain/medicament.c Domain/medicament.h Repository/medicament_repo.c Repository/medicament_repo.h Service/medicament_service.c Service/medicament_service.h UI/medicament_ui.c UI/medicament_ui.h Tests/test_repo.c Tests/test_repo.h Tests/test_service.c Tests/test_service.h Validator/validate.c Validator/validate.h Utils/useful_functions.c Utils/useful_functions.h)