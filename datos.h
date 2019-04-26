/*
datos: a borrar.
Debe ser reemplazado por horas.h y salario.h, similares a empleado.h,
cuando estos esten listos.
*/

#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#include <cstdlib>
#include <cstdio>

#include "enums.h"
#include "etiquetas.h"
#include "estructuras.h"

namespace datos {
    const char horas_archivo[] = "horas.bin";
    const char salario_archivo[] = "salario.bin";
    float valor_hora[3];

    void cargar_default() {
        valor_hora[enums::DISENO] = 0;
        valor_hora[enums::DESARROLLO] = 0;
        valor_hora[enums::ANALISIS] = 0;
    }

    void cambiar_salario(
            enums::sector sector,
            float nuevo_salario) {
        valor_hora[sector] = nuevo_salario;
    }
}

#endif // DATOS_H_INCLUDED
