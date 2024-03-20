#include <iostream>
#include "operations.cpp"

using namespace std;


int main () {

    int edge;
    cin >> edge;

    long long cube[edge][32][32];

    fillCube(edge, cube);
    printCube(edge, cube);

    int l, v, p, h, w, d, e, r;
    char operation = '_';
    while (operation != 'E') {

        cout << "insert operation: ";
        cin >> operation;

        switch (operation) {
            case 'C':
                cin >> l >> v >> p >> h >> w >> d;
                cuboid(cube, edge, l, v, p, h, w, d);
                break;
            case 'T':
                cin >> l >> v >> p >> e;
                tetrahedron(cube, edge, l, v, p, e);
                break;
            case 'O':
                cin >> l >> v >> p >>r;
                octal(cube, edge, l, v, p, r);
                break;
            case 'D':
                char k; int i;
                cin >> k >> i;
                determinant(cube, edge, k, i);
            default:
                break;
        }
    }
    return 0;
}
