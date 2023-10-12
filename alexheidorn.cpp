/*
* Alex Heidorn
* Created: 10-10-23
* CS2 Lab5
*  
*/

/* Comment about the results
The add function for and sorting the bag is significantly slower because it needs to do all
the comparisons and move around the elements every time the function runs. The fxn takes way too
long with a bag size of 5000, so I didn't even bother waiting to get that data for comparison.
When using simple search for both sorted & unsorted arrays, at bag sizes of 1000,
it appears that the contains and getFrequencyOf functions are slightly faster
for the unsorted array. Whereas the remove and removeAll functions were slightly faster 
for the sorted array. This presumably has to do with the amount of memory allocated and
how the compiler is processing/saving data in the backend.
Ie - it's quicker for the compiler to find and remove the same data members when they are next to
each other for some reason

But when compared to the 2000 element bag, it appears that the contains & remove functions are
significantly faster and the other tests are relatively similar speed.
This is likely because the unsorted bag can break earlier and return the found values
if they're in a lower array location than they would be in the sorted version.
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

/* 2000 element bags
Given bag tests:

Add test:
Finished adding contents to bag in 1.9628 milliseconds.

Contains Test:
Bag contains 10
That search zipped by in 0.5269 milliseconds.
Bag contains 20
That search zipped by in 0.7311 milliseconds.
Bag contains 30
That search zipped by in 0.6308 milliseconds.
Bag contains 40
That search zipped by in 0.5612 milliseconds.
Bag contains 50
That search zipped by in 0.1144 milliseconds.
Bag contains 60
That search zipped by in 0.1756 milliseconds.
Bag contains 70
That search zipped by in 0.0961 milliseconds.
Bag contains 80
That search zipped by in 0.0878 milliseconds.
Bag contains 90
That search zipped by in 0.0864 milliseconds.

getFrequencyOf Test:
Found 10 24 time(s).
That search zipped by in 0.1791 milliseconds.
Found 20 19 time(s).
That search zipped by in 0.1886 milliseconds.
Found 30 19 time(s).
That search zipped by in 0.1622 milliseconds.
Found 40 25 time(s).
That search zipped by in 0.5372 milliseconds.
Found 50 16 time(s).
That search zipped by in 0.2535 milliseconds.
Found 60 15 time(s).
That search zipped by in 0.2388 milliseconds.
Found 70 20 time(s).
That search zipped by in 0.1854 milliseconds.
Found 80 19 time(s).
That search zipped by in 0.1853 milliseconds.
Found 90 21 time(s).
That search zipped by in 0.1713 milliseconds.

remove Test:
Removed 10
That search zipped by in 0.1671 milliseconds.
Removed 20
That search zipped by in 0.1261 milliseconds.
Removed 30
That search zipped by in 0.129 milliseconds.
Removed 40
That search zipped by in 0.1336 milliseconds.
Removed 50
That search zipped by in 0.1229 milliseconds.
Removed 60
That search zipped by in 0.1184 milliseconds.
Removed 70
That search zipped by in 0.1202 milliseconds.
Removed 80
That search zipped by in 0.1525 milliseconds.
Removed 90
That search zipped by in 0.1389 milliseconds.

removeAll Test:
Removed 10 23 time(s).
That search zipped by in 0.214 milliseconds.
Removed 20 18 time(s).
That search zipped by in 0.1842 milliseconds.
Removed 30 18 time(s).
That search zipped by in 0.1979 milliseconds.
Removed 40 24 time(s).
That search zipped by in 0.1937 milliseconds.
Removed 50 15 time(s).
That search zipped by in 0.1905 milliseconds.
Removed 60 14 time(s).
That search zipped by in 0.191 milliseconds.
Removed 70 19 time(s).
That search zipped by in 0.2236 milliseconds.
Removed 80 18 time(s).
That search zipped by in 0.1875 milliseconds.
Removed 90 20 time(s).
That search zipped by in 0.1922 milliseconds.

Sorted bag tests:

Add test:
Finished adding contents to bag in 28886.5 milliseconds.

Contains Test:
Bag contains 10
That search zipped by in 0.2575 milliseconds.
Bag contains 20
That search zipped by in 0.2573 milliseconds.
Bag contains 30
That search zipped by in 0.1311 milliseconds.
Bag contains 40
That search zipped by in 0.6892 milliseconds.
Bag contains 50
That search zipped by in 0.36 milliseconds.
Bag contains 60
That search zipped by in 0.6049 milliseconds.
Bag contains 70
That search zipped by in 0.7122 milliseconds.
Bag contains 80
That search zipped by in 0.2625 milliseconds.
Bag contains 90
That search zipped by in 0.7033 milliseconds.

getFrequencyOf Test:
Found 10 14 time(s).
That search zipped by in 1.2834 milliseconds.
Found 20 17 time(s).
That search zipped by in 0.5782 milliseconds.
Found 30 18 time(s).
That search zipped by in 0.7516 milliseconds.
Found 40 27 time(s).
That search zipped by in 0.8113 milliseconds.
Found 50 20 time(s).
That search zipped by in 1.2036 milliseconds.
Found 60 29 time(s).
That search zipped by in 0.7619 milliseconds.
Found 70 31 time(s).
That search zipped by in 0.6792 milliseconds.
Found 80 12 time(s).
That search zipped by in 0.3624 milliseconds.
Found 90 21 time(s).
That search zipped by in 0.6628 milliseconds.

remove Test:
Removed 10
That search zipped by in 0.7994 milliseconds.
Removed 20
That search zipped by in 0.4754 milliseconds.
Removed 30
That search zipped by in 0.2605 milliseconds.
Removed 40
That search zipped by in 0.5547 milliseconds.
Removed 50
That search zipped by in 0.2423 milliseconds.
Removed 60
That search zipped by in 0.4503 milliseconds.
Removed 70
That search zipped by in 0.2751 milliseconds.
Removed 80
That search zipped by in 0.6462 milliseconds.
Removed 90
That search zipped by in 0.3221 milliseconds.

removeAll Test:
Removed 10 13 time(s).
That search zipped by in 1.0595 milliseconds.
Removed 20 16 time(s).
That search zipped by in 1.2699 milliseconds.
Removed 30 17 time(s).
That search zipped by in 1.5716 milliseconds.
Removed 40 26 time(s).
That search zipped by in 1.4309 milliseconds.
Removed 50 19 time(s).
That search zipped by in 0.6706 milliseconds.
Removed 60 28 time(s).
That search zipped by in 0.9907 milliseconds.
Removed 70 30 time(s).
That search zipped by in 1.491 milliseconds.
Removed 80 11 time(s).
That search zipped by in 0.7835 milliseconds.
Removed 90 20 time(s).
That search zipped by in 1.0225 milliseconds.
PS C:\Users\alexh\CS2> */

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
    const int ARRAY_SIZE = 1000;
    // timing test given bag ADT
    cout << "Given bag tests:\n"
        << "\nAdd test:\n";
    oldMyBag_String oldBag(ARRAY_SIZE);
    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    for (int i = 0; i < ARRAY_SIZE; i++) {
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
    sortedMyBag_String sortBag(ARRAY_SIZE);
    startTime = high_resolution_clock::now();
    for (int i = 0; i < ARRAY_SIZE; i++) {
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