#include <iostream>

#include "CMyThread.h"

using namespace std;

int main() {

  CMyThread thread;
  thread.Create();

  thread.Join();
  return 0;
}
