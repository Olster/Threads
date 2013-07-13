#include <iostream>
#include "threading/thread.h"

using namespace std;

class FooThread : public threading::Thread {
 private:
  void ThreadMain() override;
};

void FooThread::ThreadMain() {
  for (int i = 0; i < 5; i++) {
    cout << "Running thread " << threading::Thread::GetThreadID() << endl;
  }
}

int main() {
  FooThread thread1;
  FooThread thread2;

  thread1.CreateThread();
  thread2.CreateThread();

  threading::Thread::JoinThread(thread1);
  threading::Thread::JoinThread(thread2);

  return 0;
}
