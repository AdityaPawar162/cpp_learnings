#include<iostream>
using namespace std;

bool SearchSumPair(int arr[], int size, int x) {
    int i;
    for (i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1])
            break;
    }
    // Smallest element
    int s = (i + 1) % size;
    // Largest element
    int l = i;

    while (s != l) {
        if (arr[s] + arr[l] == x)
            return true;
        if (arr[s] + arr[l] < x)
            s = (s + 1) % size;
        else
            l = (l - 1 + size) % size;
    }
    return false;
}

int main() {
    int arr[] = {11, 15, 6, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 16;

    if (SearchSumPair(arr, size, x))
        cout << "Pair with sum " << x << " exists in the array";
    else
        cout << "Pair with sum " << x << " does not exist in the array";

    return 0;
}
