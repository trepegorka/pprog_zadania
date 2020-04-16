#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void count(string word);

int main() {
    count("Moje zdanie");
}

void count(string word) {
    unsigned short wordSize = word.length();
    char array[wordSize];
    strcpy(array, word.c_str());
    int numb[wordSize];
    map<char, int> map;
    for (int i = 0; i < wordSize; i++) {
        numb[i] = 1;
    }
    for (int i = 0; i < wordSize; i++) {
        for (int j = 0; j < wordSize; j++) {
            if (array[i] == array[j]) {
                numb[i] = numb[i] + 1;
            }
        }
        numb[i] = numb[i] - 1;
        map.insert(pair<char,int>(array[i], numb[i]));
    }
    for(const auto &p : map){
        cout<<p.first<<"="<<p.second<<endl;
    }
}