#include <iostream>
#include "hasptr_shared.h"
#include "msg.h"

using namespace std;

namespace e_13_34 {

void exercise() {
    Folder my_document;
    Message jon("hello world");

    jon.save(my_document);

    cout << jon.contents() << endl;
}

}

int main(void) {
    HasPtr hp1("fuck!");
    HasPtr hp3;

    do {
        HasPtr hp2 = hp1;

        hp3 = hp2;
        hp2 = hp2;

        swap(hp2, hp3);

        cout << *hp3.data() << endl;
        cout << *hp2.data() << endl;
    } while (0);

    cout << *hp3.data() << endl;

    e_13_34::exercise();

    return 0;
}
