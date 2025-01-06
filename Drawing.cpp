#include <typeindex>
#include <iostream>
#include <typeinfo>
#include "Drawing.h"

Drawing::Drawing() {
    shapes = new ListLinked<Shape*>;
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); ++i) {
        delete shapes->get(i);
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
    }
}

double Drawing::get_area_all_circles() {
    double areaT = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle != nullptr) {
            areaT += circle->area();
        }
    }
    return areaT;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square != nullptr) {
            square->translate(incX, incY);
        }
    }
}

