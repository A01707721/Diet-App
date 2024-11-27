/* 
* Proyecto App Calorias
* Adrian Marquez Nunez
* A01707721
* 14/10/2024
*/
#ifndef BST_H
#define BST_H
//Bibliotecas
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "User.h"


template <class T> class BST;

//Clase nodo del BST
template <class T>
class TreeNode{
    private:
    //Apuntadores para sus 2 hojas
    TreeNode<T> *left;
    TreeNode<T> *right;
    //Valor del nodo
    T value;
    //Metodo que imprime el arbol de mayor a menor
    void inorder(std::stringstream& aux);
    public:
    //Constructores
    TreeNode(T);
    TreeNode(T, TreeNode<T>*, TreeNode<T>*);
    //Metodo para añadir un valor
    void add(T);
    //Metodo para ver el nivel del arbol
    int height();
    //Metodo para eliminar a los hijos de un nodo
    void removeChilds();
    //Metodo para encontrar un nodo
    TreeNode<T>* fi(float);
    //Funcion auxiliar para borrar
    TreeNode<T>* predecesor();
    void remove(float);

    friend class BST<T>;
};

/**Constructor default 
*@param
*@return objeto TreeNode
*/
template <class T>
TreeNode<T>::TreeNode(T val){
    value=val;
    left=0;
    right=0;
}

/**Constructor default 
*@param T: valor del nodo, TreeNode ptr: apuntador a la izquierda y derecha
*@return objeto TreeNode
*/
template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T>* l, TreeNode<T>* r ){
    value=val;
    left=l;
    right=r;
}


/**Funcion para imprimir de menor a mayor
*@param stringstream:cadena de texto
*@return
*/
template <class T>
void TreeNode<T>::inorder(std::stringstream& aux) {
    if (left != 0){
        left ->inorder(aux);
        aux << " ";
    }
    aux << value.display();

    if (right != 0){
        aux << " ";
        right -> inorder(aux);
    }
}

/**Funcion para agregar un nodo
*@param T:valor del nodo
*@return
*/
template <class T>
void TreeNode<T>::add(T val){
    if(val.get_calories() < value.get_calories()){
        if(left==0){
            left=new TreeNode<T>(val);
        }
        else{
            left->add(val);
        }
    }
    else{
        if(right==0){
            right=new TreeNode<T>(val);
        }
        else{
            right->add(val);
        }
    }
}

/**Funcion para ver la altura del arbol
*@param 
*@return int:altura del arbol
*/
template <class T>
int TreeNode<T>::height(){
    int height_r=0;
    int height_l=0;
    if(left!=0){
        height_l=left->height();
    }
    if(right!=0){
        height_r=right->height();
    }
    if(height_l > height_r){
        return height_l+1;
    }
    else{
        return height_r+1;
    }

}

/**Funcion para eliminar los hijos del nodo
*@param
*@return
*/
template <class T>
void TreeNode<T>::removeChilds(){
    if (left != 0) {
        left->removeChilds();
        delete left;
        left = 0;
        }
    if (right != 0) {
        right->removeChilds();
        delete right;
        right = 0;
    }
}

/**Funcion para encontrar un nodo
*@param T:valor del nodo
*@return TreeNode ptr: nodo
*/
template <class T>
TreeNode<T>* TreeNode<T>::fi(float val){
    if(val == value.get_calories()){
        return this;
    }
    else{
        if(value.get_calories() > val){
            if(left!=0){
                left->fi(val);
            }
            else{
                return this;
            }
            
        }
        else if(value.get_calories() < val){
            if(right!=0){
                right->fi(val);
            }
            else{
                return this;
            }
            
        }
    }
}

/**Funcion para enocntrar el predecesor del nodo
*@param
*@return TreeNode ptr: predecesor
*/
template <class T>
TreeNode<T>* TreeNode<T>::predecesor(){
    TreeNode<T> *l,*r;
    l=left;
    r=right;
    if(left==0){
        if(right!=0){
            right=0;
        }
        return r;
    }
    if(left->right==0){
       left=left->left;
       l->left=0;
       return l;
    }
    TreeNode<T> *parent, *child;
    parent=left;
    child=left->right;
    while(child->right!=0){
        parent=child;
        child=child->right;
    }
    parent->right=child->left;
    child->left=0;
    return child;
}

/**Funcion para remover el nodo
*@param T:valor del nodo
*@return
*/
template <class T>
void TreeNode<T>::remove(float val){
	TreeNode<T> * succ, *old;

	if (val < value.get_calories()) {
		if (left != 0) {
			if (left->value.get_calories() == val) {
				old = left;
				succ = left->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value.get_calories()) {
		if (right != 0) {
			if (right->value.get_calories() == val) {
				old = right;
				succ = right->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

//Clase BST
template <class T>
class BST{
    private:
    //Raiz del arbol
    TreeNode<T>* root;
    public:
    //Constructor
    BST(): root(0){};
    //Destructor
    ~BST(){
        remove();
    }
    //Metodo para ver los niveles del arbol
    int height();
    //Metodo para eliminar el arbol
    void remove();
    //Metodo para a;adir valores al arbol
    void add(T);
    //Metodo para imrpimir valores del arbol
    std::string visit();
    //Metodo para encontrar un valor en el arbol
    void find(float);
    string delete_node(float);

};


template <class T>
int BST<T>::height(){
    return root->height();
}



template <class T>
void BST<T>::remove(){
    if(root!=0){
        root->removeChilds();
    }
    delete root;
    root=0;

}


template <class T>
void BST<T>::add(T val){
    if(root!=0){
        root->add(val);
    }
    else{
        root=new TreeNode<T>(val);
    }
}


template <class T>
std::string BST<T>::visit(){
    std::stringstream aux;
    aux << "";
    root->inorder(aux);
    aux << "";
    return aux.str();
}


template <class T>
void BST<T>::find(float val){
    if(root != 0){
        TreeNode<T> *aux = root->fi(val);
        if(aux->value.get_calories()==val){
            std::cout << aux->value.display();
        }
        else{
            std::cout << "Food not found" << std::endl;
        }
    }

}

template <class T>
string BST<T>::delete_node(float cal){
    string aux;
    if(root!=0){
        if(cal==root->value.get_calories()){
            TreeNode<T> *succesor = root->predecesor();
            if(succesor!=0){
                succesor->left=root->left;
                succesor->right=root->right;
            }
            aux=root->value.get_name();
            delete root;
            root=succesor;
        }
        else{
            root->remove(cal);
        }
        return aux;
    }
}


#endif
