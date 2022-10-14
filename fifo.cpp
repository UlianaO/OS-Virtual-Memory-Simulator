// File that implements first-in first-out replacement policy
#include "policies.h"
#include "dataStructures.h"

extern vector<PageEntry> inputVector;
extern int numOfFrames;

void fifo()
{
    PageEntry pe();
    vector<PageEntry> FIFO;
    int numReads = 0;
    int numWrites = 0;
    cout << "FIFO" << endl;

    /* inputVector has all the traces from .trace files */

    for (int i = 0; i < inputVector.size(); i++)
    {
        // Page is in FIFO cache/page table
        auto indexFound = find(FIFO.begin(), FIFO.end(), inputVector[i]);
        int index = distance(FIFO.begin(), indexFound);
        if (indexFound != FIFO.end())
        {
            //cout << "HIT" << endl;
            // Solution: Update write if ‘W’ encountered
            if (inputVector[i].getOperation() == 'W')
            {
                FIFO[index].setOperation('W');
            }
        }
        else
        {
            //cout << "MISS" << endl;
            // Page is NOT in FIFO and FIFO is NOT full
            if (FIFO.size() < numOfFrames)
            {
                // Solution: Add new page to back of FIFO
                FIFO.push_back(inputVector[i]);

                //if (inputVector[i].getOperation() == 'R')     // 54 total disk reads
                    numReads++;
                //if (FIFO[0].getOperation() == 'R')            // 64 total disk reads
                //     numReads++;
            }
            // Page is NOT in FIFO and FIFO is full
            else
            {
                //if (FIFO[0].getOperation() == 'R')  // 889 total disk reads
                     numReads++;

                // Solution: Eject the front of FIFO and add new page to back
                if (FIFO[0].getOperation() == 'W')
                    numWrites++;
                FIFO.erase(FIFO.begin());
                FIFO.push_back(inputVector[i]);

                //if (inputVector[i].getOperation() == 'R')   // 1169 total disk reads
                //     numReads++;
            }

            //if (inputVector[i].getOperation() == 'R')   // 1225 total disk reads
            //    numReads++;
        }
    }

    cout << "Total memory frames: " << numOfFrames << endl;
    cout << "Events in trace: " << inputVector.size() << endl;
    cout << "Total disk reads: " << numReads << endl;
    cout << "Total disk writes: " << numWrites << endl;
}