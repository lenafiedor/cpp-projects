#include <iostream>
using namespace std;


static short int MAX_SIZE = 4095;


bool isValid(int number) {
    return number > 0 && number <= MAX_SIZE;
}

int find_size(int array[]) {
    return sizeof(array) / sizeof(array[0]);
}

void List(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int array[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void Add(int number, int array[]) {

    if (isValid(number)) {
        int size = find_size(array);

        for (int i = 0; i < size; i++) {
            if (array[i] == number) {
                break;
            }
            if (i == size - 1) {
                array[size] = number;
                array[size+1] = -1;
                bubbleSort(array, size + 1);
            }
        }
    }
}

void Create(int sizeFirst, int tabFirst[], int tabSec[]) {

    int sizeSec = find_size(tabSec);

	for (int i = 0; i < sizeFirst; i++) {
		if (isValid(tabFirst[i])) {
			for (int j = 0; j < sizeSec; j++) {
	            if (tabSec[j] == tabSec[i]) {
	                break;
                }
                if (j == sizeSec - 1) {
                    tabSec[sizeSec] = tabFirst[i];
                    tabSec[sizeSec+1] = -1;
                }
			}
		}
	}
	bubbleSort(tabSec, sizeSec);
}

void Union(int tabFirst[], int tabSec[], int result[]) {

    int sizeFirst = find_size(tabFirst);
    int sizeSec = find_size(tabSec);

    for (int i = 0; i < sizeFirst; i++) {
        result[i] = result[i];
        result[i+1] = -1;
	}

    int sizeThird = find_size(result);

    for (int i = 0; i < sizeSec; i++) {
        for (int j = 0; j <= sizeThird; j++) {
            if (result[j] == tabSec[i] ) {
                break;
            }
            if (j == sizeThird - 1) {
                result[j] = tabSec[i];
                result[j+1] = -1;
            }
        }
    }
    bubbleSort(result, sizeThird);
}

void Intersection(int tabFirst[], int tabSec[], int result[]) {
    int k = 0;
    for (int i = 0; tabFirst[i] != -1; i++) {
        for (int j = 0; tabSec[j] != -1; j++) {
            if (tabFirst[i] == tabSec[j]) {
                result[k] = result[i];
                result[k++] = -1;
            }
        }
    }
    bubbleSort(result, k);
}

void Difference(int tabFirst[], int tabSec[], int result[]) {

    int k = 0;
    bool cond = true;
    int sizeSec = find_size(tabSec);

    for (int i = 0; tabFirst[i] != -1; i++) {
        for (int j = 0; tabSec[j] != -1; j++) {
            if (tabFirst[i] == tabSec[j]) {
                break;
            }
            if (j == sizeSec - 1) {
                result[k] = tabFirst[i];
                result[k++] = -1;
            }
        }
    }
    bubbleSort(result, k);
}

void Symmetric(int tabFirst[], int tabSec[], int result[]) {

    int k = 0;
    int sizeFirst = find_size(tabFirst);
    int sizeSec = find_size(tabSec);

    for (int i = 0; tabFirst[i] != -1; i++) {
        for (int j = 0; tabSec[j] != -1; j++) {
            if (tabFirst[i] == tabSec[j]) {
                break;
            }
            if (j == sizeSec - 1) {
                result[k] = tabFirst[i];
                result[k++] = -1;
            }
        }
    }

    for (int i = 0; tabSec[i] != -1; i++ ) {
        for (int j = 0; tabFirst[j] != -1; j++) {
            if (tabSec[i] == tabFirst[j] ) {
                break;
            }
            if (j == sizeFirst - 1) {
                result[k] = tabSec[i];
                result[k++] = -1;
            }
        }
    }
    bubbleSort(result, k);
}

void Complement(int array[], int result[]) {

    int k = 0;
    int size = find_size(array);

    for (int u = 1; u <= MAX_SIZE; u++) {
        for (int i = 0; array[i] != -1; i++) {
            if (array[i] == u) {
                break;
            }
            if (i == size - 1) {
                result[k] = array[i];
                result[k++] = -1;
            }
        }
    }
}

bool Subset(int tabFirst[], int tabSec[]) {

    if (find_size(tabFirst) == 0) {
        return true;
    }

    for (int i = 0; tabFirst[i] != -1; i++) {

        bool found = false;

        for (int j = 0; tabSec[j] != -1; j++) {
            if (tabFirst[i] == tabSec[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool Equal(int tabFirst[], int tabSec[]) {
    return find_size(tabFirst) == find_size(tabSec) && Subset(tabFirst, tabSec);    
}

bool Empty(int array[]) {
    return array[0] == -1;
}

bool Nonempty(int array[]) {
    return !Empty(array);
}

double Arithmetic(int array[]) {

    int size = find_size(array);
    int sum = 0;

    if (size == 0) {
        return 0;
    }

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum * 1.0 / size * 1.0;
}

double Harmonic(int array[]) {

    int size = find_size(array);
    int sum = 0;

    if (size == 0) {
        return 1;
    }

    int sum = 0;
    double denom = 0;

    for (int i = 0; i < size; i++) {
        denom += (1.0 / array[i]) ;
    }
    return size / denom * 1.0;
}

bool Element(int number, int array[]) {
    int number_arrayed[1] = {number};
    return Subset(number_arrayed, array);
}

void MinMax(int array[], int* min, int& max) {
    if (array[0] != -1) {

    	*min = 4095;
    	max = 1;
        int size = find_size(array);

        for (int i = 0; i < size; i++ ) {
            if (array[i] < *min) {
                *min = array[i];
            }
            if (array[i] > max) {
                max = array[i];
            }
        }
    }
}

void Cardinality(int array[], int* card) {
    *card = find_size(array);
}

void Properties(int array[], char operations[], double& arith, double* harm, int& min, int* max, int& card) {
    for (int i = 0; operations[i] != 0; i++) {
        switch (operations[i]) {
            case 'a':
                arith = Arithmetic(array);
                break;
            case 'h':
                *harm = Harmonic(array);
                break;
            case 'm':
                MinMax(array, &min, *max);
                break;
            case 'c':
                Cardinality(array, &card);
                break;
            default:
                break;
        }
    }
}
