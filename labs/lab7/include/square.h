#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle{
    public:
        Square();
        Square(float, string, string);

        void set_width(float width) override;
        void set_height(float height) override;
        void print_object() override;
};

#endif