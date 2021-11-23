#include <iostream>
#include "Rational.h"
#include "Poly.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    auto coeffes = std::vector<Rational>{ Rational(),
    Rational(), Rational(), Rational(5,1), Rational(2,1),
    Rational(4,1) };
    Poly p1(coeffes);
    Poly p2(p1);
    cout << p1 << endl;
    cout << p1 - p2 << endl;
    exit(EXIT_SUCCESS);
}
