#ifndef CTHREAD_H_
#define CTHREAD_H_

#include <pthread.h>
#include <unistd.h>

#include "build_required.h"

namespace Threads {

class CThread {
 public:
  CThread() {}
  virtual ~CThread() {}
  DISALLOW_COPY_AND_ASSIGN(CThread);

  // The "main" function of a thread
  virtual void ThreadMain() = 0;

  bool CreateThread();
  static bool JoinThread(CThread& thread);
  static void Sleep(long milisec);
  static unsigned long int GetTID();

 private:

  // NOTE: Tricky usage of |static|
  // If not static, this function is not allowed to be called
  // In pthread_create(). Probably because |this| is passed into a
  // non-static class member function, but not into static one
  static void* Internal(void* thread);

  pthread_t m_thread;
};

} // namespace Threads

#endif // CTHREAD_H
