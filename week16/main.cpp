#include <iostream>
#include <vector>

using namespace std;

struct Person {
    string name;
    string surname;
    string pesel;
    int salary[12]{};
    int averageSalary = 0;
};
vector<Person> firm;

void fillInformation(Person&  person);

void showInformation(const Person &person);

void addPersonToFirm(const Person &person);

void showAll();

void showFirmAverageSalary();

int main() {
    short numberOfEmployyes = 2;
    Person employee[numberOfEmployyes];
    for (int i = 0; i < numberOfEmployyes; i++) {
        cout << "\nPerson №" << i+1 << endl;
        fillInformation(employee[i]);
        addPersonToFirm(employee[i]);
        showInformation(firm[i]);
    }
    showAll();
    showFirmAverageSalary();
    return 0;

}

void fillInformation(Person& person) {
    cout << "Person name: ";
    cin >> person.name;
    cout << "Person surname: ";
    cin >> person.surname;
    cout << "Person pesel: ";
    cin >> person.pesel;
    cout << "Person salary for every month:\nJanuary: ";
    cin >> person.salary[0];
    cout << "February: ";
    cin >> person.salary[1];
    cout << "March: ";
    cin >> person.salary[2];
    cout << "April: ";
    cin >> person.salary[3];
    cout << "May: ";
    cin >> person.salary[4];
    cout << "June: ";
    cin >> person.salary[5];
    cout << "July: ";
    cin >> person.salary[6];
    cout << "August: ";
    cin >> person.salary[7];
    cout << "September: ";
    cin >> person.salary[8];
    cout << "October: ";
    cin >> person.salary[9];
    cout << "November: ";
    cin >> person.salary[10];
    cout << "December: ";
    cin >> person.salary[11];
    for (int i : person.salary) {
        person.averageSalary = person.averageSalary + i;
    }
    person.averageSalary = person.averageSalary / 12;
}

void showInformation(const Person &person) {
    cout << "\n";
    for (int i = 0; i < 20; i++) {
        cout << "-";
    }
    cout << "\n" << person.name << endl;
    cout << person.surname << endl;
    cout << person.pesel << endl;
    cout << person.averageSalary << endl;
    cout << "\n";
    for (int i = 0; i < 20; i++) {
        cout << "-";
    }
}

void addPersonToFirm(const Person &person) {
    firm.push_back(person);
}

void showAll() {
    for (const Person &person : firm) {
        showInformation(person);
    }
}

void showFirmAverageSalary() {
    int bb;
    for (const Person &person: firm) {
        bb = bb + person.averageSalary;
    }
    bb = bb / firm.size();
    cout << "\nAverage salary of the firm is: " << bb << endl;
}
