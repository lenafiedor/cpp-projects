#include <iostream>
using namespace std;
int main () {

    int ileZestawow;
    int size;
    int i = 0;
    char oper;
    int index;
    int lenght;
    int move;
    int l;
    int m;
    int n;
    int x;
    int y;
    int j;
    int klatki;

    cin >> ileZestawow;

    while ( ileZestawow > 0 ) {

        oper = 'P';
        i = 0;

        cin >> size;
        if ( size <= 0 ) {
            oper = 'F';
        }
        int arr[size];
        klatki = size;

        while ( i < size ) {
            cin >> arr[i];
            i++;
        }

        i = 0;
        while ( i < size - 1 ) {
            cout << arr[i] << " ";
            i++;
        }
        cout << arr[i] << endl;

        while ( oper != 'F' ) {

            cin >> oper;
            klatki = size;

			if ( oper == 'R' ) {

                cin >> index >> lenght;

                index = index % size;
                if ( index < 0 ) {
                    index = index + size;
                }
                if ( lenght <= 1 || lenght > size ) {
                    klatki = lenght - 1;
                }
                while ( klatki >= lenght ) {
                
                    l = lenght;
                    i = lenght;
                    j = index;

                    while ( i > lenght / 2 ) {
                        j = j % size;
                        n = ( j + l - 1 ) % size;
                        x = arr[j];
                        arr[j] = arr[n];
                        arr[n] = x;
                        l -= 2;
                        j++;
                        i--;
                    } 
                    klatki = klatki - lenght;
                    index = index + lenght;
                }
            }

            else if ( oper == 'S' ) {

                cin >> index >> lenght;

                if ( lenght <= 0 || size < lenght * 2 ) {
                    klatki = lenght - 1;
                }
                index = index % size;
                if ( index < 0 ) {
                    index = index + size;
                }
				if ( lenght > size ) {
                    lenght = size;
                    klatki = lenght;
                }

                while ( klatki >= 2 * lenght ) {

                    i = index;
                    l = 0;

                    while ( l < lenght ) {
                        i = i % size;
                        n = ( i + lenght ) % size;
                        x = arr[i];
                        arr[i] = arr[n];
                        arr[n] = x;
                        i++;
                        l++;
                    }
                    klatki = klatki - ( 2 * lenght );
                    index = index + ( 2 * lenght );
                }
            }

            else if ( oper == 'C' ) {

                cin >> index >> lenght >> move;

                m = move;

                if ( lenght > 0 && move != 0 ) {
                    
                    if ( lenght > size ) {
                        move = move % size;
                        lenght = size;
                        klatki = lenght;
                    }
                    else {
                        move = move % lenght;
                    }
                    if ( lenght == 0 ) {
                        lenght = size;
                    }
                    index = index % size;
                    if ( index < 0 ) {
                        index = index + size;
                    }

                    while ( klatki >= lenght ) {

                        i = index;
                        l = 0;
                        j = 0;

                        if ( move < 0 ) {
                            while ( l > move ) {
                                i = i % size;
                                n = ( i + lenght - 1 ) % size;
                                x = arr[n];
                                arr[n] = arr[i];
                                i--;
                                j++;
                                while ( j < lenght ) {
                                    i = i % size;
                                    n = ( i + lenght - 1 ) % size;
                                    y = arr[n];
                                    arr[n] = x;
                                    x = y;
                                    i--;
                                    j++;
                                }
                                l--;
                                i = index;
                                j = 0;
                            }
                        }
                        else {
                            while ( l < move ) {
                                i = i % size;
                                n = ( i + lenght - 1 ) % size;
                                x = arr[i];
                                arr[i] = arr[n];
                                arr[n] = arr[i];
                                i++;
                                j++;
                                while ( j < lenght ) {
                                    i = i % size;
                                    y = arr[i];
                                    arr[i] = x;
                                    x = y;
                                    i++;
                                    j++;
                                }
                                l++;
                                i = index;
                                j = 0;
                            }
                        }
                        klatki = klatki - lenght;
                        index = ( index + lenght ) % size;
                    }

                    if ( lenght < 0 || m == 0 ) {
                        klatki = 0;
                    }

                    if ( klatki != 0 && klatki != 1 ) {
                        m = m % klatki;
                        i = index;
                        l = 0;
                        j = 0;

                        if ( m < 0 ) {
                            while ( l > m ) {
                                i = index % size;
                                n = ( i + klatki - 1 ) % size;
                                x = arr[n];
                                arr[n] = arr[i];
                                i--;
                                j++;
                                while ( j < klatki ) {
                                    i = i % size;
                                    n = ( i + klatki - 1 ) % size;
                                    y = arr[n];
                                    arr[n] = x;
                                    x = y;
                                    i--;
                                    j++;
                                }
                                l--;
                                j = 0;
                            }
                        }
                        else {
                            while ( l < m ) {
                                i = index % size;
                                n = ( i + klatki - 1 ) % size;
                                x = arr[i];
                                arr[i] = arr[n];
                                arr[n] = arr[i];
                                i++;
                                j++;
                                while ( j < klatki ) {
                                    i = i % size;
                                    y = arr[i];
                                    arr[i] = x;
                                    x = y;
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
            else {
                oper = 'F';
            }
        }

        i = 0;
        while ( i < size - 1 ) {
            cout << arr[i] << " ";
            i++;
        }
        cout << arr[i] << endl;

        ileZestawow--;
    }

    return 0;
}