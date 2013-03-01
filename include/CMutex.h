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

#endif // CMUTEX_H
