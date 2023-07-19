#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#include "lecturas.h"

#define MAX_PRODUCTOS 100

void mostrarMenu();
float calcularPrecioConIVA(float precio);
void registrarEntrada(const char *usuario);

int main() {
    char nombres[MAX_PRODUCTOS][11];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion;
    char password[8];
    char correctPassword[] = "1234567";
    char usuario[50];

    printf("Ingrese su nombre de usuario(Nombres y Apellidos): ");
    leerCadena(usuario, 50);

    do {
        printf("Ingrese la clave (maximo 7 caracteres): ");
        leerCadena(password, 8);

        if (strcmp(password, correctPassword) != 0 || strlen(password) != 7) {
            printf("Clave incorrecta o excede los 7 caracteres. Intente nuevamente.\n");
        }
    } while (strcmp(password, correctPassword) != 0 || strlen(password) != 7);

    registrarEntrada(usuario);

    do {
        mostrarMenu();
        opcion = leerEntero();

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 2:
                editarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 3:
                eliminarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 4:
                listarProductos(nombres, cantidades, precios, numProductos);
                break;
            case 5:
                printf("Cambios finalizados\n");
                break;
            default:
                printf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

void mostrarMenu() {
    printf("\n--- Sistema de Inventario ---\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Salir\n");
    printf("Selecciona una opcion: ");
}

void registrarEntrada(const char *usuario) {
    time_t tiempoActual;
    struct tm *tiempoInfo;
    char buffer[80];

    time(&tiempoActual);
    tiempoInfo = localtime(&tiempoActual);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", tiempoInfo);

    FILE *archivo = fopen("registro.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "Usuario: %s, Entrada: %s\n", usuario, buffer);
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo de registro.\n");
    }
}