#include "CMutex.h"

CMutex::CMutex() {
  m_bIsLocked = false;
  pthread_mutex_init(&m_mutex, 0);
}

CMutex::~CMutex() {
  // Not sure if I should really unlock it before destroying
  if (m_bIsLocked) {
    Unlock();
  }

  pthread_mutex_destroy(&m_mutex);
}

bool CMutex::Lock() {
  m_bIsLocked = pthread_mutex_lock(&m_mutex) == 0;
  return m_bIsLocked;
}

bool CMutex::TryLock() {
  return pthread_mutex_trylock(&m_mutex) == 0;
}

bool CMutex::Unlock() {
  m_bIsLocked = pthread_mutex_unlock(&m_mutex) == 0;
  return m_bIsLocked;
}

