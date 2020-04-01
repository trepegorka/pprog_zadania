#include "Vec.h"
#include "iostream"
#include "cmath"
using namespace std;

void Vec::fillArray() {
    cout<<"Fill array(-1=exit) : ";
    while(digit!=-1){
         cin>>digit;
        arr.push_back(digit);
        if(digit>0){
            dodatnie++;
        }
        if(digit<0){
            ujemne++;
        }
    }
    arr.pop_back();
    ujemne--;
    cout <<"success\n";
}

void Vec::showArray() {
    for (int a: Vec::arr){
        cout << a <<" ";
    }
}

double Vec::srednia() {
    for (int a: arr){
        sredn=sredn+a;
        dd++;
    }
    sredn=sredn/dd;
    return sredn;
}

double Vec::standartoweOdhylenie(){
    for(int i=0; i<dd; i++){
        kwadratyOdchylenia.push_back(pow(arr[i]-sredn, 2));
    }
    for(int i: kwadratyOdchylenia){
        dispersion=dispersion+i;
    }
    return sqrt(dispersion/dd);
}

int Vec::getDodat() {
    return dodatnie;
}

int Vec::getUjemn() {
    return ujemne;
}

void Vec::reverse() {
    for(int i=dd-1; i>-1; i--){
        reverseArr.push_back(arr[i]);
    }
    cout<<"reverse arr: ";
    for(int i: reverseArr){
        cout<<i<<" ";
    }
}
