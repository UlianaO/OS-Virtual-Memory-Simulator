// File that implements first-in first-out replacement policy
#include "policies.h"
#include <deque>

extern vector<PageEntry> inputVector;
extern int numOfFrames;
extern string mode;

void lru()
{
    deque<PageEntry> LRU;
    int numReads = 0;
    int numWrites = 0;

    if (mode == "debug")
        std::cout << "LRU" << endl;

    /* inputVector has all the traces from .trace files */
    /* (front-oldest page)----------(back-newest page)*/

    for (int i = 0; i < inputVector.size(); i++)
    {
        if (mode == "debug")
            inputVector[i].printPageInfo();


        auto indexFound = find(LRU.begin(), LRU.end(), inputVector[i]);
        int index = distance(LRU.begin(), indexFound);

        // Page is in LRU cache/page table
        if (indexFound != LRU.end())
        {
            if (mode == "debug")
                std::cout << "HIT" << endl;

            // Solution: Update write if ‘W’ encountered
            if (inputVector[i].getOperation() == 'W')
                LRU[index].setOperation('W');

            //Move to the back(most recently used)
            PageEntry temp = LRU[index];
            LRU.erase(LRU.begin() + index);
            LRU.push_back(temp);
        }
        else
        {
            if (mode == "debug")
                std::cout << "MISS" << endl;

            // Page is NOT in LRU and LRU is NOT full
            if (LRU.size() < numOfFrames)
            {
                // Solution: Add new page to back of FIFO
                LRU.push_back(inputVector[i]);
                numReads++;
            }
            // Page is NOT in LRU and LRU is full
            else
            {
                numReads++;

                // Solution: Eject the oldest page(kept in the front) of LRU and add new page to back(newest)
                
                if (LRU.front().getOperation() == 'W')
                    numWrites++;
                LRU.pop_front();
                LRU.push_back(inputVector[i]);
            }
        }
    }

    // Print details
    std::cout << "Total memory frames: " << numOfFrames << endl;
    std::cout << "Events in trace: " << inputVector.size() << endl;
    std::cout << "Total disk reads: " << numReads << endl;
    std::cout << "Total disk writes: " << numWrites << endl;
}