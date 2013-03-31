#ifndef CMUTEX_H
#define CMUTEX_H

#include <pthread.h>
#include "build_required.h"

namespace Threads {

class CMutex {
 public:
  CMutex();
  ~CMutex();
  DISALLOW_COPY_AND_ASSIGN(CMutex);

  bool Lock();
  bool TryLock();
  bool Unlock();

 private:
  pthread_mutex_t m_mutex;

  bool m_bIsLocked;
};

class CAutoMutex {
 public:
  CAutoMutex(CMutex& mutex) : m_mutex(mutex) {
    m_mutex.Lock();
  }

  ~CAutoMutex() {
    m_mutex.Unlock();
  }

  DISALLOW_COPY_AND_ASSIGN(CAutoMutex);
 private:
  CMutex& m_mutex;
};

} // namespace Threads

#endif // CMUTEX_H
