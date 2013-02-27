#include "CThread.h"

namespace Threading {

void* internal(void* data) {
  CThread* thread = (CThread*)(data);
  thread->ThreadMain();
  pthread_exit(0);
}

bool CreateThread(CThread* thread) {
  return (pthread_create(&thread->m_thread, 0, internal, thread) == 0);
}

bool CThread::Create() {

  return CreateThread(this);
}

bool CThread::Join() {
  return (pthread_join(m_thread, 0) == 0);
}

void CThread::Sleep(long milisec) {

  if (milisec < 0) {
    return;
  }

  timespec time;
  time.tv_sec = 0;
  time.tv_nsec = milisec * 1000000L;

  timespec remain = time;

  while (nanosleep(&time, &remain) == -1) {
    time = remain;
  }
}

} // namespace Threading

