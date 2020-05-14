#include <iostream>
#include <mutex>
#include <vector>
#include <fstream>

std::mutex logMutex;
using namespace std;

struct Person {
    string name;
    string surname;
    string pesel;
    int salary[12]{};
    int averageSalary = 0;
};

void fillInformation(Person &person) {
    cout << "Person name: ";
    cin >> person.name;
    cout << "Person surname: ";
    cin >> person.surname;
    cout << "Person pesel: ";
    cin >> person.pesel;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                         "October", "November", "December"};
    cout << "Set salary for every month" << endl;
    for (int i = 0; i < 12; i++) {
        cout << months[i] << ": ";
        cin >> person.salary[i];
    }
    for (int i : person.salary) {
        person.averageSalary = person.averageSalary + i;
    }
    person.averageSalary = person.averageSalary / 12;
}

bool fileExists(string &fileName) {
    return static_cast<bool>(ifstream(fileName));
}

template<typename filename, typename T1, typename T2, typename T3>
bool writeCsvFile(filename &fileName, T1 column1, T2 column2, T3 column3) {
    lock_guard<mutex> csvLock(logMutex);
    fstream file;
    file.open(fileName, ios::out | ios::app);
    if (file) {
        file << "\"" << column1 << "\",";
        file << "\"" << column2 << "\",";
        file << "\"" << column3 << "\"";
        file << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << "Number of employees: ";
    short numberOfEmployyes;
    cin >> numberOfEmployyes;
    Person employee[numberOfEmployyes];
    for (int i = 0; i < numberOfEmployyes; i++) {
        cout << "\nPerson №" << i + 1 << endl;
        fillInformation(employee[i]);
    }

    string csvFile = "logfile2.csv";
    if (!fileExists(csvFile))
        writeCsvFile(csvFile, "PersonName", "Pesel", "AverageSalary");

    for (int i = 0; i < numberOfEmployyes; ++i) {
        if (!writeCsvFile(csvFile, employee[i].name + " " + employee[i].surname, employee[i].pesel,
                          employee[i].averageSalary)) {        //ZAPISYWANIE DANYCH
            cerr << "Failed to write to file: " << csvFile << "\n";
        }
    }

    string line;
    ifstream in("logfile2.csv");                 //WCZYTANIE
    if (in.is_open()) {
        while (getline(in, line)) {
            cout << line << endl;
        }
    }
    in.close();
    // csvFile.clear();

    return 0;
}