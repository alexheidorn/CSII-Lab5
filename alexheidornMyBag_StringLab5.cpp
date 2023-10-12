//
// Created by Richard Maclin on 9/9/23.
//

#include "alexheidornMyBag_StringLab5.h"
#include <iostream>

namespace std {
    sortedMyBag_String::sortedMyBag_String(int sz) {
        numInBag = 0;
        if (sz < 16) {
            sz = 16;
        }
        numAllocated = sz;
        bagStrings = new string[numAllocated];
    }
    sortedMyBag_String::sortedMyBag_String(const sortedMyBag_String &oldB) {
        numInBag = oldB.numInBag;
        numAllocated = oldB.numAllocated;
        bagStrings = new string[numAllocated];
        for (int i = 0; i < numInBag; i++) {
            bagStrings[i] = oldB.bagStrings[i];
        }
    }
    sortedMyBag_String sortedMyBag_String::operator=(const sortedMyBag_String& srcB) {
        numInBag = srcB.numInBag;
        numAllocated = srcB.numAllocated;
        bagStrings = new string[numAllocated];
        for (int i = 0; i < numInBag; i++) {
            bagStrings[i] = srcB.bagStrings[i];
        }
        return *this;
    }
    sortedMyBag_String::~sortedMyBag_String() {
        delete [] bagStrings;
    }
    int sortedMyBag_String::getCurrentSize() {
        return numInBag;
    }
    bool sortedMyBag_String::isEmpty() {
        return (numInBag == 0);
    }
    void sortedMyBag_String::add(string s) {
        if ((numInBag+1) >= numAllocated) {
            numAllocated *= 2;
            string *oldStrings = bagStrings;
            bagStrings = new string[numAllocated];
            for (int i = 0; i < numInBag; i++){
                bagStrings[i] = oldStrings[i];
            }
            delete [] oldStrings;
        }
        bagStrings[numInBag] = s;
        numInBag++;
        sort(bagStrings);
    }
    void sortedMyBag_String::sort(string* bagStrings){ //selection sort
        int i, j, min_idx;
    
        // One by one move boundary of
        // unsorted subarray
        for (i = 0; i < numInBag - 1; i++) {
    
            // Find the minimum element in
            // unsorted array
            min_idx = i;
            for (j = i + 1; j < numInBag; j++) {
                if (bagStrings[j] < bagStrings[min_idx])
                    min_idx = j;
            }
    
            // Swap the found minimum element
            // with the first element
            if (min_idx != i)
                swap(bagStrings[min_idx], bagStrings[i]);
        }
    }
    bool sortedMyBag_String::contains(string s) {
        for (int i = 0; i < numInBag; i++) {
            if (s.compare(bagStrings[i]) == 0) {
                return true;
            }
        }
        return false;
    }
    string sortedMyBag_String::getByIndex(int index) {
        if ((index < 0) || (index >= numInBag)) {
            return "ERROR: index out of bounds";
        }
        return bagStrings[index];
    }
    int sortedMyBag_String::getFrequencyOf(string s) {
        int count = 0;
        for (int i = 0; i < numInBag; i++) {
            if (s.compare(bagStrings[i]) == 0) {
                count++;
            }
        }
        return count;
    }
    bool sortedMyBag_String::remove(string s) {
        int i = 0;
        while (i < numInBag) {
            if (s.compare(bagStrings[i]) == 0) {
                for (int j = i + 1; j < numInBag; j++) {
                    bagStrings[j-1] = bagStrings[j];
                }
                numInBag--;
                return true;
            }
            i++;
        }
        return false;
    }
    int sortedMyBag_String::removeAll(string s) {
        int numRemoved = 0;
        int i = 0;
        while ((i < numInBag) && (s.compare(bagStrings[i]) != 0)) {
            i++;
        }
        if (i < numInBag) {
            int numRemoved = 1;
            int j = i;
            i++;
            while (i < numInBag) {
                if (s.compare(bagStrings[i]) != 0) {
                    bagStrings[j] = bagStrings[i];
                    j++;
                    i++;
                }
                else {
                    numRemoved++;
                    i++;
                }
            }
            numInBag = j;
            return numRemoved;
        }
        else {
            return 0;
        }
    }
    void sortedMyBag_String::showBagContents() {
        cout << "Current size is " << getCurrentSize() << endl;
        for (int i = 0; i < getCurrentSize(); i++) {
            cout << i << " " << getByIndex(i) << endl;
        }
    }
    bool sortedMyBag_String::doTest() {
        sortedMyBag_String myBag1;
        sortedMyBag_String myBag2(20);
        string simpleNumbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        srand(time(0));
        if ((myBag1.getCurrentSize() != 0) || (myBag2.getCurrentSize() != 0)) {
            cerr << "myBag1 or myBag2 not initially size 0" << endl;
            return false;
        }
        if ((!myBag1.isEmpty()) || (!myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 not initially empty" << endl;
            return false;
        }
        myBag1.add("first string");
        myBag2.add("second string");
        if ((myBag1.getCurrentSize() != 1) || (myBag2.getCurrentSize() != 1)) {
            cerr << "myBag1 or myBag2 not size 1 after initial insert" << endl;
            return false;
        }
        if ((myBag1.isEmpty()) || (myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 empty after initial insert" << endl;
            return false;
        }
        myBag1.add("third string");
        myBag2.add("fourth string");
        if ((myBag1.getCurrentSize() != 2) || (myBag2.getCurrentSize() != 2)) {
            cerr << "myBag1 or myBag2 not size 2 after second insert" << endl;
            return false;
        }
        if ((myBag1.isEmpty()) || (myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 empty after second insert" << endl;
            return false;
        }
        if (!myBag1.contains("first string") || myBag1.contains("second string") || !myBag1.contains("third string") || myBag1.contains("fourth string")) {
            cerr << "problem with contains on myBag1" << endl;
            return false;
        }
        if (myBag2.contains("first string") || !myBag2.contains("second string") || myBag2.contains("third string") || !myBag2.contains("fourth string")) {
            cerr << "problem with contains on myBag2" << endl;
            return false;
        }
        if (!myBag1.remove("first string") || myBag1.remove("second string") || !myBag1.remove("third string") || myBag1.remove("fourth string")) {
            cerr << "problem with remove on myBag1" << endl;
            return false;
        }
        if (myBag2.remove("first string") || !myBag2.remove("second string") || myBag2.remove("third string") || !myBag2.remove("fourth string")) {
            cerr << "problem with remove on myBag2" << endl;
            return false;
        }
        if ((!myBag1.isEmpty()) || (!myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 not empty after removes" << endl;
            return false;
        }
        for (int i = 0; i < 100; i++) {
            myBag1.add(simpleNumbers[i%10]);
            if (myBag1.getCurrentSize() != (i+1)) {
                cerr << "problem with add at index " << i << endl;
                return false;
            }
        }
        for (int i = 0; i < 100; i++) {
            if (simpleNumbers[i%10].compare(myBag1.getByIndex(i)) != 0) {
                cerr << "problem with getByIndex at index " << i << endl;
                return false;
            }
        }
        if (myBag1.getByIndex(-1).compare("ERROR: index out of bounds") != 0) {
            cerr << "problem with getByIndex at index -1" << endl;
            return false;
        }
        if (myBag1.getByIndex(myBag1.getCurrentSize()).compare("ERROR: index out of bounds") != 0) {
            cerr << "problem with getByIndex at index -1" << endl;
            return false;
        }
        for (int i = 0; i < 10; i++) {
            if (myBag1.getFrequencyOf(simpleNumbers[i]) != 10) {
                cerr << "problem with getFrequencyOf at index " << i << endl;
                return false;
            }
        }
        if (myBag1.getFrequencyOf("not a number") != 0) {
            cerr << "problem with getFrequencyOf of non existent string" << endl;
            return false;
        }
        if (myBag1.removeAll("not in Bag") != 0) {
            cerr << "wrong number reported for removal that gets no strings" << endl;
            return false;
        }
        sortedMyBag_String myBag3;
        myBag2 = myBag1;
        myBag3 = myBag1;
        for (int i = 0; i < 10; i++) {
            if (myBag1.removeAll(simpleNumbers[i]) != 10) {
                cerr << "Incorrect number reported for removal of string " << simpleNumbers[i] << endl;
                return false;
            }
            if (myBag1.getCurrentSize() != (100 - ((i+1)*10))) {
                cerr << "Incorrect size reported after removal of string " << simpleNumbers[i] << endl;
                return false;
            }
            // showBagContents(myBag1);
        }
        return true;
    }
    void sortedMyBag_String::unitTest() {
        if (sortedMyBag_String::doTest()) {
            cout << "No test issues reported" << endl;
        }
    }

    oldMyBag_String::oldMyBag_String(int sz) {
        numInBag = 0;
        if (sz < 16) {
            sz = 16;
        }
        numAllocated = sz;
        bagStrings = new string[numAllocated];
    }
    oldMyBag_String::oldMyBag_String(const oldMyBag_String &oldB) {
        numInBag = oldB.numInBag;
        numAllocated = oldB.numAllocated;
        bagStrings = new string[numAllocated];
        for (int i = 0; i < numInBag; i++) {
            bagStrings[i] = oldB.bagStrings[i];
        }
    }
    oldMyBag_String oldMyBag_String::operator=(const oldMyBag_String& srcB) {
        numInBag = srcB.numInBag;
        numAllocated = srcB.numAllocated;
        bagStrings = new string[numAllocated];
        for (int i = 0; i < numInBag; i++) {
            bagStrings[i] = srcB.bagStrings[i];
        }
        return *this;
    }
    oldMyBag_String::~oldMyBag_String() {
        delete [] bagStrings;
    }
    int oldMyBag_String::getCurrentSize() {
        return numInBag;
    }
    bool oldMyBag_String::isEmpty() {
        return (numInBag == 0);
    }
    void oldMyBag_String::add(string s) {
        if ((numInBag+1) >= numAllocated) {
            numAllocated *= 2;
            string *oldStrings = bagStrings;
            bagStrings = new string[numAllocated];
            for (int i = 0; i < numInBag; i++){
                bagStrings[i] = oldStrings[i];
            }
            delete [] oldStrings;
        }
        bagStrings[numInBag] = s;
        numInBag++;
    }
    bool oldMyBag_String::contains(string s) {
        for (int i = 0; i < numInBag; i++) {
            if (s.compare(bagStrings[i]) == 0) {
                return true;
            }
        }
        return false;
    }
    string oldMyBag_String::getByIndex(int index) {
        if ((index < 0) || (index >= numInBag)) {
            return "ERROR: index out of bounds";
        }
        return bagStrings[index];
    }
    int oldMyBag_String::getFrequencyOf(string s) {
        int count = 0;
        for (int i = 0; i < numInBag; i++) {
            if (s.compare(bagStrings[i]) == 0) {
                count++;
            }
        }
        return count;
    }
    bool oldMyBag_String::remove(string s) {
        int i = 0;
        while (i < numInBag) {
            if (s.compare(bagStrings[i]) == 0) {
                for (int j = i + 1; j < numInBag; j++) {
                    bagStrings[j-1] = bagStrings[j];
                }
                numInBag--;
                return true;
            }
            i++;
        }
        return false;
    }
    int oldMyBag_String::removeAll(string s) {
        int numRemoved = 0;
        int i = 0;
        while ((i < numInBag) && (s.compare(bagStrings[i]) != 0)) {
            i++;
        }
        if (i < numInBag) {
            int numRemoved = 1;
            int j = i;
            i++;
            while (i < numInBag) {
                if (s.compare(bagStrings[i]) != 0) {
                    bagStrings[j] = bagStrings[i];
                    j++;
                    i++;
                }
                else {
                    numRemoved++;
                    i++;
                }
            }
            numInBag = j;
            return numRemoved;
        }
        else {
            return 0;
        }
    }
    void oldMyBag_String::showBagContents() {
        cout << "Current size is " << getCurrentSize() << endl;
        for (int i = 0; i < getCurrentSize(); i++) {
            cout << i << " " << getByIndex(i) << endl;
        }
    }
    bool oldMyBag_String::doTest() {
        oldMyBag_String myBag1;
        oldMyBag_String myBag2(20);
        string simpleNumbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        srand(time(0));
        if ((myBag1.getCurrentSize() != 0) || (myBag2.getCurrentSize() != 0)) {
            cerr << "myBag1 or myBag2 not initially size 0" << endl;
            return false;
        }
        if ((!myBag1.isEmpty()) || (!myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 not initially empty" << endl;
            return false;
        }
        myBag1.add("first string");
        myBag2.add("second string");
        if ((myBag1.getCurrentSize() != 1) || (myBag2.getCurrentSize() != 1)) {
            cerr << "myBag1 or myBag2 not size 1 after initial insert" << endl;
            return false;
        }
        if ((myBag1.isEmpty()) || (myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 empty after initial insert" << endl;
            return false;
        }
        myBag1.add("third string");
        myBag2.add("fourth string");
        if ((myBag1.getCurrentSize() != 2) || (myBag2.getCurrentSize() != 2)) {
            cerr << "myBag1 or myBag2 not size 2 after second insert" << endl;
            return false;
        }
        if ((myBag1.isEmpty()) || (myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 empty after second insert" << endl;
            return false;
        }
        if (!myBag1.contains("first string") || myBag1.contains("second string") || !myBag1.contains("third string") || myBag1.contains("fourth string")) {
            cerr << "problem with contains on myBag1" << endl;
            return false;
        }
        if (myBag2.contains("first string") || !myBag2.contains("second string") || myBag2.contains("third string") || !myBag2.contains("fourth string")) {
            cerr << "problem with contains on myBag2" << endl;
            return false;
        }
        if (!myBag1.remove("first string") || myBag1.remove("second string") || !myBag1.remove("third string") || myBag1.remove("fourth string")) {
            cerr << "problem with remove on myBag1" << endl;
            return false;
        }
        if (myBag2.remove("first string") || !myBag2.remove("second string") || myBag2.remove("third string") || !myBag2.remove("fourth string")) {
            cerr << "problem with remove on myBag2" << endl;
            return false;
        }
        if ((!myBag1.isEmpty()) || (!myBag2.isEmpty())) {
            cerr << "myBag1 or myBag2 not empty after removes" << endl;
            return false;
        }
        for (int i = 0; i < 100; i++) {
            myBag1.add(simpleNumbers[i%10]);
            if (myBag1.getCurrentSize() != (i+1)) {
                cerr << "problem with add at index " << i << endl;
                return false;
            }
        }
        for (int i = 0; i < 100; i++) {
            if (simpleNumbers[i%10].compare(myBag1.getByIndex(i)) != 0) {
                cerr << "problem with getByIndex at index " << i << endl;
                return false;
            }
        }
        if (myBag1.getByIndex(-1).compare("ERROR: index out of bounds") != 0) {
            cerr << "problem with getByIndex at index -1" << endl;
            return false;
        }
        if (myBag1.getByIndex(myBag1.getCurrentSize()).compare("ERROR: index out of bounds") != 0) {
            cerr << "problem with getByIndex at index -1" << endl;
            return false;
        }
        for (int i = 0; i < 10; i++) {
            if (myBag1.getFrequencyOf(simpleNumbers[i]) != 10) {
                cerr << "problem with getFrequencyOf at index " << i << endl;
                return false;
            }
        }
        if (myBag1.getFrequencyOf("not a number") != 0) {
            cerr << "problem with getFrequencyOf of non existent string" << endl;
            return false;
        }
        if (myBag1.removeAll("not in Bag") != 0) {
            cerr << "wrong number reported for removal that gets no strings" << endl;
            return false;
        }
        oldMyBag_String myBag3;
        myBag2 = myBag1;
        myBag3 = myBag1;
        for (int i = 0; i < 10; i++) {
            if (myBag1.removeAll(simpleNumbers[i]) != 10) {
                cerr << "Incorrect number reported for removal of string " << simpleNumbers[i] << endl;
                return false;
            }
            if (myBag1.getCurrentSize() != (100 - ((i+1)*10))) {
                cerr << "Incorrect size reported after removal of string " << simpleNumbers[i] << endl;
                return false;
            }
            // showBagContents(myBag1);
        }
        return true;
    }
    void oldMyBag_String::unitTest() {
        if (oldMyBag_String::doTest()) {
            cout << "No test issues reported" << endl;
        }
    }

} // std