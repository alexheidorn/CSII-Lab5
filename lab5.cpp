/*
* Alex Heidorn
* Created: 10-10-23
* CS2 Lab5
*  
*/

/* Comment about the results
talk about which one was faster, and why
Just one sentence is fine


consdier adding bin search if time
just change add fxn for now
*/

/* Test w 1000 element bags
Given bag tests:

Add test:
Finished adding contents to bag in 0.4827 milliseconds.

Contains Test:
Bag contains 10
That search zipped by in 0.0889 milliseconds.
Bag contains 20
That search zipped by in 0.1482 milliseconds.
Bag contains 30
That search zipped by in 0.1044 milliseconds.
Bag contains 40
That search zipped by in 0.2625 milliseconds.
Bag contains 50
That search zipped by in 0.1341 milliseconds.
Bag contains 60
That search zipped by in 0.1087 milliseconds.
Bag contains 70
That search zipped by in 0.1098 milliseconds.
Bag contains 80
That search zipped by in 0.1179 milliseconds.
Bag contains 90
That search zipped by in 0.2002 milliseconds.

getFrequencyOf Test:
Found 10 14 time(s).
That search zipped by in 0.2457 milliseconds.
Found 20 8 time(s).
That search zipped by in 0.1859 milliseconds.
Found 30 4 time(s).
That search zipped by in 0.2014 milliseconds.
Found 40 5 time(s).
That search zipped by in 0.4015 milliseconds.
Found 50 13 time(s).
That search zipped by in 0.2623 milliseconds.
Found 60 14 time(s).
That search zipped by in 0.2117 milliseconds.
Found 70 13 time(s).
That search zipped by in 0.2148 milliseconds.
Found 80 13 time(s).
That search zipped by in 0.3502 milliseconds.
Found 90 14 time(s).
That search zipped by in 0.2236 milliseconds.

remove Test:
Removed 10
That search zipped by in 0.1462 milliseconds.
Removed 20
That search zipped by in 0.1526 milliseconds.
Removed 30
That search zipped by in 0.1245 milliseconds.
Removed 40
That search zipped by in 0.1417 milliseconds.
Removed 50
That search zipped by in 0.1279 milliseconds.
Removed 60
That search zipped by in 0.1908 milliseconds.
Removed 70
That search zipped by in 0.1491 milliseconds.
Removed 80
That search zipped by in 0.1461 milliseconds.
Removed 90
That search zipped by in 0.1398 milliseconds.

removeAll Test:
Removed 10 13 time(s).
That search zipped by in 0.2283 milliseconds.
Removed 20 7 time(s).
That search zipped by in 0.2203 milliseconds.
Removed 30 3 time(s).
That search zipped by in 0.2049 milliseconds.
Removed 40 4 time(s).
That search zipped by in 0.2132 milliseconds.
Removed 50 12 time(s).
That search zipped by in 0.2662 milliseconds.
Removed 60 13 time(s).
That search zipped by in 0.3091 milliseconds.
Removed 70 12 time(s).
That search zipped by in 0.2073 milliseconds.
Removed 80 12 time(s).
That search zipped by in 0.209 milliseconds.
Removed 90 13 time(s).
That search zipped by in 0.2372 milliseconds.

Sorted bag tests:

Add test:
Finished adding contents to bag in 3946.21 milliseconds.

Contains Test:
Bag contains 10
That search zipped by in 0.4564 milliseconds.
Bag contains 20
That search zipped by in 0.2381 milliseconds.
Bag contains 30
That search zipped by in 0.2283 milliseconds.
Bag contains 40
That search zipped by in 0.5276 milliseconds.
Bag contains 50
That search zipped by in 0.6687 milliseconds.
Bag contains 60
That search zipped by in 0.3017 milliseconds.
Bag contains 70
That search zipped by in 0.554 milliseconds.
Bag contains 80
That search zipped by in 0.1224 milliseconds.
Bag contains 90
That search zipped by in 0.2291 milliseconds.

getFrequencyOf Test:
Found 10 13 time(s).
That search zipped by in 0.2934 milliseconds.
Found 20 7 time(s).
That search zipped by in 0.2315 milliseconds.
Found 30 15 time(s).
That search zipped by in 0.2127 milliseconds.
Found 40 8 time(s).
That search zipped by in 0.2396 milliseconds.
Found 50 13 time(s).
That search zipped by in 0.3771 milliseconds.
Found 60 8 time(s).
That search zipped by in 0.3135 milliseconds.
Found 70 7 time(s).
That search zipped by in 0.3549 milliseconds.
Found 80 6 time(s).
That search zipped by in 0.3241 milliseconds.
Found 90 8 time(s).
That search zipped by in 0.4999 milliseconds.

remove Test:
Removed 10
That search zipped by in 0.6054 milliseconds.
Removed 20
That search zipped by in 0.1732 milliseconds.
Removed 30
That search zipped by in 0.1712 milliseconds.
Removed 40
That search zipped by in 0.1714 milliseconds.
Removed 50
That search zipped by in 0.1756 milliseconds.
Removed 60
That search zipped by in 0.0984 milliseconds.
Removed 70
That search zipped by in 0.0997 milliseconds.
Removed 80
That search zipped by in 0.0971 milliseconds.
Removed 90
That search zipped by in 0.119 milliseconds.

removeAll Test:
Removed 10 12 time(s).
That search zipped by in 0.1562 milliseconds.
Removed 20 6 time(s).
That search zipped by in 0.1582 milliseconds.
Removed 30 14 time(s).
That search zipped by in 0.1584 milliseconds.
Removed 40 7 time(s).
That search zipped by in 0.1402 milliseconds.
Removed 50 12 time(s).
That search zipped by in 0.1476 milliseconds.
Removed 60 7 time(s).
That search zipped by in 0.1365 milliseconds.
Removed 70 6 time(s).
That search zipped by in 0.1379 milliseconds.
Removed 80 5 time(s).
That search zipped by in 0.1266 milliseconds.
Removed 90 7 time(s).
That search zipped by in 0.1259 milliseconds.
PS C:\Users\alexh\CS2> 
*/

#include <iostream>
#include <fstream> 
#include <string> 
#include <chrono>
#include "alexheidornMyBag_StringLab5.cpp"

using namespace std;
using namespace std::chrono;

int RandInRange(int low, int high) {
    return (low + rand()%(high - low + 1));
}

int main()
{
    srand(time(0));
    // timing test given bag ADT
    cout << "Given bag tests:\n"
        << "\nAdd test:\n";
    oldMyBag_String oldBag;
    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        string s = to_string(RandInRange(1,100));
        oldBag.add(s);
    }
    high_resolution_clock::time_point stopTime = high_resolution_clock::now();
    duration<double, std::milli> timeTaken = (stopTime - startTime);
    /*
    cout << "Given bag contents: ";
    oldBag.showBagContents();
    */
    cout << "Finished adding contents to bag in " << timeTaken.count() << " milliseconds.\n";

    //contains
    cout << "\nContains Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = 0;
        if (oldBag.contains(findS)){
            cout << "Bag contains " << findS << "\n";
        }
        else {
            cout << "Bag does not contain " << findS << endl;
        }
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }

    //getFrequencyOf
    cout << "\ngetFrequencyOf Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = oldBag.getFrequencyOf(findS);
        cout << "Found " << findS << " " << i << " time(s).\n";
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }


    //remove
    cout << "\nremove Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        if (oldBag.remove(findS)){
            cout << "Removed " << findS << "\n";
        }
        else {
            cout << "Bag does not contain " << findS << endl;
        }
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }

    //removeAll
    cout << "\nremoveAll Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = oldBag.removeAll(findS);
        cout << "Removed " << findS << " " << i << " time(s).\n";
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }

    // timing tests sorted bag ADT
    cout << "\nSorted bag tests:\n"
        << "\nAdd test:\n";
    sortedMyBag_String sortBag;
    startTime = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        string s = to_string(RandInRange(1,100));
        sortBag.add(s);
    }
    stopTime = high_resolution_clock::now();
    timeTaken = (stopTime - startTime);
    /*
    cout << "Given bag contents: ";
    sortBag.showBagContents();
    */
    cout << "Finished adding contents to bag in " << timeTaken.count() << " milliseconds.\n";

    //contains
    cout << "\nContains Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = 0;
        if (sortBag.contains(findS)){
            cout << "Bag contains " << findS << "\n";
        }
        else {
            cout << "Bag does not contain " << findS << endl;
        }
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }

    //getFrequencyOf
    cout << "\ngetFrequencyOf Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = sortBag.getFrequencyOf(findS);
        cout << "Found " << findS << " " << i << " time(s).\n";
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }


    //remove
    cout << "\nremove Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        if (sortBag.remove(findS)){
            cout << "Removed " << findS << "\n";
        }
        else {
            cout << "Bag does not contain " << findS << endl;
        }
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }

    //removeAll
    cout << "\nremoveAll Test:\n";
    for (int findN = 10; findN < 100; findN += 10) {
        string findS = to_string(findN);
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = sortBag.removeAll(findS);
        cout << "Removed " << findS << " " << i << " time(s).\n";
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }
}