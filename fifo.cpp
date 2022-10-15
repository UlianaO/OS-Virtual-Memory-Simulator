// File that implements first-in first-out replacement policy
#include "policies.h"
#include "dataStructures.h"

extern vector<PageEntry> inputVector;
extern int numOfFrames;
extern string mode;

void fifo()
{
    vector<PageEntry> FIFO;
    int numReads = 0;
    int numWrites = 0;

    if (mode == "debug")
        cout << "FIFO" << endl;

    /* inputVector has all the traces from .trace files */

    for (int i = 0; i < inputVector.size(); i++)
    {
        if (mode == "debug")
            inputVector[i].printPageInfo();

        // Page is in FIFO cache/page table
        auto indexFound = find(FIFO.begin(), FIFO.end(), inputVector[i]);
        int index = distance(FIFO.begin(), indexFound);
        if (indexFound != FIFO.end())
        {
            if (mode == "debug")
                cout << "HIT" << endl;

            // Solution: Update write if ‘W’ encountered
            if (inputVector[i].getOperation() == 'W')
                FIFO[index].setOperation('W');
        }
        else
        {
            if (mode == "debug")
                cout << "MISS" << endl;

            // Page is NOT in FIFO and FIFO is NOT full
            if (FIFO.size() < numOfFrames)
            {
                // Solution: Add new page to back of FIFO
                FIFO.push_back(inputVector[i]);
                numReads++;
            }
            // Page is NOT in FIFO and FIFO is full
            else
            {
                numReads++;

                // Solution: Eject the front of FIFO and add new page to back
                if (FIFO[0].getOperation() == 'W')
                    numWrites++;
                FIFO.erase(FIFO.begin());
                FIFO.push_back(inputVector[i]);
            }
        }
    }

    // Print details
    cout << "Total memory frames: " << numOfFrames << endl;
    cout << "Events in trace: " << inputVector.size() << endl;
    cout << "Total disk reads: " << numReads << endl;
    cout << "Total disk writes: " << numWrites << endl;
}