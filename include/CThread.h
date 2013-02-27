#ifndef CTHREAD_H
#define CTHREAD_H

// TODO (Olster): Add support for detached threads and
// I forgot... but it's something important

#include <pthread.h>
#include <unistd.h>

#include "../build_required.h"

namespace Threading {

class CThread {
 public:
  CThread() {};
  virtual ~CThread() {};

  // The "main" function of a thread
  virtual void ThreadMain() = 0;

  bool Create();
  bool Join();

 protected:
  void Sleep(long milisec);
 private:
  friend bool CreateThread(CThread* thread);

  pthread_t m_thread;

  DISALLOW_COPY_AND_ASSIGN(CThread);
};

} // namespace Threading

#endif // CTHREAD_H
