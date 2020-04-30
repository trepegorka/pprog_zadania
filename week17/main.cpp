#include <iostream>
#include <vector>

using namespace std;
int main()
{
//    int *A = new int;
//    int *B = new int;
//    A = B;                     // wyciek pamięci
//    delete A;
//    delete B;
    int size;
    int *dan;
    cout << "Enter array size: ";
    cin >> size;
    dan = new int[size];         //alokacja
    for (int i = 0; i<size; i++) {
        cout << "dan[" << i << "] = ";
        cin >> dan[i];
    }
    for (int i = 0; i<size; i++)
        cout << dan[i] << " ";
    vector<int>vec(dan, dan+size);
    delete[] dan;                //uzywanie delete
    return 0;
}
