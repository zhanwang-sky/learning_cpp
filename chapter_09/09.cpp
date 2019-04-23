#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

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

namespace e_9_14 {
char word1[] = "hello";
char word2[] = "world";
list<char *> lst = { word1, word2 };
vector<string> vec = { "hello world", "i am the king of the world!" };

void exercise_9_14(list<char *> &lst, vector<string> &vec) {
    vec.assign(lst.begin(), lst.end());
}
}

namespace e_9_18 {
deque<string> c;

void exercise_9_18(size_t count) {
    string tmp_str;

    for (size_t i = 0; i < count; i++) {
        cin >> tmp_str;
        c.push_back(tmp_str);
    }

    cout << "Your inputs:" << endl;
    for (auto it = c.begin(); it != c.end(); ++it) {
        cout << *it << endl;
    }

    return;
}
}

namespace e_9_20 {
list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
deque<int> dq1, dq2;
vector<deque<int>> vec = { dq1, dq2 };

void exercise_9_20(void) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        vec[*it % 2].push_back(*it);
    }

    for (size_t i = 0; i < 2; i++) {
        cout << "content of dq" << i + 1 << ":" << endl;
        for (auto element : vec[i]) {
            cout << element << " ";
        }
        cout << endl;
    }

    return;
}
}

int main(void) {
    int nu;

    if (!(cin >> nu)) {
        cerr << "input error!" << endl;
        return -1;
    }

    switch (nu) {
    case 14:
        using namespace e_9_14;

        cout << "exercise 9.14" << endl;

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                cout << "before:" << endl;
            } else {
                cout << "after:" << endl;
            }
            cout << "lst:" << endl;
            for (auto pChar : lst) {
                cout << "    " << pChar << endl;
            }
            cout << "vec:" << endl;
            for (auto str : vec) {
                cout << "    " << str << endl;
            }
            if (i == 0) {
                exercise_9_14(lst, vec);
            }
        }

        break;
    case 18:
        using namespace e_9_18;

        size_t count;

        cout << "count: ";
        cin >> count;
        exercise_9_18(count);

        break;
    case 20:
        using namespace e_9_20;
        exercise_9_20();
        break;
    default:
        cout << "no such number..." << endl;
    }

    return 0;
}
