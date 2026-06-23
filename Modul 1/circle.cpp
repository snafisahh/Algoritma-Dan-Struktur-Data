#include "circle.h"
#include <cmath>

double distance(const Circle * c,const Point * p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    return sqrt(dx * dx + dy * dy);
}

std::string CheckPointInCircle(double distance, double radius) {
    if (fabs(distance - radius) < EPSILON)
        return "On Circle";
    else if (distance < radius)
        return "Inside";
    else
        return "Outside";
}