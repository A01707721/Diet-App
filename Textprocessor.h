/* 
* Proyecto App Calorias
* Adrian Marquez Nunez
* A01707721
* 11/11/2024
*/
//Bibliotecas
#ifndef Textprocessor_H
#define Textprocessor_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

//Clase que ayuda a leer y escribir el archivo .txt
class Textprocessor{
    private:
    //Atributos de la clase: nombre del archivo de texto (name)
    string name;
    public:
    /**Constructor default 
    *@param
    *@return objeto Textprocessor
    */
    Textprocessor():name("Food.txt"){};
    //Metodo que va a un numero de linea
    string go_line(int);
    //Metodo que cuenta la cantidad de lineas del archivo de texto
    int count_lines();
    //Metodos que traducen el texto a otro tipo de datos
    int text_to_int(string);
    float text_to_float(string);
    string text_to_text(string);
};

/**Va a una linea especifica del archivo
*@param int:numero de linea
*@return string:contenido de la linea
*/
string Textprocessor::go_line(int num){
    ifstream file(name);
    string line;
    int currentline=1;
    while(getline(file,line)){
        if(currentline==num){
            file.close();
            return line;
        }
        currentline++;
    }
    
}

/**Cuenta la cantidad de lineas del archivo
*@param 
*@return int:numero de lineas
*/
int Textprocessor::count_lines(){
    ifstream file(name);
    string line;
    int count=0;
    while(getline(file,line)){
        count++;
    }
    file.close();
    return count;
}

/**Traduce texto a un numero entero
*@param string:linea de texto
*@return int:numero de la linea
*/
int Textprocessor::text_to_int(string t){
    int aux=stoi(t);
    return aux;
}

/**Traduce texto a un numero flotante
*@param string:linea de texto
*@return int:numero de la linea
*/
float Textprocessor::text_to_float(string t){
    float aux=stof(t);
    return aux;
}

/**Traduce texto a texto
*@param string:linea de texto
*@return string:texto
*/
string Textprocessor::text_to_text(string t){
    return t;
}

#endif
