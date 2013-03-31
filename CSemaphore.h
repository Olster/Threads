#ifndef CSEMAPHORE_H_
#define CSEMAPHORE_H_

#include <semaphore.h>
#include "build_required.h"

namespace Threads {

class CSemaphore {
 public:
  CSemaphore(int initial = 0, int max = 100);
  ~CSemaphore();
  DISALLOW_COPY_AND_ASSIGN(CSemaphore);

  void Post();
  void Wait();

  int GetValue();

 private:
  sem_t m_semaphore;

  // Maximum threads waiting at semaphore
  int m_nMaxAquired;
  int m_nCurrent;
};

} // namespace Threads
#endif // CSEMAPHORE_H
