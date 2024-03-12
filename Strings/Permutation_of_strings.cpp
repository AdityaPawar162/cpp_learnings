#include <iostream>
#include <string>
using namespace std;

void calc(string s, int ind, string output) {
    // Base case
    if (ind == s.length()) {
        cout << output << endl;
        return;
    }

    for (int i = ind; i < s.length(); i++) {
        string nn = s.substr(0, ind) + s.substr(ind + 1);
        calc(nn, ind, output + s[i]);
    }
}

int main() {
    string s = "abc";
    calc(s, 0, "");
    return 0;
}
