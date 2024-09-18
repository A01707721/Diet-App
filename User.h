#ifndef User_H
#define User_H
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class User{
    private:
    string name;
    int age;
    float weigth;
    float calory_goal;
    public:
    User():name(""), age(0), weigth(0), calory_goal(0){};
    User(string n,int a,float w,float cg): name(n), age(a), weigth(w), calory_goal(cg){};
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

class Food{
    private:
    string name;
    int type;
    float size;
    float calories;
    public:
    Food():name(""),type(0),size(0),calories(0){};
    Food(string n,int t,float s):name(n),type(t),size(s),calories(0){};
    string get_type();
    float get_size();
    float get_calories();
    void display();
};

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

void Food::display(){
    cout << name << endl;
    cout << size << " grams" << endl;
    cout << get_calories() << " calories" << endl;
    cout << endl;
}

#endif
