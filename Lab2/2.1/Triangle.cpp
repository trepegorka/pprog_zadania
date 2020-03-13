#include <cmath>
using namespace std;

void IsRectangular(){
    if(A>(B&&C)){
        if(A*A==B*B+C*C){
            cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you can build a right triangle";
        } else cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you CAN'T build a right triangle";
    } else if(B>(A&&C)){
        if(B*B==A*A+C*C){
            cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you can build a right triangle";
        } else cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you CAN'T build a right triangle";
    } else if(C>(A&&B)){
        if(C*C==A*A+B*B){
            cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you can build a right triangle";
        } else cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you CAN'T build a right triangle";
    } else cout<<"\nWith sides "<<A<<", "<<B<<", "<<C<<" you CAN'T build a right triangle";
}