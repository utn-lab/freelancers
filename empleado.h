#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <cstdio>
#include "enums.h"
#include "etiquetas.h"
#include "pantalla.h"

namespace empleado {
    const char empleado_archivo[] = "empleados.bin";
    int empleados_c;
    estructuras::empleado *empleados;

    estructuras::lista *empleado_a_lista(
            estructuras::empleado *empleado) {
        char *horas_char = new char[32];
        std::snprintf(&horas_char, 32, "%f", empleado->horas_semana);
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

    void liberar_lista(
            estructuras::lista *empleado_lista) {
        delete[] empleado_lista->v[3];
        delete empleado_lista;
    }

    void cargar() {
        FILE *fp;
        fp = std::fopen(empleado_archivo, "rb");
        if (!fp) {
            empleados_c = 0;
            empleados = NULL;
            return;
        }

        std::fseek(fp, 0, SEEK_END);
        long tamano = std::ftell(fp);
        std::rewind(fp);

        if (tamano % sizeof(estructuras::empleado) == 0) {
            empleados_c = tamano / sizeof(estructuras::empleado);
    
            empleados =
                new estructuras::empleado[empleados_c]; // borrar con delete[]
            std::fread(
                    &empleados,
                    sizeof(estructuras::empleado),
                    empleados_c,
                    fp);
        } else {
            empleados_c = 0;
            empleados = NULL;
        }
        std::fclose(fp);
    }

    void liberar() {
        delete[] empleados;
    }

    // Devuelve la cantidad de bytes escritos
    size_t guardar(estructuras::empleado *empleados) {
        FILE *fp;
        fp = std::fopen(empleado_archivo, "wb");
        size_t devolver = std::fwrite(
                &empleados,
                sizeof(empleados),
                1,
                fp);
        std::fclose(fp);
        return devolver;
    }

    void mostrar() {
        // Mostrar titulo
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_EMPLEADO,
                enums::CEN);
        // Mostrar cabecera de grilla
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::EMPLEADO_CABECERA,
                enums::CEN);

        // Esto altera empleado_c y empleados
        cargar();

        if (empleados_c == 0) {
            pantalla::mostrar_campo(
                    etiquetas::no_registros,
                    pantalla::pantalla_ancho,
                    enums::CEN);
            pantalla::mostrar_nueva_linea(1);
            pantalla::mostrar_separadores_h(
                    pantalla::pantalla_ancho);
            pantalla::mostrar_enter();
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
            } else {
                limite = empleados_c;
            }

            for (int renglon = 0; renglon < limite; renglon++) {
                {
                    estructuras::lista *p;
                    p = empleado_a_lista(
                            &empleados[renglon]);
                    pantalla::mostrar_grilla_renglon(
                            &p[renglon],
                            alineaciones);
                    liberar_lista(p);
                }
            }

            estructuras::lista ocurrencias = {
                limite,
                ""
            };

            pantalla::mostrar_separadores_h(
                    pantalla::pantalla_ancho);
            pantalla::mostrar_nueva_linea(1);
            pantalla::mostrar_seleccione(
                    etiquetas::empleado_seleccionar,
                    &ocurrencias);
            liberar();
        }
    }
}

#endif // EMPLEADO_H_INCLUDED
