#include "CoreNumeric.h"
#include "Clases.h"
#include <iostream>

using namespace std;
using namespace core_numeric;

int main() {
    auto s1 = sum_variadic(1, 2, 33, 4);
    cout << "sum_variadic(1,2,33,4)         = " << s1 << "\n";

    auto s2 = mean_variadic(0.1, 2.0, 3.0, 4.0);
    cout << "mean_variadic(0.1,2,3,4)       = " << s2 << "\n";

    // mean con enteros: gracias al if constexpr se promueve a double.
    auto s2b = mean_variadic(1, 2, 3, 4);
    cout << "mean_variadic(1,2,3,4)         = " << s2b << "\n";

    auto s3 = variance_variadic(1, 2, 3, 4);
    cout << "variance_variadic(1,2,3,4)     = " << s3 << "\n";

    auto s4 = max_variadic(1, 2, 3, 4);
    cout << "max_variadic(1,2,3,4)          = " << s4 << "\n";

    // Con Vec3D
    Vec3D a{1,0,0}, b{0,2,0}, c{0,0,3};
    Vec3D s5 = sum_variadic(a, b, c);
    cout << "sum_variadic(a,b,c) Vec3D      = ("
         << s5.x << ", " << s5.y << ", " << s5.z << ")\n";

    // ==== Casos que NO compilan ====

    // sum_variadic(Punto{1,2}, Punto{3,4});
    // Falla el concept Addable: Punto no define operator+.

    // max_variadic(Punto{1,2}, Punto{3,4});
    // Falla el concept Comparable: Punto no define operator<.

    return 0;
}
