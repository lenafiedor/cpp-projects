#include <iostream>
#include "binarySets.cpp"

using namespace std;

#define N 100

int main () {

    int value;
    int i = 0;
    char set [ N ] = { ' ', ' ', '0', '0', '1', '0', '1', ' ', ' ', ' ', '0', '0', '1', '0', '0', ' ', '\0' };
    char set2 [ N ] = { ' ', ' ', '0', '0', '1', '0', '1', ' ', ' ', '\0' };

    Emplace ( set, &value );
    Print ( value, set );
    while ( set[i] != '\0' ) {
        cout << set[i];
        i++;
    }
    cout << '\n';
    i = 0;

    Erase ( set2, &value );
    Print ( value, set );
    while ( set[i] != '\0' ) {
        cout << set[i];
        i++;
    }
    cout << '\n';

    cout << "kardynalka: " << Cardinality ( value );

    return 0;
}