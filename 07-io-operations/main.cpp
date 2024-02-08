#include <iostream>
#include <fstream>
#include <string>
#include "source.cpp"

using namespace std;

int main () {

    string first = "input1.txt";
    string second = "helpSecond.txt";
    string third = "helpThird.txt";

    SortCount ( "input1.txt", "helpSecond.txt", "helpThird.txt" );

    return 0;
}