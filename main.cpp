#include <iostream>

#include "CMyThread.h"

using namespace std;

int main() {

  CMutex mutex;

  CMyThread thread(&mutex);
  CMyThread thread2(&mutex);
  thread.Create();
  thread2.Create();

  thread.Join();
  thread2.Join();
  return 0;
}
