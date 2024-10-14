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
    void fi(float);

    friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(T val){
    value=val;
    left=0;
    right=0;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T>* l, TreeNode<T>* r ){
    value=val;
    left=l;
    right=r;
}


template <class T>
void TreeNode<T>::inorder(std::stringstream& aux) {
    if (left != 0){
        left ->inorder(aux);
        aux << " ";
    }
    aux << value.get_calories();

    if (right != 0){
        aux << " ";
        right -> inorder(aux);
    }
}

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

template <class T>
void TreeNode<T>::fi(float val){
    if(val == value.get_calories()){
        value.display();
    }
    else{
        if(value.get_calories() > val){
            left->fi(val);
        }
        else if(value.get_calories() < val){
            right->fi(val);
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
    aux << "[";
    root->inorder(aux);
    aux << "]";
    return aux.str();
}


template <class T>
void BST<T>::find(float val){
    if(root != 0){
        root->fi(val);
    }
}



#endif
