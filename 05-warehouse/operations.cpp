#include <iostream>
#include "warehouse.cpp"

using namespace std;


long long sum = 0;
unsigned short CAPACITY = 128;

bool in_range(unsigned short value, unsigned short upper) {
    return 0 <= value < upper;
}

void delete_from_place(unsigned short w, unsigned short r, unsigned short s, unsigned short p) {
    sum -= store.warehouses[w].racks[r].shelves[s].places[p].amount;
    store.warehouses[w].racks[r].shelves[s].places[p].ZERO_PLACE();
}


int min(int firstValue, int secondValue) {
    return firstValue <= secondValue ? firstValue : secondValue;
}

int max(int firstValue, int secondValue) {
    return firstValue >= secondValue ? firstValue : secondValue;
}

void set_ap(int w, int r, int s, int p) {
    cout << "used warehouses: " << store.usedwarehouses << endl;
    cout << "used racks: " << store.warehouses[w].usedracks << endl;
    cout << "used shelves: " << store.warehouses[w].racks[r].usedshelves << endl;
    cout << "used places: " << store.warehouses[w].racks[r].shelves[s].usedplaces << endl;
    if (in_range(w, store.usedwarehouses) && in_range(r, store.warehouses[w].usedracks) &&
        in_range(s, store.warehouses[w].racks[r].usedshelves) && in_range(p, CAPACITY + 1)) {
        if (in_range(p, store.warehouses[w].racks[r].shelves[s].usedplaces)) {
            for (int i = p; i < store.warehouses[w].racks[r].shelves[s].usedplaces; i++) {
                delete_from_place(w, r, s, i);
            }
        }
        store.warehouses[w].racks[r].shelves[s].usedplaces = p;
    }
    else {
        cout << "error" << endl;
    }
    cout << "used places (after set_ap): " << store.warehouses[w].racks[r].shelves[s].usedplaces << endl;
}

void set_as(int w, int r, int s, int p) {
    if (in_range(w, store.usedwarehouses) && in_range(r, store.warehouses[w].usedracks) &&
        in_range(s, CAPACITY + 1) && in_range(p, CAPACITY + 1)) {

        int n = in_range(s, store.warehouses[w].racks[r].usedshelves) ? s : store.warehouses[w].racks[r].usedshelves;
        for (int i = 0; i < n; i++) {
            if (store.warehouses[w].racks[r].shelves[i].usedplaces > p) {
                for (int j = p; j < store.warehouses[w].racks[r].shelves[i].usedplaces; j++) {
                    delete_from_place(w, r, i, j);
                }
            }
            store.warehouses[s].racks[r].shelves[i].usedplaces = p;
        }
        if (store.warehouses[w].racks[r].usedshelves < s) {
            for (int i = store.warehouses[w].racks[r].usedshelves; i < s; i++) {
                store.warehouses[s].racks[r].shelves[i].usedplaces = p;
            }
        }
        else {
            for (int i = s; i < store.warehouses[w].racks[r].usedshelves; i++) {
                for (int j = 0; j < store.warehouses[s].racks[r].shelves[i].usedplaces; j++) {
                    delete_from_place(s, r, i, j);
                }
                store.warehouses[s].racks[r].shelves[i].usedplaces = 0;
            }
        }
    }
    else {
        cout << "error" << endl;
    }
}

void set_ar(int w, int r, int s, int p) {
    if (in_range(w, store.usedwarehouses) && in_range(r, CAPACITY + 1) && in_range(s, CAPACITY + 1) && in_range(p, CAPACITY + 1)) {
        for (int i = r; i < max(r, store.warehouses[w].usedracks); i++) {
            for (int j = 0; j < max(s, store.warehouses[w].racks[i].usedshelves); j++) {
                for (int k = 0; k < max(p, store.warehouses[w].racks[i].shelves[j].usedplaces); k++) {
                    delete_from_place(w, i, j, k);
                }
                store.warehouses[w].racks[i].shelves[j].usedplaces = p;
            }
            store.warehouses[w].racks[i].usedshelves = s;
        }
        store.warehouses[w].usedracks = r;
    }
    else {
        cout << "error" << endl;
    }
}

void set_aw(int w, int r, int s, int p) {
    if (in_range(w, CAPACITY + 1) && in_range(r, CAPACITY + 1) && in_range(s, CAPACITY + 1) && in_range(p, CAPACITY + 1)) {        
        for (int i = w; i < max(w, store.usedwarehouses); i++) {
            for (int j = 0; j < max(r, store.warehouses[i].usedracks); j++) {
                for (int k = 0; k < max(s, store.warehouses[i].racks[j].usedshelves); k++) {
                    for (int l = 0; l < max(p, store.warehouses[i].racks[j].shelves[k].usedplaces); l++) {
                        delete_from_place(i, j, k, l);
                    }
                    store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                }
                store.warehouses[i].racks[j].usedshelves = s;
            }
            store.warehouses[i].usedracks = r;
        }
        store.usedwarehouses = w;
    }
    else {
        cout << "error" << endl;
    }
}

void set_hw (int w, int p) {
}

void set_hr (int s, int p) {
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

void put_w(int w, int r, int s, int p, int a) { 
    if (in_range(w, store.usedwarehouses) && in_range(r, store.warehouses[r].usedracks) &&
        in_range(s, store.warehouses[w].racks[r].usedshelves) && in_range(p, store.warehouses[w].racks[r].shelves[s].usedplaces)) {
        if (store.warehouses[w].racks[r].shelves[s].places[p].amount + a > 65535) {
            store.warehouses[w].racks[r].shelves[s].places[p].amount = 65535;
            sum += 65535;
        }
        else {
            store.warehouses[w].racks[r].shelves[s].places[p].amount += a;
            sum += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_h(int w, int p, int a) {  
    if (in_range(w, store.usedwarehouses) && in_range(p, store.warehouses[w].handyshelf.usedplaces)) {
        if (store.warehouses[w].handyshelf.places[p].amount + a > 65535) {
            store.warehouses[w].handyshelf.places[p].amount = 65535;
            sum += 65535;
        }
        else {
            store.warehouses[w].handyshelf.places[p].amount += a;
            sum += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_r(int s, int p, int a) {  
    if (in_range(s, store.handyshelf.usedplaces)) {
        if (store.handyrack.shelves[s].places[p].amount + a > 65535 ) {
            store.handyrack.shelves[s].places[p].amount = 65535;
            sum = +65535;
        }
        else {
            store.handyrack.shelves[s].places[p].amount += a;
            sum += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void put_s(int p, int a) { 
    if (in_range(p, store.handyshelf.usedplaces)) {
        if (store.handyshelf.places[p].amount + a > 65535) {
            store.handyshelf.places[p].amount = 65535;
            sum += 65535;
        }
        else {
            store.handyshelf.places[p].amount += a;
            sum += a;
        }
    }
    else {
        cout << "error" << endl;
    }
}

void fill(int w, int r, int s, int p, int a) {
    if (in_range(w, CAPACITY + 1) && in_range(r, CAPACITY + 1) && in_range(s, CAPACITY + 1) && in_range(p, CAPACITY + 1)) {

        sum = 0;
        if (a > 65535) {
            a = 65535;
        }

        for (int i = 0; i < store.handyshelf.usedplaces; i++) {
            store.handyshelf.places[i].amount = 0;
            store.handyshelf.places[i].id1 = '\0';
            store.handyshelf.places[i].id2 = '\0';
        }
        store.handyshelf.usedplaces = 0;

        
        for (int i = 0; i < store.handyrack.usedshelves; i++) {
            for (int j = 0; j < store.handyrack.shelves[i].usedplaces; i++) {
                store.handyrack.shelves[i].places[j].amount = 0;
                store.handyrack.shelves[i].places[j].id1 = '\0';
                store.handyrack.shelves[i].places[j].id2 = '\0';
            }
            store.handyrack.shelves[i].usedplaces = 0;
        }
        store.handyrack.usedshelves = 0;

        for (int i = 0; i < store.usedwarehouses; i++) {
            for (int j = 0; j < store.warehouses[w].handyshelf.usedplaces; j++) {
                store.warehouses[i].handyshelf.places[j].amount = 0;
                store.warehouses[i].handyshelf.places[j].id1 = '\0';
                store.warehouses[i].handyshelf.places[j].id2 = '\0';
            }
            store.warehouses[i].handyshelf.usedplaces = 0;
    
            for (int j = 0; j < store.warehouses[i].usedracks; j++) {
                for (int k = 0; k < store.warehouses[i].racks[j].usedshelves; k++) {
                    for (int l = 0; i < store.warehouses[i].racks[j].shelves[k].usedplaces; l++) {
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
        for (int i = 0; i < w; i++) {
            store.warehouses[i].usedracks = r;
            for ( int j = 0; i < r; i++ ) {
                store.warehouses[i].racks[j].usedshelves = s;
                for ( int k = 0; k < s; k++ ) {
                    store.warehouses[i].racks[j].shelves[k].usedplaces = p;
                    for (int l = 0; l < p; l++) {
                        sum += a;
                        store.warehouses[i].racks[j].shelves[k].places[l].amount = a;
                        store.warehouses[i].racks[j].shelves[k].places[l].id1 = '\0';
                        store.warehouses[i].racks[j].shelves[k].places[l].id2 = '\0';
                    }
                }
            }
        }

        store.handyshelf.usedplaces = p;
        for (int i = 0; i < p; i++) {
            sum += a;
            store.handyshelf.places[i].amount = a;
            store.handyshelf.places[i].id1 = '\0';
            store.handyshelf.places[i].id2 = '\0';
        }

        store.handyrack.usedshelves = s;
        for ( int i = 0; i < s; i++ ) {
            store.handyrack.shelves[i].usedplaces = p;
            for (int j = 0; j < p; j++) {
                sum += a;
                store.handyrack.shelves[i].places[j].amount = a;
                store.handyrack.shelves[i].places[j].id1 = '\0';
                store.handyrack.shelves[i].places[j].id2 = '\0';
            }
        }

        for (int i = 0; i < w; i++) {
            store.warehouses[i].handyshelf.usedplaces = p;
            for (int j = 0; j < p; j++) {
                sum += a;
                store.warehouses[i].handyshelf.places[j].amount = a;
                store.warehouses[i].handyshelf.places[j].id1 = '\0';
                store.warehouses[i].handyshelf.places[j].id2 = '\0';
            }
        }
    }
    else {
        cout << "error" << endl;
    }
}

void pop_w(int w, int r, int s, int p, int a) {
    if ( ( w < store.usedwarehouses ) && ( r < store.warehouses[r].usedracks ) && ( s < store.warehouses[w].racks[r].usedshelves )
    && ( p < store.warehouses[w].racks[r].shelves[s].usedplaces ) ) {
        if ( store.warehouses[w].racks[r].shelves[s].places[p].amount - a < 0 ) {
            sum -= store.warehouses[w].racks[r].shelves[s].places[p].amount;
            store.warehouses[w].racks[r].shelves[s].places[p].amount = 0;
        }
        else {
            sum -= a;
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
            sum -= store.warehouses[w].handyshelf.places[p].amount;
            store.warehouses[w].handyshelf.places[p].amount = 0;
        }
        else {
            sum -= a;
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
            sum -= store.handyrack.shelves[s].places[p].amount;
            store.handyrack.shelves[s].places[p].amount = 0;
        }
        else {
            sum -= a;
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
            sum -= store.handyshelf.places[p].amount;
        }
        else {
            store.handyshelf.places[p].amount -= a;
            sum -= a;
        }
    }
}

void mov_w(int w1, int r1, int s1, int w2, int r2, int s2, int p, int a) {
    // body
}

void mov_h(int w, int r, int s, int p, int a) {
    // body
}

void mov_r(int w, int r, int s1, int s2, int p, int a) {
    // body
}

void mov_s(int s, int p, int a) {
    // body
}

void get_w(int w) {
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

void get_rw(int w, int r) {
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

void get_rh() {
    long long quantity = 0;
    for ( int i = 0; i < store.handyrack.usedshelves; i++ ) {
        for ( int j = 0; j < store.handyrack.shelves[i].usedplaces; j++ ) {
            quantity += store.handyrack.shelves[i].places[j].amount;
        }
    }
    cout << quantity << endl;
}

void get_sw(int w, int r, int s) {
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

void get_sh(int w) {
    if ( w < store.usedwarehouses ) {
        long long quantity = 0;
        for (int i = 0; i < store.warehouses[w].handyshelf.usedplaces; i++) {
            quantity += store.warehouses[w].handyshelf.places[i].amount;
        }
        cout << quantity << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void get_sr(int s) {
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

void get_s() {
    long long quantity = 0;
    for ( int i = 0; i < store.handyshelf.usedplaces; i++ ) {
        quantity += store.handyshelf.places[i].amount;
    }
    cout << quantity << endl;
}
