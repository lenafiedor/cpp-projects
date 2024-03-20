#include <iostream>

using namespace std;


void fillCube(int edge, long long (*cube)[32][32]) {
    int i = 0;
    for (int d = 0; d < edge; d++) {
        for (int h = 0; h < edge; h++) {
            for (int w = 0; w < edge; w++) {
                cin >> cube[h][w][d];
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

int square(int number) {
    return number * number;
}

int max(int firstNumber, int secNumber) {
    return firstNumber >= secNumber ? firstNumber : secNumber;
}

int min(int firstNumber, int secNumber) {
    return firstNumber <= secNumber ? firstNumber : secNumber;
}

void normalize_dimension(int edge, int& coordinate, int& dimension) {
    if (coordinate < 0) {
        int i = 0;
        while (coordinate < 0) {
            cout << "i: " << i << ", coordinate: " << coordinate << endl;
            i++;
            coordinate++;
        }
        dimension -= i;
    }
    else if (coordinate >= edge) {
        int i = 0;
        while (coordinate >= edge) {
            cout << "i: " << i << ", coordinate: " << coordinate << endl;
            i++;
            coordinate--;
        }
        dimension -= i;
    }
}

bool insideTetrahedron(int e, int l, int v, int p, int i, int j, int k) {
    return modulo(l - i) + modulo(v - j) + modulo(p - k) <= e;
}

bool insideOctal(int r, int l, int v, int p, int i, int j, int k) {
    return square(l - i) + square(v - j) + square(p - k) <= square(r);
}

bool zeroMatrix(long long (*cube)[32], int edge) {
    for (int i = 0; i < edge; i++) {
        for (int j = 0; j < edge; j++) {
            if (cube[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void cuboid(long long (*cube)[32][32], int edge, int l, int v, int p, int h, int w, int d) {

    normalize_dimension(edge, l, h);
    normalize_dimension(edge, v, w);
    normalize_dimension(edge, p, d);

    int sum = 0;

    int startL = l < edge / 2 ? l : l - h;
    int endL = l < edge / 2 ? l + h : l;
    int startV = v < edge / 2 ? v : v - w;
    int endV = v < edge / 2 ? v + w : v;
    int startP = p < edge / 2 ? p : p - d;
    int endP = p < edge / 2 ? p + d : p;

    for (int i = max(startL, 0); i <= min(endL, edge - 1); i++) {
        for (int j = max(startV, 0); j <= min(endV, edge - 1); j++) {
            for (int k = max(startP, 0); k <= min(endP, edge - 1); k++) {
                sum += cube[i][j][k];
            }
        }
    }
    cout << "sum : " << sum << endl;
}

void tetrahedron(long long (*cube)[32][32], int edge, int l, int v, int p, int e) {

    int sum = 0;

    int startL = l < edge / 2 ? l : l - e;
    int endL = l < edge / 2 ? l + e : l;
    int startV = v < edge / 2 ? v : v - e;
    int endV = v < edge / 2 ? v + e : v;
    int startP = p < edge / 2 ? p : p - e;
    int endP = p < edge / 2 ? p + e : p;

    for (int i = max(startL, 0); i <= min(endL, edge - 1); i++) {
        for (int j = max(startV, 0); j <= min(endV, edge - 1); j++) {
            for (int k = max(startP, 0); k <= min(endP, edge - 1); k++) {
                if (insideTetrahedron(e, l, v, p, i, j, k)) {
                    sum += cube[i][j][k];
                }
            }
        }
    }
    cout << "sum : " << sum << endl;
}

void octal(long long (*cube)[32][32], int edge, int l, int v, int p, int r) {

    int sum = 0;

    int startL = l < edge / 2 ? l : l - r;
    int endL = l < edge / 2 ? l + r : l;
    int startV = v < edge / 2 ? v : v - r;
    int endV = v < edge / 2 ? v + r : v;
    int startP = p < edge / 2 ? p : p - r;
    int endP = p < edge / 2 ? p + r : p;

    for (int i = max(startL, 0); i <= min(endL, edge - 1); i++) {
        for (int j = max(startV, 0); j <= min(endV, edge - 1); j++) {
            for (int k = max(startP, 0); k <= min(endP, edge - 1); k++) {
                if (insideOctal(r, l, v, p, i, j, k)) {
                    sum += cube[i][j][k];
                }
            }
        }
    }
    cout << "sum : " << sum << endl;
}

void createSlice(long long (*cube)[32][32], long long (*slice)[32], int edge, char k, int index) {

    switch(k) {
        case 'l':
            for (int i = 0; i < edge; i++) {
                for (int j = 0; j < edge; j++) {
                    slice[i][j] = cube[index][i][j];
                }
            }
            break;
        case 'v':
            for (int i = 0; i < edge; i++) {
                for (int j = 0; j < edge; j++) {
                    slice[i][j] = cube[i][index][j];
                }
            }
            break;
        case 'p':
            for (int i = 0; i < edge; i++) {
                for (int j = 0; j < edge; j++) {
                    slice[i][j] = cube[i][j][index];
                }
            }
            break;
        default:
            cout << "Invalid slice dimension." << endl;
            break;
    }
}

long long calculateDet(long long (*slice)[32], int edge) {

    if (edge == 2) {
        return slice[0][0] * slice[1][1] - slice[0][1] * slice[1][0];
    }
    else if (zeroMatrix(slice, edge) || edge <= 0) {
        return 0;
    }
    else {
        long long det = 1;
        int sign = 1;

        for (int k = 0; k < edge - 1; k++) {
            if (slice[k][k] == 0) {
                int move = 0;
                for (move = k + 1; move < edge; move++) {
                    if (slice[move][k] != 0) {
                        for (int i = 0; i < edge; i++) {
                            int temp = slice[move][i];
                            slice[move][i] = slice[k][i];
                            slice[k][i] = temp;
                        }
                        sign = -sign;
                        break;
                    }
                }
                if (move == edge) {
                    det = 0;
                    break;
                }
            }
            for (int i = k + 1; i < edge; i++) {
                for (int j = k + 1; j < edge; j++) {
                    slice[i][j] = slice[i][j] * slice[k][k] - slice[i][k] * slice[k][j];
                    if (k!= 0) {
                        slice[i][j] /= slice[k-1][k-1];
                    }
                }
            }
        }
        det = sign * slice[edge-1][edge-1];
        return det;
    }
}

void determinant(long long (*cube)[32][32], int edge, char k, int i) {

    long long slice[edge][32];
    createSlice(cube, slice, edge, k, i);
    long long det = calculateDet(slice, edge);

    cout << "determinant : " << det << endl;
}
