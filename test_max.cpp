#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace core_numeric;

int main() {
    vector<double> vd {1.0, 2.7, 0.3, 2.0};
    cout << "max(vd)   = " << max(vd) << "\n";

    vector<int> vi {10, 3, 42, 7, 15};
    cout << "max(vi)   = " << max(vi) << "\n";

    vector<Vec3D> vv {{1,0,0}, {0,3,0}, {0,0,2}};
    Vec3D r = max(vv);
    cout << "max(vv)   = (" << r.x << ", " << r.y << ", " << r.z << ") "
         << "(por magnitud)\n";

    // ==== Casos que NO compilan ====

    // vector<Punto> vp {{1,2}, {3,4}};
    // max(vp);
    // Falla el concept Comparable: Punto no define operator<.

    return 0;
}
