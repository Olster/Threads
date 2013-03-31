#include <iostream>

#include "CMyThread.h"

using namespace std;

int main() {
  CMyThread thread1;
  CMyThread thread2;

  thread1.CreateThread();
  thread2.CreateThread();

  Threads::CThread::JoinThread(thread1);
  Threads::CThread::JoinThread(thread2);

  return 0;
}
