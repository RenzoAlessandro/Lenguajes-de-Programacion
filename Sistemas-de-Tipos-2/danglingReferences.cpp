// Copyright 2020 Renzo Alessandro Sucari Velasquez
#include<iostream>

int main(){
    //Ejemplo Nº1
    int * puntero_x = new int;
    delete puntero_x;
    int i = *puntero_x; // error, puntero_x ha sido eliminado!

    //Ejemplo Nº2
    int * arrayPtr1;
    int * arrayPtr2 = new int[100];
    arrayPtr1 = arrayPtr2;
    delete [] arrayPtr2;
    //Ahora, arrayPtr1 está colgando, porque el almacenamiento 
    //dinámico al que apuntaba ha sido desasignado.
}