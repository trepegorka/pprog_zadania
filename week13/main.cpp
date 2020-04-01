#include <iostream>
#include <vector>
#include "Vec.h"

using namespace std;

int main() {
    Vec vec;
    vec.fillArray();
    vec.showArray();
    cout<<"\nsrednia = "<<vec.srednia();
    cout<<"\nstandartowe odchylenie = "<<vec.standartoweOdhylenie();
    cout<<"\nlicba dodatnich = "<<vec.getDodat();
    cout<<"\nlicba ujemnych = "<<vec.getUjemn()<<endl;
    vec.reverse();
}