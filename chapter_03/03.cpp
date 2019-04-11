#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test_string() {
    const string s = "Keep out!";
    for (auto &c: s) {
        cout << c << endl;
    }
    return;
}

vector<int>& test_vector(vector<int> &vx) {
    const vector<int> v0 = {1, 2, 3, 4, 5};
    for (auto it0 = v0.begin(); it0 != v0.end(); ++it0) {
        vx.push_back(*it0);
    }
    return vx;
}

vector<int> vx = {0, 99, 98, -100};

int main(void) {
    test_string();
    auto v = test_vector(vx);
    for (auto i : v) {
        cout << i << endl;
    }
    return 0;
}
