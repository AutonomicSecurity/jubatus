// This file is auto-generated from clustering.idl(0.5.3-20-gc68eb49) with jenerator version 0.5.2-45-gc4cfc98/implement-clear
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <glog/logging.h>

#include "jubatus/core/common/exception.hpp"
#include "../../server/framework/aggregators.hpp"
#include "../../server/framework/proxy.hpp"
#include "clustering_types.hpp"

namespace jubatus {

int run_proxy(int argc, char* argv[]) {
  try {
    jubatus::server::framework::proxy k(
        jubatus::server::framework::proxy_argv(argc, argv, "clustering"));
    k.register_async_random<bool,
        std::vector<jubatus::core::fv_converter::datum> >("push");
    k.register_async_random<uint32_t>("get_revision");
    k.register_async_random<std::vector<std::vector<std::pair<double,
        jubatus::core::fv_converter::datum> > > >("get_core_members");
    k.register_async_random<std::vector<jubatus::core::fv_converter::datum> >(
        "get_k_center");
    k.register_async_random<jubatus::core::fv_converter::datum,
        jubatus::core::fv_converter::datum>("get_nearest_center");
    k.register_async_random<std::vector<std::pair<double,
        jubatus::core::fv_converter::datum> >,
        jubatus::core::fv_converter::datum>("get_nearest_members");
    k.register_async_broadcast<bool>("clear",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  jubatus::run_proxy(argc, argv);
}
