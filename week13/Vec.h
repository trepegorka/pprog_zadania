#ifndef WEEK13_VEC_H
#define WEEK13_VEC_H


#include <vector>

class Vec {
private:
    std::vector<int> arr;
    std::vector<int> kwadratyOdchylenia;
    std::vector<int> reverseArr;
    int digit;
    double sredn=0;
    int dd=0;
    double dispersion=0;
    int dodatnie=0;
    int ujemne=0;

public  :
    void fillArray();
    void showArray();
    double srednia();
    double standartoweOdhylenie();
    int getDodat();
    int getUjemn();
    void reverse();

};


#endif //WEEK13_VEC_H
