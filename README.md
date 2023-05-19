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
To run the program: <br/>
1. For FIFO and LRU use this format: <br/>
“./memsim tracefile nFrames policy quiet/debug” if on the student cluster or  <br/>
“.\memsim tracefile nFrames policy quiet/debug” if not on the student cluster <br/>
2. For Segmented FIFO (vms) use this format: <br/>
“./memsim tracefile nFrames policy percentage quiet/debug” if on the student cluster or <br/>
“.\memsim tracefile nFrames policy quiet/debug” if not on the student cluster <br/>
<br/>
<br/>
Explanation of terminal inputs: <br/>
● tracefile: Name of the tracefile (bzip.trace or sixpack.trace for example) <br/>
● nFrames: Number of frames to use <br/>
● policy: fifo, lru, or vms<br/>
● percentage: If using vms, this is the percentage between 1 and 100<br/>
● quiet: Will only print statistics at the end<br/>
● debug: Will print information for every event that happens.<br/>
<br/>
<br/>
Running Examples:<br/>
./memsim bzip.trace 64 fifo quiet<br/>
Total memory frames: 64<br/>
Events in trace: 1000000<br/>
Total disk reads: 1467<br/>
Total disk writes: 514<br/>
FIFO took 518.011ms<br/>
./memsim bzip.trace 64 vms 25 quiet<br/>
Total memory frames: 64<br/>
Events in trace: 1000000<br/>
Total disk reads: 1367<br/>
Total disk writes: 471<br/>
SFIFO took 1107.97ms<br/>
./memsim bzip.trace 64 lru quiet<br/>
Total memory frames: 64<br/>
Events in trace: 1000000<br/>
Total disk reads: 1264<br/>
Total disk writes: 420<br/>
LRU took 1636.02ms<br/>
