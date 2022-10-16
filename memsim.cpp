// Main interface of the simulator, it takes user input in two forms

#include "policies.h"
#include "dataStructures.h"
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>

    int numOfFrames;
    std::string algorithm;
    std::string mode;
    std::string filePath;
    int p;
    vector<PageEntry> inputVector;  // Will store all of the adresses and r/w in vector (using PageEntry class) which were taken from the input file

    std::string makeLowerCase(std::string str);


    void fifo();
    void lru();
    void segfifo();

// ULIANA CHECKKKKKKKKKKK

int main(int argc, char* argv[]) {

    // the input in the format: memsim <tracefile> <nframes> <lru|fifo|vms> <debug|quiet> 
   if (argc >= 5) {
        filePath = makeLowerCase(argv[1]);
        numOfFrames = stoi(argv[2]);
        algorithm = makeLowerCase(argv[3]);
        if (algorithm == "vms") {
            p = stoi(argv[4]);
            mode = makeLowerCase(argv[5]);
        }
        else
            mode = makeLowerCase(argv[4]);
    } 

    // Check if file is in directory
    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile)
    {
        cout << "File not found" << endl;
        return 1;
    }

    // Get inputs from file and store them
    unsigned addr;
    char rw;
    FILE *file = fopen(argv[1], "r");
    while(fscanf(file, "%x %c", &addr, &rw) != EOF)
    {
        // Store info (create objects)
        PageEntry pe(addr, rw);     
        inputVector.push_back(pe);  // Store adress and r/w
    }

    cout << "Done reading file" << endl;
    std::chrono::duration<double, std::milli> duration;


    if (mode == "debug")
        cout << "Done reading file." << endl;

    // Perform algorithm mentioned
    if (algorithm == "fifo") {
        std::cout << "Hello from fifo" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        fifo();
        auto stop = std::chrono::high_resolution_clock::now();
        duration = stop - start;
        std::cout << "FIFO took " << duration.count() << "ms" << std::endl;
    }
    else if (algorithm == "lru") {
        auto start = std::chrono::high_resolution_clock::now();
        lru();
        auto stop = std::chrono::high_resolution_clock::now();
        duration = stop - start;
        std::cout << "LRU took " << duration.count() << "ms" << std::endl;
    }
    else if (algorithm == "vms") {
        auto start = std::chrono::high_resolution_clock::now();
        segfifo();
        auto stop = std::chrono::high_resolution_clock::now();
        duration = stop - start;
        std::cout << "SFIFO took " << duration.count() << "ms" << std::endl;
    }
    else
    {
        cout << "Invalid algorithm." << endl;
        return 1;
    }


    //Close files
    inFile.close();
    fclose(file);
	return 0;
}

std::string makeLowerCase(std::string str) {

    std::string str_new = "";
    char ch;
    for (int i = 0; i < str.length(); i++) {
        ch = tolower(str[i]);
        str_new = str_new + ch;
    }

    return str_new;
}
