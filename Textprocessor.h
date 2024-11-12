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

class Textprocessor{
    private:
    string name;
    public:
    Textprocessor():name("Food.txt"){};
    string go_line(int);
    int count_lines();
    int text_to_int(string);
    float text_to_float(string);
    string text_to_text(string);
};

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

int Textprocessor::text_to_int(string t){
    int aux=stoi(t);
    return aux;
}

float Textprocessor::text_to_float(string t){
    float aux=stof(t);
    return aux;
}

string Textprocessor::text_to_text(string t){
    return t;
}

#endif
