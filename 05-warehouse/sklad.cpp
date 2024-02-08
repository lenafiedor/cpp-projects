// autor: Lena Fiedor
// tytul: sklad

#include <iostream>
using namespace std;

long long suma = 0;

struct PLACE {
    unsigned short amount;
    char id1;
    char id2;

    void ZERO_PLACE () {
        amount = 0;
        id1 = '\0';
        id2 = '\0';
    }
};

struct SHELF {
    PLACE places[128];
    unsigned short usedplaces;
};

struct RACK {
    SHELF shelves[128];
    unsigned short usedshelves;
};

struct WAREHOUSE {
    RACK racks[128];
    SHELF handyshelf;
    unsigned int usedracks;
};

struct STORE {
    WAREHOUSE warehouses[128];
    RACK handyrack;
    SHELF handyshelf;
    unsigned int usedwarehouses;
} store;

void set_ap ( int w, int r, int s, int p ) {
    /* cout << store.usedwarehouses << endl;
    cout << store.warehouses[w].usedracks << endl;
    cout << store.warehouses[w].racks[r].usedshelves << endl;
    cout << store.warehouses[w].racks[r].shelves[s].usedplaces << endl; */
    if ( w < store.usedwarehouses && r < store.warehouses[w].usedracks && s < store.warehouses[w].racks[r].usedshelves && p >= 0 && p <= 128 ) {
        if ( p < store.warehouses[w].racks[r].shelves[s].usedplaces ) {
            for ( int i = p; i < store.warehouses[w].racks[r].shelves[s].usedplaces; i++ ) {
                suma -= store.warehouses[w].racks[r].shelves[s].places[i].amount;
                store.warehouses[w].racks[r].shelves[s].places[i].ZERO_PLACE ();
            }
        }
        store.warehouses[w].racks[r].shelves[s].usedplaces = p;
    }
    else {
        cout << "error" << endl;
    }
    // cout << store.warehouses[w].racks[r].shelves[s].usedplaces << endl;
}

void set_as ( int w, int r, int s, int p ) {
    if ( w < store.usedwarehouses && r < store.warehouses[w].usedracks && s >= 0 && s <= 128 && p >= 0 && p <= 128 ) {

        int n;

        if ( s < store.warehouses[w].racks[r].usedshelves ) {
            n = s;
        }
        else {
            n = store.warehouses[w].racks[r].usedshelves;
        }

        for ( int i = 0; i < n; i++ ) {
            if ( store.warehouses[w].racks[r].shelves[i].usedplaces > p ) {
                for ( int j = p; j < store.warehouses[w].racks[r].shelves[i].usedplaces; j++ ) {
                    suma -= store.warehouses[w].racks[r].shelves[i].places[j].amount;
                    store.warehouses[w].racks[r].shelves[i].places[j].ZERO_PLACE ();
                }
            }
            store.warehouses[s].racks[r].shelves[i].usedplaces = p;
        }

        if ( store.warehouses[w].racks[r].usedshelves < s ) {
            for ( int i = store.warehouses[w].racks[r].usedshelves; i < s; i++ ) {
                store.warehouses[s].racks[r].shelves[i].usedplaces = p;
            }
        }
        else {
            for ( int i = s; i < store.warehouses[w].racks[r].usedshelves; i++ ) {
                for ( int j = 0; j < store.warehouses[s].racks[r].shelves[i].usedplaces; j++ ) {
                    suma -= store.warehouses[s].racks[r].shelves[i].places[j].amount;
                    store.warehouses[s].racks[r].shelves[i].places[j].ZERO_PLACE ();
                }
                store.warehouses[s].racks[r].shelves[i].usedplaces = 0;
            }
        }
    }
    else {
        cout << "error" << endl;
    }
}

void set_ar ( int w, int r, int s, int p ) {
    if ( w < store.usedwarehouses && r >= 0 && r <= 128 && s >= 0 && s <= 128 && p >= 0 && p <= 128 ) {
        if ( r < store.warehouses[w].usedracks ) {
            for ( int i = r; i < store.warehouses[w].usedracks; i++ ) {
                if ( s < store.warehouses[w].racks[i].usedshelves ) {
                    for ( int j = 0; j < store.warehouses[w].racks[i].usedshelves; j++ ) {
                        if ( p < store.warehouses[w].racks[i].shelves[j].usedplaces ) {
                            for ( int k = 0; k < store.warehouses[w].racks[i].shelves[j].usedplaces; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        else {
                            for ( int k = 0; k < p; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        store.warehouses[w].racks[i].shelves[j].usedplaces = p;
                    }
                }
                else {
                    for ( int j = 0; j < s; j++ ) {
                        if ( p < store.warehouses[w].racks[i].shelves[j].usedplaces ) {
                            for ( int k = 0; k < store.warehouses[w].racks[i].shelves[j].usedplaces; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        else {
                            for ( int k = 0; k < p; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        store.warehouses[w].racks[i].shelves[j].usedplaces = p;
                    }
                }
                store.warehouses[w].racks[i].usedshelves = s;
            }
        }
        else {
            for ( int i = store.warehouses[w].usedracks; i < r; i++ ) {
                if ( s < store.warehouses[w].racks[i].usedshelves ) {
                    for ( int j = 0; j < store.warehouses[w].racks[i].usedshelves; j++ ) {
                        if ( p < store.warehouses[w].racks[i].shelves[j].usedplaces ) {
                            for ( int k = 0; k < store.warehouses[w].racks[i].shelves[j].usedplaces; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        else {
                            for ( int k = 0; k < p; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        store.warehouses[w].racks[i].shelves[j].usedplaces = p;
                    }
                }
                else {
                    for ( int j = 0; j < s; j++ ) {
                        if ( p < store.warehouses[w].racks[i].shelves[j].usedplaces ) {
                            for ( int k = 0; k < store.warehouses[w].racks[i].shelves[j].usedplaces; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        else {
                            for ( int k = 0; k < p; k++ ) {
                                suma -= store.warehouses[w].racks[i].shelves[j].places[k].amount;
                                store.warehouses[w].racks[i].shelves[j].places[k].ZERO_PLACE ();
                            }
                        }
                        store.warehouses[w].racks[i].shelves[j].usedplaces = p;
                    }
                }
                store.warehouses[w].racks[i].usedshelves = s;
            }
        }
        store.warehouses[w].usedracks = r;
    }
    else {
        cout << "error" << endl;
    }
}

void set_aw ( int w, int r, int s, int p ) {
    if ( w >= 0 && w <= 128 && r >= 0 && r <= 128 && s >= 0 && s <= 128 && p >= 0 && p <= 128 ) {        
        if ( w < store.usedwarehouses ) {
            for ( int i = w; i < store.usedwarehouses; i++ ) {
                if ( r < store.warehouses[i].usedracks ) {
                    for ( int j = 0; j < store.warehouses[i].usedracks; j++ ) {
                        if ( s < store.warehouses[i].racks[j].usedshelves ) {
                            for ( int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        else {
                            for ( int k = 0; k < s; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        store.warehouses[i].racks[j].usedshelves = s;
                    }
                }
                else {
                    for ( int j = 0; j < r; j++ ) {
                        if ( s < store.warehouses[i].racks[j].usedshelves ) {
                            for ( int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        else {
                            for ( int k = 0; k < s; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        store.warehouses[i].racks[j].usedshelves = s;
                    }   
                }
                store.warehouses[i].usedracks = r;
            }
        }
        else {
            for ( int i = 0; i < w; i++ ) {
                if ( r < store.warehouses[i].usedracks ) {
                    for ( int j = 0; j < store.warehouses[i].usedracks; j++ ) {
                        if ( s < store.warehouses[i].racks[j].usedshelves ) {
                            for ( int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        else {
                            for ( int k = 0; k < s; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        store.warehouses[i].racks[j].usedshelves = s;
                    }
                }
                else {
                    for ( int j = 0; j < r; j++ ) {
                        if ( s < store.warehouses[i].racks[j].usedshelves ) {
                            for ( int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        else {
                            for ( int k = 0; k < s; k++ ) {
                                if ( p < store.warehouses[i].racks[j].shelves[s].usedplaces ) {
                                    for ( int l = 0; l < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                else {
                                    for ( int l = 0; l < p; l++ ) {
                                        suma -= store.warehouses[i].racks[j].shelves[k].places[l].amount;
                                        store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                                    }
                                }
                                store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                            }
                        }
                        store.warehouses[i].racks[j].usedshelves = s;
                    }   
                }
                store.warehouses[i].usedracks = r;
            }
        }
        store.usedwarehouses = w;
    }
    else {
        cout << "error" << endl;
    }
}

void set_hw ( int w, int p ) {
}

void set_hr ( int s, int p ) {
}

void set_hs ( int p ) {
    if ( p >= 0 && p <= 128 ) {
        if ( p < store.handyshelf.usedplaces ) {
            for ( int i = p; i < store.handyshelf.usedplaces; i++ ) {
                store.handyshelf.places[i].ZERO_PLACE ();
            }
        }
        else {
            for ( int i = store.handyshelf.usedplaces; i < p; i++ ) {
                store.handyshelf.places[i].ZERO_PLACE ();
            }
        }
        store.handyshelf.usedplaces = p;
    }
    else {
        cout << "error" << endl;
    }
}

void put_w ( int w, int r, int s, int p, int a ) { 
    if ( ( w < store.usedwarehouses ) && ( r < store.warehouses[r].usedracks ) && ( s < store.warehouses[w].racks[r].usedshelves )
    && ( p < store.warehouses[w].racks[r].shelves[s].usedplaces ) ) {
        if ( store.warehouses[w].racks[r].shelves[s].places[p].amount + a > 65535 ) {
            store.warehouses[w].racks[r].shelves[s].places[p].amount = 65535;
            suma += 65535;
        }
        else {
            store.warehouses[w].racks[r].shelves[s].places[p].amount += a;
            suma += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_h ( int w, int p, int a ) {  
    if ( ( w < store.usedwarehouses ) && ( p < store.warehouses[w].handyshelf.usedplaces ) ) {
        if ( store.warehouses[w].handyshelf.places[p].amount + a > 65535 ) {
            store.warehouses[w].handyshelf.places[p].amount = 65535;
            suma += 65535;
        }
        else {
            store.warehouses[w].handyshelf.places[p].amount += a;
            suma += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_r ( int s, int p, int a ) {  
    if ( s < store.handyshelf.usedplaces ) {
        if ( store.handyrack.shelves[s].places[p].amount + a > 65535 ) {
            store.handyrack.shelves[s].places[p].amount = 65535;
            suma = +65535;
        }
        else {
            store.handyrack.shelves[s].places[p].amount += a;
            suma += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_s ( int p, int a ) { 
    if ( p < store.handyshelf.usedplaces ) {
        if ( store.handyshelf.places[p].amount + a > 65535) {
            store.handyshelf.places[p].amount = 65535;
            suma += 65535;
        }
        else {
            store.handyshelf.places[p].amount += a;
            suma += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void fill ( int w, int r, int s, int p, int a ) {
    if ( w >= 0 && w <= 128 && r >= 0 && r <= 128 && s >= 0 && s <= 128 && p >= 0 && p <= 128 ) {

        suma = 0;
        if ( a > 65535 ) {
            a = 65535;
        }

        for ( int i = 0; i < store.handyshelf.usedplaces; i++ ) { // handyshelf
            store.handyshelf.places[i].amount = 0;
            store.handyshelf.places[i].id1 = '\0';
            store.handyshelf.places[i].id2 = '\0';
        }
        store.handyshelf.usedplaces = 0;

        
        for ( int i = 0; i < store.handyrack.usedshelves; i++ ) { // handyrack
            for ( int j = 0; j < store.handyrack.shelves[i].usedplaces; i++ ) {
                store.handyrack.shelves[i].places[j].amount = 0;
                store.handyrack.shelves[i].places[j].id1 = '\0';
                store.handyrack.shelves[i].places[j].id2 = '\0';
            }
            store.handyrack.shelves[i].usedplaces = 0;
        }
        store.handyrack.usedshelves = 0;

        for ( int i = 0; i < store.usedwarehouses; i++ ) { // handyshelves in warehouses
            for ( int j = 0; j < store.warehouses[w].handyshelf.usedplaces; j++ ) {
                store.warehouses[i].handyshelf.places[j].amount = 0;
                store.warehouses[i].handyshelf.places[j].id1 = '\0';
                store.warehouses[i].handyshelf.places[j].id2 = '\0';
            }
            store.warehouses[i].handyshelf.usedplaces = 0;
    
            for ( int j = 0; j < store.warehouses[i].usedracks; j++ ) { // the whole store
                for ( int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++ ) {
                    for ( int l = 0; i < store.warehouses[i].racks[j].shelves[k].usedplaces; l++ ) {
                        store.warehouses[i].racks[j].shelves[k].places[l].amount = 0;
                        store.warehouses[i].racks[j].shelves[k].places[l].id1 = '\0';
                        store.warehouses[i].racks[j].shelves[k].places[l].id2 = '\0';
                    }
                    store.warehouses[i].racks[j].shelves[k].usedplaces = 0;
                }
                store.warehouses[i].racks[j].usedshelves = 0;
            }
            store.warehouses[i].usedracks = 0;
        }

        store.usedwarehouses = w;
        for ( int i = 0; i < w; i++ ) {
            store.warehouses[i].usedracks = r;
            for ( int j = 0; i < r; i++ ) {
                store.warehouses[i].racks[j].usedshelves = s;
                for ( int k = 0; k < s; k++ ) {
                    store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                    for ( int l = 0; l < p; l++ ) {
                        suma += a;
                        store.warehouses[i].racks[j].shelves[k].places[l].amount = a;
                        store.warehouses[i].racks[j].shelves[k].places[l].id1 = '\0';
                        store.warehouses[i].racks[j].shelves[k].places[l].id2 = '\0';
                        // cout << "dodaje_w" << endl;
                    }
                }
            }
        }

        store.handyshelf.usedplaces = p;
        for ( int i = 0; i < p; i++ ) {
            suma += a;
            store.handyshelf.places[i].amount = a;
            store.handyshelf.places[i].id1 = '\0';
            store.handyshelf.places[i].id2 = '\0';
            // cout << "dodaje_s" << endl;
        }

        store.handyrack.usedshelves = s;
        for ( int i = 0; i < s; i++ ) {
            store.handyrack.shelves[i].usedplaces = p;
            for ( int j = 0; j < p; j++ ) {
                suma += a;
                store.handyrack.shelves[i].places[j].amount = a;
                store.handyrack.shelves[i].places[j].id1 = '\0';
                store.handyrack.shelves[i].places[j].id2 = '\0';
                // cout << "dodaje_r" << endl;
            }
        }

        for ( int i = 0; i < w; i++ ) {
            store.warehouses[i].handyshelf.usedplaces = p;
            for ( int j = 0; j < p; j++ ) {
                suma += a;
                store.warehouses[i].handyshelf.places[j].amount = a;
                store.warehouses[i].handyshelf.places[j].id1 = '\0';
                store.warehouses[i].handyshelf.places[j].id2 = '\0';
                // cout << "dodaje_ws" << endl;
            }
        }
    }
    else {
        cout << "error" << endl;
    }
}

void pop_w ( int w, int r, int s, int p, int a ) {
    if ( ( w < store.usedwarehouses ) && ( r < store.warehouses[r].usedracks ) && ( s < store.warehouses[w].racks[r].usedshelves )
    && ( p < store.warehouses[w].racks[r].shelves[s].usedplaces ) ) {
        if ( store.warehouses[w].racks[r].shelves[s].places[p].amount - a < 0 ) {
            suma -= store.warehouses[w].racks[r].shelves[s].places[p].amount;
            store.warehouses[w].racks[r].shelves[s].places[p].amount = 0;
        }
        else {
            suma -= a;
            store.warehouses[w].racks[r].shelves[s].places[p].amount -= a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void pop_h ( int w, int p, int a ) {
    if ( ( w < store.usedwarehouses ) && ( p < store.warehouses[w].handyshelf.usedplaces ) ) {
        if ( store.warehouses[w].handyshelf.places[p].amount - a < 0 ) {
            suma -= store.warehouses[w].handyshelf.places[p].amount;
            store.warehouses[w].handyshelf.places[p].amount = 0;
        }
        else {
            suma -= a;
            store.warehouses[w].handyshelf.places[p].amount -= a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void pop_r ( int s, int p, int a ) {
    if ( ( s < store.handyrack.usedshelves ) && ( p < store.handyrack.shelves[s].usedplaces ) ) {
        if ( store.handyrack.shelves[s].places[p].amount - a < 0 ) {
            suma -= store.handyrack.shelves[s].places[p].amount;
            store.handyrack.shelves[s].places[p].amount = 0;
        }
        else {
            suma -= a;
            store.handyrack.shelves[s].places[p].amount -= a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void pop_s ( int p, int a ) {
    if ( p < store.handyshelf.usedplaces ) {
        if ( store.handyshelf.places[p].amount - a < 0 ) {
            store.handyshelf.places[p].amount = 0;
            suma -= store.handyshelf.places[p].amount;
        }
        else {
            store.handyshelf.places[p].amount -= a;
            suma -= a;
        }
    }
}

void mov_w ( int w1, int r1, int s1, int w2, int r2, int s2, int p, int a ) {
    // body
}

void mov_h ( int w, int r, int s, int p, int a ) {
    // body
}

void mov_r ( int w, int r, int s1, int s2, int p, int a ) {
    // body
}

void mov_s ( int s, int p, int a ) {
    // body
}

void get_w ( int w ) {
    if ( w < store.usedwarehouses ) {
        long long quantity = 0;
        for ( int i = 0; i < store.warehouses[w].usedracks; i++ ) {
            for ( int j = 0; j < store.warehouses[w].racks[i].usedshelves; j++ ) {
                for ( int k = 0; k < store.warehouses[w].racks[i].shelves[j].usedplaces; k++ ) {
                    quantity += store.warehouses[w].racks[i].shelves[j].places[k].amount;
                }
            }
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_rw ( int w, int r ) {
    if ( w < store.usedwarehouses && r < store.warehouses[w].usedracks ) {
        long long quantity = 0;
        for ( int i = 0; i < store.warehouses[w].racks[r].usedshelves; i++ ) {
            for ( int j = 0; j < store.warehouses[w].racks[r].shelves[j].usedplaces; j++ ) {
                quantity += store.warehouses[w].racks[r].shelves[j].places[j].amount;
            }
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_rh () {
    long long quantity = 0;
    for ( int i = 0; i < store.handyrack.usedshelves; i++ ) {
        for ( int j = 0; j < store.handyrack.shelves[i].usedplaces; j++ ) {
            quantity += store.handyrack.shelves[i].places[j].amount;
        }
    }
    cout << quantity << endl;
}

void get_sw ( int w, int r, int s ) {
    if ( w < store.usedwarehouses && r < store.warehouses[w].usedracks && s < store.warehouses[w].racks[r].usedshelves ) {
        long long quantity = 0;
        for ( int i = 0; i < store.warehouses[w].racks[r].shelves[s].usedplaces; i++ ) {
            quantity += store.warehouses[w].racks[r].shelves[s].places[i].amount;
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_sh ( int w ) {
    if ( w < store.usedwarehouses ) {
        long long quantity = 0;
        for ( int i = 0; i < store.warehouses[w].handyshelf.usedplaces; i++ ) {
            quantity += store.warehouses[w].handyshelf.places[i].amount;
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_sr ( int s ) {
    if ( s < store.handyrack.usedshelves ) {
        long long quantity = 0;
        for ( int i = 0; i < store.handyrack.shelves[s].usedplaces; i++ ) {
            quantity += store.handyrack.shelves[s].places[i].amount;
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_s () {
    long long quantity = 0;
    for ( int i = 0; i < store.handyshelf.usedplaces; i++ ) {
        quantity += store.handyshelf.places[i].amount;
    }
    cout << quantity << endl;
}

/////////////////////////// MAIN ///////////////////////////

int main () {

    for ( int i = 0; i < 128; i++ ) {
        store.handyshelf.places[i].ZERO_PLACE ();
        for ( int j = 0; j < 128; j++ ) {
            store.handyrack.shelves[i].places[j].ZERO_PLACE ();
            for ( int k = 0; k < 128; k++ ) {
                for ( int l = 0; l < 128; l++ ) {
                    store.warehouses[i].racks[j].shelves[k].places[l].ZERO_PLACE ();
                }
                store.warehouses[i].racks[j].shelves[k].usedplaces = 0;
            }
            store.warehouses[i].racks[j].usedshelves = 0;
        }
        store.warehouses[i].usedracks = 0;
        store.handyrack.shelves[i].usedplaces = 0;
        store.warehouses[i].handyshelf.usedplaces = 0;
    }
    store.handyshelf.usedplaces = 0;
    store.handyrack.usedshelves = 0;
    store.usedwarehouses = 0;

    string komenda = "";

    while ( komenda != "END" ) {

        cin >> komenda;
    
        if ( komenda == "SET-AP" ) {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_ap ( w, r, s, p );
        }

        else if ( komenda == "SET-AS" ) {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_as ( w, r, s, p );
        }

        else if ( komenda == "SET-AR" ) {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_ar ( w, r, s, p );
        }

        else if ( komenda == "SET-AW" ) {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_aw ( w, r, s, p );
        }

        else if ( komenda == "SET-HW" ) {
            int w, p;
            cin >> w >> p;
            set_hw ( w, p );
        }

        else if ( komenda == "SET-HR" ) {
            int s, p;
            cin >> s >> p;
            set_hr ( s, p );
        }

        else if ( komenda == "SET-HS" ) {
            int p;
            cin >> p;
            set_hs ( p );
        }

        else if ( komenda == "PUT-W" ) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            put_w ( w, r, s, p, a );
        }

        else if ( komenda == "PUT-H" ) {
            int w, p, a;
            cin >> w >> p >> a;
            put_h ( w, p, a );
        }

        else if ( komenda == "PUT-R" ) {
            int s, p, a;
            cin >> s >> p >> a;
            put_r ( s, p, a );
        }

        else if ( komenda == "PUT-S" ) {
            int p, a;
            cin >> p >> a;
            put_s ( p, a );
        }

        else if ( komenda == "FILL" ) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            fill ( w, r, s, p, a );
        }

        else if ( komenda == "POP-W" ) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            pop_w ( w, r, s, p, a );
        }

        else if ( komenda == "POP-H" ) {
            int w, p, a;
            cin >> w >> p >> a;
            pop_h ( w, p, a );
        }

        else if ( komenda == "POP-R" ) {
            int s, p, a;
            cin >> s >> p >> a;
            pop_r ( s, p, a );
        }

        else if ( komenda == "POP-S" ) {
            int p, a;
            cin >> p >> a;
            pop_s ( p, a );
        }

        else if ( komenda == "MOV-W" ) {
            int w1, r1, s1, w2, r2, s2, p, a;
            cin >> w1 >> r1 >> s1 >> w2 >> r2 >> s2 >> p >> a;
            mov_w ( w1, r1, s1, w2, r2, s2, p, a );
        }

        else if ( komenda == "MOV-H" ) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            mov_h ( w, r, s, p , a );
        }

        else if ( komenda == "MOV-R" ) {
            int w, r, s1, s2, p, a;
            cin >> w >> r >> s1 >> s2 >> p >> a;
            mov_r ( w, r, s1, s2, p, a );
        }

        else if ( komenda == "MOV-S" ) {
            int s, p, a;
            cin >> s >> p >> a;
            mov_s ( s, p, a );
        }

        else if ( komenda == "GET-E" ) {
            cout << suma << endl;
        }

        else if ( komenda == "GET-W" ) {
            int w;
            cin >> w;
            get_w ( w );
        }

        else if ( komenda == "GET-RW" ) {
            int w, r;
            cin >> w >> r;
            get_rw ( w, r );
        }

        else if ( komenda == "GET-RH" ) {
            get_rh ();
        }

        else if ( komenda == "GET-SW" ) {
            int w, r, s;
            cin >> w >> r >> s;
            get_sw ( w, r, s);
        }

        else if ( komenda == "GET-SH" ) {
            int w;
            cin >> w;
            get_sh ( w );
        }

        else if ( komenda == "GET-SR" ) {
            int s;
            cin >> s;
            get_sr ( s );
        }

        else if ( komenda == "GET-S" ) {   
            get_s ();
        }

        else if ( komenda == "SET-LW" ) {
            int w, r, s, p;
            char d[2];
            cin >> w >> r >> s >> p >> d[0] >> d[1];
            store.warehouses[w].racks[r].shelves[s].places[p].id1 = d[0];
            store.warehouses[w].racks[r].shelves[s].places[p].id2 = d[1];
        }

        else if ( komenda == "SET-LH" ) {
            int w, p;
            char d[2];
            cin >> w >> p >> d[0] >> d[1];
            store.warehouses[w].handyshelf.places[p].id1 = d[0];
            store.warehouses[w].handyshelf.places[p].id2 = d[1];
        }

        else if ( komenda == "SET-LR" ) {
            int s, p;
            char d[2];
            cin >> s >> p >> d[0] >> d[1];
            store.handyrack.shelves[s].places[p].id1 = d[0];
            store.handyrack.shelves[s].places[p].id2 = d[1];
        }

        else if ( komenda == "SET-LS" ) {
            int p;
            char d[2];
            cin >> p >> d[0] >> d[1];
            store.handyshelf.places[p].id1 = d[0];
            store.handyshelf.places[p].id2 = d[1];
        }

        else if ( komenda == "GET-LW" ) {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            cout << store.warehouses[w].racks[r].shelves[s].places[p].id1 << store.warehouses[w].racks[r].shelves[s].places[p].id2 << endl;
        }

        else if ( komenda == "GET-LH" ) {
            int w, p;
            cin >> w >> p;
            cout << store.warehouses[w].handyshelf.places[p].id1 << store.warehouses[w].handyshelf.places[p].id2 << endl;
        }

        else if ( komenda == "GET-LR" ) {
            int s, p;
            cin >> s >> p;
            cout << store.handyrack.shelves[s].places[p].id1 << store.handyrack.shelves[s].places[p].id2 << endl;
        }

        else if ( komenda == "GET-LS" ) {
            int p;
            cin >> p;
            cout << store.handyshelf.places[p].id1 << store.handyshelf.places[p].id2 << endl;
        }
    }

    return 0;
}