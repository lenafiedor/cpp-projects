#include <iostream>
using namespace std;

void displayArray(int array[], int size) {
    int i = 0;
    while (i < size) {
        cout << array[i] << " ";
        i++;
    }
    cout << endl;
}

int main() {
    cin >> int arrayCount;
    while (arrayCount > 0) {
        char operation = ' ';

        cin >> int size;
        if (size <= 0) {
            operation = 'F';
        }
        int array[size];

        int i = 0;
        while (i < size) {
            cin >> array[i]
            i++;
        }

        displayArray(array, size);

        while (operation != 'F') {
            cin >> operation;
            switch (operation) {
                case 'R':
                    break;
                case 'S':
                    break;
                case 'C':
                    break;
                default:
                    operation = 'F';
                    break;
            }
            
        }

        arrayCount--;
    }

}