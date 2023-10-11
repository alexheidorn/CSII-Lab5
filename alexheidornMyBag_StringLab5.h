//
// Created by Richard Maclin on 9/9/23.
//

#ifndef MYBAG_STRING_H
#define MYBAG_STRING_H

#include <string>

namespace std {

    class sortedMyBag_String {
    protected:
        string *bagStrings;
        int numInBag;
        int numAllocated;
    public:
        sortedMyBag_String(int sz = 0);
        sortedMyBag_String(const sortedMyBag_String& oldB);
        sortedMyBag_String operator=(const sortedMyBag_String& srcB);
        ~sortedMyBag_String();
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

    class oldMyBag_String {
    protected:
        string *bagStrings;
        int numInBag;
        int numAllocated;
    public:
        oldMyBag_String(int sz = 0);
        oldMyBag_String(const oldMyBag_String& oldB);
        oldMyBag_String operator=(const oldMyBag_String& srcB);
        ~oldMyBag_String();
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
