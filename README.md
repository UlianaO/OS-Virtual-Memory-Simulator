# OS_Project2

For this project, the FIFO, LRU, and the Segmented FIFO policies were implemented. <br/>
Trace files such as bzip.trace and sixpack.trace, which are real recordings of a running program, were used in our simulation. <br/>
<br/>
Files necessary to compile the program:<br/>
● memsim.cpp: The main interface of the simulator, takes inputs from the terminal and the
trace files <br/>
● fifo.cpp: File that implements the First-In-First-Out policy <br/>
● lru.cpp: File that implements the Least Recently Used policy <br/>
● vms.cpp: File that implements the Segmented FIFO policy <br/>
● makefile: The makefile which compiles all of these files. The makefile target is called
memsim <br/>
● policies.h: File which includes the policies and the PageEntry class which stores
information for each entry <br/>
● bzip.trace: Trace file to be tested <br/>
● sixpack.trace: Trace file to be tested <br/>
<br/>
<br/>
To compile the program:<br/>
1. Use “make memsim” to compile all of the files using the makefile, if it is compiled on the
student cluster. Else, use “mingw32-make memsim” or “nmake memsim” to compile
them. <br/>
2. Use “g++ -std=c++11 memsim.cpp fifo.cpp lru.cpp vms.cpp -o memsim” if compiling on
the cluster. Else, use “g++ memsim.cpp fifo.cpp lru.cpp vms.cpp -o memsim” to compile
them. <br/>
<br/>
<br/>
To run the program:
1. For FIFO and LRU use this format:
“./memsim tracefile nFrames policy quiet/debug” if on the student cluster or “.\memsim
tracefile nFrames policy quiet/debug” if not on the student cluster
2. For Segmented FIFO (vms) use this format:
“./memsim tracefile nFrames policy percentage quiet/debug” if on the student cluster or
“.\memsim tracefile nFrames policy quiet/debug” if not on the student cluster


Explanation of terminal inputs:
● tracefile: Name of the tracefile (bzip.trace or sixpack.trace for example)
● nFrames: Number of frames to use
● policy: fifo, lru, or vms
● percentage: If using vms, this is the percentage between 1 and 100
● quiet: Will only print statistics at the end
● debug: Will print information for every event that happens.


Running Examples:
./memsim bzip.trace 64 fifo quiet
Total memory frames: 64
Events in trace: 1000000
Total disk reads: 1467
Total disk writes: 514
FIFO took 518.011ms
./memsim bzip.trace 64 vms 25 quiet
Total memory frames: 64
Events in trace: 1000000
Total disk reads: 1367
Total disk writes: 471
SFIFO took 1107.97ms
./memsim bzip.trace 64 lru quiet
Total memory frames: 64
Events in trace: 1000000
Total disk reads: 1264
Total disk writes: 420
LRU took 1636.02ms
