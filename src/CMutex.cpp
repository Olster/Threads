#include "CMutex.h"

CMutex::CMutex() {
  m_bIsLocked = false;
  pthread_mutex_init(&m_mutex, 0);
}

CMutex::~CMutex() {
  if (m_bIsLocked) {
    Unlock();
  }

  pthread_mutex_destroy(&m_mutex);
}

bool CMutex::Lock() {
  return pthread_mutex_lock(&m_mutex) == 0;
}

bool CMutex::TryLock() {
  return pthread_mutex_trylock(&m_mutex) == 0;
}

bool CMutex::Unlock() {
  return pthread_mutex_unlock(&m_mutex) == 0;
}

