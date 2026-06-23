#include "line.h"

double gradient(const Line * l, const Point * p) {
    double hasil = l->a * p->x + l->b * p->y + l->c;
    return hasil;
}

std::string CheckPointPosition(double gradient) {
    if (gradient > EPSILON)
        return "Left";
    else if (gradient < -EPSILON)
        return "Right";
    else
        return "On Line";
}