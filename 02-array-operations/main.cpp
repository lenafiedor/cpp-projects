#include <iostream>
using namespace std;


void printArray(int* array, int size) {
    int i = 0;
    while (i < size) {
        cout << array[i] << " ";
        i++;
    }
    cout << endl;
}


void rotate(int* array, int size) {
    int index, length, numCages = size;
    cin >> index >> length;
    index = index % size < 0 ? index % size : index % size + size;
    if (length <= 1 || length > size) {
        numCages = length - 1;
    }

    while (numCages >= length) {

        int l = length, i = length, j = index;
        while (i > length / 2) {
            j = j % size;
            int n = (j + l - 1) % size;
            int temp = array[j];
            array[j] = array[n];
            array[n] = temp;
            l -= 2;
            j++;
            i--;
        }
        numCages -= length;
        index = index + length;
    }
}


void switch_(int* array, int size) {
    int index, length, numCages = size;
    cin >> index >> length;
    if (length <= 0 || size < length * 2) {
        numCages = length - 1;
    }
    index = index % size < 0 ? index % size : index % size + size;
    if (length > size) {
        length = size;
        numCages = length;
    }
    while (numCages >= 2 * length) {

        int i = index, l = 0;
        while ( l < length ) {
            int i = i % size;
            int n = (i + length) % size;
            int temp = array[i];
            array[i] = array[n];
            array[n] = temp;
            i++;
            l++;
        }
        numCages -= (2 * length);
        index = index + (2 * length);
    }
}


void shift(int* array, int size) {
    int index, length, move, numCages = size;
    cin >> index >> length >> move;
    int m = move;

    if (length > 0 && move != 0) {
        if (length > size) {
            move = move % size;
            length = size;
            numCages = length;
        }
        else {
            move = move % length;
        }
        if (length == 0) {
            length = size;
        }
        index = index % size < 0 ? index % size : index % size + size;

        while (numCages >= length) {
            int i = index, l = 0, j = 0;
            if (move < 0) {
                while (l < move) {
                    i = i % size;
                    int n = (i + length - 1) % size;
                    int temp = array[n];
                    array[n] = array[i];
                    i--;
                    j++;
                    while (j < length) {
                        i = i % size;
                        n = (i + length - 1) % size;
                        int temp2 = array[n];
                        array[n] = temp;
                        temp = temp2;
                        i--;
                        j++;
                    }
                    l--;
                    i = index;
                    j = 0;
                }
            }
            else {
                while (l < move) {
                    i = i % size;
                    int n = (i + length - 1) % size;
                    int temp = array[i];
                    array[i] = array[n];
                    array[n] = array[i];
                    i++;
                    j++;
                    while (j < length) { 
                        i = i % size;
                        int temp2 = array[i];
                        array[i] = temp;
                        temp = temp2;
                        i++;
                        j++;
                    }
                    l++;
                    i = index;
                    j = 0;
                }
            }
            numCages -= length;
            index = (index + length) % size;
        }
        if (length < 0 || m == 0) {
            numCages = 0;
        }
        if (numCages != 0 && numCages != 1) {
            m = m % numCages;
            int i = index, l = 0, j = 0;

            if (m < 0) {
                while (l > m) {
                    i = index % size;
                    int n = (i + numCages - 1) % size;
                    int temp = array[n];
                    array[n] = array[i];
                    i--;
                    j++;
                    while (j < numCages) {
                        i = i % size;
                        n = ( i + numCages - 1 ) % size;
                        int temp2 = array[n];
                        array[n] = temp;
                        temp = temp2;
                        i--;
                        j++;
                    }
                    l--;
                    j = 0;  
                }
            }
            else {
                while (l < m) {
                    i = index % size;
                    int n = (i + numCages - 1) % size;
                    int temp = array[i];
                    array[i] = array[n];
                    array[n] = array[i];
                    i++;
                    j++;
                    while (j < numCages) {
                        i = i % size;
                        int temp2 = array[i];
                        array[i] = temp;
                        temp = temp2;
                        i++;
                        j++;
                    }
                    l++;
                    j = 0;
                }
            }
        }
    }

}


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