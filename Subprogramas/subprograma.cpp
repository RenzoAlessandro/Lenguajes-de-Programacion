// Copyright 2020 Renzo Sucari Velasquez
// SubProgramas

/*
// Paso por valor
#include <iostream>
void funcion(int y)
{
    std::cout << "y = " << y <<std::endl;
}
 
int main()
{
    int x = 12;
    funcion(x); 
    return 0;
}
*/
/*
/// Pasar por referencia
#include <iostream>
#include <stdio.h>
void swapnum(int &i, int &j) 
{ 
    int temp = i; 
    i = j; 
    j = temp; 
} 
  
int main(void) 
{ 
    int a = 1000;
    int b = 2000; 
    swapnum(a, b); 
    std::cout<<"Valor de a es: "<< a << " y de b es: "<< b <<std::endl; 
    return 0; 
} 
*/


/*
/// Paso por valor/resultado
#include <iostream>
#include <string.h>
using namespace std;

void intercambio(int a, int b)
{
    int temporal;
    temporal = a;
    a = b;
    b = temporal;
}
int main()
{
  int valor = 12;
  int lista[5] = {4, 6, 7};
  intercambio(value, lista[0]);
  return 0;
}  
*/

/*
// Parametros predeterminados
#include<iostream> 
using namespace std;  
int sumar(int a, int b, int c=0, int d=0) 
{ 
    return (a + b + c + d); 
} 
int main() 
{ 
    cout << sumar(100, 300) << endl;  
    return 0; 
}
*/

#include<iostream>
using namespace std;
template <class T> //int o float
int generica(T *array, T escalar){
    for(int i=0;i<=5;i++){
        if( escalar == array[i])
            return i; // devolvemos el subindice
    }
    return -1; // no encontramos el escalar en el array
}
int main(){
    int array_ints[]={1,2,3,4,5,6};
    float array_floats[]={1.5,2.5,3.5,4.5,5.5};
    if(generica(array_ints,3)>0){
        cout<<" 3 (int) se encuentra en el subíndice "<<generica(array_ints,3)<<endl;
    }
    else{
        cout<<" 3 (int) no encontrado "<<endl;
    }
    if(generica(array_floats,(float)3.5)>0){
        cout<<" 3.5 (float) se encuentra en el subíndice "<<generica(array_floats,(float)3.5)<<endl;
    }
    else{
        cout<<" 3.5 (int) no encontrado "<<endl;
    }
}