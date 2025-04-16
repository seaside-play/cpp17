#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "sun/earth/basic.hpp"

void TestCompileDefinition();
void test_hex_to_char();
std::string encode(const std::string& plainText);
std::string decode(const std::string &hexString);

int main(int agrc, char** argv) {
    std::cout << "hello world!\n";

    std::cout << "3 + 2 = " << Add(3, 2) << std::endl;

    // test_hex_to_char();
    TestCompileDefinition();

    std::string raw_key = "{v1;basic;name;seats;email;company;1845620137;1845806537}";
    auto encrypted_key = encode(raw_key);
    std::cout << "encrypted key: " << encrypted_key << std::endl;
    auto result = decode(encrypted_key);
    std::cout << "result key: " << result << std::endl;

    return 0;
}

void TestCompileDefinition() {
#ifdef SUN_TARGET
    std::cout << "SUN_TARGET is defined" << std::endl;
#else
    std::cout << "SUN_TARGET is not defined " << std::endl;
#endif


#if SUN_TARGET == gnulinux
    std::cout << "now is gunlinux\n";
#else
    std::cout << "now is not gunlinux\n";
#endif
}

std::string decode(const std::string &hexString)
{
  if (hexString.length() % 2 != 0) {
    return "fatal";
  }

  std::string plainText;
  plainText.reserve(hexString.length() / 2);

  for (size_t i = 0; i < hexString.length(); i += 2) {
    std::string byteString = hexString.substr(i, 2);
    auto byte = static_cast<char>(std::stoi(byteString, nullptr, 16));
    plainText.push_back(byte);
  }

  return plainText;
}

void test_hex_to_char() {
    std::string byteString = "FF";
    try {
        char result = static_cast<char>(std::stoi(byteString, nullptr, 16));
        std::cout << "Converted value: " << static_cast<int>(result) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    return;
}
// 定义 encode 函数，将普通字符串转换为十六进制字符串
std::string encode(const std::string& plainText) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');

    for (unsigned char c : plainText) {
        oss << std::setw(2) << static_cast<int>(c);
    }

    return oss.str();
}