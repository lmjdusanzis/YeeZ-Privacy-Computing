#pragma once
#include <cassert>
#include <memory>

namespace ypc {
class memref {
public:
  inline memref() : m_data(nullptr), m_len(0){};
  inline size_t &size() { return m_len; }
  inline const size_t &size() const { return m_len; }
  inline uint8_t *data() { return m_data; }
  inline const uint8_t *data() const { return m_data; }

  inline void alloc(size_t s) {
    assert(!m_data);
    m_data = new uint8_t[s];
    m_len = s;
  }
  inline void dealloc() {
    if (m_data) {
      delete[] m_data;
      m_data = nullptr;
      m_len = 0;
    }
  }

private:
  uint8_t *m_data;
  size_t m_len;
};
} // namespace ypc
