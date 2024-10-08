/* 
* Proyecto App Calorias
* Adrian Marquez Nunez
* A01707721
* 18/09/2024
*/
#ifndef App_H
#define App_H
//Bibliotecas
#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"

using namespace std;

//Clase de la app que maneja los alimentos consumidos y datos del usuario
class CaloryApp{
    private:
	//Atributos
    User Client;
	//Arreglo de alimentos consumidos 
    Food Food_Consumed[100];
	//arreglo auxiliar
    Food Copy[100];
    int food_num;
	//Funciones auxiliares para ordenar
    void copyArray(int, int);
	void mergeSplit(int, int);
    void mergeArray(int, int, int);
    public:
	//Constructor default
    CaloryApp():food_num(0){};
	//Metodo para ordenar alimentos de menor a mayor dependiendo de las calorias
	//Complejidad de tiempo O(nlog(n))
	//Complejidad espacial O(n)
    void merge_sort();
	//Metodo para asignar el usuario
    void assign_User(User&);
	//Metodo para agregar alimentos al arreglo
    void add_Food(string, int, float);
	//Sumatoria de las calorias
	float total_calories();
	//Diferencia entre calorias totales y meta de calorias
	void status();
	//Info de los alimentos
	void info(){
		for(int i=0; i < food_num; i++){
        Food_Consumed[i].display();
    	}
	}


};

void CaloryApp::merge_sort(){
	mergeSplit(0,food_num-1);

}

void CaloryApp::copyArray(int low, int high) {
	for(int i=low; i <= high; i++){
		Food_Consumed[i]=Copy[i];
	}
}

void CaloryApp::mergeArray(int low, int mid, int high) {
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high){
		if(Food_Consumed[i].get_calories() > Food_Consumed[j].get_calories()){
			Copy[k]=Food_Consumed[j];
			j++;
		}
		else{
			Copy[k]=Food_Consumed[i];
			i++;
		}
		k++;
	}

	if(i>mid){
		for(;j<=high;j++){
			Copy[k++]=Food_Consumed[j];
		}
	}
	else{
		for(;i<=mid;i++){
			Copy[k++]=Food_Consumed[i];
		}
	}
}

void CaloryApp::mergeSplit(int low, int high) {
	int mid;
	if(high-low < 1){
			return;
	}
	else{
		mid=(high+low)/2;
		mergeSplit(low,mid);
		mergeSplit(mid+1,high);
		mergeArray(low,mid,high);
		copyArray(low,high);
	}
}

void CaloryApp::assign_User(User &u){
    Client=u;
}

void CaloryApp::add_Food(string n, int t, float s){
    Food_Consumed[food_num]=Food(n,t,s);
    food_num++;
}

float CaloryApp::total_calories(){
	float total=0.0;
	for(int i=0; i < food_num; i++){
		total=total+Food_Consumed[i].get_calories();
	}
	return total;
}

void CaloryApp::status(){
	float diff;
	if(total_calories() > Client.get_cg()){
		diff=total_calories() - Client.get_cg();
		cout << "You have surpassed your calorie goal by: " << diff << endl;
		cout << endl;
	}
	if(total_calories() < Client.get_cg()){
		diff=Client.get_cg() - total_calories();
		cout << "You are under your calorie goal by : " << diff << endl;
		cout << endl;
	}
	if(total_calories() == Client.get_cg()){
		cout << "Good Job, you achieved your calory goal" << endl;
		cout << endl;
	}
}

#endif
