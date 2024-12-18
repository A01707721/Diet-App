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
#include <fstream>
#include "User.h"
#include "App.h"
#include "Textprocessor.h"

using namespace std;

//Menu inicial
void menu(){
    cout << endl;
    cout << "What do you wanna consult" << endl;
    cout << "1. Food eaten through the day" << endl;
    cout << "2. Status of you calory goal" << endl;
    cout << "3. Add food to the list" << endl;
    cout << "4. Find a food based on the amount of calories" << endl;
    cout << "5. Save changes on the file" << endl;
    cout << "6. Exit" << endl;
}

//Menu secundario en caso de elegir la opcion 1
void menu_1(){
    cout << endl;
    cout << "In what order do you wanna consult" << endl;
    cout << "1. Alphabetically" << endl;
    cout << "2. By calories" << endl;
    cout << endl;
}



int main(){
    //Variables bool para continuar mostrando el menu
    bool cond=true;
    //Variables int para seleccionar en los menus
    int a=0,sel=0,sel_1=0;
    //Variables para los constrcutores de objetos
    string n,t,fn;
    float w=0,cg=0,s=0, find_calories=0;
    //Bienvenida
    cout << endl;
    cout << "Welcome to the calory tracker" << endl;
    cout << endl;
    cout << "Firts let's create your user" << endl;
    //Creacion de la app
    CaloryApp Test("Tracker app");
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
    Test.initialize();
    Test.merge_sort();
    while(cond==true){
        menu();
        cout << "Select: " << endl;
        cin >> sel;
        //Opcion para consultar la info de los alimentos en orden alfabetico o menor a mayor
        if(sel==1){
            menu_1();
            cout << "Select: " << endl;
            cin >> sel_1;
            cout << endl;
            if(sel_1==1){
                Test.order_alpha();
            }
            else if(sel_1==2){
                Test.order_cal();
            }
            cout << endl;
            sel=0;
            sel_1=0;
        }
        //Opcion para consultar el estatus de tu meta de calorias
        if(sel==2){
            cout << endl;
            Test.status();
            cout << endl;
            sel=0;
        }
        //Opcion para registrar mas alimentos consumidos
        if(sel==3){
            cout << "Name of the food (in lowercase letters): " << endl;
            cin.ignore();
            getline(cin,fn);
            cout << "Type of food" << endl;
            cout << "(Carbohydrate, Protein, Lipids): ";
            cin >> t;
            cout << "Size in grams: ";
            cin >> s;
            Test.add_Food(fn,t,s);
            Test.merge_sort();
            cout << endl;
            sel=0;
        }
        //Opcion para buscar un alimento en el BST
        if(sel==4){
            cout << "Amount of calories to find a certain food:" << endl;
            cin >> find_calories;
            cout << endl;
            Test.find(find_calories); 
            sel=0; 
        }
        //Opcion para guardar los cambio en el archivo
        if(sel==5){
            Test.rewrite();
            cout << "The file has been updated :)" << endl;
        }
        //Opcion para salir
        if(sel==6){
            cout << "\n Thanks for using the app" << endl;
            cond=false;
            cout << endl;
            
        }
        //Validacion en caso de numero no aceptado
        if(sel>6 || sel<0){
            cout << "Invalid option" << endl;
            cout << endl;
        }
    }
    return 0;
}
