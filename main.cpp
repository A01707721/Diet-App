/* 
* Proyecto App Calorias
* Adrian Marquez Nunez
* A01707721
* 18/09/2024
*/
//Bibliotecas
#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"
#include "App.h"

using namespace std;

//Manu
void menu(){
    cout << "What do you wanna consult" << endl;
    cout << "1. Food eaten through the day" << endl;
    cout << "2. Status of you calory goal" << endl;
    cout << "3. Add food to the list" << endl;
    cout << "4. Exit" << endl;
}


int main(){
    //Variables
    bool cond=true;
    int a=0,sel=0,t=0;
    string n,fn;
    float w=0,cg=0,s=0;
    //Bienvenida
    cout << "Welcome to the calory tracker" << endl;
    cout << "Firts let's create your user" << endl;
    //Creacion de la app
    CaloryApp Test;
    //Registro de info del usuario
    cout << "Name: " << endl;
    cin.ignore();
    getline(cin,n);
    cout << "Age: ";
    cin >> a;
    cout << "Weight: ";
    cin >> w;
    cout << "Calory goal: ";
    cin >> cg;
    //Asignacion del usuario a la app
    User U(n, a, w, cg);
    Test.assign_User(U);
    //Asigancion de alimentos al arreglo
    Test.add_Food("banana",1,100);
    Test.add_Food("orange",1,50);
    Test.add_Food("bread",1,25);
    Test.add_Food("muffin",1,250);
    Test.add_Food("pasta",1,75);
    Test.merge_sort();
    while(cond==true){
        menu();
        cout << "Select: " << endl;
        cin >> sel;
        //Opcion para consultar la info de los alimentos
        if(sel==1){
            cout << endl;
            Test.info();
            cout << endl;
        }
        //Opcion para consultar el estatus de tu meta de calorias
        if(sel==2){
            cout << endl;
            Test.status();
            cout << endl;
        }
        //Opcion para registrar mas alimentos consumidos
        if(sel==3){
            cout << "Name of the food: " << endl;
            cin.ignore();
            getline(cin,fn);
            cout << "Type of food" << endl;
            cout << "(1. Carbohydrate, 2. Protein, 3. Lipids): ";
            cin >> t;
            cout << "Size in grams: ";
            cin >> s;
            Test.add_Food(fn,t,s);
            Test.merge_sort();
            cout << endl;
        }
        //Opcion para salir
        if(sel==4){
            cond=false;
            cout << endl;
        }
        //Validacion en caso de numero no aceptado
        if(sel>4 || sel<0){
            cout << "Invalid option" << endl;
            cout << endl;
        }
    }
    return 0;
}
