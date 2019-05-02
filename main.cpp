/*
main: punto de partida para ejecucion del programa.
*/

#include "enums.h"
#include "interfaz.h"
#include "empleado.h"
#include "sector.h"

int main(int argc, char **argv) {
    empleado::cargar();
    sector::cargar();
    enums::pantalla pantalla = enums::MENU;
    while (pantalla != enums::NINGUNO)
        pantalla = interfaz::ir_a(pantalla);
    empleado::guardar_solo_activos();
}
