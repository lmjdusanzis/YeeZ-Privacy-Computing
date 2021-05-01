#pragma once
#include "ypc/byte.h"
#include <ff/util/ntobject.h>
#include <string>
#include <unordered_map>

define_nt(data_hash, ypc::bytes);
define_nt(provider_pub_key, ypc::bytes);

typedef ff::util::ntobject<data_hash, provider_pub_key> onchain_data_meta_t;

class onchain_data_reader {
public:
  virtual ~onchain_data_reader();

  virtual void init() = 0;

  inline const std::vector<onchain_data_meta_t> &all_onchain_data() const {
    return m_all_data;
  }

  const onchain_data_meta_t &get_data_with_hash(const ypc::bytes &hash);

protected:
  std::vector<onchain_data_meta_t> m_all_data;
  std::unordered_map<ypc::bytes, size_t> m_data_index;
};

class dummy_onchain_data_reader : public onchain_data_reader {
public:
  dummy_onchain_data_reader(const std::string &path);

  virtual void init();

protected:
  std::string m_sample_path;
};

