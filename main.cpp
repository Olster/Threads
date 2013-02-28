#include <iostream>

#include "CMyThread.h"

using namespace std;

int main() {

  CMyThread thread;
  COtherThread otherThread;

  otherThread.Create();
  thread.Create();

  thread.Join();
  otherThread.Join();
  return 0;
}
