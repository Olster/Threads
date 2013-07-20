#include "threading/thread.h"

namespace threading {
Thread::~Thread() {
}

bool Thread::CreateThread() {
  return pthread_create(&m_thread, 0, Internal, this) == 0;
}

// static
bool Thread::JoinThread(Thread& thread) {
  return (pthread_join(thread.m_thread, 0) == 0);
}

// static
void Thread::Sleep(long millisec) {
  if (milisec < 0) {
    return;
  }

  timespec time;
  time.tv_sec = 0;

  // Nanoseconds to miliseconds
  time.tv_nsec = milisec * 1000000L;

  timespec remain = time;

  while (nanosleep(&time, &remain) == -1) {
    time = remain;
  }
}

// static
unsigned long int Thread::GetThreadID() {
  return pthread_self();
}

void* Thread::Internal(void* data) {
  Thread* thread = (Thread*)(data);
  thread->ThreadMain();
  pthread_exit(0);
}

} // namespace threading

