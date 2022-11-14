#include "rectangle.h"

Rectangle::Rectangle(){
    this->width = 0;
    this->height = 0;
}

Rectangle::Rectangle(float width, float height, string color, string name) : Shape(color, name) {
    this->width = width;
    this->height = height;
}

//getters
float Rectangle::get_width(){
    return this->width;
}

float Rectangle::get_height(){
    return this->height;
}

//setter
void Rectangle::set_width(float width){
    this->width = width;
}

void Rectangle::set_height(float height){
    this->height = height;
}

//member functions
float Rectangle::area(){
    return this->width * this->height;
}

void Rectangle::print_object(){
    cout << "\nThis is a rectangle, named: " << this->name << ", with a height of: " << this->height << " and a width of: " << this->width << " and an area of " << this->area();
    cout << " with a color of: " << this->color << "\n"; 
}

Rectangle::~Rectangle(){
    cout << "\n~Rectangle\n";
}