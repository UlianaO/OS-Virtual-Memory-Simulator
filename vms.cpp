// File that implements segmented-fifo polciy 
#include "policies.h"
#include "dataStructures.h"
#include <deque>
#include <queue>

extern vector<PageEntry> inputVector;
extern int numOfFrames;
extern int p;
void frontFifo_to_frontLru(deque <PageEntry>& FIFO, deque <PageEntry>& LRU);

void segfifo()
{
    PageEntry pe();
    deque <PageEntry> FIFO_MAIN;
    deque <PageEntry> LRU_SEC;

    int numReads = 0;
    int numWrites = 0;
    int lru_numOfFrames = (numOfFrames * p) / 100;
    int fifo_numOfFrames = numOfFrames - lru_numOfFrames;

    cout << "VMS" << endl;

    for (int i = 0; i < inputVector.size(); i++)
    {
        auto lru_indexFound = find(LRU_SEC.begin(), LRU_SEC.end(), inputVector[i]);
        int lru_index = distance(LRU_SEC.begin(), lru_indexFound);

        /*page is in LRU and not in FIFO; FIFO is full*/
        if (lru_indexFound != LRU_SEC.end()) {
            //update W
            if (inputVector[i].getOperation() == 'W')
            {
                LRU_SEC[lru_index].setOperation('W');
            }

            /*move the page from lru to back of FIFO*/
            PageEntry vpe = LRU_SEC[lru_index];
            LRU_SEC.erase(LRU_SEC.begin() + lru_index);
            FIFO_MAIN.push_back(vpe);

            frontFifo_to_frontLru(FIFO_MAIN, LRU_SEC);
        }

        auto indexFound = find(FIFO_MAIN.begin(), FIFO_MAIN.end(), inputVector[i]);
        int index = distance(FIFO_MAIN.begin(), indexFound);

        /*page is in FIFO*/
        if (indexFound != FIFO_MAIN.end())
        {
            //update W bit            
            if (inputVector[i].getOperation() == 'W')  
            {
                FIFO_MAIN[index].setOperation('W');
            }
        }
        //page is not in fifo 
        else 
        {    
            /*increment read every time it needs to read*/
            numReads++;

            /*page not in FIFO and FIFO not full*/
            if (FIFO_MAIN.size() < fifo_numOfFrames) 
            {
                //add page to back of FIFO
                FIFO_MAIN.push_back(inputVector[i]);
            }

            /*page not in FIFO and FIFO is full, LRU not full*/
            else if (FIFO_MAIN.size() == fifo_numOfFrames && LRU_SEC.size() < lru_numOfFrames) 
            {
                //move front of fifo to front of lru
                frontFifo_to_frontLru(FIFO_MAIN, LRU_SEC);
                //put the new page in FIFO
                FIFO_MAIN.push_back(inputVector[i]);
            }

            /*page is not in FIFO and not in LRU*/
            else if (FIFO_MAIN.size() == fifo_numOfFrames && LRU_SEC.size() == lru_numOfFrames) 
            {
                //eject oldest lru - from the back
                PageEntry temp = LRU_SEC.back();
                if (temp.getOperation() == 'W') {
                    numWrites++;
                   }
                LRU_SEC.pop_back();

                //move front of fifo to front of lru
                frontFifo_to_frontLru(FIFO_MAIN, LRU_SEC);
                //add new page to back of fifo
                FIFO_MAIN.push_back(inputVector[i]);
            }
        }
    }

    
    cout << "Total memory frames: " << numOfFrames << endl;
    cout << "Events in trace: " << inputVector.size() << endl;
    cout << "Total disk reads: " << numReads << endl;
    cout << "Total disk writes: " << numWrites << endl;
}


void frontFifo_to_frontLru(deque <PageEntry>& FIFO, deque <PageEntry>& LRU) {
    PageEntry vpee = FIFO.front();
    //eject from fifo
    FIFO.pop_front();
    //move to front of LRU
    LRU.push_front(vpee);
}