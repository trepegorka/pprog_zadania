#include "menu.cpp"
using namespace std;

void DecideEquation1(double &x1, double &x2){
    Discrim = (B*B)-(4*A*C);
    if(Discrim>0) {
        switcher=1;
    } else if (Discrim==0){
        switcher=0;
    } else {
        switcher=-1;
    }

    switch (switcher){
        case 1:
            x1 = (B * (-1) + (sqrt(Discrim))) / 2 * A;
            x2 = (B * (-1) - (sqrt(Discrim))) / 2 * A;
            break;
        case 0:
            x1 = (B * (-1) + (sqrt(Discrim))) / 2 * A;
            x2 = x1;
            break;
        case -1:
            cout <<"\nEquation has no decisions";
            exit(0);
    }
}

void second(){
    for(int i=0; i<40; i++){
        cout<<"_";
    }
    cout<<"\nZadanie2\n";
    showText();
    ShowDecision();
    showMenu();
}
