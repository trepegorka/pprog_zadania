#include <stdio.h>
#include <windows.h>

using namespace  std;

void howToFill(){                //metoda pyta, jak wypełnić punkty A B C: z klawiatury lub losowo.
    cout<<"\n1. Fill array from the keyboard";
    cout<<"\n2. Fill array by random numbers\nChoose: ";
    cin>>filler;
    if(filler!=1&&filler!=2){
        cout<<"Choose 1 or 2";
        howToFill();
    }
}

void EnterByKey(int liczbaWspol){              //jesli wybrac 1(z klawiatury), metoda prosi o wprowadzenie 3 cyfr z klawiatury dla każdego punktu.
    if (liczbaWspol==3){
        cout<<"\nEnter A B C of first point: ";
        cin>>point1[0]>>point1[1]>>point1[2];

        cout<<"\nEnter A B C of second point: ";
        cin>>point2[0]>>point2[1]>>point2[2];

        cout<<"\nEnter A B C of third point: ";
        cin>>point3[0]>>point3[1]>>point3[2];
    }
    if (liczbaWspol==2){
        cout<<"\nEnter x y of first point: ";
        cin>>point1_2[0]>>point1_2[1];

        cout<<"\nEnter x y of second point: ";
        cin>>point2_2[0]>>point2_2[1];

        cout<<"\nEnter x y of third point: ";
        cin>>point3_2[0]>>point3_2[1];
    }
}

void EnterRandom(int liczbaWspol){              //esli wybor 2(random), metoda wybiera losowe liczby dla każdego punktu
    if (liczbaWspol==3){
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
    if (liczbaWspol==2){

        srand(time(NULL));
        for(int i=0; i<2; i++){
            point1_2[i]=rand()%2001-1000;
        }
        for(int i=0; i<2; i++){
            point2_2[i]=rand()%2001-1000;
        }
        for(int i=0; i<2; i++){
            point3_2[i]=rand()%2001-1000;
        }
    }
}

void showPoint(int a[], int liczbaWspol){         //pokaza współrzędne punktu
   if (liczbaWspol==3){
       cout<< "("<<a[0]<<","<<a[1]<<","<<a[2]<<")";
   }
   if (liczbaWspol==2){
        cout<< "("<<a[0]<<","<<a[1]<<")";
   }
}

void testIt2(int x, int y){
    int linear = (((point2_2[1] - point1_2[1]) * (x - point1_2[0])) / (point2_2[0] - point1_2[0])) + point1_2[1];
    if(y==linear){
        cout<<"\nPoints A"; showPoint(point1_2, 2); cout<<" B";showPoint(point2_2, 2);
        cout<<" C";showPoint(point3_2,2); cout<<" are collinear.";
    }else {
        cout<<"\nPoints A"; showPoint(point1_2, 2); cout<<" B";showPoint(point2_2, 2);
        cout<<" C";showPoint(point3_2,2); cout<<" are NOT collinear.";
    }
}

void testIt(int liczbaWspol){                  //metoda sprawdza, czy punkty sa współliniowe i wyswietla w console
    switch (liczbaWspol){
        case 3:
            if (AC[0]/AB[0]==AC[1]/AB[1]&&AC[1]/AB[1]==AC[2]/AB[2]){
                cout<<"\nPoints A"; showPoint(point1, 3); cout<<" B";showPoint(point2, 3);
                cout<<" C";showPoint(point3,3); cout<<" are collinear.";
            } else {
                cout<<"\nPoints A"; showPoint(point1,3); cout<<" B";showPoint(point2,3);
                cout<<" C";showPoint(point3,3); cout<<" are NOT collinear.";
            }
            break;
        case 2:
            testIt2(c[0],c[1]);
           break;
    }
}

void second(int liczbaWspol){    //po prostu metoda ktora zawiera w sobie wszystkie metody, zeby nie pisac to w main()
    if (liczbaWspol==3){         //esli punkt wyglada: A(x,y,z).
        howToFill();
        if(filler==1){
            EnterByKey(3);
        }
        if(filler==2){
            EnterRandom(3);
        }

        for (int i=0; i<3; i++){
            AB[i]=point2[i]-point1[i];
        }
        for (int i=0; i<3; i++){
            AC[i]=point3[i]-point1[i];
        }


        testIt(3);

        cout <<"\nIf you want to do N number of tests, enter N. N==0 => exit(0)";
        cin>>N;
        if(N!=0&&N>0){
            for (int i=0; i<N; i++){
                Sleep(1000);
                EnterRandom(3);
                testIt(3);
            }
        } else exit(0);
    }
    else if(liczbaWspol==2){       //esli punkt wyglada: A(x,y).
        howToFill();
        if(filler==1){
            EnterByKey(2);
        }
        if(filler==2){
            EnterRandom(2);
        }
        testIt2(point3_2[0],point3_2[1]);

        cout <<"\nIf you want to do N number of tests, enter N. N==0 => exit(0)";
        cin>>N;
        if(N!=0&&N>0){
            for (int i=0; i<N; i++){
                Sleep(1000);
                EnterRandom(2);
                testIt(2);
            }
        } else exit(0);
    }
}

// (y-a[1])(b[0]-a[0])=(b[1]-a[1])(x-a[0])
// ((y-a[1])(b[0]-a[0]))/(b[1]-a[1])=x-a[0]
// y=(((b[1]-a[1])(x-a[0]))/(b[0]-a[0]))+a[1]
// x=(((y-a[1])(b[0]-a[0]))/(b[1]-a[1]))+a[0]
