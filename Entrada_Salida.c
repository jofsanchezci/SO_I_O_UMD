#include <unistd.h>   // Para read(), write(), close()
#include <fcntl.h>    // Para open()

int main() {
    char buffer[100];
    int fd_in, fd_out;
    ssize_t n;

    // Abrir el archivo de entrada
    fd_in = open("entrada.txt", O_RDONLY);
    if (fd_in < 0) {
        write(1, "Error al abrir el archivo de entrada.\n", 39);
        return 1;
    }

    // Abrir el archivo de salida
    fd_out = open("salida.txt", O_WRONLY | O_CREAT, 0644);
    if (fd_out < 0) {
        write(1, "Error al abrir el archivo de salida.\n", 38);
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
