#include <iostream>
#include <cmath>
using namespace std;


double f(double  x)
{
    return pow(sin(x),2)-x-log(x); //f-cja 1
    //return sin(x)-pow(x,2)-log(x);  //f-cja 2

}
int main()
{
    double a, b, c = 0, e;
    e=0.001;
    a=0;
    b=10;

        if (f(a)*f(b) > 0)
            cout << "Brak pierwiastkow";
        else
        {
            while ((fabs(b - a)) > e )
            {
                if (f(a)*f(c) < 0)
                    b = c;
                else
                    a = c;
                c = (a + b) / 2;
            }
            cout << "\n" << "c=" << c << endl;
        }
    system("exit");
    return 0;
}

