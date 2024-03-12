#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char One_extra_char(string s1, string s2) {
    int arr[256] = {0};
    
    for (char x : s2) {
        arr[x]++;
    }
    
    for (char x : s1) {
        arr[x]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (arr[i] == 1) return static_cast<char>(i);
    }
    
    return '\0';
}

int main(int argc, char *argv[]) {
    string s1 = "abcd";
    string s2 = "abced";
    
    char extraChar = One_extra_char(s1, s2);
    if (extraChar != '\0') {
        cout << "Extra character in s2 compared to s1: " << extraChar << endl;
    } else {
        cout << "No extra character found." << endl;
    }
    
    return 0;
}
