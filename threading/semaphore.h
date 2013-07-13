#ifndef THREADING_SEMAPHORE_H_
#define THREADING_SEMAPHORE_H_

#include <semaphore.h>
#include "build_required.h"

namespace threading {
class Semaphore {
 public:
  Semaphore(int initial = 0, int max = 100);
  ~Semaphore();
  DISALLOW_COPY_AND_ASSIGN(Semaphore);
  DISALLOW_MOVE(Semaphore);

  void Post();
  void Wait();

  int GetValue();
 private:
  sem_t m_semaphore;

  // Maximum threads waiting at semaphore
  int m_nMaxAquired;
  int m_nCurrent = 0;
};

} // namespace threading
#endif // THREADING_SEMAPHORE_H_
