﻿#include <iostream>
#include "Rational.h"
#include "Poly.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    //auto coeffes = std::vector<Rational>{ Rational(14,1),
    //Rational(), Rational(), Rational(5,1), Rational(),
    //Rational(17,2) };
    //Poly p1(coeffes);
    //cout << p1 << endl;
    //Poly p2 = p1;
    auto coeffes = std::vector<Rational>{ Rational(5,1),
    Rational(4, 1), Rational(3, 1)};
    Poly p1(coeffes);
    //p2 = p1;
    cout << p1(2) << endl;

    exit(EXIT_SUCCESS);
}
