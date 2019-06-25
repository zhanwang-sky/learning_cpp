#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "util.h"
#include "blob.h"
#include "sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<int> vi = { 1, 2, 3, 4, 5 };
vector<string> vs = { "hello", "wonderful", "world" };
char cstr[] = "I am the king of the world";

int main(void) {
    cout << compare(1, 2) << endl;
    cout << compare('x', 'y') << endl;
    cout << compare(string("1"), string("12")) << endl;

    cout << endl; //////////

    auto vi_it = find(vi.begin(), vi.end(), 5);
    if (vi_it != vi.end()) {
        cout << *vi_it << endl;
    } else {
        cout << "\'5\' not found in vi\n";
    }

    auto vs_it = find(vs.begin(), vs.end(), "nihao");
    if (vs_it != vs.end()) {
        cout << *vs_it << endl;
    } else {
        cout << "\'nihao\' not found in vs\n";
    }

    auto cstr_it = find(begin(cstr), end(cstr), 'k');
    if (cstr_it != end(cstr)) {
        cout << *cstr_it << endl;
    } else {
        cout << "\'k\' not found in cstr\n";
    }

    cout << endl; //////////

    cstr[sizeof(cstr) - 1] = '#';
    print_array1(cstr);
    print_array2(cstr);
    print_array3(&cstr);

    cout << endl; //////////

    cout << "end(cstr) - begin(cstr) = " << end(cstr) - begin(cstr) << endl;
    vi.push_back(6);
    cout << "size of vi = " << get_size(vi) << endl;
    cout << "size of cstr = " << size_of(cstr) << endl;
    // error: cout << "size of cstr: " << get_size(cstr) << endl;

    cout << endl; //////////

    return 0;
}
