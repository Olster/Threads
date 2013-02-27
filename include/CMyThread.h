#ifndef CMYTHREAD_H
#define CMYTHREAD_H

#include "CThread.h"

class CMyThread : public Threading::CThread {
 public:
  CMyThread() {};

  void ThreadMain();
};

#endif // CMYTHREAD_H
