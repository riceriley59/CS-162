#include "circle.h"

Circle::Circle(){
    this->radius = 0;
}

Circle::Circle(float radius, string color, string name) : Shape(color, name){
    this->radius = radius;
}

//getters
float Circle::get_radius(){
    return this->radius;
}

//setters
void Circle::set_radius(float radius){
    this->radius = radius;
}

//member functions
float Circle::area(){
    return (3.14 * this->radius * this->radius);
}

void Circle::print_object(){
    cout << "\nThis is a circle, named " << this->name << ", with radius: " << this->radius << " and an area of " << this->area();
    cout << " with a color of " << this->color << "\n";
}

Circle::~Circle(){
    cout << "\n~Circle\n";
}