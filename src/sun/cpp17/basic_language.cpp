#include "basic_language.hpp"

#include <iostream>
#include <string>

namespace sun {

void BasicLanguage::Test() {
  TestStructBind();
}

void BasicLanguage::TestStructBind() {
  std::cout << __func__ << std::endl;
  struct MyStruct {
    int i {0};
    std::string s;
  };

  MyStruct ms = { 42, "chris" };
  auto&& [v, n] = std::move(ms);
  std::cout << ms.i << " : " << ms.s << std::endl;
  std::cout << v << " : " << n << std::endl;
  
}

}