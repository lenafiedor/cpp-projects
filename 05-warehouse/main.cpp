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
        else if (command == "SET-HR") {
            int s, p;
            cin >> s >> p;
            set_hr(s, p);
        }
        else if (command == "SET-HS") {
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
            int w_b, r_b, s_b, w_e, r_e, s_e, p, a;
            cin >> w_b >> r_b >> s_b >> w_e >> r_e >> s_e >> p >> a;
            mov_w (w_b, r_b, s_b, w_e, r_e, s_e, p, a);
        }

        else if (command == "MOV-H") {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            mov_h(w, r, s, p, a);
        }

        else if (command == "MOV-R") {
            int w, r, s_b, s_e, p, a;
            cin >> w >> r >> s_b >> s_e >> p >> a;
            mov_r(w, r, s_b, s_e, p, a);
        }

        else if (command == "MOV-S") {
            int s, p, a;
            cin >> s >> p >> a;
            mov_s(s, p, a);
        }

        else if (command == "GET-E") {
            get_e();
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
            char id[2];
            cin >> w >> r >> s >> p >> id[0] >> id[1];
            set_lw(w, r, s, p, id);
        }

        else if (command == "SET-LH") {
            int w, p;
            char id[2];
            cin >> w >> p >> id[0] >> id[1];
            set_lh(w, p, id);
        }

        else if (command == "SET-LR") {
            int s, p;
            char id[2];
            cin >> s >> p >> id[0] >> id[1];
            set_lr(s, p, id);
        }

        else if (command == "SET-LS") {
            int p;
            char id[2];
            cin >> p >> id[0] >> id[1];
            set_ls(p, id);
        }

        else if (command == "GET-LW") {
            int w, r, s, p;
            cin >> w >> r >> s >> p;
            get_lw(w, r, s, p);
        }

        else if (command == "GET-LH") {
            int w, p;
            cin >> w >> p;
            get_lh(w, p);
        }

        else if (command == "GET-LR") {
            int s, p;
            cin >> s >> p;
            get_lr(s, p);
        }

        else if (command == "GET-LS") {
            int p;
            cin >> p;
            get_ls(p);
        }
    }
    return 0;
}
