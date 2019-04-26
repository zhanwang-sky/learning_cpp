#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ch2nu(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'a' + 10;
    }
}

char nu2ch(int nu) {
    if (nu < 10) {
        return '0' + nu;
    } else {
        return nu - 10 + 'a';
    }
}

string convertBase(string &number, int fromBase, int toBase) {
    size_t nr_from_bits = number.size();
    size_t nr_to_bits = 0;
    int real_number = 0;
    int remainder = 0;
    string ret;

    cout << "nr_from_bits = " << nr_from_bits << endl; // test

    for (size_t i = 0; i < nr_from_bits; i++) {
        real_number += ch2nu(number[i]) * pow(fromBase, nr_from_bits - i - 1);
    }
    cout << "real_number = " << real_number << endl; // test

    nr_to_bits = log(real_number) / log(toBase) + 1;
    cout << "nr_to_bits = " << nr_to_bits << endl; // test

    remainder = real_number;
    while (nr_to_bits > 0) {
        ret.push_back(nu2ch(remainder / pow(toBase, --nr_to_bits)));
        remainder %= int(pow(toBase, nr_to_bits));
    }

    return ret;
}

int main(void) {
    string number;
    int fromBase;
    int toBase;

    cout << "number: ";
    cin >> number;
    cout << "fromBase: ";
    cin >> fromBase;
    cout << "toBase: ";
    cin >> toBase;

    cout << convertBase(number, fromBase, toBase) << endl;

    return 0;
}
