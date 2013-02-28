#ifndef CMYTHREAD_H
#define CMYTHREAD_H

#include "CThread.h"
#include "CMutex.h"

class CMyThread : public Threads::CThread {
 public:
  CMyThread(CMutex* mutex) { m_mutex = mutex; }

  void ThreadMain();

 private:
  CMutex* m_mutex;
};

class COtherThread : public Threads::CThread {
 public:
  COtherThread() {}
  void ThreadMain();
};

#endif // CMYTHREAD_H
