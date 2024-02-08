#include <iostream>

using namespace std;

bool isValid(int move) {
    return (move > 0 && move <= 4);
}

bool insertMoves(char& id, int& firstMove, int& secMove, int& thirdMove, int& fourthMove) {
    cin >> id;
    if (id < 'a' || id > 'e') {
        cout << "ID is not valid." << endl;
        return false;
    }
    cin >> firstMove >> secMove >> thirdMove >> fourthMove;
    if (!isValid(firstMove) || !isValid(secMove) || !isValid(thirdMove) || !isValid(fourthMove)) {
        cout << "Number is not valid." << endl;
        return false;
    }
    return true;
}

bool fourIdentical(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return firstMove == secMove && secMove == thirdMove && thirdMove == fourthMove;
}

bool fourDifferent(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return (firstMove != secMove) && (secMove != thirdMove) && (thirdMove != fourthMove) && (firstMove != thirdMove) &&
    (firstMove != fourthMove) && (secMove != fourthMove);
}

int sum(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return firstMove + secMove + thirdMove + fourthMove;
}

void compareSums(int first1move, int first2move, int first3move, int first4move, int sec1move, int sec2move, int sec3move, int sec4move,
int& firstWon, int& firstLost, int& firstTie, int& secWon, int& secLost, int& secTie) {

    int sumFirst = sum(first1move, first2move, first3move, first4move);
    int sumSec = sum(sec1move, sec2move, sec3move, sec4move);

    if (sumFirst > sumSec) {
        firstWon += 1;
        secLost += 1;
    }
    else if (sumFirst < sumSec) {
        firstLost += 1;
        secWon += 1;
    }
    else {
        firstTie += 1;
        secTie += 1;
    }
}

bool twoPairs(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return (firstMove == secMove && thirdMove == fourthMove) || (firstMove == thirdMove && secMove == fourthMove) ||
    (firstMove == fourthMove && secMove == thirdMove);
}

void compareTwoPairs(int first1move, int first2move, int first3move, int first4move, int sec1move, int sec2move, int sec3move, int sec4move,
int& firstWon, int& firstLost, int& firstTie, int& secWon, int& secLost, int& secTie) {

    int sumFirst, sumSec;

    if (first1move == first2move) {
        sumFirst = max(first1move + first2move, first3move + first4move);
    }
    else if (first1move == first3move) {
        sumFirst = max(first1move + first3move, first2move + first4move);
    }
    else if (first1move == first4move) {
        sumFirst = max(first1move + first4move, first2move + first3move);
    }

    if (sec1move == sec2move) {
        sumSec = max(sec1move + sec2move, sec3move + sec4move);
    }
    else if (sec1move == sec3move) {
        sumSec = max(sec1move + sec3move, sec2move + sec4move);
    }
    else if (sec1move == sec4move) {
        sumSec = max(sec1move + sec4move, sec2move + sec3move);
    }

    if (sumFirst > sumSec) {
        firstWon += 1;
        secLost += 1;
    }
    else if (sumFirst < sumSec) {
        firstLost += 1;
        secWon += 1;
    }
    else {
        compareSums(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
        firstWon, firstLost, firstTie, secWon, secLost, secTie);
    }
}

bool threeIdentical(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return (firstMove == secMove == thirdMove) || (firstMove == secMove == fourthMove) ||
    (firstMove == thirdMove == fourthMove) || (secMove == thirdMove == fourthMove);
}

void compareThree(int first1move, int first2move, int first3move, int first4move, int sec1move, int sec2move, int sec3move, int sec4move,
int& firstWon, int& firstLost, int& firstTie, int& secWon, int& secLost, int& secTie) {

    int sumFirst, sumSec;

    if (first1move == first2move == first3move) {
        sumFirst = first1move + first2move + first3move;
    }
    else if (first1move == first2move == first4move) {
        sumFirst = first1move + first2move + first4move;
    }
    else if (first1move == first3move == first4move) {
        sumFirst = first1move + first3move + first4move;
    }
    else if (first2move == first3move == first4move) {
        sumFirst = first2move + first3move + first4move;
    }

    if (sec1move == sec2move == sec3move) {
        sumSec = sec1move + sec2move + sec3move;
    }
    else if (sec1move == sec2move == sec4move) {
        sumSec = sec1move + sec2move + sec4move;
    }
    else if (sec1move == sec3move == sec4move) {
        sumSec = sec1move + sec3move + sec4move;
    }
    else if (sec2move == sec3move == sec4move) {
        sumSec = sec2move + sec3move + sec4move;
    }

    if (sumFirst > sumSec) {
        firstWon += 1;
        secLost += 1;
    }
    else if (sumFirst < sumSec) {
        firstLost += 1;
        secWon += 1;
    }
    else {
        compareSums(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
        firstWon, firstLost, firstTie, secWon, secLost, secTie);
    }
}

bool onePair(int firstMove, int secMove, int thirdMove, int fourthMove) {
    return (firstMove == secMove || firstMove == thirdMove || firstMove == fourthMove || secMove == thirdMove
    || secMove == fourthMove || thirdMove == fourthMove);
}

void comparePairs(int first1move, int first2move, int first3move, int first4move, int sec1move, int sec2move, int sec3move, int sec4move,
int& firstWon, int& firstLost, int& firstTie, int& secWon, int& secLost, int& secTie) {

    int sumFirst, sumSec;

    if (first1move == first2move) {
        sumFirst = first1move + first2move;
    }
    else if (first1move == first3move) {
        sumFirst = first1move + first3move;
    }
    else if (first1move == first4move) {
        sumFirst = first1move + first4move;
    }
    else if (first2move == first3move) {
        sumFirst = first2move + first3move;
    }
    else if (first2move == first4move) {
        sumFirst = first2move + first4move;
    }
    else if (first3move == first4move) {
        sumFirst = first3move + first4move;
    }

    if (sec1move == sec2move) {
        sumSec = sec1move + sec2move;
    }
    else if (sec1move == sec3move) {
        sumSec = sec1move + sec3move;
    }
    else if (sec1move == sec4move) {
        sumSec = sec1move + sec4move;
    }
    else if (sec2move == sec3move) {
        sumSec = sec2move + sec3move;
    }
    else if (sec2move == sec4move) {
        sumSec = sec2move + sec4move;
    }
    else if (sec3move == sec4move) {
        sumSec = sec3move + sec4move;
    }

    if (sumFirst > sumSec) {
        firstWon += 1;
        secLost += 1;
    }
    else if (sumFirst < sumSec) {
        firstLost += 1;
        secWon += 1;
    }
    else {
        compareSums(first1move, first2move, first3move, first4move, sec1move, sec2move, sec3move, sec4move,
        firstWon, firstLost, firstTie, secWon, secLost, secTie);
    }
}
