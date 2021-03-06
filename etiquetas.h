/*
etiquetas: todo texto mostrado en pantalla esta definido
en este archivo, que usa estructuras estructuras::lista
definidas en estructuras.h.
*/

#ifndef ETIQUETAS_H_INCLUDED
#define ETIQUETAS_H_INCLUDED

#include "estructuras.h"

namespace etiquetas {
    const char seleccionar[] = "Seleccione";
    const char continuar[] = "Continuar?";
    const char nuevo_valor[] = "Nuevo valor";
    const char buscar_seleccionar[] = "Buscar palabra o ingresar comando";
    const char invalido[] = "Debe indicar un registro valido, o 'q'.";
    const char no_existe[] = "Agregando un registro nuevo.";
    const char existe[] = "Este registro existe. Los cambios modificaran el registro que ya existe.";
    const char no_registros[] = "No hay registros";
    const char validando[] = "Validando...";
    const char guardando[] = "Guardando...";
    const char enter[] = "Presione enter o ingrese un comando";

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

    estructuras::lista TITULO_EMPLEADO_HORAS = {
        1,
        {
            "CAMBIAR HORAS DE EMPLEADO"
        }
    };

    estructuras::lista TITULO_EMPLEADO_BORRAR = {
        1,
        {
            "BORRAR EMPLEADO"
        }
    };

    estructuras::lista TITULO_EMPLEADO_AGREGAR = {
        1,
        {
            "AGREGAR O MODIFICAR EMPLEADO"
        }
    };

    estructuras::lista TITULO_SECTOR = {
        1,
        {
            "VALORES DE HORA"
        }
    };

    estructuras::lista TITULO_SECTOR_CAMBIAR = {
        1,
        {
            "CAMBIAR VALOR DE HORA"
        }
    };

    estructuras::lista TITULO_AYUDA = {
        1,
        {
            "AYUDA"
        }
    };

    estructuras::lista TITULO_OPCIONES = {
        1,
        {
            "OPCIONES"
        }
    };

    estructuras::lista TITULO_OPCIONES_CAMBIAR = {
        1,
        {
            "CAMBIAR OPCION"
        }
    };

    estructuras::lista TITULO_SALIR = {
        1,
        {
            "SALIR?"
        }
    };

    estructuras::lista MENU_PRINCIPAL = {
        5,
        {
            "Empleados",
            "Valores de hora",
            "Ayuda",
            "Opciones",
            "Salir"
        }
    };

    estructuras::lista EMPLEADO_CABECERA = {
        6,
        {
            "DNI",
            "Nombre",
            "Apellido",
            "Rol",
            "Horas/semana",
            "Salario"
        }
    };

    estructuras::lista SECTOR_CABECERA = {
        2,
        {
            "Rol",
            "Valor de hora"
        }
    };

    estructuras::lista AYUDA = {
        18,
        {
            "Modulos:",
            "",
            "- Empleado: permite ver y agregar empleados, y ver las horas trabajadas",
            "  por ellos",
            "- Valores de hora: para cambiar el valor de hora (salario) para cada rol",
            "",
            "Controles:",
            "",
            "En menu, la primer letra selecciona una opcion (a = ayuda, s = salir);",
            "En grilla:",
            "- Al menos dos letras para buscar palabra",
            "- 'a' = pagina anterior, 's' = siguiente",
            "- 'b' = borrar empleado",
            "- 'n' = nuevo empleado",
            "- 'h' = cambiar horas trabajadas por empleado",
            "- 'q' = salir",
            "Para filtrar el listado de empleados por activos o inactivos, o por sus",
            "respectivos salarios, cambiar estos parametros en Opciones."
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
            "Disenador",
            "Desarrollador",
            "Analista"
        }
    };
}

#endif // ETIQUETAS_H_INCLUDED
