#include "threading/thread.h"

namespace threading {
Thread::~Thread() {
  ::CloseHandle(m_thread);
}

bool Thread::CreateThread() {
  m_thread = ::CreateThread(nullptr, 0, Internal, this, 0, nullptr);
  return m_thread != nullptr;
}

// static
bool Thread::JoinThread(Thread& thread) {
  DWORD err = WaitForSingleObject(thread.m_thread, INFINITE);
  return err == WAIT_OBJECT_0;
}

// static
void Thread::Sleep(long millisec) {
  ::Sleep(millisec);
}

// static
unsigned long int Thread::GetThreadID() {
  return ::GetCurrentThreadId();
}

DWORD WINAPI Thread::Internal(LPVOID data) {
  Thread* thread = (Thread*)(data);
  thread->ThreadMain();
  
  return 0;
}

} // namespace threading

