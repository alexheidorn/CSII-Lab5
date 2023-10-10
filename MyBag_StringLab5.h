//
// Created by Richard Maclin on 9/9/23.
//

#ifndef MYBAG_STRING_H
#define MYBAG_STRING_H

#include <string>

namespace std {

    class MyBag_String {
    protected:
        string *bagStrings;
        int numInBag;
        int numAllocated;
    public:
        MyBag_String(int sz = 0);
        MyBag_String(const MyBag_String& oldB);
        MyBag_String operator=(const MyBag_String& srcB);
        ~MyBag_String();
        int getCurrentSize();
        bool isEmpty();
        void add(string s);
        bool contains(string s);
        string getByIndex(int index);
        int getFrequencyOf(string s);
        bool remove(string s);
        int removeAll(string s);
        void showBagContents();
        static bool doTest();
        static void unitTest();
    };

} // std

#endif //MYBAG_STRING_H
