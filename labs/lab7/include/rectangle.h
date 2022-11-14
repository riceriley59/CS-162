#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    protected:
        float width;
        float height;
    public:
        Rectangle();
        Rectangle(float, float, string, string);

        //getters
        float get_width();
        float get_height();

        //setter
        virtual void set_width(float);
        virtual void set_height(float);

        //member functions
        float area() override;
        virtual void print_object() override;

        ~Rectangle();
};

#endif