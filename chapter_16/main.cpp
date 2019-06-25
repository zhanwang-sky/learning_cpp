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
using util::print_array1;
using util::print_array2;
using util::print_array3;
using util::get_size;
using util::size_of;

vector<int> vi = { 1, 2, 3, 4, 5 };
vector<string> vs = { "hello", "wonderful", "world" };
char cstr[] = "I am the king of the world";

int main(void) {
    cout << util::compare(1, 2) << endl;
    cout << util::compare('x', 'y') << endl;
    cout << util::compare(string("1"), string("12")) << endl;

    cout << endl; //////////

    auto vi_it = util::find(vi.begin(), vi.end(), 5);
    if (vi_it != vi.end()) {
        cout << *vi_it << endl;
    } else {
        cout << "\'5\' not found in vi\n";
    }

    auto vs_it = util::find(vs.begin(), vs.end(), "nihao");
    if (vs_it != vs.end()) {
        cout << *vs_it << endl;
    } else {
        cout << "\'nihao\' not found in vs\n";
    }

    auto cstr_it = util::find(util::begin(cstr), util::end(cstr), 'k');
    if (cstr_it != util::end(cstr)) {
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

    cout << "end(cstr) - begin(cstr) = " << util::end(cstr) - util::begin(cstr) << endl;
    vi.push_back(6);
    cout << "size of vi = " << get_size(vi) << endl;
    cout << "size of cstr = " << size_of(cstr) << endl;
    // error: cout << "size of cstr: " << get_size(cstr) << endl;

    cout << endl; //////////

    return 0;
}
