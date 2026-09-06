#ifndef CLASES_H
#define CLASES_H

#include <cstddef>

// Vec3D cumple todos los concepts (Addable, Divisible, Comparable).
struct Vec3D {
    double x, y, z;

    Vec3D() : x(0), y(0), z(0) {}
    Vec3D(double a, double b, double c) : x(a), y(b), z(c) {}

    Vec3D operator+(const Vec3D& o) const { return {x + o.x, y + o.y, z + o.z}; }
    Vec3D operator-(const Vec3D& o) const { return {x - o.x, y - o.y, z - o.z}; }
    Vec3D operator*(const Vec3D& o) const { return {x * o.x, y * o.y, z * o.z}; }
    Vec3D operator/(std::size_t n) const  { return {x / n, y / n, z / n}; }

    // Comparacion por magnitud al cuadrado (evita sqrt).
    bool operator<(const Vec3D& o) const {
        return (x*x + y*y + z*z) < (o.x*o.x + o.y*o.y + o.z*o.z);
    }
};

// Punto no define ningun operador: no cumple Addable ni Comparable.
struct Punto {
    double x, y;
};

#endif
