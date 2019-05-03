/*
estructuras: estructuras usadas desde otros archivos.
*/

#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include "enums.h"

namespace estructuras {
    // c es el recuento de campos en v,
    // v es un array de arrays char
    struct lista {
        const int c;
        const char *v[18];
    };

    struct empleado {
        bool activo;
        char dni[16];
        char nombre[32];
        char apellido[32];
        float horas_semana;
        enums::sector sector;
    };
}

#endif // ESTRUCTURAS_H_INCLUDED
