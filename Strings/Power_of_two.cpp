#include <iostream>
#include <string>
using namespace std;

bool isPowerOfTwo(int n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        int bit = n & (1 << i);
        if (bit == 1) cnt++;
        if (cnt > 1) return false;
    }
    if (cnt == 1) return true;
    return false;
}

int main() {
    int a = 1982;
    string s = to_string(a);
    cout << s[1] << " " << s[2] << endl;
    // Check if a is a power of two
    if (isPowerOfTwo(a)) {
        cout << a << " is a power of two." << endl;
    } else {
        cout << a << " is not a power of two." << endl;
    }

    return 0;
}
