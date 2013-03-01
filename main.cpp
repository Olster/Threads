#include <iostream>

#include "CMyThread.h"

using namespace std;

int main() {
  CMutex mutex;
  CSemaphore sem;
  std::queue<std::string> data;

  CReader thread(&data, &mutex, &sem);
  CWriter thread2(&data, &mutex, &sem);

  thread.Create();
  thread2.Create();

  thread.Join();
  thread2.Join();
  return 0;
}
