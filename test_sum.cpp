#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace core_numeric;

int main() {
    vector<int> vi {1, 2, 3, 4};
    cout << "sum(vi)   = " << sum(vi) << "\n";

    vector<double> vd {1.5, 2.5, 3.0};
    cout << "sum(vd)   = " << sum(vd) << "\n";

    vector<Vec3D> vv {{1,2,3}, {4,5,6}, {7,8,9}};
    Vec3D r = sum(vv);
    cout << "sum(vv)   = (" << r.x << ", " << r.y << ", " << r.z << ")\n";

    // ==== Casos que NO compilan (descomentar para verificar) ====

    // vector<Punto> vp {{1,2}, {3,4}};
    // sum(vp);
    // Falla el concept Addable: Punto no define operator+.

    // int x = 5;
    // sum(x);
    // Falla el concept Iterable: int no tiene begin()/end().

    return 0;
}
