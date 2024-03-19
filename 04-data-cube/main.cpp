#include <iostream>
#include "operations.cpp"

using namespace std;


int main () {

    int edge = 2;
    // cin >> edge;

    long long cube[edge][32][32];

    fillCube(edge, cube);
    printCube(edge, cube);

    char operation = '_';
    while (operation != 'E') {

        cout << "insert operation: ";
        cin >> operation;

        // switch (operation) {
        //     case 'C':
        //         int l, v, p, h, w, d;
        //         cin >> l >> v >> p >> h >> w >> d;
        //         cout << "myimplementation: " << endl;
        //         cuboid(cube, edge, l, v, p, h, w, d);
        //         break;
        //     default:
        //         break;
        // }

        if (operation == 'C') {

            int l, v, p, h, w, d;
            cin >> l >> v >> p >> h >> w >> d;

            cuboid(cube, edge, l, v, p, h, w, d);
        }
        else if (operation == 'T') {

            int suma = 0;
            bool cond = false;

            int l, v, p, e;
            cin >> l >> v >> p >> e;

            if ( l < edge / 2 ) {
                for ( int pomoc1 = l; pomoc1 <= l + e && pomoc1 < edge; pomoc1++ ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + e && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + e && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) + ( pomoc2 - v ) + ( pomoc3 - p ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }      
                            }
                            else {
                                for ( int pomoc3 = p; pomoc3 >= p - e && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( ( pomoc1 - l ) + ( pomoc2 - v ) + ( p - pomoc3 ) ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            } 
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - e && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + e && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) + ( v - pomoc2 ) + ( pomoc3 - p ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - e && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) + ( v - pomoc2 ) + ( p - pomoc3 ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }
            else {
                for ( int pomoc1 = l; pomoc1 >= l - e && pomoc1 >= 0; pomoc1-- ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + e && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + e && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) + ( pomoc2 - v ) + ( pomoc3 - p ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - e && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) + ( pomoc2 - v ) + ( p - pomoc3 ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - e && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + e && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) + ( v - pomoc2 ) + ( pomoc3 - p ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - e && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) + ( v - pomoc2 ) + ( p - pomoc3 ) <= e )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }

            cout << suma << endl;
        }

        else if (operation == 'O') {

            int suma = 0;
            bool cond = false;

            int l, v, p, r;
            cin >> l >> v >> p >>r;

            if ( l < edge / 2 ) {
                for ( int pomoc1 = l; pomoc1 <= l + r && pomoc1 < edge; pomoc1++ ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + r && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + r && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) * ( pomoc1 - l ) + ( pomoc2 - v ) * ( pomoc2 - v ) + ( pomoc3 - p ) * ( pomoc3 - p ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }      
                            }
                            else {
                                for ( int pomoc3 = p; pomoc3 >= p - r && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( ( pomoc1 - l ) * ( pomoc1 - l ) + ( pomoc2 - v ) * ( pomoc2 - v ) + ( p - pomoc3 ) * ( p - pomoc3 ) ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            } 
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - r && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + r && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) * ( pomoc1 - l ) + ( v - pomoc2 ) * ( v - pomoc2 ) + ( pomoc3 - p ) * ( pomoc3 - p ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - r && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( pomoc1 - l ) * ( pomoc1 - l ) + ( v - pomoc2 ) * ( v - pomoc2 ) + ( p - pomoc3 ) * ( p - pomoc3 ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }
            else {
                for ( int pomoc1 = l; pomoc1 >= l - r && pomoc1 >= 0; pomoc1-- ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + r && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + r && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) * ( l - pomoc1 ) + ( pomoc2 - v ) * ( pomoc2 - v ) + ( pomoc3 - p ) * ( pomoc3 - p ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - r && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) * ( l - pomoc1 ) + ( pomoc2 - v ) * ( pomoc2 - v ) + ( p - pomoc3 ) * ( p - pomoc3 ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - r && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + r && pomoc3 < edge; pomoc3++ ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) * ( l - pomoc1 ) + ( v - pomoc2 ) * ( v - pomoc2 ) + ( pomoc3 - p ) * ( pomoc3 - p ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - r && pomoc3 >= 0; pomoc3-- ) {
                                    cond = false;
                                    if ( ( l - pomoc1 ) * ( l - pomoc1 ) + ( v - pomoc2 ) * ( v - pomoc2 ) + ( p - pomoc3 ) * ( p - pomoc3 ) <= r * r )
                                    cond = true;
                                    if ( pomoc1 >= 0 && pomoc1 < edge && pomoc2 >= 0 && pomoc2 < edge && pomoc3 >= 0 && pomoc3 < edge && cond == true )
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        
        else if (operation == 'D') {

            long long det = 0;
            bool cond = true;
            int sign = 1;
            char k;
            long long i;

            cin >> k >> i;

            if ( k == 'l' ) {

                cond = true;

                for ( int wiersz = 0; wiersz < edge; wiersz++ ) {
                    for ( int panel = 0; panel < edge; panel++ ) {
                        if ( cube[i][wiersz][panel] != 0 )
                        cond = false;
                        break;
                    }
                }

                if ( cond == false ) {
        
                    if ( edge == 2 )
                    det = cube[i][0][0] * cube[i][1][1] - cube[i][0][1] * cube[i][1][0];
                    else {

                        for ( long long k = 0; k < edge - 1; k++ ) {

                            if ( cube[i][k][k] == 0 ) {
                                long long move = 0;
                                for ( move = k + 1; move < edge; move++ ) {
                                    if ( cube[i][move][k] != 0 ) {
                                        for (int pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            int pomoc2 = cube[i][move][pomoc1];
                                            cube[i][move][pomoc1] = cube[i][k][pomoc1];
                                            cube[i][k][pomoc1] = pomoc2;
                                        }
                                        sign = -sign;
                                        break;
                                    }
                                }
                                if ( move == edge ) {
                                    det = 0;
                                    break;
                                }
                            }
                            
                            for ( int l = k + 1; l < edge; l++ ) {
                                for ( int j = k + 1; j < edge; j++ ) {
                                    cube[i][l][j] = ( cube[i][l][j] * cube[i][k][k] - cube[i][l][k] * cube[i][k][j] );
                                    if ( k != 0 )
                                    cube[i][l][j] /= cube[i][k-1][k-1];
                                }
                            }
                        }
                        det = sign * cube[i][edge-1][edge-1];
                    }
                }   
            }

            else if ( k == 'v' ) {

                cond = true;

                for ( int kolumna = 0; kolumna < edge; kolumna++ ) {
                    for ( int panel = 0; panel < edge; panel++ ) {
                        if ( cube[kolumna][i][panel] != 0 )
                        cond = false;
                        break;
                    }
                }

                if ( cond == false ) {

                    if ( edge == 2 )
                    det = cube[0][i][0] * cube[1][i][1] - cube[0][i][1] * cube[1][i][0];
                    else {

                        for ( int k = 0; k < edge - 1; k++ ) {

                            if ( cube[k][i][k] == 0 ) {
                                long long move = 0;
                                for ( move = k + 1; move < edge; move++ ) {
                                    if ( cube[move][i][k] != 0 ) {
                                        for (int pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            int pomoc2 = cube[move][i][pomoc1];
                                            cube[move][i][pomoc1] = cube[k][i][pomoc1];
                                            cube[k][i][pomoc1] = pomoc2;
                                        }
                                        sign = -sign;
                                        break;
                                    }
                                }
                                if ( move == edge ) {
                                    det = 0;
                                    break;
                                }
                            }

                            for ( int l = k + 1; l < edge; l++ ) {
                                for ( int j = k + 1; j < edge; j++ ) {
                                    cube[l][i][j] = ( cube[l][i][j] * cube[k][i][k] - cube[l][i][k] * cube[k][i][j] );
                                    if ( k != 0 )
                                    cube[l][i][j] /= cube[k-1][i][k-1];
                                }
                            }
                        }
                        det = sign * cube[edge-1][i][edge-1];
                    }
                }   
            } 

            else if ( k == 'p' ) {

                cond = true;

                for ( int kolumna = 0; kolumna < edge; kolumna++ ) {
                    for ( int wiersz = 0; wiersz < edge; wiersz++ ) {
                        if ( cube[kolumna][wiersz][i] != 0 )
                        cond = false;
                        break;
                    }
                }

                if ( cond == false ) {

                    if ( edge == 2 )
                    det = cube[0][0][i] * cube[1][1][i] - cube[0][1][i] * cube[1][0][i];
                    else {
                    
                        for ( int k = 0; k < edge - 1; k++ ) {

                            if ( cube[k][k][i] == 0 ) {
                                long long move = 0;
                                for ( move = k + 1; move < edge; move++ ) {
                                    if ( cube[move][k][i] != 0 ) {
                                        for (int pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            int pomoc2 = cube[move][pomoc1][i];
                                            cube[move][pomoc1][i] = cube[k][pomoc1][i];
                                            cube[k][pomoc1][i] = pomoc2;
                                        }
                                        sign = -sign;
                                        break;
                                    }
                                }
                                if ( move == edge ) {
                                    det = 0;
                                    break;
                                }
                            }

                            for ( int l = k + 1; l < edge; l++ ) {
                                for ( int j = k + 1; j < edge; j++ ) {
                                    cube[l][j][i] = ( cube[l][j][i] * cube[k][k][i] - cube[l][k][i] * cube[k][j][i] );
                                    if ( k != 0 )
                                    cube[l][j][i] /= cube[k-1][k-1][i];
                                }
                            }
                        }
                        det = sign * cube[edge-1][edge-1][i];
                    }
                }
            }

            if (cond == true || edge <= 0) {
                det = 0;
            }
            cout << det << endl;
        }
    }
    return 0;
}
