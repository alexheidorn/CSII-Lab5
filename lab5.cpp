/*
* Alex Heidorn
* Created: 10-10-23
* CS2 Lab5
*  
*/

#include <iostream>
#include <fstream> 
#include <string> 
#include <chrono>
#include "alexheidornMyBag_StringLab5.cpp"

using namespace std;

int RandInRange(int low, int high) {
    return (low + rand()%(high - low + 1));
}

int main()
{
    srand(time(0));
    oldMyBag_String oldBag;
    sortedMyBag_String sortBag;
    for (int i = 0; i < 500; i++) {
        string s = to_string(RandInRange(1,100));
        oldBag.add(s);
        sortBag.add(s);
    }
    cout << "Old bag: ";
    oldBag.showBagContents();

    cout << "Sort bag: ";
    sortBag.showBagContents();
    return 0;
}