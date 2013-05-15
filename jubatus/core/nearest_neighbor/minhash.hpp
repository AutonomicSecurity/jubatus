// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012 Preferred Infrastracture and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_NEAREST_NEIGHBOR_MINHASH_HPP_
#define JUBATUS_CORE_NEAREST_NEIGHBOR_MINHASH_HPP_

#include <map>
#include <string>
#include <vector>
#include "bit_vector_nearest_neighbor_base.hpp"

namespace jubatus {
namespace core {
namespace nearest_neighbor {

class minhash : public bit_vector_nearest_neighbor_base {
 public:
  struct config {
    config()
      : bitnum(64u) {
    }

    int32_t bitnum;

    template <typename Ar>
    void serialize(Ar& ar) {
      ar & MEMBER(bitnum);
    }
  };

  minhash(
      const config& conf,
      table::column_table* table,
      const std::string& id);
  minhash(
      const config& conf,
      table::column_table* table,
      std::vector<table::column_type>& schema,
      const std::string& id);

  virtual std::string type() const {
    return "minhash";
  }

 protected:
  virtual table::bit_vector hash(const sfv_t& sfv) const;
};

}  // namespace nearest_neighbor
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_NEAREST_NEIGHBOR_MINHASH_HPP_
