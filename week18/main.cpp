#include <iostream>

using namespace std;

//algorytm Euklidesa
int NWD(int a, int b) {
    if (a != b)
        return NWD(a > b ? a - b : a, b > a ? b - a : b);
    return a;
}

//ciąg Fibonacciego
int fib(int n) {
    if (n < 3)
        return 1;

    return fib(n - 2) + fib(n - 1);
}

//podnoszenie do potęgi
int power(long int x, unsigned int y) {
    int d = 0;
    if (y == 0)
        d = 1;
    else if (y == 1)
        d = x;
    else if (y % 2 == 0)
        d = power(x * x, y / 2);
    else
        d = x * power(x * x, y / 2);
    return d;
}

//wypisanie wyrazu wspak
void RevStr(char *S, int l) {
    char c;
    if (l > 1) {
        c = S[0];
        S[0] = S[l - 1];
        S[l - 1] = c;
        RevStr(S + 1, l - 2);
    }
}

//silnię
long long silnia(int n) {
    if (n < 2)
        return 1; //silnia z 0 i 1 wynosi 1

    return n * silnia(n - 1);
}

int main() {
    //algorytm Euklidesa
    int a, b;
    cout << "Podaj dwie liczby: ";
    cin >> a >> b;
    cout << "NWD(" << a << "," << b << ") = " << NWD(a, b) << endl;

    //ciąg Fibonacciego
    int n;
    cout << "Podaj nr wyrazu ciągu: ";
    cin >> n;
    cout << n << " wyraz ciągu ma wartość " << fib(n) << endl;

    //podnoszenie do potęgi
    int a1, b1;
    cout << "Podaj liczbe: " << endl;
    cin >> a1;
    cout << "Podaj liczbe: " << endl;
    cin >> b1;
    cout << power(a1, b1) << endl;

    //wypisanie wyrazu wspak
    char S[12] = "Test";
    RevStr(S, 11);
    cout << S << endl;

    //silnię
    int N;
    cout << "Podaj liczbę: ";
    cin >> N;
    cout << "N! = " << silnia(N) << endl;
    
    return 0;
}
