#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    cout << "sizeof(arr): " << sizeof(arr) << " bytes" << endl;

    cout << "sizeof(arr[0]): " << sizeof(arr[0]) << " bytes" << endl;

    cout << "Number of elements: " << sizeof(arr) / sizeof(arr[0]) << endl; 

    cout << "size of ptr: " << sizeof(ptr) << " bytes." << endl;

    return 0;
}