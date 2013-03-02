#ifndef CMUTEX_H
#define CMUTEX_H

#include <pthread.h>
#include "../build_required.h"

// TODO (Olster): Add automatic mutex that locks
// in its scope

class CMutex {
 public:
  CMutex();
  ~CMutex();

  bool Lock();
  bool TryLock();
  bool Unlock();

 private:
  pthread_mutex_t m_mutex;

  bool m_bIsLocked;

  DISALLOW_COPY_AND_ASSIGN(CMutex);
};

class CAutoMutex {
 public:
  CAutoMutex() { m_mutex.Lock(); }
  ~CAutoMutex() { m_mutex.Unlock(); }
 private:
  CMutex m_mutex;
  DISALLOW_COPY_AND_ASSIGN(CAutoMutex);
};

#endif // CMUTEX_H
