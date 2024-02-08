// autor: Lena Fiedor

#define FLAG_00000 0x00000001
#define FLAG_00001 0x00000002
#define FLAG_00010 0x00000004
#define FLAG_00011 0x00000008
#define FLAG_00100 0x00000010
#define FLAG_00101 0x00000020
#define FLAG_00110 0x00000040
#define FLAG_00111 0x00000080

#define FLAG_01000 0x00000100
#define FLAG_01001 0x00000200
#define FLAG_01010 0x00000400
#define FLAG_01011 0x00000800
#define FLAG_01100 0x00001000
#define FLAG_01101 0x00002000
#define FLAG_01110 0x00004000
#define FLAG_01111 0x00008000

#define FLAG_10000 0x00010000
#define FLAG_10001 0x00020000
#define FLAG_10010 0x00040000
#define FLAG_10011 0x00080000
#define FLAG_10100 0x00100000
#define FLAG_10101 0x00200000
#define FLAG_10110 0x00400000
#define FLAG_10111 0x00800000

#define FLAG_11000 0x01000000
#define FLAG_11001 0x02000000
#define FLAG_11010 0x04000000
#define FLAG_11011 0x08000000
#define FLAG_11100 0x10000000
#define FLAG_11101 0x20000000
#define FLAG_11110 0x40000000
#define FLAG_11111 0x80000000

void BinaryToFlag ( int* temp ) {

    if ( *temp == 0 ) {
        *temp = FLAG_00000;
    }
    else if ( *temp == 0b00001 ) {
        *temp = FLAG_00001;
    }
    else if ( *temp == 0b00010 ) {
        *temp = FLAG_00010;
    }
    else if ( *temp == 0b00011 ) {
        *temp = FLAG_00011;
    }
    else if ( *temp == 0b00100 ) {
        *temp = FLAG_00100;
    }
    else if ( *temp == 0b00101 ) {
        *temp = FLAG_00101;
    }
    else if ( *temp == 0b00110 ) {
        *temp = FLAG_00110;
    }
    else if ( *temp == 0b00111 ) {
        *temp = FLAG_00111;
    }
    else if ( *temp == 0b01000 ) {
        *temp = FLAG_01000;
    }
    else if ( *temp == 0b01001 ) {
        *temp = FLAG_01001;
    }
    else if ( *temp == 0b01010 ) {
        *temp = FLAG_01010;
    }
    else if ( *temp == 0b01011 ) {
        *temp = FLAG_01011;
    }
    else if ( *temp == 0b001100 ) {
        *temp = FLAG_01100;
    }
    else if ( *temp == 0b01101 ) {
        *temp = FLAG_01101;
    }
    else if ( *temp == 0b01110 ) {
        *temp = FLAG_01110;
    }
    else if ( *temp == 0b01111 ) {
        *temp = FLAG_01111;
    }
    else if ( *temp == 0b10000 ) {
        *temp = FLAG_10000;
    }
    else if ( *temp == 0b10001 ) {
        *temp = FLAG_10001;
    }
    else if ( *temp == 0b10010 ) {
        *temp = FLAG_10010;
    }
    else if ( *temp == 0b10011 ) {
        *temp = FLAG_10011;
    }
    else if ( *temp == 0b10100 ) {
        *temp = FLAG_10100;
    }
    else if ( *temp == 0b10101 ) {
        *temp = FLAG_10101;
    }
    else if ( *temp == 0b10110 ) {
        *temp = FLAG_10110;
    }
    else if ( *temp == 0b10111 ) {
        *temp = FLAG_10111;
    }
    else if ( *temp == 0b11000 ) {
        *temp = FLAG_11000;
    }
    else if ( *temp == 0b11001 ) {
        *temp = FLAG_11001;
    }
    else if ( *temp == 0b11010 ) {
        *temp = FLAG_11010;
    }
    else if ( *temp == 0b11011 ) {
        *temp = FLAG_11011;
    }
    else if ( *temp == 0b11100 ) {
        *temp = FLAG_11100;
    }
    else if ( *temp == 0b11101 ) {
        *temp = FLAG_11101;
    }
    else if ( *temp == 0b11110 ) {
        *temp = FLAG_11110;
    }
    else if ( *temp == 0b11111 ) {
        *temp = FLAG_11111;
    }
}

void Insert ( char* setString, int* setValue ) {

    int temp = 0;

    if ( *setString == '\0' ) {
        return;
    }
    if ( *setString == ' ' ) {
        Insert ( ( setString + 1 ), setValue );
        return;
    }

    if ( ( *( setString ) - '0' ) == 1 ) {
        temp += 16;
    }
    if ( ( *( setString + 1 ) - '0' ) == 1 ) {
        temp += 8;
    }
    if ( ( *( setString + 2 ) - '0' ) == 1 ) {
        temp += 4;
    }
    if ( ( *( setString + 3 ) - '0' ) == 1 ) {
        temp += 2;
    }
    if ( ( *( setString + 4 ) - '0' ) == 1 ) {
        temp += 1;
    }
   
    BinaryToFlag ( &temp );
    if ( !( *( setValue ) & temp ) ) {
        *setValue += temp;
    }

    if ( *setString + 5 == '\0' ) {
        return;
    }
    else {
        Insert ( setString + 5, setValue );
    }
}

void Emplace ( char* setString, int* setValue ) {

    *setValue = 0;
    Insert ( setString, setValue );
}

void Erase ( char* setString, int* setValue ) {

    int temp = 0;

    if ( *setString == '\0' ) {
        return;
    }
    if ( *setString == ' ' ) {
        Erase ( ( setString + 1 ), setValue );
        return;
    }

    if ( ( *( setString ) - '0' ) == 1 ) {
        temp += 16;
    }
    if ( ( *( setString + 1 ) - '0' ) == 1 ) {
        temp += 8;
    }
    if ( ( *( setString + 2 ) - '0' ) == 1 ) {
        temp += 4;
    }
    if ( ( *( setString + 3 ) - '0' ) == 1 ) {
        temp += 2;
    }
    if ( ( *( setString + 4 ) - '0' ) == 1 ) {
        temp += 1;
    }

    BinaryToFlag ( &temp );
    if ( *( setValue ) & temp ) {
        *setValue -= temp;
    }

    if ( *(setString + 5 ) == '\0' ) {
        return;
    }
    else {
        Erase ( setString + 5, setValue );
    }
}

void Print ( int setValue, char* setString ) {

    if ( setValue == 0 ) {
        *setString = 'e';
        *( setString + 1 ) = 'm';
        *( setString + 2 ) = 'p';
        *( setString + 3 ) = 't';
        *( setString + 4 ) = 'y';
        *( setString + 5 ) = '\0';
    }

    if ( ( setValue & FLAG_11111 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11110 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11101 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11100 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11011 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11010 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11001 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_11000 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }    
    if ( ( setValue & FLAG_10111 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10110 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10101 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10100 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10011 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10010 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10001 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_10000 ) != 0 ) {
        *setString = '1';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01111 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01110 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01101 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01100 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01011 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01010 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01001 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_01000 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '1';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00111 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00110 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00101 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00100 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '1';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00011 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00010 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '1';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00001 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '1';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    if ( ( setValue & FLAG_00000 ) != 0 ) {
        *setString = '0';
        *( setString + 1 ) = '0';
        *( setString + 2 ) = '0';
        *( setString + 3 ) = '0';
        *( setString + 4 ) = '0';
        *( setString + 5 ) = ' ';
        setString += 6;
    }
    setString--;
    *( setString ) = '\0';
}

int Cardinality ( int setValue ) {
    int power = 0;

    if ( setValue & FLAG_00000 ) {
        power++;
    }
    if ( setValue & FLAG_00001 ) {
        power++;
    }
    if ( setValue & FLAG_00010 ) {
        power++;
    }
    if ( setValue & FLAG_00011 ) {
        power++;
    }
    if ( setValue & FLAG_00100 ) {
        power++;
    }
    if ( setValue & FLAG_00101 ) {
        power++;
    }
    if ( setValue & FLAG_00110 ) {
        power++;
    }
    if ( setValue & FLAG_00111 ) {
        power++;
    }
    if ( setValue & FLAG_01000 ) {
        power++;
    }
    if ( setValue & FLAG_01001 ) {
        power++;
    }
    if ( setValue & FLAG_01010 ) {
        power++;
    }
    if ( setValue & FLAG_01011 ) {
        power++;
    }
    if ( setValue & FLAG_01100 ) {
        power++;
    }
    if ( setValue & FLAG_01101 ) {
        power++;
    }
    if ( setValue & FLAG_01110 ) {
        power++;
    }
    if ( setValue & FLAG_01111 ) {
        power++;
    }
    if ( setValue & FLAG_10000 ) {
        power++;
    }
    if ( setValue & FLAG_10001 ) {
        power++;
    }
    if ( setValue & FLAG_10010 ) {
        power++;
    }
    if ( setValue & FLAG_10011 ) {
        power++;
    }
    if ( setValue & FLAG_10100 ) {
        power++;
    }
    if ( setValue & FLAG_10101 ) {
        power++;
    }
    if ( setValue & FLAG_10110 ) {
        power++;
    }
    if ( setValue & FLAG_10111 ) {
        power++;
    }
    if ( setValue & FLAG_11000 ) {
        power++;
    }
    if ( setValue & FLAG_11001 ) {
        power++;
    }
    if ( setValue & FLAG_11010 ) {
        power++;
    }
    if ( setValue & FLAG_11011 ) {
        power++;
    }
    if ( setValue & FLAG_11100 ) {
        power++;
    }
    if ( setValue & FLAG_11101 ) {
        power++;
    }
    if ( setValue & FLAG_11110) {
        power++;
    }
    if ( setValue & FLAG_11111 ) {
        power++;
    }

    return power;
}

bool Emptiness ( int set ) {
    return !set;
}

bool Nonempty ( int set ) {
    return !( Emptiness ( set ) );
}

bool Member ( char* setString, int setValue ) {

    int temp = 0;

    if ( *setString == ' ' ) {
        return Member ( setString + 1, setValue );
    }

    if ( ( *( setString ) - '0' ) == 1 ) {
        temp += 16;
    }
    if ( ( *( setString + 1 ) - '0' ) == 1 ) {
        temp += 8;
    }
    if ( ( *( setString + 2 ) - '0' ) == 1 ) {
        temp += 4;
    }
    if ( ( *( setString + 3 ) - '0' ) == 1 ) {
        temp += 2;
    }
    if ( ( *( setString + 4 ) - '0' ) == 1 ) {
        temp += 1;
    }

    BinaryToFlag ( &temp );

    if ( setValue & temp ) {
        return true;
    }
    else {
        return false;
    }
}

bool Conjunctive ( int setFirst, int setSecond ) {
    return ( setFirst & setSecond );
}

bool Disjoint ( int setFirst, int setSecond ) {
    return !( setFirst & setSecond );
}

bool Equality ( int setFirst, int setSecond ) {
    return ( setFirst == setSecond );
}

bool Inclusion ( int setFirst, int setSecond ) {
    return ( ( setFirst & setSecond  ) == setFirst );
}

void Union ( int setFirst, int setSecond, int* setThird ) {
    *setThird = ( setFirst | setSecond );
}

void Intersection ( int setFirst, int setSecond, int* setThird ) {
    *setThird = ( setFirst & setSecond );
}

void Symmetric ( int setFirst, int setSecond, int* setThird ) {
    *setThird = ( setFirst ^ setSecond );
}

void Difference ( int setFirst, int setSecond, int* setThird ) {
    *setThird = ( setFirst & ( ~setSecond ) );
}

void Complement ( int setFirst, int* setSecond ) {
    *setSecond = ( ~setFirst );
}

bool LessThen ( int setFirst, int setSecond ) {
    if ( Cardinality ( setFirst ) < Cardinality ( setSecond ) ) {
        return true;
    }
    else {
        if ( Cardinality ( setFirst ) == Cardinality ( setSecond ) ) {
            return ( setFirst < setSecond );
        }
        else {
            return false;
        }
    }
}

bool LessEqual ( int setFirst, int setSecond ) {
    return ( ( LessThen ( setFirst, setSecond ) ) || Equality ( setFirst, setSecond ) );
}

bool GreatEqual ( int setFirst, int setSecond ) {
    return ( LessEqual ( setSecond, setFirst ) );
}

bool GreatThen ( int setFirst, int setSecond ) {
    return ( LessThen ( setSecond, setFirst ) );
}