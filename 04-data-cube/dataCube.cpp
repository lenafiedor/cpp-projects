#include <iostream>
using namespace std;

int main () {

    int edge;
    int l;
    int v;
    int p;
    int h;
    int w;
    int d;
    int e;
    int r;
    long long i;
    long long pomoc1;
    long long pomoc2;
    long long sign;
    int suma = 0;
    long long det = 0;
    char shape = 'C';
    char k;
    bool cond = true;

    cin >> edge;

    long long cube[edge][edge][edge];

    for ( d = 0; d < edge; d++ ) {
        for ( h = 0; h < edge; h++ ) {
            for ( w = 0; w < edge; w++ ) {
                cin >> cube[h][w][d];
            }
        }
    }

    while ( shape != 'E' ) {

        cin >> shape;

        if ( shape == 'C' ) {

            suma = 0;

            cin >> l;
            cin >> v;
            cin >> p;
            cin >> h;
            cin >> w;
            cin >> d;

            if ( l < 0 ) {
                i = 0;
                while ( l < 0 ) {
                    i++;
                    l++;
                }
                h -= i;
            }
            else if ( l >= edge ) {
                i = 0;
                while ( l >= edge ) {
                    i++;
                    l--;
                }
                h -= i;
            }

            if ( v < 0 ) {
                i = 0;
                while ( v < 0 ) {
                    i++;
                    v++;
                }
                w -= i;
            }
            else if ( v >= edge ) {
                i = 0;
                while ( v >= edge ) {
                    i++;
                    v--;
                }
                w -= i;
            }

            if ( p < 0 ) {
                i = 0;
                while ( p < 0 ) {
                    i++;
                    p++;
                }
                d -= i;
            }
            else if ( p >= edge ) {
                i = 0;
                while ( p >= edge ) {
                    i++;
                    p--;
                }
                d -= i;
            }

            if ( l < edge / 2 ) {
                for ( int pomoc1 = l; pomoc1 <= l + h && pomoc1 < edge; pomoc1++ ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + w && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + d && pomoc3 < edge; pomoc3++ ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - d && pomoc3 >= 0; pomoc3-- ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - w && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + d && pomoc3 < edge; pomoc3++ ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - d && pomoc3 >= 0; pomoc3-- ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }
            else {
                for ( int pomoc1 = l; pomoc1 >= l - h && pomoc1 >= 0; pomoc1-- ) {
                    if ( v < edge / 2 ) {
                        for ( int pomoc2 = v; pomoc2 <= v + w && pomoc2 < edge; pomoc2++ ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + d && pomoc3 < edge; pomoc3++ ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - d && pomoc3 >= 0; pomoc3-- ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                    else {
                        for ( int pomoc2 = v; pomoc2 >= v - w && pomoc2 >= 0; pomoc2-- ) {
                            if ( p < edge / 2 ) {
                                for ( int pomoc3 = p; pomoc3 <= p + d && pomoc3 < edge; pomoc3++ ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                            else {
                                for (int pomoc3 = p; pomoc3 >= p - d && pomoc3 >= 0; pomoc3-- ) {
                                    suma = suma + cube[pomoc1][pomoc2][pomoc3];
                                }
                            }
                        }
                    }
                }
            }

            cout << suma << endl;
        }

        else if ( shape == 'T' ) {

            suma = 0;
            cond = false;

            cin >> l;
            cin >> v;
            cin >> p;
            cin >> e;

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

        else if ( shape == 'O' ) {

            suma = 0;
            cond = false;

            cin >> l;
            cin >> v;
            cin >> p;
            cin >> r;

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
        
        else if ( shape == 'D' ) {

            det = 0;
            cond = true;
            sign = 1;

            cin >> k;
            cin >> i;

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
                                        for ( pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            pomoc2 = cube[i][move][pomoc1];
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
                                        for ( pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            pomoc2 = cube[move][i][pomoc1];
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
                                        for ( pomoc1 = 0; pomoc1 < edge; pomoc1++ ) {
                                            pomoc2 = cube[move][pomoc1][i];
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

            if ( cond == true || edge <= 0 ) {
                det = 0;
            }

            cout << det << endl;
        }
    }

    return 0;
}