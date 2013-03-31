#include "CMyThread.h"

#include <iostream>

void CMyThread::ThreadMain() {
  for (int i = 0; i < 10; i++) {
    std::cout << "My thread ID is: " << Threads::CThread::GetTID() << std::endl;
    Threads::CThread::Sleep(0);
  }
}
