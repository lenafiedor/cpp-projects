#include <iostream>
using namespace std;

void List ( int tab[], int roz ) {
    for ( int i = 0; i < roz; i++ ) {
        cout << tab[i] << " ";
    }
    cout << "" << endl;
}

void Sort ( int tab[], int roz ) {
    int help;
    int i = roz - 1;
    bool change = true;
    while ( change == true ) {
        change = false;
        while ( i > 0 ) {
            if ( tab[i] < tab[i-1] ) {
                help = tab[i];
                tab[i] = tab[i-1];
                tab[i-1] = help;
                change = true;
            }
            i--;
        }
        i = roz - 1;
    }
}

void Add ( int liczba, int tab[] ) {
    if ( liczba >= 1 && liczba <= 4095 ) {
        int roz;
        int i = 0;
        bool cond = false;
        while ( tab[i] != -1 ) {
            i++;
        }
        roz = i;
        for ( int k = 0; k <= roz; k++ ) {
            if ( tab[k] == liczba ) {
                cond = true;
                break;
            }
        }
        if ( cond == false ) {
            tab[roz] = liczba;
            tab[roz+1] = -1;
            Sort ( tab, roz + 1 );
        }
    }
}

void Create ( int ile, int tab1[], int tab2[] ) {
	int k = 0;
	tab2[0] = -1;
	for ( int i = 0; i < ile; i++  ) {
		if ( tab1[i] >= 1 && tab1[i] <= 4095 ) {
			int roz;
			int j = 0;
			bool cond = false;
			while ( tab2[j] != -1 ) {
			    j++;
			}
        	roz = j;
			for ( k = 0; k <= roz; k++ ) {
	            if ( tab2[k] == tab1[i] ) {
	                cond = true;
	                break;
	            }
			}
        	if ( cond == false ) {
            	tab2[roz] = tab1[i];
            	tab2[roz+1] = -1;
        	}
		}
	}
	Sort ( tab2, k );
}

void Union ( int tab1[], int tab2[], int tab3[] ) {
    int roz1;
    int roz2;
    int i = 0;
    int j = 0;
    int k = 0;
    bool cond = false;
    while ( tab1[i] != -1 ) {
        i++;
    }
    roz1 = i;
    while ( tab2[j] != -1 ) {
        j++;
    }
    roz2 = j;
    tab3[0] = -1;
    for ( i = 0; i < roz1; i++, k++ ) {
        tab3[i] = tab1[i];
        tab3[i+1] = -1;
	}
    for ( i = 0; i < roz2; i++ ) {
        for ( j = 0; j <= k; j++ ) {
            if ( tab3[j] == tab2[i] ) {
                cond = true;
            }
        }
        if ( cond == false ) {
            tab3[k] = tab2[i];
            tab3[k+1] = -1;
            k++;
        }
        cond = false;
    }
    Sort ( tab3, k );
}

void Intersection ( int tab1[], int tab2[], int tab3[] ) {
    int k = 0;
    tab3[0] = -1;
    for ( int i = 0; tab1[i] != -1; i++ ) {
        for ( int j = 0; tab2[j] != -1; j++ ) {
            if ( tab1[i] == tab2[j] ) {
                tab3[k] = tab1[i];
                tab3[k+1] = -1;
                k++;
            }
        }
    }
    Sort ( tab3, k );
}

void Difference ( int tab1[], int tab2[], int tab3[] ) {
    int k = 0;
    bool cond = true;
    tab3[0] = -1;
    for ( int i = 0; tab1[i] != -1; i++ ) {
        for ( int j = 0; tab2[j] != -1; j++ ) {
            if ( tab1[i] == tab2[j] ) {
                cond = false;
            }
        }
        if ( cond == true ) {
            tab3[k] = tab1[i];
            tab3[k+1] = -1;
            k++;
        }
        cond = true;
    }
    Sort ( tab3, k );
}

void Symmetric ( int tab1[], int tab2[], int tab3[] ) {
    int k = 0;
    bool cond = true;
    tab3[0] = -1;
    for ( int i = 0; tab1[i] != -1; i++ ) {
        for ( int j = 0; tab2[j] != -1; j++ ) {
            if ( tab1[i] == tab2[j] ) {
                cond = false;
            }
        }
        if ( cond == true ) {
            tab3[k] = tab1[i];
            tab3[k+1] = -1;
            k++;
        }
        cond = true;
    }
    for ( int i = 0; tab2[i] != -1; i++ ) {
        for ( int j = 0; tab1[j] != -1; j++ ) {
            if ( tab2[i] == tab1[j] ) {
                cond = false;
                break;
            }
        }
        if ( cond == true ) {
            tab3[k] = tab2[i];
            tab3[k+1] = -1;
            k++;
        }
        cond = true;
    }
    Sort ( tab3, k );
}

void Complement ( int tab1[], int tab2[] ) {
    int k = 0;
    bool cond = true;
    tab2[0] = -1;
    for ( int u = 1; u <= 4095; u++ ) {
        for ( int i = 0; tab1[i] != -1; i++ ) {
            if ( tab1[i] == u ) {
                cond = false;
            }
        }
        if ( cond == true ) {
            tab2[k] = u;
            tab2[k+1] = -1;
            k++;
        }
        cond = true;
    }
}

bool Subset ( int tab1[], int tab2[] ) {
    bool cond = false;
    if ( tab1[0] == -1 ) {
        cond = true;
    }
    else {
        for ( int i = 0; tab1[i] != -1; i++ ) {
            for ( int j = 0; tab2[j] != -1; j++ ) {
                if ( tab1[i] == tab2[j] ) {
                    cond = true;
                    break;
                }
                else {
                    cond = false;
                }
            }
            if ( cond == false ) {
                break;
            }
        }
    }
    return cond;
}

bool Equal ( int tab1[], int tab2[] ) {
    int roz1;
    int roz2;
    int i = 0;
    int j = 0;
    bool cond = false;
    while ( tab1[i] != -1 ) {
        i++;
    }
    roz1 = i;
    while ( tab2[j] != -1 ) {
        j++;
    }
    roz2 = j;
    if ( i == j ) {
        if ( Subset ( tab1, tab2 ) == true ) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Empty ( int tab[] ) {
    if ( tab[0] == -1 ) {
        return true;
    }
    else {
        return false;
    }
}

bool Nonempty ( int tab[] ) {
    if ( tab[0] != -1 ) {
        return true;
    }
    else {
        return false;
    }
}

double Arithmetic ( int tab[] ) {
    int roz;
    int i = 0;
    int suma = 0;
    double main;
    if ( tab[0] != -1 ) {
        while ( tab[i] != -1 ) {
            i++;
        }
        roz = i;
        for ( i = 0; i < roz; i++ ) {
            suma = suma + tab[i];
        }
        main = suma * 1.0 / roz * 1.0;
    }
    else {
        main = 0;
    }
    return main;
}

double Harmonic ( int tab[] ) {
    int roz;
    int i = 0;
    int suma = 0;
    double mianownik = 0;
    double main;
    if ( tab[0] != -1 ) {
        while ( tab[i] != -1 ) {
            i++;
        }
        roz = i;
        for ( i = 0; i < roz; i++ ) {
            mianownik = mianownik + ( 1.0 / tab[i] ) ;
        }
        main = roz / mianownik * 1.0;
    }
    else {
        main = 1;
    }
    return main;
}

bool Element ( int liczba, int tab[] ) {
    bool cond = false;
    int roz;
    int i = 0;
    while ( tab[i] != -1 ) {
        i++;
    }
    roz = i;
    for ( int i = 0; i < roz; i++ ) {
        if ( liczba == tab[i] ) {
            cond = true;
            break;
        }
    }
    return cond;
}

void MinMax ( int tab[], int* min, int& max ) {
    if ( tab[0] != -1 ) {
    	*min = 4095;
    	max = 1;
        int roz;
        int i = 0;
        while ( tab[i] != -1 ) {
            i++;
        }
        roz = i;
        for ( i = 0; i < roz; i++ ) {
            if ( tab[i] < *min ) {
                *min = tab[i];
            }
            if ( tab[i] > max ) {
                max = tab[i];
            }
        }
    }
}

void Cardinality ( int tab[], int* power ) {
    int i = 0;
    while ( tab[i] != -1 ) {
        i++;
    }
    *power = i;
}

void Properties ( int tab[], char prop[], double& arith, double* harm, int& min, int* max, int& power ) {
    for ( int i = 0; prop[i] != 0; i++ ) {
        if ( prop[i] == 'a' ) {
            arith = Arithmetic ( tab );
        }
        if ( prop[i] == 'h' ) {
            *harm = Harmonic ( tab );
        }
        if ( prop[i] == 'm' ) {
            MinMax ( tab, &min, *max );
        }
        if ( prop [i] == 'c' ) {
            Cardinality ( tab, &power );
        }
    }
}