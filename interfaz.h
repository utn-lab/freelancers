/*
interfaz: contiene funcion ir_a, llamada desde main.cpp,
que controla el curso del programa y recibe respuesta del
usuario.
*/

#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include "estado.h"
#include "enums.h"
#include "sistema.h"
#include "varios.h"
#include "empleado.h"
#include "sector.h"

namespace interfaz {
    // Indice en empleado::empleados desde donde empezar
    // a mostrar datos en grilla
    int grilla_indice = 0;
    // Usada desde ir_a
    enums::pantalla pantalla_actual;
    // Respuesta de usuario
    char respuesta[100];

    // Llamada desde ir_a
    void recibir_respuesta() {
        std::cin.getline(respuesta, 100);
    }

    // ir_a: responsable del flujo del programa
    enums::pantalla ir_a(enums::pantalla pantalla) {
        if (pantalla != enums::AYUDA
                and pantalla != enums::SALIR)
            pantalla_actual = pantalla;
        sistema::clear();
        respuesta[0] = '\0';
        switch (pantalla) {
            case enums::MENU:
                menu::mostrar();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '1':
                    case 'e':
                        return enums::EMPLEADO;
                        break;

                    case '2':
                    case 'v':
                        // Valores de hora
                        return enums::SECTOR;
                        break;

                    case '4':
                    case 'o':
                        return enums::OPCIONES;
                        break;

                    case '5':
                    case 's':
                    case 'q':
                        return enums::SALIR;
                        break;

                    default:
                        return enums::AYUDA;
                        break;
                }
                break;

            case enums::EMPLEADO:
                // El argumento es un patron
                // Si es NULL, muestra todos los empleados
                empleado::mostrar(NULL);
                recibir_respuesta();

                if (empleado::empleados_c
                        && std::strlen(respuesta) >= 2) {
                    // Buscar empleado
                    sistema::clear();
                    empleado::mostrar(respuesta);
                    recibir_respuesta();
                    switch (respuesta[0]) {
                        case 'h':
                            sistema::clear();
                            empleado::cambiar_horas();
                            return enums::EMPLEADO;
                            break;
                    }
                    return enums::EMPLEADO;
                } else {
                    switch (respuesta[0]) {
                        case 'a':
                            estado::empezar_por_indice -=
                                pantalla::grilla_buffer;
                            if (estado::empezar_por_indice < 0)
                                estado::empezar_por_indice = 0;
                            return enums::EMPLEADO;
                            break;

                        case 's':
                            estado::empezar_por_indice +=
                                pantalla::grilla_buffer;
                            if (estado::empezar_por_indice
                                    > empleado::empleados_c)
                                estado::empezar_por_indice =
                                    empleado::empleados_c;
                            return enums::EMPLEADO;
                            break;

                        case 'h':
                            sistema::clear();
                            empleado::cambiar_horas();
                            return enums::EMPLEADO;
                            break;

                        case 'n':
                            sistema::clear();
                            empleado::nuevo();
                            empleado::cargar();
                            return enums::EMPLEADO;
                            break;

                        case 'b':
                            // Borrar
                            sistema::clear();
                            empleado::borrar();
                            return enums::EMPLEADO;
                            break;

                        case 'q':
                            return enums::MENU;
                            break;

                        default:
                            return enums::AYUDA;
                            break;
                    }
                }
                break;

            case enums::SECTOR:
                sector::cargar();
                sector::mostrar();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '1':
                    case '2':
                    case '3':
                        sistema::clear();
                        sector::cambiar_valor(
                                (enums::sector)(respuesta[0] - 49));
                        sector::guardar();
                        return enums::SECTOR;
                        break;

                    case 'q':
                        return enums::MENU;
                        break;

                    default:
                        return enums::AYUDA;
                        break;
                }
                break;

            case enums::AYUDA:
                ayuda::mostrar();
                recibir_respuesta();
                if (std::strcmp("q", respuesta) == 0)
                    return enums::MENU;
                else
                    return pantalla_actual;
                break;

            case enums::OPCIONES:
                opciones::mostrar();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '1':
                    case 'm':
                        estado::mostrar_eliminados =
                            (!estado::mostrar_eliminados);
                        if (!estado::mostrar_eliminados)
                            estado::mostrar_eliminados_solamente = false;
                        return enums::OPCIONES;
                        break;

                    case '2':
                        estado::mostrar_eliminados_solamente =
                            (!estado::mostrar_eliminados_solamente);
                        if (estado::mostrar_eliminados_solamente)
                            estado::mostrar_eliminados = true;
                        return enums::OPCIONES;
                        break;

                    case '3':
                        sistema::clear();
                        opciones::cambiar();
                        std::cin >> estado::salario_desde;
                        std::cin.ignore();
                        return enums::OPCIONES;
                        break;

                    case '4':
                        sistema::clear();
                        opciones::cambiar();
                        std::cin >> estado::salario_hasta;
                        std::cin.ignore();
                        return enums::OPCIONES;
                        break;

                    case 'q':
                        return enums::MENU;
                        break;

                    default:
                        return enums::AYUDA;
                        break;
                }
                break;

            case enums::SALIR:
                salir::mostrar();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '\0':
                    case '1':
                    case 'q':
                    case 'y':
                        sistema::clear();
                        return enums::NINGUNO;
                        break;

                    default:
                        return pantalla_actual;
                        break;
                }
                break;

            default:
                return enums::AYUDA;
                break;
        }
        return pantalla;
    }
}

#endif // INTERFAZ_H_INCLUDED
