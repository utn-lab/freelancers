/*
sistema: para correr comandos en el sistema
y mostrar un archivo en la pantalla.
*/

#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "estado.h"

namespace sistema {
    // Devuelve las lineas escritas
    void imprimir_archivo(const char archivo_nombre[]) {
        FILE *archivo;
        archivo = std::fopen(archivo_nombre, "r");
        if (!archivo) {
            std::cerr << "'" << archivo_nombre
                << "' no puede abrirse." << std::endl;
            return;
        }
    
        char buffer;
        while (std::fread(&buffer, sizeof(buffer), 1, archivo)) {
            if (buffer == '\n')
                estado::lineas_ocupadas++;
            std::cout << buffer;
        }
        std::fclose(archivo);
    }

    void clear() {
#ifdef _WIN32
        std::system("cls");
#else 
        std::system("clear");
#endif
        estado::lineas_ocupadas = 0;
    }
}

#endif // SISTEMA_H_INCLUDED
