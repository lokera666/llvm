#pragma once
#include <string>
#include <set>
#include <memory>

namespace eosio { namespace cdt {
   // singleton to allow clang to communicate with llvm easier
   class autogen {
      public:
         ~autogen() {}
         static inline autogen& get() {
            static autogen instance;
            return instance;
         }
         inline void add_action(const std::string& name) {
            actions.insert(name);
         }
         inline std::set<std::string>& get_actions() { return actions; } 
      private:
         autogen() {}
         std::set<std::string> actions;
   };
}} // ns eosio::cdt
