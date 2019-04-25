#include <iostream>
#include <stdexcept>

using namespace std;

namespace e_5_6 {
void exercise_5_6(void) {
    cout << "hello world!" << endl;

    try {
        throw runtime_error("fuck you!");
    } catch (runtime_error err) {
        cout << err.what() << endl;
    }

    return;
}
}

int main(void) {
    e_5_6::exercise_5_6();

    return 0;
}
