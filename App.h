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
#include "Bst.h"
#include "Textprocessor.h"

using namespace std;

//Clase de la app que maneja los alimentos consumidos y datos del usuario
class CaloryApp{
    private:
	//Atributos
	string name;
    User Client;
	//Arreglo de alimentos consumidos 
    vector<Food> Food_Consumed;
	//arreglo auxiliar
    vector<Food> Copy;
	//BST
	BST<Food> Tree;
	//Objeto auxiliar para el texto
	Textprocessor Text;
	//Numero para conteo de lineas
	int num_text;
	//Funciones auxiliares para ordenar
    void copyArray(int, int);
	void mergeSplit(int, int);
    void mergeArray(int, int, int);
    public:
	/**Constructor default 
    *@param
    *@return objeto App
    */
	CaloryApp():name(""),num_text(1){};
	/**Constructor donde se reciben las variables para los diferentes atributos
    *@param string n: el nombre de la app
    *@return objeto App
    */
    CaloryApp(string n):name(n),num_text(1){};
	//Metodo para ordenar alimentos de menor a mayor dependiendo de las calorias
	//Complejidad de tiempo O(nlog(n))
	//Complejidad espacial O(n)
    void merge_sort();
	//Metodo para asignar el usuario
    void assign_User(User&);
	//Metodo para agregar alimentos al arreglo
    void add_Food(string, string, float);
	//Sumatoria de las calorias
	float total_calories();
	//Diferencia entre calorias totales y meta de calorias
	void status();
	//Encuentra un alimento en el arbol en base a sus calorias
	void find(float);
	//Lectura de archivos
	void read();
	//Copiar el archivo a la estructura
	void initialize();
	//Modificar el archivo
	void rewrite();
	//Info de los alimentos en orden alfabetico
	void order_alpha(){
		for(int i=0; i < Food_Consumed.size(); i++){
        cout << Food_Consumed[i].display();
    	}
	}
	//Info de los alimentos en orden menor a mayor
	void order_cal(){
		cout << Tree.visit() << endl;
	}


};

/**Funcion para ordenar
*@param 
*@return
*/
void CaloryApp::merge_sort(){
	mergeSplit(0,Food_Consumed.size()-1);

}

/**Funcion para ordenar
*@param int:indices del vector
*@return
*/
void CaloryApp::copyArray(int low, int high) {
	for(int i=low; i <= high; i++){
		Food_Consumed[i]=Copy[i];
	}
}

/**Funcion para ordenar
*@param int:indices del vector
*@return
*/
void CaloryApp::mergeArray(int low, int mid, int high) {
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	char c_i,c_j,c_k;
	while(i<=mid && j<=high){
		c_i=Food_Consumed[i].get_char();
		c_j=Food_Consumed[j].get_char();
		c_k=Food_Consumed[k].get_char(); 
		if(c_i > c_j){
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

/**Funcion para ordenar
*@param int:indices del vector
*@return
*/
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

/**Funcion para agregar un usuario
*@param User:usuario
*@return
*/
void CaloryApp::assign_User(User &u){
    Client=u;
}

/**Funcion para agregar comida al vector y BST
*@param string:nombre del alimento, string:tipo de alimento, float:tamano
*@return
*/
void CaloryApp::add_Food(string n, string t, float s){
	Food F(n,t,s);
    Food_Consumed.push_back(F);
	Copy.push_back(F);
	Tree.add(F);
}

/**Funcion para obtener el total de calorias consumidas
*@param 
*@return float:total de calorias
*/
float CaloryApp::total_calories(){
	float total=0.0;
	for(int i=0; i < Food_Consumed.size(); i++){
		total=total+Food_Consumed[i].get_calories();
	}
	return total;
}

/**Funcion para mostrar el estatus con respecto a la meta de calorias
*@param
*@return
*/
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

/**Funcion para buscar un objeto por calorias en el BST
*@param float:calorias
*@return
*/
void CaloryApp::find(float cal){
	Tree.find(cal);
}

/**Funcion para leer texto del archivo y convertirlo en objetos en las estructuras
*@param 
*@return
*/
void CaloryApp::read(){
	int aux=num_text;
	string n,t,aux_text;
	float s;
	aux_text=Text.go_line(aux);
	n=Text.text_to_text(aux_text);
	aux++;
	aux_text=Text.go_line(aux);
	t=Text.text_to_text(aux_text);
	aux++;
	aux_text=Text.go_line(aux);
	s=Text.text_to_float(aux_text);
	aux++;
	num_text=num_text+4;
	add_Food(n,t,s);
}

/**Funcion para inicializar los objetos default del archivo de texto
*@param
*@return
*/
void CaloryApp::initialize(){
	int aux=(Text.count_lines()/4);
	while(aux>0){
		read();
		aux--;
	}
}

/**Funcion para sobrescribir los cambios hechos en los alimentos en el archivo
*@param 
*@return
*/
void CaloryApp::rewrite(){
	ofstream file("Food.txt");
	for(int i=0; i < Food_Consumed.size(); i++){
		file << Food_Consumed[i].get_name() << "\n";
		file << Food_Consumed[i].get_type() << "\n";
        file << Food_Consumed[i].get_size() << "\n";
		file << "\n";
    }
	file.close();
}


#endif
