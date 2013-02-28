#ifndef CMUTEX_H
#define CMUTEX_H

#include <pthread.h>

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
};

#endif // CMUTEX_H
