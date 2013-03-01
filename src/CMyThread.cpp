#include "CMyThread.h"

#include <iostream>

CReader::CReader(std::queue<std::string>* queue, CMutex* mutex, CSemaphore* sem) {
  m_mutex = mutex;
  m_sem = sem;

  m_data = queue;
}

CWriter::CWriter(std::queue<std::string>* queue, CMutex* mutex, CSemaphore* sem) {
  m_mutex = mutex;
  m_sem = sem;

  m_data = queue;
}

void CReader::ThreadMain() {
  while (true) {
    m_mutex->Lock();

    m_data->push("A really interesting message");

    m_mutex->Unlock();
    m_sem->Post();
  }
}

void CWriter::ThreadMain() {
  while (true) {
    m_sem->Wait();
    m_mutex->Lock();

    while (!m_data->empty()) {
      std::cout << m_data->front() << std::endl;
      m_data->pop();
    }

    m_mutex->Unlock();
  }
}
