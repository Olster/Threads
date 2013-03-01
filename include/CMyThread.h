#ifndef CMYTHREAD_H
#define CMYTHREAD_H

#include <queue>
#include <string>

#include "CThread.h"
#include "CMutex.h"
#include "CSemaphore.h"

class CReader : public Threads::CThread {
 public:
  CReader(std::queue<std::string>* queue, CMutex* mutex, CSemaphore* sem);
  void ThreadMain();
 private:
  CMutex* m_mutex;
  CSemaphore* m_sem;

  std::queue<std::string>* m_data;
};

class CWriter : public Threads::CThread {
 public:
  CWriter(std::queue<std::string>* queue, CMutex* mutex, CSemaphore* sem);
  void ThreadMain();
 private:
  CMutex* m_mutex;
  CSemaphore* m_sem;

  std::queue<std::string>* m_data;
};

#endif // CMYTHREAD_H
