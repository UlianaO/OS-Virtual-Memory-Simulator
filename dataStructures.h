// The file makes the dataStructures accessible to all the policies

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

/*
// Page replacement algorithms
class PageReplacementAlgorithm
{
    private:
        int numReads;
        int numWrites;
        string algorithm;
        vector<PageEntry> FIFO;
    public:
        PageReplacementAlgorithm(string alg) 
        { 
            algorithm = alg;
            performAlgorithm();
        }

        void performAlgorithm()
        {
            if (algorithm == "fifo")
            {

            }
        }
        void fifo();
        void lru();
        void vms();
};
*/


        void fifo();
        void lru();
        void segfifo();