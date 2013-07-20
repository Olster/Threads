#ifndef THREADING_THREAD_H_
#define THREADING_THREAD_H_

#ifdef UNIX
#include <pthread.h>
#include <unistd.h>
using thread_handle = pthread_t;
#elif defined(WIN32)
#include <Windows.h>
using thread_handle = HANDLE;
#endif

#include "build_required.h"

namespace threading {
class Thread {
 public:
  Thread() {}
  virtual ~Thread();
  DISALLOW_COPY_AND_ASSIGN(Thread);
  DISALLOW_MOVE(Thread);

  bool CreateThread();

  static bool JoinThread(Thread& thread);
  static void Sleep(long millisec);
  static unsigned long int GetThreadID();
 private:
  // The "main" function of a thread
  virtual void ThreadMain() = 0;

  // NOTE: Tricky usage of |static|
  // If not static, this function is not allowed to be called
  // In pthread_create(). Probably because |this| is passed into a
  // non-static class member function, but not into static one
#ifdef UNIX
  static void* Internal(void* thread);
#elif defined(WIN32)
  static DWORD WINAPI Internal(LPVOID thread);
#endif

  thread_handle m_thread;
};

} // namespace threading

#endif // THREADING_THREAD_H_
