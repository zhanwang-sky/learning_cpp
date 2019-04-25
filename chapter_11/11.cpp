#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

namespace e_11_4 {
set<string> gExcludedWords = { "a", "an", "the" };

void exercise_11_4(istream &is) {
    map<string, size_t> word_count;
    string word;

    cout << "input words, press '#' to end:" << endl;

    while (is >> word) {
        if (word == "#") {
            break;
        }
        if (gExcludedWords.find(word) == gExcludedWords.end()) {
            ++word_count[word];
        }
    }

    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second << " times." << endl;
    }

    return;
}
}

namespace e_11_12 {
vector<pair<string, int>> pvec;

void exercise_11_12(void) {
    string str_nu;
    int nu;

    cout << "enter some integers, press 'q' to end" << endl;
    while (cin >> nu) {
        str_nu = to_string(nu);
        pvec.emplace_back(pair<string, int>(str_nu, nu));
    }

    for (const auto &p : pvec) {
        cout << p.first << ", " << p.second;
    }
    cout << endl;

    return;
}
}

namespace e_11_31 {
multimap<string, set<string>> book_store = {
    { "Charles Dickens",
        { "A Tale of Two Cities", "Oliver Twist", "Great Expectations" }
    },
    { "Jane Austen",
        { "Pride and Prejudice", "Sense and Sensibility" }
    },
    { "Daniel Defoe",
        { "The adventures of Robinson Crusoe" }
    },
    { "Francis Fitzgerald",
        { "The great Gatsby", "Tender is the Night" }
    }
};

void exercise_11_31(void) {
    string str_auth, str_book;

    for (auto it_auth = book_store.begin();
            it_auth != book_store.end();
            ++it_auth) {
        cout << it_auth->first << endl;
        for (const auto &book : it_auth->second) {
            cout << "    " << book << endl;
        }
    }

    cout << "which item do you want to remove?" << endl;
    // TODO: ugly, is there any method can exhaust all chars remained in istream?
    getline(cin, str_auth);
    cout << "author: ";
    getline(cin, str_auth);
    cout << "book: ";
    getline(cin, str_book);

    cout << "confirm the item which you want to delete:" << endl;
    cout << "author: " << str_auth << endl;
    cout << "book: " << str_book << endl;

    return;
}
}

int main(void) {
    int nu;

    cin >> nu;
    switch (nu) {
    case 4:
        e_11_4::exercise_11_4(cin);
        break;
    case 12:
        e_11_12::exercise_11_12();
        break;
    case 31:
        e_11_31::exercise_11_31();
        break;
    default:
        cout << "no such number, please check." << endl;
    }

    return 0;
}
