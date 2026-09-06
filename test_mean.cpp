#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace core_numeric;

int main() {
    vector<double> vd {1.0, 2.0, 3.0, 4.0};
    cout << "mean(vd)  = " << mean(vd) << "\n";

    vector<Vec3D> vv {{2,4,6}, {4,8,12}};
    Vec3D r = mean(vv);
    cout << "mean(vv)  = (" << r.x << ", " << r.y << ", " << r.z << ")\n";

    // ==== Casos que NO compilan ====

    // vector<int> vi {1, 2, 3};
    // mean(vi);
    // Falla el concept Divisible: int / size_t promueve a unsigned long,
    // no cumple same_as<int>.

    // vector<Punto> vp {{1,2}, {3,4}};
    // mean(vp);
    // Falla Addable y Divisible: Punto no tiene operator+ ni operator/.

    return 0;
}
