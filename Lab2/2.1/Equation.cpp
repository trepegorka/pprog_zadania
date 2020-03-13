#include "Equation.h"
#include <string>
#include <cmath>
#include <stdlib.h>
#include "Triangle.cpp"

using namespace std;

    void showText() {
        cout << "We have an equation of the form Ax^2 + Bx + C.\nPlease, enter A: ";
        cin >> A;
        cout << "enter B: ";
        cin >> B;
        cout << "enter C: ";
        cin >> C;
        cout << "\nOur equation is: " << A << "x^2 + " << B << "x + " << C;
    }

    void DecideEquation(double &x1, double &x2) {
        Discrim = (B * B) - (4 * A * C);
        if (Discrim > 0) {
            x1 = (B * (-1) + (sqrt(Discrim))) / 2 * A;
            x2 = (B * (-1) - (sqrt(Discrim))) / 2 * A;
        } else if (Discrim == 0) {
            x1 = (B * (-1) + (sqrt(Discrim))) / 2 * A;
            x2 = x1;
        } else {
            cout << "\nEquation has no decisions";
            exit(0);
        }
    }

    void ShowDecision() {
        DecideEquation(x1, x2);
        cout << fixed;
        cout.precision(2);
        if (x1 != x2) {
            cout << "\nx1 = " << x1 << "\nx2 = " << x2;
        } else if (x1 == x2) {
            cout << "\nx = " << x1;
        } else {
            cout << "\nEquation has no decisions";
        }
    }

void first() {
        cout<<"Zadanie 1\n";
        showText();
        ShowDecision();
        IsRectangular();
        cout<<"\n";
}

