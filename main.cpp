/*
main: punto de partida para ejecucion del programa.
*/

#include "enums.h"
#include "interfaz.h"
#include "empleado.h"

int main(int argc, char **argv) {
    empleado::cargar();
    sector::cargar();
    interfaz::ir_a(enums::MENU);
}
