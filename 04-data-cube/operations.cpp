#include <iostream>

using namespace std;


void fillCube(int edge, long long (*cube)[32][32]) {
    int i = 0;
    for (int d = 0; d < edge; d++) {
        for (int h = 0; h < edge; h++) {
            for (int w = 0; w < edge; w++) {
                // cin >> cube[h][w][d];
                cube[h][w][d] = i++;
            }
        }
    }
}

void printCube(int edge, long long (*cube)[32][32]) {
    for (int d = 0; d < edge; d++) {
        for (int h = 0; h < edge; h++) {
            for (int w = 0; w < edge; w++) {
                cout << cube[h][w][d] << " ";
            }
            cout << "\t";
        }
        cout << endl;
    }
}

int modulo(int number) {
    return number < 0 ? -number : number;
}

int max(int firstNumber, int secNumber) {
    return firstNumber >= secNumber ? firstNumber : secNumber;
}

int min(int firstNumber, int secNumber) {
    return firstNumber <= secNumber ? firstNumber : secNumber;
}

void normalize_dimension(int edge, int& coordinate, int& dimension) {
    if (coordinate < 0) {
        // *dimension -= modulo(*coordinate);
        // *coordinate = 0;
        int i = 0;
        while (coordinate < 0) {
            cout << "i: " << i << ", coordinate: " << coordinate << endl;
            i++;
            coordinate++;
        }
        dimension -= i;
    }
    else if (coordinate >= edge) {
        // *dimension -= (edge - *coordinate);
        // *coordinate = edge - 1;
        int i = 0;
        while (coordinate >= edge) {
            cout << "i: " << i << ", coordinate: " << coordinate << endl;
            i++;
            coordinate--;
        }
        dimension -= i;
    }
}

void cuboid(long long (*cube)[32][32], int edge, int l, int v, int p, int h, int w, int d) {

    normalize_dimension(edge, l, h);
    normalize_dimension(edge, v, w);
    normalize_dimension(edge, p, d);

    cout << "p, v, l: " << p << v << l << endl;
    cout << "h, w, d: " << h << w << d << endl;

    int sum = 0;

    int startL = l < edge / 2 ? l : l - h;
    int endL = l < edge / 2 ? l + h : l;
    int startV = v < edge / 2 ? v : v - w;
    int endV = v < edge / 2 ? v + w : v;
    int startP = p < edge / 2 ? p : p - d;
    int endP = p < edge / 2 ? p + d : p;

    cout << "start L: " << startL << ", end: " << endL << endl;
    cout << "start V: " << startV << ", end: " << endV << endl;
    cout << "start P: " << startP << ", end: " << endP << endl;
    for (int i = max(startL, 0); i <= min(endL, edge - 1); i++) {
        for (int j = max(startV, 0); j <= min(endV, edge - 1); j++) {
            for (int k = max(startP, 0); k <= min(endP, edge - 1); k++) {
                sum += cube[i][j][k];
            }
        }
    }
    cout << "sum : " << sum << endl;
}