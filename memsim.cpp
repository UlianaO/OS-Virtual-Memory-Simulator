// Main interface of the simulator, it takes user input in two forms

#include "policies.h"
#include "dataStructures.h"

    int numOfFrames;
    std::string algorithm;
    std::string mode;
    std::string filePath;
    vector<PageEntry> inputVector;  // Will store all of the adresses and r/w in vector (using PageEntry class) which were taken from the input file

    std::string makeLowerCase(std::string str);


    void fifo();
    void lru();
    void vms();

// ULIANA CHECKKKKKKKKKKK

int main(int argc, char* argv[]) {
	std::cout << "Hello" << std::endl;

    // the input in the format: memsim <tracefile> <nframes> <lru|fifo|vms> <debug|quiet> 
    if (argc >= 5) {
        filePath = makeLowerCase(argv[1]);
        numOfFrames = stoi(argv[2]);
        algorithm = makeLowerCase(argv[3]);
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

    // Perform the appropriate algorithm
    if (algorithm == "fifo") {
        std::cout << "Hello from fifo" << std::endl;
        fifo();
    }
    else if (algorithm == "lru")
        lru();
    else if (algorithm == "vms")
        vms();
    else
    {
        cout << "Invalid algorithm." << endl;
        return 1;
    }


    // Close files
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
