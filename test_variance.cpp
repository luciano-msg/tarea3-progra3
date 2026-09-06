#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace core_numeric;

int main() {
    vector<double> vd {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << "variance(vd) = " << variance(vd) << "\n";

    vector<Vec3D> vv {{1,2,3}, {2,4,6}, {3,6,9}};
    Vec3D r = variance(vv);
    cout << "variance(vv) = (" << r.x << ", " << r.y << ", " << r.z << ")\n";

    // ==== Casos que NO compilan ====

    // vector<string> vs {"a", "b", "c"};
    // variance(vs);
    // Falla en la llamada interna a mean: string no cumple Divisible.

    // vector<Punto> vp {{1,2}, {3,4}};
    // variance(vp);
    // Falla el concept Addable: Punto no define operator+.

    return 0;
}
