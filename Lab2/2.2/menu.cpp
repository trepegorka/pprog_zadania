#include "MathActions.cpp"
using namespace std;

void showMenu(){
    cout<<"\nWhat do you want?: \n";
    cout<<"1. Sum(+) of 2 digits";
    cout<<"\n2. Subtraction(-) of 2 digits";
    cout<<"\n3. Multiplication(*) of 2 digits";
    cout<<"\n4. Division(/) of 2 digits";
    cout<<"\nChoose by number: ";
    cin>>number;
    cout<<"\nEnter 2 digits: \nA= ";
    cin>>digit1;
    cout<<"B= ";
    cin>>digit2;
    if(number>0&&number<5){
        switch (number){
            case 1:
                cout<<"A + B = "<<Sum(digit1,digit2);
                break;
            case 2:
                cout<<"A - B = "<<Subtraction(digit1,digit2);
                break;
            case 3:
                cout<<"A * B = "<<Multiplication(digit1,digit2);
                break;
            case 4:
                if (digit2==0){
                   cout<<"Impossible /0";
                    exit(0);
                }
                cout<<"A / B = "<<Division(digit1,digit2);
                break;
        }
    } else{
        cout<<"Number is not correct.";
        showMenu();
    }
}

