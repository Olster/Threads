#include "CMyThread.h"

#include <iostream>

void CMyThread::ThreadMain() {
  for (int i = 0; i < 100; i++) {
    m_mutex->Lock();
    std::cout << "Hello " << i << std::endl;
    m_mutex->Unlock();
    Sleep(100);
  }
}

void COtherThread::ThreadMain() {
  for (int i = 0; i < 200; i++) {
    std::cout << "Hello from another thread" << i << std::endl;
    Sleep(200);
  }
}
