/*
empleado: mantiene y muestra datos de empleados en
la pantalla, usando funciones de pantalla.h.
*/

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <cstdio>

// Necesario para nuevo()
#include <cstring>
#include <iostream>

#include "enums.h"
#include "estructuras.h"
#include "etiquetas.h"
#include "pantalla.h"

namespace empleado {
    // Archivo que guarda vector de estructura::empleado
    const char archivo[] = "empleados.bin";
    // Recuento de empleados
    int empleados_c = 0;
    // Contenido de archivo una vez cargado en memoria
    estructuras::empleado *empleados;

    // Declara estructura::lista a partir de estructura::empleado,
    // devolviendo un puntero a la estructura::lista
    estructuras::lista *empleado_a_lista(
            estructuras::empleado *empleado) {
        char *horas_char = new char[16];
        std::snprintf(horas_char, 16, "%.1f", empleado->horas_semana);
        estructuras::lista *empleado_lista = new estructuras::lista {
            5,
            {
                empleado->dni,
                empleado->nombre,
                empleado->apellido,
                horas_char,
                etiquetas::EMPLEADO_TIPOS.v[empleado->sector]
            }
        };
        return empleado_lista;
    }

    // Borra la lista devuelta por empleado_a_lista
    // de la memoria
    void liberar_lista(
            estructuras::lista *empleado_lista) {
        delete[] empleado_lista->v[3];
        delete empleado_lista;
    }

    // Borra datos de vector de empleados
    void liberar() {
        empleados_c = 0;
        delete[] empleados;
        empleados = NULL;
    }

    // Puebla vector de estructura::empleado, leyendo archivo
    void cargar() {
        if (empleados_c)
            liberar();
        else {
            empleados_c = 0;
            empleados = NULL;
        }

        FILE *fp;
        fp = std::fopen(archivo, "rb");
        
        // Si el archivo no existe o no puede ser abierto
        if (!fp)
            return;

        // Calcular tamano total de archivo
        std::fseek(fp, 0, SEEK_END);
        long tamano = std::ftell(fp);
        std::rewind(fp);

        if (tamano % sizeof(estructuras::empleado) == 0) {
            // Guardar el archivo entero en memoria
            empleados_c = tamano / sizeof(estructuras::empleado);
    
            empleados =
                new estructuras::empleado[empleados_c]; // borrar con delete[]
            std::fread(
                    empleados,
                    sizeof(estructuras::empleado),
                    empleados_c,
                    fp);
        }
        std::fclose(fp);
    }

    void a_minusculas(char *string) {
        int i = 0;
        while (string[i] != '\0') {
            if (string[i] >= 'A'
                    && string[i] <= 'Z')
                string[i] += 32;
            i++;
        }
    }

    bool buscar_patron(const char *array, const char *patron) {
        char temp_1[32];
        char temp_2[32];
        std::strcpy(temp_1, array);
        std::strcpy(temp_2, patron);
        a_minusculas(temp_1);
        a_minusculas(temp_2);
        return (std::strstr(temp_1, temp_2) != NULL);
    }

    // Muestra pantalla empleado
    void mostrar(
            const int empezar_por_indice,
            const char *patron) { // patron puede ser NULL
        // Mostrar titulo
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_EMPLEADO,
                enums::CEN);
        // Mostrar cabecera de grilla
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::EMPLEADO_CABECERA,
                enums::CEN);

        // Si no hay empleados cargados
        if (empleados_c == 0) {
            pantalla::mostrar_campo(
                    etiquetas::no_registros,
                    pantalla::pantalla_ancho,
                    enums::CEN);
            pantalla::mostrar_nueva_linea(1);
            pantalla::mostrar_separadores_h(
                    pantalla::pantalla_ancho);
            pantalla::mostrar_seleccione(
                    etiquetas::enter,
                    0);
        } else {
            // Por cada columna, elegir una alineacion
            // Esto afecta a renglones y no a la cabecera
            enums::alineacion alineaciones[] = {
                enums::DER,
                enums::IZQ,
                enums::IZQ,
                enums::DER,
                enums::CEN
            };
            // Si la cantidad de empleados es superior a lo que la grilla
            // permite ver, el limite es el buffer de grilla
            int limite;
            if (empleados_c > pantalla::grilla_buffer) {
                limite = pantalla::grilla_buffer;
                limite += empezar_por_indice;
            } else {
                limite = empleados_c;
            }

            // Mostrar renglones de grilla
            estructuras::lista *p;
            int ocurrencias = 0;
            // Empezando por el indice indicado por el parametro
            // empezar_por_indice, recorrer array de empleados
            for (
                    int renglon = empezar_por_indice;
                    renglon < limite;
                    renglon++) {
                // Si empleado esta activo (inactivo = borrado), y si patron
                // es nulo, o no es nulo, pero el parametro coincide
                if (empleados[renglon].activo
                        && (!patron
                            || buscar_patron(
                                empleados[renglon].dni, patron)
                            || buscar_patron(
                                empleados[renglon].nombre, patron)
                            || buscar_patron(
                                empleados[renglon].apellido, patron))) {
                    // pantalla::mostrar_grilla_renglon recibe un
                    // estructuras::lista como parametro, pero el
                    // vector de empleados que estamos leyendo
                    // contiene estructura::empleado
                    // Convertirlo
                    p = empleado_a_lista(
                            &empleados[renglon]);
                    // Pasar a mostrar_grilla_renglon
                    pantalla::mostrar_grilla_renglon(
                            p,
                            alineaciones);
                    liberar_lista(p);
                    ocurrencias++;
                }
            }

            // Si un patron fue definido
            if (patron) {
                if (ocurrencias == 0) {
                    pantalla::mostrar_campo(
                            etiquetas::no_registros,
                            pantalla::pantalla_ancho,
                            enums::CEN);
                    pantalla::mostrar_nueva_linea(1);
                }
                pantalla::mostrar_separadores_h(
                        pantalla::pantalla_ancho);
                pantalla::mostrar_seleccione(
                        etiquetas::enter,
                        0);
            } else {
                pantalla::mostrar_separadores_h(
                        pantalla::pantalla_ancho);
                pantalla::mostrar_nueva_linea(1);
                pantalla::mostrar_seleccione(
                        etiquetas::buscar_seleccionar,
                        ocurrencias);
            }
        }
    }

    void nuevo() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_EMPLEADO_AGREGAR,
                enums::CEN);
        estructuras::empleado nuevo_empleado;

        nuevo_empleado.activo = true;

        // DNI
        nuevo_empleado.dni[0] = '\0';
        // Validar que el usuario no presione enter
        while (nuevo_empleado.dni[0] == '\0') {
            std::cout << etiquetas::EMPLEADO_CABECERA.v[0] << ": ";
            std::cin.getline(nuevo_empleado.dni, 16);
            std::cout << etiquetas::validando << std::endl;
            if (std::strcmp(nuevo_empleado.dni, "q") == 0)
                return;
        }

        // Chequear si el DNI existe en la lista actual de empleados
        int existe = -1;
        for (int i = 0; i < empleados_c; i++) {
            if (std::strcmp(
                        empleados[i].dni,
                        nuevo_empleado.dni) == 0) {
                existe = i;
                break;
            }
        }

        pantalla::mostrar_nueva_linea(1);
        // Nombre
        std::cout << etiquetas::EMPLEADO_CABECERA.v[1] << ": ";
        std::cin.getline(nuevo_empleado.nombre, 32);

        // Apellido
        std::cout << etiquetas::EMPLEADO_CABECERA.v[2] << ": ";
        std::cin.getline(nuevo_empleado.apellido, 32);

        // Horas/semana
        std::cout << etiquetas::EMPLEADO_CABECERA.v[3] << ": ";
        std::cin >> nuevo_empleado.horas_semana;

        // Sector
        {
            int temp = -1;

            std::cout << etiquetas::EMPLEADO_CABECERA.v[4]
                << " (1-" << etiquetas::EMPLEADO_TIPOS.c << "):";
            pantalla::mostrar_nueva_linea(1);
            pantalla::mostrar_lista_vertical(
                    &etiquetas::EMPLEADO_TIPOS,
                    enums::IZQ);
            pantalla::mostrar_nueva_linea(1);
            while (!(temp >= 1 && temp <= 3)) {
                std::cout << etiquetas::seleccionar << ": ";
                std::cin >> temp;
                std::cin.ignore();
            }
            nuevo_empleado.sector = (enums::sector)(temp - 1);
        }
        std::cout << etiquetas::guardando << std::endl;

        // Guardar dato en archivo
        FILE *fp;
        if (existe == -1) {
            // Ya que no existe, vamos a agregar el empleado al archivo
            fp = std::fopen(archivo, "ab");
        } else {
            // El DNI existe, reescribir registro
            fp = std::fopen(archivo, "rb+");
            std::fseek(
                    fp,
                    sizeof(estructuras::empleado) * existe,
                    SEEK_SET);
        }
        std::fwrite(
                &nuevo_empleado, sizeof(estructuras::empleado), 1, fp);
        std::fclose(fp);
    }
}

#endif // EMPLEADO_H_INCLUDED
