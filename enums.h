/*
enums: hechos para facilitar la lectura de codigo,
usados desde la mayoria de los otros archivos.
*/

#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

namespace enums {
    enum pantalla {
        NINGUNO,
        MENU,
        EMPLEADO,
        SECTOR,
        AYUDA,
        OPCIONES,
        SALIR
    };

    enum sector {
        DISENO = 0,
        DESARROLLO = 1,
        ANALISIS = 2
    };

    enum alineacion {
        IZQ,
        CEN,
        DER
    };
}

#endif // ENUMS_H_INCLUDED
