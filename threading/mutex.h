#ifndef THREADING_MUTEX_H_
#define THREADING_MUTEX_H_

#if defined(UNIX)
#include <pthread.h>
using mutex_type = pthread_mutex_t;
#elif defined(WIN32)
#include <Windows.h>
using mutex_type = HANDLE;
#endif

#include "build_required.h"

namespace threading {
class Mutex {
 public:
  Mutex();
  ~Mutex();

  DISALLOW_COPY_AND_ASSIGN(Mutex);
  DISALLOW_MOVE(Mutex);

  bool Lock();
  bool TryLock();
  bool Unlock();

 private:
  mutex_type m_mutex;

  bool m_bIsLocked = false;
};

class AutoMutex {
 public:
  AutoMutex(Mutex& mutex) : m_mutex(mutex) {
    m_mutex.Lock();
  }

  ~AutoMutex() {
    m_mutex.Unlock();
  }

  DISALLOW_COPY_AND_ASSIGN(AutoMutex);
  DISALLOW_MOVE(AutoMutex);
 private:
  Mutex& m_mutex;
};

} // namespace threading

#endif // THREADING_MUTEX_H_
