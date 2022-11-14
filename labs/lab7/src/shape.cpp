#include "shape.h"

Shape::Shape(){
    this->color = "NONE";
}

Shape::Shape(string color, string name) : name(name){
    this->color = color;
}

//setters
void Shape::set_color(string color){
    this->color = color;
}

//getters
string Shape::get_name() const{
    return this->name;
}

string Shape::get_color() const{
    return this->color;
}

//member functions
Shape::~Shape(){
    cout << "\n~Shape\n";
}