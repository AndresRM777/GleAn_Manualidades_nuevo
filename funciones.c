#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"
#include <string.h>

#define MAX_PRODUCTOS 100

float calcularPrecioConIVA(float precio) {
    float porcentajeIVA = 0.12;  // 12% de IVA
    float precioConIVA = precio * (1 + porcentajeIVA);
    return precioConIVA;
}

void ingresarProducto(char nombres[][11], int cantidades[], float precios[], int *numProductos) {
    if (*numProductos == MAX_PRODUCTOS) {
        printf("Inventario lleno. No se pueden agregar mas productos.\n");
        return;
    }

    int numIngresos;
    printf("Digite cantidad de productos que desea ingresar: ");
    numIngresos = leerEntero();

    if (numIngresos <= 0) {
        printf("Numero de productos invalido.\n");
        return;
    }

    for (int i = 0; i < numIngresos; i++) {
        printf("\n--- Ingresar producto %d ---\n", i + 1);
        printf("Nombre producto: ");
        scanf("%10s", nombres[*numProductos]);
        printf("Cantidad: ");
        cantidades[*numProductos] = leerEntero();
        printf("Precio: ");
        precios[*numProductos] = leerFlotante();
        fflush(stdin);

        (*numProductos)++;
    }

    printf("Productos ingresados exitosamente.\n");
}

void editarProducto(char nombres[][11], int cantidades[], float precios[], int numProductos) {
    if (numProductos == 0) {
        printf("Inventario vacio. No se pueden editar productos.\n");
        return;
    }

    int indice;
    printf("\n--- Editar producto ---\n");
    printf("Digite el numero de producto que desea editar (1-%d): ", numProductos);
    indice = leerEntero();

    if (indice < 1 || indice > numProductos) {
        printf("Numero de producto inválido.\n");
        return;
    }

    printf("Nuevo nombre producto: ");
    scanf("%10s", nombres[indice - 1]);
    printf("Nueva cantidad: ");
    cantidades[indice - 1] = leerEntero();
    printf("Nuevo precio: ");
    precios[indice - 1] = leerFlotante();
    fflush(stdin);

    printf("Producto editado exitosamente.\n");
}

void eliminarProducto(char nombres[][11], int cantidades[], float precios[], int *numProductos) {
    if (*numProductos == 0) {
        printf("Inventario vacio. No se pueden eliminar productos.\n");
        return;
    }

    int indice;
    printf("\n--- Eliminar producto ---\n");
    printf("Digite el numero de producto que desea eliminar (1-%d): ", *numProductos);
    indice = leerEntero();

    if (indice < 1 || indice > *numProductos) {
        printf("Numero de producto invalido.\n");
        return;
    }

    for (int i = indice - 1; i < *numProductos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        precios[i] = precios[i + 1];
    }

    (*numProductos)--;

    printf("Producto eliminado exitosamente.\n");
}

void listarProductos(char nombres[][11], int cantidades[], float precios[], int numProductos) {
    if (numProductos == 0) {
        printf("Inventario vacio.\n");
        return;
    }

    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
        printf("  Precio: %.2f\n", precios[i]);
        printf("  Precio con IVA: %.2f\n", calcularPrecioConIVA(precios[i]));
        printf("\n");
    }
}