#include "CMyThread.h"

#include <iostream>

void CMyThread::ThreadMain() {
  for (int i = 0; i < 100; i++) {
    std::cout << "Hello " << i << std::endl;
    Sleep(100);
  }
}
