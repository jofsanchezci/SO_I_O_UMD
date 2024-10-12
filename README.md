
# Gestión de Entrada y Salida en Sistemas Operativos - Implementaciones en C

Este documento contiene implementaciones básicas en C que ilustran la gestión de **entrada** y **salida** en un sistema operativo. Aquí se proporcionan tres ejemplos de cómo se pueden gestionar estas acciones en diferentes contextos.

## 1. Entrada de Datos desde el Usuario
Este programa recibe una cadena de texto y la muestra como salida.

```c
#include <stdio.h>

int main() {
    char input[100];  // Buffer para la entrada del usuario

    // Solicitar entrada al usuario
    printf("Ingrese una cadena de texto: ");
    
    // Leer la entrada del usuario
    fgets(input, 100, stdin);

    // Mostrar lo que el usuario ingresó
    printf("Has ingresado: %s", input);

    return 0;
}
```

### Explicación:
- **Entrada**: Se usa la función `fgets()` para leer una cadena de texto desde el teclado (dispositivo de entrada estándar).
- **Salida**: Utilizamos `printf()` para mostrar la cadena ingresada.

## 2. Gestión de Archivos como Entrada y Salida
Este programa lee datos de un archivo y escribe el resultado en otro archivo.

```c
#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[255];

    // Abrir archivo de entrada en modo lectura
    inputFile = fopen("entrada.txt", "r");

    // Verificar si el archivo se abrió correctamente
    if (inputFile == NULL) {
        printf("Error al abrir archivo de entrada.
");
        return 1;
    }

    // Abrir archivo de salida en modo escritura
    outputFile = fopen("salida.txt", "w");

    // Verificar si el archivo se abrió correctamente
    if (outputFile == NULL) {
        printf("Error al abrir archivo de salida.
");
        return 1;
    }

    // Leer del archivo de entrada y escribir en el archivo de salida
    while (fgets(buffer, 255, inputFile) != NULL) {
        fprintf(outputFile, "Procesando: %s", buffer);
    }

    // Cerrar los archivos
    fclose(inputFile);
    fclose(outputFile);

    printf("Archivo procesado correctamente.
");
    return 0;
}
```

### Explicación:
- **Entrada**: Se lee desde el archivo `entrada.txt` utilizando la función `fgets()`.
- **Proceso**: El programa toma cada línea del archivo de entrada y la procesa.
- **Salida**: Se escribe el resultado procesado en `salida.txt` usando `fprintf()`.

## 3. Entrada/Salida con System Calls (Llamadas al Sistema)
Un ejemplo más cercano a cómo los sistemas operativos manejan la entrada y salida utilizando las llamadas al sistema Unix **`read()`** y **`write()`**.

```c
#include <unistd.h>   // Para read(), write(), close()
#include <fcntl.h>    // Para open()

int main() {
    char buffer[100];
    int fd_in, fd_out;
    ssize_t n;

    // Abrir el archivo de entrada
    fd_in = open("entrada.txt", O_RDONLY);
    if (fd_in < 0) {
        write(1, "Error al abrir el archivo de entrada.
", 39);
        return 1;
    }

    // Abrir el archivo de salida
    fd_out = open("salida.txt", O_WRONLY | O_CREAT, 0644);
    if (fd_out < 0) {
        write(1, "Error al abrir el archivo de salida.
", 38);
        close(fd_in);
        return 1;
    }

    // Leer desde el archivo de entrada y escribir en el archivo de salida
    while ((n = read(fd_in, buffer, sizeof(buffer))) > 0) {
        write(fd_out, buffer, n);
    }

    // Cerrar los archivos
    close(fd_in);
    close(fd_out);

    return 0;
}
```

### Explicación:
- **Entrada**: Utilizamos la syscall `read()` para leer desde el archivo de entrada.
- **Salida**: Utilizamos la syscall `write()` para escribir en el archivo de salida.
- **Syscalls**: Las llamadas al sistema `read()`, `write()`, y `open()` interactúan directamente con el sistema operativo a bajo nivel.

---

Estos ejemplos reflejan cómo un sistema operativo maneja la comunicación entre dispositivos de entrada y salida, simulando cómo los programas interactúan con esos dispositivos para completar un ciclo de entrada-proceso-salida.
