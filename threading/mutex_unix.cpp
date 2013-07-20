#include "threading/mutex.h"

namespace threading {

Mutex::Mutex() {
  pthread_mutex_init(&m_mutex, 0);
}

Mutex::~Mutex() {
  // NOTE: Not sure if I should really unlock it before destroying
  if (m_bIsLocked) {
    Unlock();
  }

  pthread_mutex_destroy(&m_mutex);
}

bool Mutex::Lock() {
  m_bIsLocked = pthread_mutex_lock(&m_mutex) == 0;
  return m_bIsLocked;
}

bool Mutex::TryLock() {
  return pthread_mutex_trylock(&m_mutex) == 0;
}

bool Mutex::Unlock() {
  m_bIsLocked = pthread_mutex_unlock(&m_mutex) == 0;
  return m_bIsLocked;
}

} // namespace threading
