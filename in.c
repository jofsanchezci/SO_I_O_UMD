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
