#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle();
        Circle(float, string, string);

        //getters
        float get_radius();

        //setters
        void set_radius(float);

        //member functions
        float area() override;
        void print_object() override;

        ~Circle();
    
};

#endif