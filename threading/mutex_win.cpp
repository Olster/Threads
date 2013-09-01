#include "threading/mutex.h"

namespace threading {

Mutex::Mutex() {
  m_mutex = ::CreateMutex(nullptr, FALSE, nullptr);
}

Mutex::~Mutex() {
  // NOTE: Not sure if I should really unlock it before destroying
  if (m_bIsLocked) {
    Unlock();
  }

  ::CloseHandle(m_mutex);
}

bool Mutex::Lock() {
  DWORD err = WaitForSingleObject(m_mutex, INFINITE);
  m_bIsLocked = err != WAIT_OBJECT_0;
  return !m_bIsLocked;
}

bool Mutex::TryLock() {
  return Lock();
}

bool Mutex::Unlock() {
  m_bIsLocked = ::ReleaseMutex(m_mutex) == FALSE;
  return m_bIsLocked;
}

} // namespace threading
