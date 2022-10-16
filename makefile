# Use "make memsim" or "mingw32-make memsim" in the terminal to use the makefile
# If on Windows, run "nmake"

# If running on the student cluster (uncomment this)
memsim: memsim.cpp fifo.cpp lru.cpp vms.cpp
	g++ -std=c++11 memsim.cpp fifo.cpp lru.cpp vms.cpp -o memsim

# If not on the student cluster (uncomment this)
#memsim: memsim.cpp fifo.cpp lru.cpp vms.cpp policies.h
#	g++ memsim.cpp fifo.cpp lru.cpp vms.cpp -o memsim

# Use "./memsim (or .\memsim) <tracefile> <nframes> <lru|fifo|vms> (<p> if vms) <debug|quiet>" to run the files