#ifndef CMYTHREAD_H_
#define CMYTHREAD_H_

#include "CThread.h"
#include "CMutex.h"
#include "build_required.h"


class CMyThread : public Threads::CThread {
 public:
  CMyThread() = default;
  DISALLOW_COPY_AND_ASSIGN(CMyThread);

  void ThreadMain();
};

#endif // CMYTHREAD_H_
