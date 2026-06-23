#include <iostream>
#include "line.h"
#include "point.h"

using namespace std;

int main() {
    Line l;
    Point p;

    cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    double g = gradient(&l, &p);
    string hasil = CheckPointPosition(g);

    cout << hasil;

    return 0;
}