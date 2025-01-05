#include <iostream>
#include "Square.h"
#include "Point2D.h"
#include "Rectangle.h"

bool Square::check(Point2D* vertices){

	double d01 = Point2D::distance(vertices[0], vertices[1]);
 	double d23 = Point2D::distance(vertices[2], vertices[3]);
 	double d12 = Point2D::distance(vertices[1], vertices[2]);
 	double d30 = Point2D::distance(vertices[3], vertices[0]);
 	return d01 == d23 && d12 == d30 && d23 == d30;}

Square::Square() : Rectangle("red", new Point2D[N_VERTICES]{
    Point2D(-1, 1),
    Point2D(1, 1),
    Point2D(1, -1),
    Point2D(-1, -1)
}) {}

Square::Square(std::string color, Point2D* vertices): Rectangle("red",vertices){
	if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }

}
void Square::set_vertices(Point2D* vertices){

    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }
    Rectangle::set_vertices(vertices);


}
std::ostream& operator<<(std::ostream &out, const Square &square){

 out << "[Rectangle: color = " << square.color
	<< "; v0 = (" << square.vs[0].x << "," << square.vs[0].y << ")"
	<< "; v1 = (" << square.vs[1].x << "," << square.vs[1].y << ")"
	<< "; v2 = (" << square.vs[2].x << "," << square.vs[2].y << ")"
	<< "; v3 = (" << square.vs[3].x << "," << square.vs[3].y << ")]";        
 return out;


}
void Square::print(){
   std::cout << "[Square: COLOR = " << color
              << "; v0 = (" << vs[0].x << "," << vs[0].y << ")"
              << "; v1 = (" << vs[1].x << "," << vs[1].y << ")"
              << "; v2 = (" << vs[2].x << "," << vs[2].y << ")"                                                                       << "; v3 = (" << vs[3].x << "," << vs[3].y << ")]"                                                                      << std::endl;  
}

double Square::area() const {
    double side = Point2D::distance(get_vertex(0), get_vertex(1));
    return side * side;
}

double Square::perimeter() const {
    double side = Point2D::distance(get_vertex(0), get_vertex(1));
    return 4 * side;
}

void Square::translate(double incX, double incY) {
    for (int i = 0; i < 4; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}
