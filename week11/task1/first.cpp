#include "variables.h"

using namespace  std;

void Evklid(int a,int b){
    while(a!=0 && b!=0){
        if (a>b){
            a=a%b;
        } else {
            b=b%a;
        }
    }
    cout<<a+b;
}

void first(){
    cout<<"Enter a: ";
    cin>>A;
    cout<<"Enter b: ";
    cin>>B;

    Evklid(A, B);
}

