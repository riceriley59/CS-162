#include "square.h"

Square::Square(float width, string color, string name) : Rectangle(width, width, color, name) {
    //nothing
}

void Square::set_width(float width){
    this->width  = width;
    this->height = width;
}

void Square::set_height(float height){
    this->width = height;
    this->height = height;
}

void Square::print_object() {
    cout << "\nThis is a square, name " << this->name << " with side length of: " << this->width << " and an area of " << this->area(); 
    cout << " The color is " << this->color << "\n";
}