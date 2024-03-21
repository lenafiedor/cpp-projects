struct PLACE {
    unsigned short amount;
    char id1;
    char id2;

    void ZERO_PLACE() {
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
    unsigned short usedracks;
};

struct STORE {
    WAREHOUSE warehouses[128];
    RACK handyrack;
    SHELF handyshelf;
    unsigned short usedwarehouses;
} store;
