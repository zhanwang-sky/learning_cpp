#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    const string s = "Keep out!";
    for (auto &c: s) {
        cout << c << endl;
    }

    return 0;
}
