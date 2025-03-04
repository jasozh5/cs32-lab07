#include <iostream>
#include <cassert>
#include <sstream>
#include "tddFuncs.h"
#include "WordCount.h"

void test_sortedByWord(){
    WordCount wc;
    wc.addAllWords("Hi my name is jason Jason");
    std::ostringstream oss;
    wc.dumpWordsSortedByWord(oss);
    ASSERT_EQUALS("name,1\nmy,1\njason,2\nis,1\nhi,1\n", oss.str()); 
}   

void test_sortedByOccurence(){
    WordCount wc;
    wc.addAllWords("Fun sentence is a fun sentence");
    std::ostringstream oss;
    wc.dumpWordsSortedByOccurence(oss);
    ASSERT_EQUALS("a,1\nis,1\nfun,2\nsentence,2\n", oss.str());
}

void test_addAllWords(){
    WordCount wc;
    wc.addAllWords("My name is Jason that is my name");
    ASSERT_EQUALS(8, wc.getTotalWords());    
    ASSERT_EQUALS(5, wc.getNumUniqueWords());
} 

int main() {
    test_sortedByWord();
    test_sortedByOccurence();
    test_addAllWords();
    std::cout << "Passed all tests!";
    return 0;
}