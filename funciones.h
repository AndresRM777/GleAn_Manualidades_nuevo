#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include "lecturas.h"

void ingresarProducto(char nombres[][11], int cantidades[], float precios[], int *numProductos);
void editarProducto(char nombres[][11], int cantidades[], float precios[], int numProductos);
void eliminarProducto(char nombres[][11], int cantidades[], float precios[], int *numProductos);
void listarProductos(char nombres[][11], int cantidades[], float precios[], int numProductos);

#endif