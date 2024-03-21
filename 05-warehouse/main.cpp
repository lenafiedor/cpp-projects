#include <iostream>
#include "operations.cpp"

using namespace std;

int main () {

    for (int i = 0; i < CAPACITY; i++) {
        store.handyshelf.places[i].clean_place();
        for (int j = 0; j < CAPACITY; j++) {
            store.handyrack.shelves[i].places[j].clean_place();
            for (int k = 0; k < CAPACITY; k++) {
                for (int l = 0; l < CAPACITY; l++) {
                    store.warehouses[i].racks[j].shelves[k].places[l].clean_place();
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

    string command = "";

    while (command != "END") {

        cin >> command;
    
        if (command == "SET-AP") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_ap(w, r, s, p);
        }
        else if (command == "SET-AS") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_as(w, r, s, p);
        }
        else if (command == "SET-AR") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_ar(w, r, s, p);
        }
        else if (command == "SET-AW") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            set_aw(w, r, s, p);
        }
        else if (command == "SET-HW") {
            int w, p;
            cin >> w >> p;
            set_hw(w, p);
        }
        else if(command == "SET-HR") {
            int s, p;
            cin >> s >> p;
            set_hr(s, p);
        }
        else if(command == "SET-HS") {
            int p;
            cin >> p;
            set_hs(p);
        }
        
        else if (command == "PUT-W") {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            put_w(w, r, s, p, a);
        }

        else if (command == "PUT-H") {
            int w, p, a;
            cin >> w >> p >> a;
            put_h(w, p, a);
        }

        else if (command == "PUT-R") {
            int s, p, a;
            cin >> s >> p >> a;
            put_r(s, p, a);
        }

        else if (command == "PUT-S") {
            int p, a;
            cin >> p >> a;
            put_s(p, a);
        }

        else if (command == "FILL") {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            fill(w, r, s, p, a);
        }

        else if (command == "POP-W") {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            pop_w(w, r, s, p, a);
        }

        else if (command == "POP-H") {
            int w, p, a;
            cin >> w >> p >> a;
            pop_h(w, p, a);
        }

        else if (command == "POP-R") {
            int s, p, a;
            cin >> s >> p >> a;
            pop_r(s, p, a);
        }

        else if (command == "POP-S") {
            int p, a;
            cin >> p >> a;
            pop_s(p, a);
        }

        else if (command == "MOV-W") {
            int w1, r1, s1, w2, r2, s2, p, a;
            cin >> w1 >> r1 >> s1 >> w2 >> r2 >> s2 >> p >> a;
            mov_w (w1, r1, s1, w2, r2, s2, p, a);
        }

        else if (command == "MOV-H") {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            mov_h(w, r, s, p , a);
        }

        else if (command == "MOV-R") {
            int w, r, s1, s2, p, a;
            cin >> w >> r >> s1 >> s2 >> p >> a;
            mov_r(w, r, s1, s2, p, a);
        }

        else if (command == "MOV-S") {
            int s, p, a;
            cin >> s >> p >> a;
            mov_s(s, p, a);
        }

        else if (command == "GET-E") {
            cout << sum << endl;
        }

        else if (command == "GET-W") {
            int w;
            cin >> w;
            get_w(w);
        }

        else if (command == "GET-RW") {
            int w, r;
            cin >> w >> r;
            get_rw(w, r);
        }

        else if (command == "GET-RH") {
            get_rh();
        }

        else if (command == "GET-SW") {
            int w, r, s;
            cin >> w >> r >> s;
            get_sw (w, r, s);
        }

        else if (command == "GET-SH") {
            int w;
            cin >> w;
            get_sh(w);
        }

        else if (command == "GET-SR") {
            int s;
            cin >> s;
            get_sr(s);
        }

        else if (command == "GET-S") {   
            get_s();
        }

        else if (command == "SET-LW") {
            int w, r, s, p;
            char d[2];
            cin >> w >> r >> s >> p >> d[0] >> d[1];
            store.warehouses[w].racks[r].shelves[s].places[p].id1 = d[0];
            store.warehouses[w].racks[r].shelves[s].places[p].id2 = d[1];
        }

        else if (command == "SET-LH") {
            int w, p;
            char d[2];
            cin >> w >> p >> d[0] >> d[1];
            store.warehouses[w].handyshelf.places[p].id1 = d[0];
            store.warehouses[w].handyshelf.places[p].id2 = d[1];
        }

        else if (command == "SET-LR") {
            int s, p;
            char d[2];
            cin >> s >> p >> d[0] >> d[1];
            store.handyrack.shelves[s].places[p].id1 = d[0];
            store.handyrack.shelves[s].places[p].id2 = d[1];
        }

        else if (command == "SET-LS") {
            int p;
            char d[2];
            cin >> p >> d[0] >> d[1];
            store.handyshelf.places[p].id1 = d[0];
            store.handyshelf.places[p].id2 = d[1];
        }

        else if (command == "GET-LW") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            cout << store.warehouses[w].racks[r].shelves[s].places[p].id1 << store.warehouses[w].racks[r].shelves[s].places[p].id2 << endl;
        }

        else if (command == "GET-LH") {
            int w, p;
            cin >> w >> p;
            cout << store.warehouses[w].handyshelf.places[p].id1 << store.warehouses[w].handyshelf.places[p].id2 << endl;
        }

        else if (command == "GET-LR") {
            int s, p;
            cin >> s >> p;
            cout << store.handyrack.shelves[s].places[p].id1 << store.handyrack.shelves[s].places[p].id2 << endl;
        }

        else if (command == "GET-LS") {
            int p;
            cin >> p;
            cout << store.handyshelf.places[p].id1 << store.handyshelf.places[p].id2 << endl;
        }
    }
    return 0;
}