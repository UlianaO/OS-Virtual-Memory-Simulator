// File that implements segmented-fifo polciy 
#include "policies.h"
#include "dataStructures.h"

extern vector<PageEntry> inputVector;
extern int numOfFrames;
extern int p;

void vms()
{
    PageEntry pe();
    vector<PageEntry> FIFO_MAIN;
    vector<PageEntry> LRU_SEC;
    int numReads = 0;
    int numWrites = 0;
    int lru_size = (numOfFrames * p) / 100;
    int fifo_size = numOfFrames - lru_size;

    cout << "VMS" << endl;

    for (int i = 0; i < inputVector.size(); i++)
    {
        auto indexFound = find(FIFO_MAIN.begin(), FIFO_MAIN.end(), inputVector[i]);
        int index = distance(FIFO_MAIN.begin(), indexFound);

        /*page is in FIFO*/
        if (indexFound != FIFO_MAIN.end())
        {
            //update W bit            
            if (inputVector[i].getOperation() == 'W')  {
                FIFO_MAIN[index].setOperation('W');
            }
        }
        //page is not in fifo 
        else 
        {    
            /*page not in FIFO and FIFO not full*/
            if (FIFO_MAIN.size() < numOfFrames) {
                //add page to back of FIFO
                FIFO_MAIN.push_back(inputVector[i]);
            }
        }

   /*page not in FIFO and FIFO is full, LRU not full*/
   //eject from fifo
   //move to lru, making it the newest

   /*page is not in FIFO and not in LRU*/
   //eject oldest lru
   //move front of fifo to lru
   //add new page to back of fifo

       /*page is in LRU(Fifo full)*/
   //update W
   //move to back to FIFO
   //move front of fifo to lru making it the newest page
    }


}

// NECESSARY HELPER FUNCTIONS FOR VMS
//add page to back of fifo
//move front fifo to lru