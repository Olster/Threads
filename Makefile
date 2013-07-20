CXX = g++

src_path = .
abs_src_path = $(abspath $(src_path))

exe_name = Threading

cxx_flags = -std=c++11 -Wall -Wextra

windows:
	$(CXX)  -I. $(cxx_flags) -DWIN32 -DDEBUG threading/thread_win.cpp threading/mutex_win.cpp threading/semaphore_win.cpp main.cpp -o $(exe_name).exe
	
unix:
	$(CXX)  -I. $(cxx_flags) -DWIN32 -DDEBUG threading/thread_unix.cpp threading/mutex_unix.cpp threading/semaphore_unix.cpp main.cpp -o $(exe_name)