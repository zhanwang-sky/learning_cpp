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
vector<bool> vb = { true, false, false };
char arrc[] = "I am the king of the world";
bool arrb[3] = { true, true, false };

int main(void) {
    arrc[sizeof(arrc) - 1] = '#';

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

    auto arrc_it = util::find(util::begin(arrc), util::end(arrc), 'k');
    if (arrc_it != util::end(arrc)) {
        cout << *arrc_it << endl;
    } else {
        cout << "\'k\' not found in arrc\n";
    }

    cout << endl; //////////

    print_array1(arrc);
    print_array2(arrc);
    print_array3(&arrc);

    cout << endl; //////////

    cout << "end(arrc) - begin(arrc) = " << util::end(arrc) - util::begin(arrc) << endl;
    vi.push_back(6);
    cout << "size of vi = " << get_size(vi) << endl;
    cout << "size of arrc = " << size_of(arrc) << endl;
    // error: cout << "size of arrc: " << get_size(arrc) << endl;

    cout << endl; //////////

    //const Blob<bool> bx = { true, true, false, true };
    const Blob<string> bx = { "Jon", "Dany", "Targaryen", "Winterfell" };
    cout << bx.at(3) << endl;

    cout << util::access(bx, 0) << endl;
    // error: cout << util::access(vb, 2) << endl;
    cout << util::caccess(arrc, 3) << endl;
    cout << util::caccess(arrb, 2) << endl;

    return 0;
}
