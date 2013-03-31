#include "CSemaphore.h"

namespace Threads {

CSemaphore::CSemaphore(int initial, int max) {
  sem_init(&m_semaphore, 0, initial);
  m_nMaxAquired = max;
}

CSemaphore::~CSemaphore() {
  sem_destroy(&m_semaphore);
}

void CSemaphore::Post() {
  sem_post(&m_semaphore);
  m_nCurrent--;
}

void CSemaphore::Wait() {
  sem_wait(&m_semaphore);
  m_nCurrent++;
}

int CSemaphore::GetValue() {
  sem_getvalue(&m_semaphore, &m_nCurrent);
  return m_nCurrent;
}

} // namespace Threads
