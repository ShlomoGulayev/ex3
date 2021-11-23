#include <iostream>
#include "Rational.h"
#include "Poly.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    auto coeffes = std::vector<Rational>{Rational(3,1), Rational(),
    Rational(6,1)};
    Poly p1(coeffes);
    cout << p1 << endl;
    Poly p2(p1);
    cout << p1*p2 << endl;

    exit(EXIT_SUCCESS);
}
