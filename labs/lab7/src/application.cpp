#include <vector>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

void print_shape_info(Shape* s){
    s->print_object();
}

int main(){
    vector<Shape *> shapevec;

    shapevec.push_back(new Rectangle(3.0f, 4.0f, "Green", "grect"));
    shapevec.push_back(new Circle(5.5f, "Green", "gcircle"));
    shapevec.push_back(new Square(5.0f, "Green", "gsquare"));
    shapevec.push_back(new Rectangle(4.0f, 5.0f, "Blue", "brect"));
    shapevec.push_back(new Circle(6.5f, "Blue", "bcircle"));
    shapevec.push_back(new Square(6.0f, "Blue", "bsquare"));
    shapevec.push_back(new Rectangle(5.0f, 6.0f, "Yellow", "yrect"));
    shapevec.push_back(new Circle(7.5f, "Yellow", "ycircle"));
    shapevec.push_back(new Square(7.0f, "Yellow", "ysquare"));
    shapevec.push_back(new Rectangle(6.0f, 7.0f, "Purple", "prect"));

    for(int i = 0; i < shapevec.size(); i++){
        print_shape_info(shapevec[i]);
        delete shapevec[i];
        shapevec[i] = NULL;
    }
    
    Shape* rect = new Rectangle(3.0f, 3.0f, "Blue", "Rectangle");
    print_shape_info(rect);

    delete rect;
    rect = NULL;

    return 0;
}