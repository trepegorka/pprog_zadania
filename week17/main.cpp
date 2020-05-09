#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
        cout << "Constructor" << endl;
    }

    ~SmartPointer() {                                      //własny inteligentny wskaźnik

        delete ptr;
        cout << "Destructor" << endl;
    }

    T &operator*() {
        return *ptr;
    }

private:
    T *ptr;
};

int main() {
    int *A = new int;
    int *B = new int;         // wyciek pamięci, jesli nie uzywamy delete
    *B = *A;
    delete A;
    delete B;


    //używając inteligentnych wskaźników nie używaj delete

    SmartPointer<int> smartPointer = new int(5); //alokacja
    cout << *smartPointer << endl;
    // SmartPointer<int> smartPointer2 = smartPointer; //blad ponieważ usunęli link na smartPointer

    unique_ptr<int> p1(new int(5));                 //alokacja pamięci dla inteligentnego wskaznika za uzywaniem memory
    unique_ptr<int> p2; //empty
    p2 = move(p1);      // -> p2 = p1

    return 0;
}
