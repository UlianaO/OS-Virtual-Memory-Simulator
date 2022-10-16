// The file includes the PageEntry class which stores information for each entry

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <deque>
#include <chrono>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class PageEntry {
private:
    unsigned address;
    // oper is either R or W.

    char operation;
   
    // Dirty Bit means an existing page on the disk was updated
    int isDirty;

    // found by shifting address >> 12 (logical address/page size. page size is 4096 = 2^12)
    int pageNum;
    
public:
    // Constructors
    PageEntry() { }

    PageEntry(unsigned a, char o)
    {
        setAddress(a);
        operation = o;
        pageNum = address/4096;
        isDirty = 0;//
    }

    int getAddress() {
        return address;
    }
    void setAddress(int add) {
        address = add;
    }

    char getOperation() {
        return operation;
    }

    void setOperation(char operation){
        this->operation = operation;
    }

    int getIsDirty() {
        return isDirty;
    }

    void setIsDirty(int num)
    {
        isDirty = num;
    }

    int getPageNum() {
        return pageNum;
    }

    // Print info to debug
    void printPageInfo()
    {
        cout << "Address: " << address << " | Operation: " << operation << " | Page number: " << pageNum << endl;
        //cout << "Address: " << address << " | Operation: " << operation << " | Page number: " << pageNum << " | isDirty? " << isDirty << endl;
    }

    // Use to find whether page is found (for the find() operation)
    bool operator==(const PageEntry& pe)
    {
        return pageNum == pe.pageNum;
    }
};
