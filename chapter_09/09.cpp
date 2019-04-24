#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

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

namespace e_9_26 {
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
vector<int> vec;
list<int> lst;

void exercise_9_26(void) {
    for (size_t i = 0; i < sizeof(ia) / sizeof(int); i++) {
        vec.push_back(ia[i]);
    }
    lst.assign(vec.begin(), vec.end());

    auto it_vec = vec.begin();
    while (it_vec != vec.end()) {
        if (*it_vec % 2)
            it_vec = vec.erase(it_vec);
        else
            ++it_vec;
    }

    auto it_lst = lst.begin();
    while (it_lst != lst.end()) {
        if (!(*it_lst % 2))
            it_lst = lst.erase(it_lst);
        else
            ++it_lst;
    }

    cout << "content of vec:" << endl;
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    cout << "content of lst:" << endl;
    for (auto i : lst) {
        cout << i << " ";
    }
    cout << endl;

    return;
}
}

namespace e_9_27 {
forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void exercise_9_27(void) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        }
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst) {
        cout << i << " ";
    }
    cout << endl;

    return;
}
}

namespace e_9_28 {
string tmp_str, str1, str2;
forward_list<string> flst;

bool exercise_9_28(forward_list<string> &flst, string &str1, string &str2) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    bool found = false;

    while (curr != flst.end()) {
        if (*curr == str1) {
            flst.insert_after(prev, str2);
            found = true;
            break;
        } else {
            prev = curr;
            ++curr;
        }
    }

    if (!found) {
        flst.insert_after(prev, str2);
    }

    return found;
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
        size_t count;

        cout << "count: ";
        cin >> count;
        e_9_18::exercise_9_18(count);

        break;
    case 20:
        e_9_20::exercise_9_20();
        break;
    case 26:
        e_9_26::exercise_9_26();
        break;
    case 27:
        e_9_27::exercise_9_27();
        break;
    case 28:
        cout << "enter 5 words:" << endl;
        for (int i = 0; i < 5; i++) {
            cin >> e_9_28::tmp_str;
            e_9_28::flst.emplace_after(e_9_28::flst.before_begin(),
                    e_9_28::tmp_str);
        }
        cout << "enter str1:" << endl;
        cin >> e_9_28::str1;
        cout << "enter str2:" << endl;
        cin >> e_9_28::str2;

        e_9_28::exercise_9_28(e_9_28::flst, e_9_28::str1, e_9_28::str2);

        for (auto str : e_9_28::flst) {
            cout << str << " ";
        }
        cout << endl;

        break;

    default:
        cout << "no such number..." << endl;
    }

    return 0;
}
