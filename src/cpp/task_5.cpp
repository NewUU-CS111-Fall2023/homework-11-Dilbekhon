/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <string>
#include <map>

std::map<char, char> build_substitution_map(const std::string& key) {
  std::map<char, char> substitution_map;
  int index = 0;
  for (char c : key) {
    if (isalpha(c) && substitution_map.count(tolower(c)) == 0) {
      substitution_map[tolower(c)] = 'a' + index++;
    }
  }
  return substitution_map;
}

std::string decode_message(const std::string& message, const std::map<char, char>& substitution_map) {
  std::string decoded_message;
  for (char c : message) {
    if (isalpha(c)) {
      char original = tolower(c);
      decoded_message += substitution_map.count(original) > 0 ? substitution_map.at(original) : c;
    } else {
      decoded_message += c;
    }
  }
  return decoded_message;
}

int main() {
  std::string key, message;
  std::cout << "Enter the key: ";
  std::getline(std::cin, key);  // Allowing multi-word input
  std::cout << "Enter the message: ";
  std::getline(std::cin, message);  // Allowing multi-word input

  std::map<char, char> substitution_map = build_substitution_map(key);
  std::string decoded_message = decode_message(message, substitution_map);

  std::cout << "The decoded message is: " << decoded_message << std::endl;

  return 0;
}
