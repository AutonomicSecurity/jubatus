// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2014 Preferred Infrastracture and Nippon Telegraph and Telephone Corporation.
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

#include <gtest/gtest.h>
#include "jubatus/util/lang/shared_ptr.h"

#include "minhash.hpp"

namespace jubatus {
namespace core {
namespace recommender {

TEST(minhash, config_validation) {
  jubatus::util::lang::shared_ptr<minhash> r;
  minhash::config c;

  // 1 <= hash_num
  c.hash_num = 0;
  ASSERT_THROW(r.reset(new minhash(c)), common::invalid_parameter);
  c.hash_num = 1;
  ASSERT_NO_THROW(r.reset(new minhash(c)));
  c.hash_num = 2;
  ASSERT_NO_THROW(r.reset(new minhash(c)));
}

}  // namespace recommender
}  // namespace core
}  // namespace jubatus
