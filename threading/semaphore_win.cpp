#include "threading/semaphore.h"

namespace threading {
Semaphore::Semaphore(int initial, int max) {
  m_semaphore = ::CreateSemaphore(nullptr, initial, max, nullptr);
  m_nMaxAquired = max;
}

Semaphore::~Semaphore() {
  ::CloseHandle(m_semaphore);
}

void Semaphore::Post() {
  ::ReleaseSemaphore(m_semaphore, 1, nullptr);
  m_nCurrent--;
}

void Semaphore::Wait() {
  ::WaitForSingleObject(m_semaphore,INFINITE);
  m_nCurrent++;
}

int Semaphore::GetValue() {
  return m_nCurrent;
}
} // namespace threading
