// This file is auto-generated from regression.idl(0.4.5-347-g86989a6) with jenerator version 0.5.2-17-g8a5dca4/develop
// *** DO NOT EDIT ***

#ifndef JUBATUS_SERVER_SERVER_REGRESSION_TYPES_HPP_
#define JUBATUS_SERVER_SERVER_REGRESSION_TYPES_HPP_

#include <stdint.h>

#include <map>
#include <string>
#include <vector>
#include <utility>

#include "jubatus/core/fv_converter/datum.hpp"
#include <msgpack.hpp>

namespace jubatus {

struct scored_datum {
 public:
  MSGPACK_DEFINE(score, data);
  float score;
  jubatus::core::fv_converter::datum data;
  scored_datum() {
  }
  scored_datum(float score, const jubatus::core::fv_converter::datum& data)
    : score(score), data(data) {
  }
};

}  // namespace jubatus

#endif  // JUBATUS_SERVER_SERVER_REGRESSION_TYPES_HPP_
