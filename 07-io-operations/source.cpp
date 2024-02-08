#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct DATA_CELL {
    int i;
    string s;
    char c;
    string line1;
    string line2;
    string line3;
    string line4;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    int uc1;
    int uc2;
    int uc3;
    int uc4;
    float f1;
    float f2;
    float f3;
    float f4;
    int counter;
};

int StructCount ( string s ) {
    fstream f;
    f.open ( s.c_str(), fstream::in );
    int howMany = 0;
    string temp;
    while ( !f.eof() ) {
        getline ( f, temp );
        howMany++;
    }
    howMany /= 7;
    f.close();
    return howMany;
}

int UpgradedStructCount ( string s ) {
    fstream f;
    f.open ( s.c_str(), fstream::in );
    int howMany = 0;
    string temp;
    while ( !f.eof() ) {
        getline ( f, temp );
        howMany++;
    }
    howMany /= 8;
    f.close();
    return howMany;
}

void CellRead ( DATA_CELL& dataCell, fstream& f ) {
    f >> dataCell.i;
    if ( !f.eof() ) {
        string temp;
        getline ( f, temp );
        getline ( f, temp );
        dataCell.s = temp;
        getline ( f, temp );
        dataCell.c = temp.at ( 0 );
        getline ( f, temp );
        dataCell.line1 = temp;
        getline ( f, temp );
        dataCell.line2 = temp;
        getline ( f, temp );
        dataCell.line3 = temp;
        getline ( f, temp );
        dataCell.line4 = temp;
    }
}

void GetCell ( DATA_CELL& dataCell, fstream& f ) {
    f >> dataCell.i;
    if ( !f.eof() ) {
        string temp;
        getline ( f, temp );
        getline ( f, temp );
        dataCell.s = temp;
        getline ( f, temp );
        dataCell.c = temp.at ( 0 );
        f >> dataCell.b1 >> dataCell.uc1 >> dataCell.f1;
        f >> dataCell.b2 >> dataCell.uc2 >> dataCell.f2;
        f >> dataCell.b3 >> dataCell.uc3 >> dataCell.f3;
        f >> dataCell.b4 >> dataCell.uc4 >> dataCell.f4;
    }
}

void UpgradedCellRead ( DATA_CELL& dataCell, fstream& f ) {
    f >> dataCell.i;
    if ( !f.eof() ) {
        string temp;
        getline ( f, temp );
        getline ( f, temp );
        dataCell.s = temp;
        getline ( f, temp );
        dataCell.c = temp.at ( 0 );
        f >> dataCell.b1 >> dataCell.uc1 >> dataCell.f1;
        f >> dataCell.b2 >> dataCell.uc2 >> dataCell.f2;
        f >> dataCell.b3 >> dataCell.uc3 >> dataCell.f3;
        f >> dataCell.b4 >> dataCell.uc4 >> dataCell.f4;
        f >> dataCell.counter;
    }
}

void Display ( DATA_CELL dataCell ) {
    cout <<  dataCell.i << endl;
    cout << dataCell.s << endl;
    cout << dataCell.c << endl;
    cout << dataCell.line1 << endl;
    cout << dataCell.line2 << endl;
    cout << dataCell.line3 << endl;
    cout << dataCell.line4 << endl;
    cout << dataCell.counter << endl;
}

void SaveToFile ( string s, DATA_CELL& dataCell ) {

    fstream f;
    f.open ( s.c_str(), fstream::app | fstream::out );

    f << dataCell.i << '\n';
    f << dataCell.s << '\n';
    f << dataCell.c << '\n';
    f << dataCell.line1 << '\n';
    f << dataCell.line2 << '\n';
    f << dataCell.line3 << '\n';
    f << dataCell.line4 << '\n';

    f.close();
}

void SaveNormalised ( string s, DATA_CELL& dataCell ) {

    fstream f;
    f.open ( s.c_str(), fstream::app | fstream::out );

    f << dataCell.i << '\n';
    f << dataCell.s << '\n';
    f << dataCell.c << '\n';
    f << dataCell.b1 << ' ' << dataCell.uc1 << ' ' << dataCell.f1 << '\n';
    f << dataCell.b2 << ' ' << dataCell.uc2 << ' ' << dataCell.f2 << '\n';
    f << dataCell.b3 << ' ' << dataCell.uc3 << ' ' << dataCell.f3 << '\n';
    f << dataCell.b4 << ' ' << dataCell.uc4 << ' ' << dataCell.f4 << '\n';

    f.close();
}

void UpgradedSave ( string s, DATA_CELL& dataCell ) {

    fstream f;
    f.open ( s.c_str(), fstream::app | fstream::out );

    f << dataCell.i << '\n';
    f << dataCell.s << '\n';
    f << dataCell.c << '\n';
    f << dataCell.b1 << ' ' << dataCell.uc1 << ' ' << dataCell.f1 << '\n';
    f << dataCell.b2 << ' ' << dataCell.uc2 << ' ' << dataCell.f2 << '\n';
    f << dataCell.b3 << ' ' << dataCell.uc3 << ' ' << dataCell.f3 << '\n';
    f << dataCell.b4 << ' ' << dataCell.uc4 << ' ' << dataCell.f4 << '\n';
    f << dataCell.counter << '\n';

    f.close();
}

void ClearFile ( string s ) {
    fstream f;
    f.open ( s.c_str(), fstream::out );
    string empty = "";
    f << empty;
    f.close();
}

bool Equal ( DATA_CELL& first, DATA_CELL& second ) {
    string str1 = first.s + first.c + first.line1 + first.line2 + first.line3 + first.line4;
    string str2 = second.s + second.c + second.line1 + second.line2 + second.line3 + second.line4;
    if ( ( str1 == str2 ) && ( first.i == second.i ) ) {
        return true;
    }
    else return false;
}

void SortInt ( string first, string second, string third ) {

    fstream firstFile;
    fstream secondFile;
    fstream thirdFile;

    DATA_CELL data1;
    DATA_CELL data2;

    bool empty = false;

    firstFile.open ( first.c_str(), fstream::in );
    firstFile.get();

    if ( !firstFile.eof() ) {

        firstFile.close();
        
        while ( !empty ) {

            ClearFile ( second );
            ClearFile ( third );

            firstFile.open ( first.c_str(), fstream::in );
            CellRead ( data1, firstFile );

            SaveToFile ( second, data1 );

            int integer1 = data1.i;
            int integer2 = data1.i;

            empty = true;
            
            while ( !firstFile.eof() ) {

                while ( ( integer1 <= integer2 ) && ( !firstFile.eof() ) ) {
                    integer1 = integer2;
                    CellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        integer2 = data2.i;
                        if ( integer1 <= integer2 ) {
                            SaveToFile ( second, data2 );
                        }
                        else {
                            SaveToFile ( third, data2 );
                            integer1 = integer2;
                            empty = false;
                            break;
                        }
                    }
                }
                while ( ( integer1 <= integer2 ) && ( !firstFile.eof() ) ) {
                    integer1 = integer2;
                    CellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        integer2 = data2.i;
                        if ( integer1 <= integer2 ) {
                            SaveToFile ( third, data2 );
                            empty = false;
                        }
                        else {
                            SaveToFile ( second, data2 );
                            integer1 = integer2;
                            break;
                        }
                    }
                }
            }
            firstFile.close();
            ClearFile ( first );

            if ( empty ) {
                secondFile.open ( second.c_str(), fstream::in );
                firstFile.open ( first.c_str(), fstream::app | fstream::out );
                string temp;
                while ( true ) {
                    CellRead ( data1, secondFile );
                    if ( secondFile.eof() ) {
                        firstFile.close();
                        secondFile.close();
                        break;
                    }
                    SaveToFile ( first, data1 );
                }
                break;
            }

            secondFile.open ( second.c_str(), fstream::in );
            thirdFile.open ( third.c_str(), fstream::in );

            CellRead ( data1, secondFile );
            CellRead ( data2, thirdFile );
            integer1 = data1.i;
            integer2 = data2.i;

            while ( ( !secondFile.eof() ) && ( !thirdFile.eof() ) ) {
                if ( integer1 <= integer2 ) {
                    SaveToFile ( first, data1 );
                    CellRead ( data1, secondFile );
                    integer1 = data1.i;
                }
                else {
                    SaveToFile ( first, data2 );
                    CellRead ( data2, thirdFile );
                    integer2 = data2.i;
                }
            }
            if ( secondFile.eof() ) {
                while ( !thirdFile.eof() ) {
                    SaveToFile ( first, data2 );
                    CellRead ( data2, thirdFile );
                }
            }
            else if ( thirdFile.eof() ) {
                while ( !secondFile.eof() ) {
                    SaveToFile ( first, data1 );
                    CellRead ( data1, secondFile );
                }
            }
            ClearFile ( second );
            ClearFile ( third );
            secondFile.close();
            thirdFile.close();
        }
    }
}

void SortString ( string first, string second, string third ) {

    fstream firstFile;
    fstream secondFile;
    fstream thirdFile;

    DATA_CELL data1;
    DATA_CELL data2;

    bool empty = false;

    firstFile.open ( first.c_str(), fstream::in );
    firstFile.get();

    if ( !firstFile.eof() ) {

        firstFile.close();
        
        while ( !empty ) {

            ClearFile ( second );
            ClearFile ( third );

            firstFile.open ( first.c_str(), fstream::in );
            CellRead ( data1, firstFile );

            SaveToFile ( second, data1 );

            string text1 = data1.s;
            string text2 = data1.s;

            empty = true;
            
            while ( !firstFile.eof() ) {

                while ( ( text1 <= text2 ) && ( !firstFile.eof() ) ) {
                    text1 = text2;
                    CellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        text2 = data2.s;
                        if ( text1 <= text2 ) {
                            SaveToFile ( second, data2 );
                        }
                        else {
                            SaveToFile ( third, data2 );
                            text1 = text2;
                            empty = false;
                            break;
                        }
                    }
                }
                while ( ( text1 <= text2 ) && ( !firstFile.eof() ) ) {
                    text1 = text2;
                    CellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        text2 = data2.s;
                        if ( text1 <= text2 ) {
                            SaveToFile ( third, data2 );
                            empty = false;
                        }
                        else {
                            SaveToFile ( second, data2 );
                            text1 = text2;
                            break;
                        }
                    }
                }
            }
            firstFile.close();
            ClearFile ( first );

            if ( empty ) {
                secondFile.open ( second.c_str(), fstream::in );
                firstFile.open ( first.c_str(), fstream::app | fstream::out );
                string temp;
                while ( true ) {
                    CellRead ( data1, secondFile );
                    if ( secondFile.eof() ) {
                        firstFile.close();
                        secondFile.close();
                        break;
                    }
                    SaveToFile ( first, data1 );
                }
                break;
            }

            secondFile.open ( second.c_str(), fstream::in );
            thirdFile.open ( third.c_str(), fstream::in );

            CellRead ( data1, secondFile );
            CellRead ( data2, thirdFile );
            text1 = data1.s;
            text2 = data2.s;

            while ( ( !secondFile.eof() ) && ( !thirdFile.eof() ) ) {
                if ( text1 <= text2 ) {
                    SaveToFile ( first, data1 );
                    CellRead ( data1, secondFile );
                    text1 = data1.s;
                }
                else {
                    SaveToFile ( first, data2 );
                    CellRead ( data2, thirdFile );
                    text2 = data2.s;
                }
            }
            if ( secondFile.eof() ) {
                while ( !thirdFile.eof() ) {
                    SaveToFile ( first, data2 );
                    CellRead ( data2, thirdFile );
                }
            }
            else if ( thirdFile.eof() ) {
                while ( !secondFile.eof() ) {
                    SaveToFile ( first, data1 );
                    CellRead ( data1, secondFile );
                }
            }
            ClearFile ( second );
            ClearFile ( third );
            secondFile.close();
            thirdFile.close();
        }
    }
}

void UpgradedSort ( string first, string second, string third ) {

    fstream firstFile;
    fstream secondFile;
    fstream thirdFile;

    DATA_CELL data1;
    DATA_CELL data2;

    bool empty = false;

    firstFile.open ( first.c_str(), fstream::in );
    firstFile.get();

    if ( !firstFile.eof() ) {

        firstFile.close();
        
        while ( !empty ) {

            ClearFile ( second );
            ClearFile ( third );

            firstFile.open ( first.c_str(), fstream::in );
            UpgradedCellRead ( data1, firstFile );

            UpgradedSave ( second, data1 );

            int integer1 = data1.counter;
            int integer2 = data1.counter;
            int ucSum1 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;
            int value1 = data1.i;
            int value2 = data1.i;
            int ucSum2 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;

            empty = true;
            
            while ( !firstFile.eof() ) {

                while ( ( integer1 >= integer2 ) && ( !firstFile.eof() ) ) {
                    integer1 = integer2;
                    value1 = value2;
                    ucSum1 = ucSum2;
                    UpgradedCellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        integer2 = data2.counter;
                        value2 = data2.i;
                        ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;
                        if ( integer1 > integer2 ) {
                            UpgradedSave ( second, data2 );
                        }
                        else if ( integer1 == integer2 ) {
                            if ( value1 > value2 ) {
                                UpgradedSave ( second, data2 );
                            }
                            else if ( value1 == value2 ) {
                                if ( ucSum1 >= ucSum2 ) {
                                    UpgradedSave ( second, data2 );
                                }
                                else {
                                    UpgradedSave ( third, data2 );
                                    integer1 = integer2;
                                    value1 = value2;
                                    ucSum1 = ucSum2;
                                    empty = false;
                                    break;  
                                }
                            }
                            else {
                                UpgradedSave ( third, data2 );
                                integer1 = integer2;
                                value1 = value2;
                                ucSum1 = ucSum2;
                                empty = false;
                                break;                         
                            }
                        }
                        else {
                            UpgradedSave ( third, data2 );
                            integer1 = integer2;
                            value1 = value2;
                            ucSum1 = ucSum2;
                            empty = false;
                            break;
                        }
                    }
                }
                while ( ( integer1 >= integer2 ) && ( !firstFile.eof() ) ) {
                    integer1 = integer2;
                    value1 = value2;
                    ucSum1 = ucSum2;
                    UpgradedCellRead ( data2, firstFile );
                    if ( !firstFile.eof() ) {
                        integer2 = data2.counter;
                        value2 = data2.i;
                        ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;
                        if ( integer1 > integer2 ) {
                            UpgradedSave ( third, data2 );
                            empty = false;
                        }
                        else if ( integer1 == integer2 ) {
                            if ( value1 > value2 ) {
                                UpgradedSave ( third, data2 );
                                empty = false;
                            }
                            else if ( value1 == value2 ) {
                                if ( ucSum1 >= ucSum2 ) {
                                    UpgradedSave ( third, data2 );
                                    empty = false;
                                }
                                else {
                                    UpgradedSave ( second, data2 );
                                    integer1 = integer2;
                                    value1 = value2;
                                    ucSum1 = ucSum2;
                                    break;
                                }
                            }
                            else {
                                UpgradedSave ( second, data2 );
                                integer1 = integer2;
                                value1 = value2;
                                ucSum1 = ucSum2;
                                break;  
                            }
                        }
                        else {
                            UpgradedSave ( second, data2 );
                            integer1 = integer2;
                            value1 = value2;
                            ucSum1 = ucSum2;
                            break;
                        }
                    }
                }
            }
            firstFile.close();
            ClearFile ( first );

            if ( empty ) {
                secondFile.open ( second.c_str(), fstream::in );
                firstFile.open ( first.c_str(), fstream::app | fstream::out );
                string temp;
                while ( true ) {
                    UpgradedCellRead ( data1, secondFile );
                    if ( secondFile.eof() ) {
                        firstFile.close();
                        secondFile.close();
                        break;
                    }
                    UpgradedSave ( first, data1 );
                }
                break;
            }

            secondFile.open ( second.c_str(), fstream::in );
            thirdFile.open ( third.c_str(), fstream::in );

            UpgradedCellRead ( data1, secondFile );
            UpgradedCellRead ( data2, thirdFile );
            integer1 = data1.counter;
            value1 = data1.i;
            ucSum1 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;

            integer2 = data2.counter;
            value2 = data2.i;
            ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;

            while ( ( !secondFile.eof() ) && ( !thirdFile.eof() ) ) {
                if ( integer1 > integer2 ) {
                    UpgradedSave ( first, data1 );
                    UpgradedCellRead ( data1, secondFile );
                    integer1 = data1.counter;
                    value1 = data1.i;
                    ucSum1 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;
                }
                else if ( integer1 == integer2 ) {
                    if ( value1 > value2 ) {
                        UpgradedSave ( first, data1 );
                        UpgradedCellRead ( data1, secondFile );
                        integer1 = data1.counter;
                        value1 = data1.i;
                        ucSum1 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;
                    }
                    else if ( value1 == value2 ) {
                        if ( ucSum1 >= ucSum2 ) {
                            UpgradedSave ( first, data1 );
                            UpgradedCellRead ( data1, secondFile );
                            integer1 = data1.counter;
                            value1 = data1.i;
                            ucSum1 = ( data1.uc1 + data1.uc2 + data1.uc3 + data1.uc4 ) % 256;
                        }
                        else {
                            UpgradedSave ( first, data2 );
                            UpgradedCellRead ( data2, thirdFile );
                            integer2 = data2.counter;
                            value2 = data2.i;
                            ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;
                        }
                    }
                    else {
                        UpgradedSave ( first, data2 );
                        UpgradedCellRead ( data2, thirdFile );
                        integer2 = data2.counter;
                        value2 = data2.i;
                        ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;
                    }
                }
                else {
                    UpgradedSave ( first, data2 );
                    UpgradedCellRead ( data2, thirdFile );
                    integer2 = data2.counter;
                    value2 = data2.i;
                    ucSum2 = ( data2.uc1 + data2.uc2 + data2.uc3 + data2.uc4 ) % 256;
                }
            }
            if ( secondFile.eof() ) {
                while ( !thirdFile.eof() ) {
                    UpgradedSave ( first, data2 );
                    UpgradedCellRead ( data2, thirdFile );
                }
            }
            else if ( thirdFile.eof() ) {
                while ( !secondFile.eof() ) {
                    UpgradedSave ( first, data1 );
                    UpgradedCellRead ( data1, secondFile );
                }
            }
            ClearFile ( second );
            ClearFile ( third );
            secondFile.close();
            thirdFile.close();
        }

        firstFile.open ( first.c_str(), fstream::in );
        secondFile.open ( second.c_str(), fstream::out );

        while ( !firstFile.eof() ) {
            UpgradedCellRead ( data1, firstFile );
            if ( firstFile.eof() ) {
                break;
            }
            UpgradedSave ( second, data1 );
        }

        firstFile.close();
        secondFile.close();

        firstFile.open ( first.c_str(), fstream::out );
        secondFile.open ( second.c_str(), fstream::in );

        while ( !secondFile.eof() ) {
            UpgradedCellRead ( data1, secondFile );
            if ( firstFile.eof() ) {
                break;
            }
            UpgradedSave ( first, data1 );
        }
    
        firstFile.close();
        secondFile.close();  

        ClearFile ( second );           
    }
}

void SymmetricDifference ( string first, string second, string third ) {

    fstream firstFile;
    fstream secondFile;
    fstream thirdFile;

    DATA_CELL data1;
    DATA_CELL data2;
    bool nonPresent;

    secondFile.open ( second.c_str(), fstream::in );

    for ( int i = 0; i < StructCount ( second ); i++ ) {
        firstFile.open ( first.c_str(), fstream::in );
        CellRead ( data2, secondFile );
        nonPresent = true;
        for ( int i = 0; i < StructCount ( first ); i++ ) {
            CellRead ( data1, firstFile );
            if ( Equal ( data1, data2 ) ) {
                SaveToFile ( third, data2 );
                nonPresent = false;
                break;
            }
        }
        firstFile.close();
        if ( nonPresent ) {
            SaveToFile ( first, data2 );
        }
    }
    secondFile.close();
    ClearFile ( second );

    thirdFile.open ( third.c_str(), fstream::in );

    for ( int i = 0; i < StructCount ( third ); i++ ) {
        CellRead ( data2, thirdFile );
        SaveToFile ( second, data2 );
    }
    
    thirdFile.close();
    ClearFile ( third );
}

void SortCount ( string first, string second, string third ) {

    fstream firstFile;
    fstream secondFile;
    fstream thirdFile;

    DATA_CELL data1;
    DATA_CELL data2;

    firstFile.open ( first.c_str(), fstream::in );
    firstFile.get();

    if ( !firstFile.eof() ) {

        firstFile.close();
        firstFile.open ( first.c_str(), fstream::in );

        while ( !firstFile.eof() ) {
            GetCell ( data1, firstFile );
            if ( firstFile.eof() ) {
                break;
            }
            SaveNormalised ( second, data1 );
        }
        firstFile.close();

        firstFile.open ( first.c_str(), fstream::in | fstream::out );
        while ( !firstFile.eof() ) {
            GetCell ( data1, firstFile );
            data1.counter = 0;
            if ( firstFile.eof() ) {
                break;
            }
            secondFile.open ( second.c_str(), fstream::in | fstream::out );
            while ( !secondFile.eof() ) {
                GetCell ( data2, secondFile );
                if ( secondFile.eof() ) {
                    secondFile.close();
                    break;
                }
                if ( data2.i == data1.i ) {
                    data1.counter++;
                }
            }
            UpgradedSave ( third, data1 );
            secondFile.close();
        }
        firstFile.close();

        ClearFile ( second );
        ClearFile ( first );
    
        UpgradedSort ( third, second, first );

        thirdFile.open ( third.c_str(), fstream::in );

        for ( int i = 0; i < UpgradedStructCount ( third ) - 1; i++ ) {
            UpgradedCellRead ( data1, thirdFile );
            if ( thirdFile.eof() ) {
                break;
            }
            SaveNormalised ( first, data1 );
        }

        thirdFile.close();

        ClearFile ( third );
    }
    firstFile.close();
}