#include <iostream>
#include "circle.h"
#include "point.h"

using namespace std;

int main() {
    Circle c;
    Point p;

    cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y;

    double d = distance(&c, &p);    
    string hasil = CheckPointInCircle(d, c.radius);

    cout << hasil;

    return 0;
}