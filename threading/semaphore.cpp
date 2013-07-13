#include "threading/semaphore.h"

namespace threading {
Semaphore::Semaphore(int initial, int max) {
  sem_init(&m_semaphore, 0, initial);
  m_nMaxAquired = max;
}

Semaphore::~Semaphore() {
  sem_destroy(&m_semaphore);
}

void Semaphore::Post() {
  sem_post(&m_semaphore);
  m_nCurrent--;
}

void Semaphore::Wait() {
  sem_wait(&m_semaphore);
  m_nCurrent++;
}

int Semaphore::GetValue() {
  sem_getvalue(&m_semaphore, &m_nCurrent);
  return m_nCurrent;
}
} // namespace threading
