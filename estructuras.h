#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include "enums.h"

namespace estructuras {
    struct lista {
        const int c;
        const char *v[12];
    };

    struct empleado {
        bool activo;
        char dni[16];
        char nombre[32];
        char apellido[32];
        float horas_semana;
        enums::sector sector;
    };

    struct horas {
        char dni[8];
        float horas;
    };

    struct sector {
        enums::sector sector;
        float valor_hora;
    };
}

#endif // ESTRUCTURAS_H_INCLUDED
