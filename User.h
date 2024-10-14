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

using namespace std;

//Clase usuario con datos genericos
class User{
    private:
    //Atributos
    string name;
    int age;
    float weigth;
    float calory_goal;
    public:
    //Constructor default
    User():name(""), age(0), weigth(0), calory_goal(0){};
    //Constructor 
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
    //Atributos
    private:
    string name;
    int type;
    float size;
    float calories;
    public:
    //Constructor default
    Food():name(""),type(0),size(0),calories(0){};
    //Constructor
    Food(string n,int t,float s):name(n),type(t),size(s),calories(0){};
    //Getters
    char get_char();
    string get_type();
    float get_size();
    float get_calories();
    //Metodo que muestra toda la info del alimento
    string display();
};

char Food::get_char(){
    return name[0];
}

string Food::get_type(){
    string t;
        if(type==1){
            t="Carbohydrate";
        }
        if(type==2){
            t="Protein";
        }
        if(type==3){
            t="Lipids";
        }
        return t;
}

float Food::get_size(){
    return size;
}

float Food::get_calories(){
    float cal=0;
    if(type==1 || type==2){
        cal=size*4;
        }
    if(type==3){
        cal=size*9;
        }
    calories=cal;
    return calories;
    
}

string Food::display(){
    stringstream aux;
    aux << name << "\n";
    aux << size << " grams" << "\n";
    aux << get_calories() << " calories" << "\n";
    aux << "\n";
    return aux.str();
}

#endif
