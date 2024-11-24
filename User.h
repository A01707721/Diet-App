/* 
* Proyecto App Calorias
* Adrian Marquez Nunez
* A01707721
* 18/09/2024
*/
#ifndef User_H
#define User_H
//Bibliotecas
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

//Clase usuario con datos genericos
class User{
    private:
    //Atributos de la clase: nombre del usuario (name), edad (age), peso (weight), meta de calorias del dia (calory_goal)
    string name;
    int age;
    float weigth;
    float calory_goal;
    public:
    /**Constructor default 
    *@param
    *@return objeto User
    */
    User():name(""), age(0), weigth(0), calory_goal(0){};
    /**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre del usuario, int a: edad, float w: peso, float cg: meta de calorias
    *@return objeto User
    */
    User(string n,int a,float w,float cg): name(n), age(a), weigth(w), calory_goal(cg){};
    //Getters y Setters
    string get_name(){
        return name;
    }
    int get_age(){
        return age;
    }
    float get_weight(){
        return weigth;
    }
    float get_cg(){
        return calory_goal;
    }
    void set_name(string n){
        name=n;
    }
    void set_age(int a){
        age=a;
    }
    void set_weigth(float w){
        weigth=w;
    }
    void set_calory(float cg){
        calory_goal=cg;
    }
};

//Clase con informacion de los alimentos
class Food{
    //Atributos de la clase: nombre del alimento (name), tipo de comida (type), tamano de la porcion (size), cantidad de calorias (calories)
    private:
    string name;
    string type;
    float size;
    float calories;
    public:
    /**Constructor default 
    *@param
    *@return objeto Food
    */
    Food():name(""),type(""),size(0),calories(0){};
    /**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre del alimento, string t: tipo de alimento, float s: tamano de la porcion
    *@return objeto Food
    */
    Food(string n,string t,float s):name(n),type(t),size(s),calories(0){};
    //Getters
    string get_name();
    char get_char();
    string get_type();
    float get_size();
    float get_calories();
    //Metodo que muestra toda la info del alimento
    string display();
};

/**Getter nombre del alimento
*@param 
*@return string:nombre 
*/
string Food::get_name(){
    return name;
}

/**Getter primera letra del nombre del alimento
*@param 
*@return char:primer caracter
*/
char Food::get_char(){
    return name[0];
}

/**Getter tipo
*@param 
*@return string:tipo de alimento
*/
string Food::get_type(){
    return type;
}

/**Getter tamano
*@param 
*@return float:tamano de la porcion
*/
float Food::get_size(){
    return size;
}

/**Getter calorias
*@param 
*@return float:cantidad de calorias
*/
float Food::get_calories(){
    float cal=0;
    if(type=="Carbohydrate" || type=="Protein"){
        cal=size*4;
        }
    if(type=="Lipids"){
        cal=size*9;
        }
    calories=cal;
    return calories;
    
}

/**Muestra los datos del objeto en una cadena de texto
*@param 
*@return string:datos del objeto 
*/
string Food::display(){
    stringstream aux;
    aux << name << "\n";
    aux << size << " grams" << "\n";
    aux << get_calories() << " calories" << "\n";
    aux << "\n";
    return aux.str();
}

#endif
