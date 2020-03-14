#include <stdio.h>
#include <windows.h>

using namespace  std;

void howToFill(){
    cout<<"\n1. Fill array from the keyboard";
    cout<<"\n2. Fill array by random numbers\nChoose: ";
    cin>>filler;
    if(filler!=1&&filler!=2){
        cout<<"Choose 1 or 2";
        howToFill();
    }
}

void EnterByKey(){
    cout<<"\nEnter A B C of first point: ";
    cin>>point1[0]>>point1[1]>>point1[2];

    cout<<"\nEnter A B C of second point: ";
    cin>>point2[0]>>point2[1]>>point2[2];

    cout<<"\nEnter A B C of third point: ";
    cin>>point3[0]>>point3[1]>>point3[2];
}

void EnterRandom(){
    srand(time(NULL));
    for(int i=0; i<3; i++){
        point1[i]=rand()%2001-1000;
    }
    for(int i=0; i<3; i++){
        point2[i]=rand()%2001-1000;
    }
    for(int i=0; i<3; i++){
        point3[i]=rand()%2001-1000;
    }
}

void showPoint(int a[]){
    cout<< "("<<a[0]<<","<<a[1]<<","<<a[2]<<")";
}
void testIt(){
    if (AC[0]/AB[0]==AC[1]/AB[1]&&AC[1]/AB[1]==AC[2]/AB[2]){
        cout<<"\nPoints A"; showPoint(point1); cout<<" B";showPoint(point2); cout<<" C";showPoint(point3); cout<<" are collinear.";
    } else {
        cout<<"\nPoints A"; showPoint(point1); cout<<" B";showPoint(point2); cout<<" C";showPoint(point3); cout<<" are NOT collinear.";
    }
}

void second(){
    howToFill();
    if(filler==1){
        EnterByKey();
    }
    if(filler==2){
        EnterRandom();
    }

    for (int i=0; i<3; i++){
        AB[i]=point2[i]-point1[i];
    }
    for (int i=0; i<3; i++){
        AC[i]=point3[i]-point1[i];
    }


    testIt();

    cout <<"\nIf you want to do N number of tests, enter N. N==0 => exit(0)";
    cin>>N;
    if(N!=0&&N>0){
        for (int i=0; i<N; i++){
            Sleep(1000);
            EnterRandom();
            testIt();
        }
    } else exit(0);
}
