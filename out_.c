#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[255];

    // Abrir archivo de entrada en modo lectura
    inputFile = fopen("entrada.txt", "r");

    // Verificar si el archivo se abrió correctamente
    if (inputFile == NULL) {
        printf("Error al abrir archivo de entrada.\n");
        return 1;
    }

    // Abrir archivo de salida en modo escritura
    outputFile = fopen("salida.txt", "w");

    // Verificar si el archivo se abrió correctamente
    if (outputFile == NULL) {
        printf("Error al abrir archivo de salida.\n");
        return 1;
    }

    // Leer del archivo de entrada y escribir en el archivo de salida
    while (fgets(buffer, 255, inputFile) != NULL) {
        fprintf(outputFile, "Procesando: %s", buffer);
    }

    // Cerrar los archivos
    fclose(inputFile);
    fclose(outputFile);

    printf("Archivo procesado correctamente.\n");
    return 0;
}
