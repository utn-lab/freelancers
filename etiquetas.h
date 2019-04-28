/*
etiquetas: todo texto mostrado en pantalla esta definido
en este archivo, que usa estructuras estructuras::lista
definidas en estructuras.h.
*/

#ifndef ETIQUETAS_H_INCLUDED
#define ETIQUETAS_H_INCLUDED

#include "estructuras.h"

namespace etiquetas {
    const char app_nombre[] = "FREELANCERS";
    const char por_favor[] = "Seleccione una opcion";
    const char empleado_seleccionar[] = "Buscar palabra o seleccionar fila";
    const char no_registros[] = "No hay registros";
    const char validando[] = "Validando...";
    const char guardando[] = "Guardando...";
    const char existe[] = "El registro que esta intentando ingresar ya existe. Presione enter para modificarlo, o 'q' para volver";
    const char enter[] = "Presione enter";

    estructuras::lista TITULO_MENU_PRINCIPAL = {
        1,
        {
            "BIENVENIDO"
        }
    };

    estructuras::lista TITULO_EMPLEADO = {
        1,
        {
            "EMPLEADOS"
        }
    };

    estructuras::lista TITULO_EMPLEADO_AGREGAR = {
        1,
        {
            "NUEVO EMPLEADO"
        }
    };

    estructuras::lista TITULO_HORAS = {
        1,
        {
            "PLANILLA DE HORAS"
        }
    };

    estructuras::lista TITULO_SECTOR = {
        1,
        {
            "VALORES DE HORA"
        }
    };

    estructuras::lista TITULO_AYUDA = {
        1,
        {
            "AYUDA"
        }
    };

    estructuras::lista TITULO_SALIR = {
        1,
        {
            "SALIR"
        }
    };

    estructuras::lista MENU_PRINCIPAL = {
        5,
        {
            "Empleados",
            "Planilla de horas",
            "Valores de hora",
            "Ayuda",
            "Salir"
        }
    };

    estructuras::lista EMPLEADO_CABECERA = {
        5,
        {
            "DNI",
            "Nombre",
            "Apellido",
            "Horas/semana",
            "Rol"
        }
    };

    estructuras::lista HORAS_CABECERA = {
        2,
        {
            EMPLEADO_CABECERA.v[0],
            EMPLEADO_CABECERA.v[3]
        }
    };

    estructuras::lista SECTOR_CABECERA = {
        2,
        {
            "Sector",
            "Valor de hora"
        }
    };

    estructuras::lista AYUDA = {
        11,
        {
            "Modulos:",
            "",
            "- Empleado: permite ver y agregar empleados",
            "- Planilla de horas: para ver las horas trabajadas por empleados",
            "- Valores de hora: para cambiar el valor de hora (salario) para cada rol",
            "",
            "Controles:",
            "",
            "En menu, la primer letra selecciona una opcion (a = ayuda, s = salir);",
            "En grilla, al menos dos letras para buscar palabra; 'q' para salir;",
            "'a' para pagina anterior, 's' para siguiente."
        }
    };

    estructuras::lista SALIR = {
        2,
        {
            "SI (enter, q, s, y)",
            "NO (n, otras teclas)"
        }
    };

    estructuras::lista EMPLEADO_TIPOS = {
        3,
        {
            "Diseñador",
            "Desarrollador",
            "Analista"
        }
    };
}

#endif // ETIQUETAS_H_INCLUDED
