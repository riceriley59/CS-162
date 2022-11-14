#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

using namespace std;

class Shape{
    protected:
        const string name;
        string color;
    public:
        Shape();
        Shape(string, string);

        //setters
        void set_color(string);

        //getters
        string get_name() const;
        string get_color() const;

        //member functions
        virtual float area() = 0;
        virtual void print_object() = 0;

        virtual ~Shape();
};

#endif