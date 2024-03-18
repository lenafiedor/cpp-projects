#include <string>
using namespace std;

bool condition ( string final ) {
    for ( int i = 0; i < final.size(); i++ ) {
        if ( final[i] == '{' ) {
            return false;
        }
    }
    return true;        
}

void fill ( string s, string& final, int begin, int end ) {
    for ( int i = begin; i < end; i++ ) {
        final += s[i];
    }
    begin = end;
}

void change ( string s, string& final, string ins ) {
    final += ins;
}

void rangeChange ( string s, string& final, string ins, int index ) {
    if ( ( s[index + 4] - '0' ) > ins.size() ) {
        final += ins;
        for ( int i = s[index + 4] - '0'; i > ins.size(); i-- ) {
            final += ' ';
        }
    }
    else if ( ( s[index + 4] - '0' ) < ins.size() ) {
        for ( int i = 0; i < s[index + 4] - '0'; i++ ) {
            final += ins[i];
        }
    }
    else {
        final += ins;
    }
}

int begin ( string s, int begin, int end ) {
    int index;
    for ( index = begin; index < end; index++ ) {
        if ( s[index] == '{' ) {
            break;
        }
    }
    return index;
}

bool white ( string s, int index ) {
    if ( ( s[index] == ' ' ) || ( s[index] == '\n' ) )
    return true;
    else return false;
}

void tempCorrection ( string s, string& temp, int position ) {
    temp = "";
    for ( int i = position; i < s.size(); i++ ) {
        temp += s[i];
    }
}

string FormatujNapis ( string s, string first, string second, string third ) {
    string final = "";
    string temp = s;
    int position = 0;
    int index = begin ( s, 0, s.size() ) + 1;
    do {
        index = begin ( s, position, s.size() ) + 1;
        int howMany = s[index + 2] - '0';
        switch ( s[index] ) {

            case 'p':
            {
                char sign = s[index + 4];
                fill ( s, final, position, index - 1 );
                position = index - 2;
                for ( int i = 0; i < howMany; i++ ) {
                    final += sign;
                }
                position += 8;
            }
            break;

            case 'u':
            {
                fill ( s, final, position, index - 1 );
                position = index + 4 + howMany;
            }
            break;

            case 'U':
            {
                fill ( s, final, position, index - 1 );
                if ( howMany > final.size() ) {
                    final.resize ( 0 );
                }
                else {
                    final.resize ( final.size() - howMany );
                }
                position = index + 4;
            }
            break;

            case 'w':
            {
                fill ( s, final, position, index - 1 );
                position = index - 2;
                int number = s[index + 2] - '0';
                if ( number == 1 ) {
                    change ( s, final, first );
                }
                else if ( number == 2 ) {
                    change ( s, final, second );
                }
                else if ( number == 3 ) {
                    change ( s, final, third );
                }
                position = index + 4;
            }
            break;

            case 'W':
            {
                fill ( s, final, position, index - 1 );
                int number = s[index + 2] - '0';
                if ( number == 1 ) {
                    rangeChange ( s, final, first, index );
                }
                else if ( number == 2 ) {
                    rangeChange ( s, final, second, index );
                }
                else if ( number == 3 ) {
                    rangeChange ( s, final, third, index );
                }
                position = index + 6;
                if ( s[position - 1] == '{' ) {
                    position--;
                }
            }
            break;

            default:
            break;
        }
        tempCorrection ( s, temp, position );
    }
    while ( !condition ( temp ) );
    fill ( s, final, position, s.size() );
    return final;
}

string NajwiekszeSlowo ( string s ) {
    string max = " ";
    string temp;
    int lntMax;
    for ( int i = 0; i < s.size(); i++ ) {
        if ( !white ( s, i ) ) {
            while ( !white ( s, i ) && i < s.size() ) {
                temp += s[i];
                i++;
            }
            lntMax = temp.size();
        }
        for ( int j = 0; j < lntMax; j++ ) {
            if ( temp[j] > max[j] ) {
                max = temp;
                break;
            }
            else break;
        }
        temp = "";
    }
    return max;
}

string UsunSlowo ( string s, int delIndex ) {
    string final = "";
    int wordIndex = 0;
    for ( int i = 0; i < s.size(); i++ ) {
        if ( !white ( s, i ) ) {
            wordIndex++;
            if ( wordIndex != delIndex ) {
                for ( ; !white ( s, i ) && i < s.size(); i++ ) {
                    final += s[i];
                }
                i--;
            }
            else {
                while ( !white ( s, i ) && i < s.size() ) {
                    i++;
                }
                i--;
            }
        }
        else {
            final += s[i];
        }
    }
    return final;
}

string NormalizujNapis ( string s ) {
    string final = "";
    bool begEnd;
    int i = 0;
    do {
        if ( s[i] == ' ' ) {
            begEnd = false;
            i++;
        }
        else {
            begEnd = true;
        }
    }
    while ( white ( s, i ) );
    for ( ; i < s.size(); i++ ) {
        if ( s[i] == ' ' ) {
            if ( ( s[i+1] == ',' ) || ( s[i+1] == '.' ) || ( s[i+1] == ' ' ) ) {
                i++;
                i--;
            }
            else {
                for ( int j = i; j < s.size(); j++ ) {
                    if ( !white ( s, j ) ) {
                        final += s[i];
                        break;
                    }
                }
            }
        }
        else if ( ( s[i] == '.' ) || ( s[i] == ',' ) ) {
            if ( ( s[i+1] != ' ' ) && ( i != s.size() - 1 ) ) {
                final += s[i];
                final += ' ';
            }
            else final += s[i];
        }
        else final += s[i];
    }
    return final;
}