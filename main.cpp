/*
main: punto de partida para ejecucion del programa.
*/

#include "enums.h"
#include "interfaz.h"
#include "empleado.h"
#include "sector.h"

int main(int argc, char **argv) {
    // Cargar datos de archivos o por defecto
    empleado::cargar();
    sector::cargar();

    // Ir al menu y permanecer en loop hasta que el usuario elija salir
    enums::pantalla pantalla = enums::MENU;
    while (pantalla != enums::NINGUNO)
        pantalla = interfaz::ir_a(pantalla);

    // Limpiar empleados inactivos del archivo empleados::archivo
//    empleado::guardar_solo_activos();
}
