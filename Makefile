CXX = g++

module_name = Threading
debug_dir = ./bin/Debug

cxx_flags = -std=c++11 -Wall -Wextra -Weffc++

win_sources = threading/thread_win.cpp\
              threading/mutex_win.cpp\
              threading/semaphore_win.cpp
              
unix_sources = threading/thread_unix.cpp\
               threading/mutex_unix.cpp\
               threading/semaphore_unix.cpp              

all:
	@echo Target must be either "windows" or "unix"

windows:
	$(CXX) -I. $(cxx_flags) -DWIN32 -DDEBUG $(win_sources) main.cpp -o $(debug_dir)/$(module_name).exe
	
unix:
	$(CXX) -I. $(cxx_flags) -DUNIX -DDEBUG $(unix_sources) main.cpp -lpthread -o $(debug_dir)/$(module_name)
