#include <iostream>
#include "gameLogic.cpp"

using namespace std;

const int NUM_MOVES = 4;

int aWon = 0, bWon = 0, cWon = 0, dWon = 0, eWon = 0;
int aLost = 0, bLost = 0, cLost = 0, dLost = 0, eLost = 0;
int aTie = 0, bTie = 0, cTie = 0, dTie = 0, eTie = 0;
float aCount = 0, bCount = 0, cCount = 0, dCount = 0, eCount = 0;

void operateGamer(char id, int& won, int& lost, int& tie) {
    switch(id) {
        case 'a':
            aWon += won;
            aLost += lost;
            aTie += tie;
            aCount++;
            break;
        case 'b':
            bWon += won;
            bLost += lost;
            bTie += tie;
            bCount++;
            break;
        case 'c':
            cWon += won;
            cLost += lost;
            cTie += tie;
            cCount++;
            break;
        case 'd':
            dWon += won;
            dLost += lost;
            dTie += tie;
            dCount++;
            break;
        case 'e':
            eWon += won;
            eLost += lost;
            eTie += tie;
            eCount++;
            break;
        default:
            break;
    }
}

void displayResults() {
    if (aCount > 0) {
        cout << "gracz a" << endl;
        if (aWon > 0)
        cout << "    wygrane: " << (aWon/aCount) * 100 << "%" << endl;
        if (aTie > 0)
        cout << "    remisy: " << (aTie/aCount) * 100 << "%" << endl;
        if (aLost > 0 )
        cout << "    przegrane: " << (aLost/aCount) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if (bCount > 0) {
        cout << "gracz b" << endl;
        if (bWon > 0)
        cout << "    wygrane: " << (bWon/bCount) * 100 << "%" << endl;
        if (bTie > 0)
        cout << "    remisy: " << (bTie/bCount) * 100 << "%" << endl;
        if (bLost > 0)
        cout << "    przegrane: " << (bLost/bCount) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if (cCount > 0) {
        cout << "gracz c" << endl;
        if (cWon > 0)
        cout << "    wygrane: " << (cWon/cCount) * 100 << "%" << endl;
        if (cTie > 0)
        cout << "    remisy: " << (cTie/cCount) * 100 << "%" << endl;
        if (cLost > 0)
        cout << "    przegrane: " << (cLost/cCount) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if (dCount > 0)
    {
        cout << "gracz d" << endl;
        if (dWon > 0)
        cout << "    wygrane: " << (dWon/dCount) * 100 << "%" << endl;
        if (dTie > 0)
        cout << "    remisy: " << (dTie/dCount) * 100 << "%" << endl;
        if (dLost > 0)
        cout << "    przegrane: " << (dLost/dCount) * 100 << "%" << endl;
        cout << "" << endl;
    }
    if (eCount > 0)
    {
        cout << "gracz e" << endl;
        if (eWon > 0)
        cout << "    wygrane: " << (eWon/eCount) * 100 << "%" << endl;
        if (eTie > 0)
        cout << "    remisy: " << (eTie/eCount) * 100 << "%" << endl;
        if (eLost > 0)
        cout << "    przegrane: " << (eLost/eCount) * 100 << "%" << endl;
        cout << "" << endl;
    }
}

int main () {

    int numOfGames;
    cin >> numOfGames;

    while (numOfGames > 0) {
        int firstWon = 0, firstLost = 0, firstTie = 0;
        int secWon = 0, secLost = 0, secTie = 0;

        char firstGamer;
        int first1move, first2move, first3move, first4move;

        char secGamer;
        int sec1move, sec2move, sec3move, sec4move;

        if (insertMoves(firstGamer, first1move, first2move, first3move, first4move) && insertMoves(secGamer, sec1move, sec2move, sec3move, sec4move)) {
            if (fourIdentical(first1move, first2move, first3move, first4move) && fourIdentical(sec1move, sec2move, sec3move, sec4move)) {
                if (first1move > sec1move) {
                    firstWon += 1;
                    secLost += 1;
                }
                else if (first1move < sec1move) {
                    firstLost += 1;
                    secWon += 1;
                }
                else {
                    firstTie += 1;
                    secTie += 1;
                }
            }
            else if (fourIdentical(first1move, first2move, first3move, first4move)) {
                firstWon += 1;
                secLost += 1;
            }
            else if (fourIdentical(sec1move, sec2move, sec3move, sec4move)) {
                firstLost += 1;
                secWon += 1;
            }

            else if (fourDifferent(first1move, first2move, first3move, first4move) && fourDifferent(sec1move, sec2move, sec3move, sec4move)) {
                compareSums(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
                firstWon, firstLost, firstTie, secWon, secLost, secTie);
            }
            else if (fourDifferent(first1move, first2move, first3move, first4move)) {
                firstWon += 1;
                secLost += 1;
            }
            else if (fourDifferent(sec1move, sec2move, sec3move, sec4move)) {
                firstLost += 1;
                secWon += 1;
            }

            else if (twoPairs(first1move, first2move, first3move, first4move) && twoPairs(sec1move, sec2move, sec3move, sec4move)) {
                compareTwoPairs(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
                firstWon, firstLost, firstTie, secWon, secLost, secTie);
            }
            else if (twoPairs(first1move, first2move, first3move, first4move)) {
                firstWon += 1;
                secLost += 1;
            }
            else if (twoPairs(sec1move, sec2move, sec3move, sec4move)) {
                firstLost += 1;
                secWon += 1;
            }

            else if (threeIdentical(first1move, first2move, first3move, first4move) && threeIdentical(sec1move, sec2move, sec3move, sec4move)) {
                compareThree(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
                firstWon, firstLost, firstTie, secWon, secLost, secTie);
            }
            else if (threeIdentical(first1move, first2move, first3move, first4move)) {
                firstWon += 1;
                secLost += 1;
            }
            else if (threeIdentical(sec1move, sec2move, sec3move, sec4move)) {
                firstLost += 1;
                secWon += 1;
            }

            else if (onePair(first1move, first2move, first3move, first4move) && onePair(sec1move, sec2move, sec3move, sec4move)) {
                comparePairs(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
                firstWon, firstLost, firstTie, secWon, secLost, secTie);
            }
            else if (onePair(first1move, first2move, first3move, first4move)) {
                firstWon += 1;
                secLost += 1;
            }
            else if (onePair(sec1move, sec2move, sec3move, sec4move)) {
                firstLost += 1;
                secWon += 1;
            }

            operateGamer(firstGamer, firstWon, firstLost, firstTie);
            operateGamer(secGamer, secWon, secLost, secTie);
        }
        else {
            
            return 1;
        }
        numOfGames--;
    }
    displayResults();
    return 0;
}
