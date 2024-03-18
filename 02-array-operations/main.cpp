#include <iostream>
#include "operations.cpp"
using namespace std;


int main() {

    int numSets;
    cin >> numSets;
    while (numSets > 0) {
        char operation = '_';

        int size;
        cin >> size;
        if (size <= 0) {
            operation = 'F';
        }

        int array[size];
        int i = 0;
        while (i < size) {
            cin >> array[i];
            i++;
        }
        printArray(array, size);

        while (operation != 'F') {

            cin >> operation;
            switch(operation) {
                case 'R':
                    rotate(array, size);
                    break;
                case 'S':
                    switch_(array, size);
                    break;
                case 'C':
                    shift(array, size);
                    break;
                default:
                    operation = 'F';
                    break;
            }
        }
        printArray(array, size);
        numSets--;
    }
    return 0;
}
