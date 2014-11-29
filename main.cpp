#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
//REFERENCIA:
//CLASE PROGRAMACION 3 DEL MIERCOLES 12-NOVIEMBRE-2014
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str()); //Se crea archivo mediante un objeto de la clase ofstream
    out<<num<<endl; //Leemos la variable tipo "int" llamada num que se almacena en el archivo
    out.close(); //Siempre debemos cerrar la escritura con un "out.close()"
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//leeremos el archivo mediante un objeto de la clase ifstream
    int num; //creamos una variable tipo "int" llamada "num" que se lee del archivo.
    in>>num; //leemos la variable num que esta almacenada
    return num; //retornamos la variable con el resultado.
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
//REFERENCIA:
//CLASE PROGRAMACION 3 DEL MIERCOLES 12-NOVIEMBRE-2014
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//Se crea archivo mediante un objeto de la clase ofstream
    out<<str<<endl;//Leemos la variable tipo "string" llamada str que se almacena en el archivo
    out.close();//Siempre debemos cerrar la escritura con un "out.close()"
}
string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//leeremos el archivo mediante un objeto de la clase ifstream
    string str; //creamos una variable tipo "string" llamada "str" que se lee del archivo.
    in>>str; //leemos la variable num que esta almacenada
    return str; //retornamos la variable con el resultado.
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
//REFERENCIA:
//CLASE PROGRAMACION 3 DEL MIERCOLES 12-NOVIEMBRE-2014 & LUNES 17-NOVIEMBRE-2014
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str());//Se crea archivo mediante un objeto de la clase ofstream
    out.write((char*)&num,4);//Leemos la variable tipo "int" llamada "num" que se almacena en el archivo
    out.close();//Siempre debemos cerrar la escritura con un "out.close()"
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//leeremos el archivo mediante un objeto de la clase ifstream
    int leido; //Creamos una variable tipo "int"  llamada "leido"
    in.read((char*)&leido,4); //leemos la variable "leido" que esta almacenada
    return leido;//retornamos la variable con el resultado.
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
//REFERENCIA:
//CLASE PROGRAMACION 3 DEL MIERCOLES 12-NOVIEMBRE-2014 & LUNES 17-NOVIEMBRE-2014
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//Se crea archivo mediante un objeto de la clase ofstream
    out.write(str.c_str(),4);//Leemos la variable tipo "string" llamada "str" que se almacena en el archivo
    out.close();//Siempre debemos cerrar la escritura con un "out.close()"
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());//leeremos el archivo mediante un objeto de la clase ifstream
    char leido[4]; //Creamos una variable tipo "arreglo"  llamada "leido"
    in.read(leido,4); //Leemos la variable tipo "arreglo" llamada "leido" que se almacena en el archivo
    return leido; //retornamos la variable con el resultado.
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    return false;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
//REFERENCIA:
//https://github.com/Ceutec/ArchivosBinarios/blob/master/main.cpp
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str());//leeremos el archivo mediante un objeto de la clase ifstream
    in.seekg(0,ios::end); //usamos seekg para movernos al final del archivo
    int tamano = in.tellg();// asignamos el tamano en una variable.
    in.seekg(0,ios::beg);//usamos seekg para desplazarnos al inicio.

    int mayor = -999;//creamos la variable "mayor" y le asignamos un valor negativo para usarlo en un IF
    while(in.tellg()<tamano)//Creamos un ciclo While para que se mueva hasta que se cumpla la condicion.
    {
        int num;//creamos una variable tipo "int" llamada "num"
        in.read((char*)&num,4);// leemos el valor y lo asignamos a la variable num
        if(mayor<num) //creamos un ciclo IF para hacer la comparacion de los numeros y devolver el numero mayor
            mayor = num;// asignamos el valor mayor que encuentre en la variable "num" y se asigna a la variable "mayor"
    }
    return mayor;//devolvemos la variable "mayor" contienendo el numero mayor.
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
