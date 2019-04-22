#include <iostream>
#include <vector>

using namespace std;

bool exercise_9_4(vector<int>::const_iterator it_begin,
        const vector<int>::const_iterator it_end, int pattern) {
    // could not perform ++it_end
    while (it_begin != it_end) {
        if (*it_begin == pattern) {
            return true;
        }
        ++it_begin;
    }

    return false;
}

vector<int>::iterator exercise_9_5(vector<int>::iterator it_begin,
        const vector<int>::const_iterator it_end, int pattern) {
    while (it_begin != it_end) {
        if (*it_begin == pattern) {
            break;
        }
        ++it_begin;
    }

    return it_begin;
}

void exercise_9_11(void) {
    vector<int> vec0;
    vector<int> vec1(10, 1);
    vector<int> vec2(vec1);
    vector<int> vec3 = vec1;
    vector<int> vec4 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    auto it = vec4.begin();
    vector<int> vec5(it, it + 5);
    vector<vector<int>> vecs = { vec0, vec1, vec2, vec3, vec4, vec5 };

    cout << "========================================" << endl
        << "content of vectors:" << endl;
    for (auto v : vecs) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;

    return;
}

vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int e1 = 1, e2 = 99;
vector<const int *> vec2 = { &e1, &e2 };

int main(void) {
    cout << "hello world" << endl;

    exercise_9_11();

    vector<const int *>::iterator it = vec2.begin();
    *it = &e2;

    return 0;
}
