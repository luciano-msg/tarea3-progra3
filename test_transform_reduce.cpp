#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace core_numeric;

int main() {
    vector<double> vd {1.0, 2.0, 3.0, 4.0};

    // Suma de cuadrados: 1 + 4 + 9 + 16 = 30
    auto r1 = transform_reduce(vd, [](double x) { return x * x; });
    cout << "sum de cuadrados = " << r1 << "\n";

    // Suma de dobles: 2 + 4 + 6 + 8 = 20
    auto r2 = transform_reduce(vd, [](double x) { return x * 2; });
    cout << "sum de dobles    = " << r2 << "\n";

    vector<Vec3D> vv {{1,2,3}, {4,5,6}};
    Vec3D r3 = transform_reduce(vv, [](const Vec3D& v) {
        return Vec3D{v.x * 2, v.y * 2, v.z * 2};
    });
    cout << "sum (Vec3D * 2)  = (" << r3.x << ", " << r3.y << ", " << r3.z << ")\n";

    // ==== Casos que NO compilan ====

    // int x = 5;
    // transform_reduce(x, [](int a) { return a; });
    // Falla el concept Iterable: int no tiene begin()/end().

    return 0;
}
