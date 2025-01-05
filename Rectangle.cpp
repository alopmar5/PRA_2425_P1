#include <stdexcept>
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);

    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return d01 == d23 && d12 == d30;
}

Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1, 0.5),
        Point2D(1, 0.5),
        Point2D(1, -0.5),
        Point2D(-1, -0.5)
    };
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no conforman un rectángulo válido");
    }

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("El vértice no se encuentra en el rectángulo");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un rectángulo válido.");
    }

    delete[] vs;
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this == &r) {
        return *this;
    }

    delete[] vs;
    this->color = r.color;

    this->vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        this->vs[i] = r.vs[i];
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "[Rectangle: color = " << r.color
        << "; v0 = (" << r.vs[0].x << "," << r.vs[0].y << ")"
        << "; v1 = (" << r.vs[1].x << "," << r.vs[1].y << ")"
        << "; v2 = (" << r.vs[2].x << "," << r.vs[2].y << ")"
        << "; v3 = (" << r.vs[3].x << "," << r.vs[3].y << ")]";
    return out;
}

double Rectangle::area() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return base * altura;
}

double Rectangle::perimeter() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return 2 * (base + altura);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << "[Rectangle: color = " << color
              << "; v0 = (" << vs[0].x << "," << vs[0].y << ")"
              << "; v1 = (" << vs[1].x << "," << vs[1].y << ")"
              << "; v2 = (" << vs[2].x << "," << vs[2].y << ")"
              << "; v3 = (" << vs[3].x << "," << vs[3].y << ")]"
              << std::endl;
}




