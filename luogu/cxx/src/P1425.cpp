#ifndef LUOGU_1425_HPP
#define LUOGU_1425_HPP

#include <iostream>
#include <string>

struct Date {
  const int hour, minute;

  explicit Date(const int &hour, const int &minute) : hour(hour), minute(minute) {}

  Date(const int &minutes) : hour(minutes / 60), minute(minutes % 60) {  }

  auto to_number() const -> int {
    return hour * 60 + minute;
  }

  auto operator-(const Date &other) const -> Date {
    return {to_number() - other.to_number()};
  }

  auto to_string() const -> std::string {
    return std::to_string(hour) + " " + std::to_string(minute);
  }
};
  
auto main(int, char**) -> int {
  int sh, sm, eh, em;
  std::cin >> sh >> sm >> eh >> em;
  
  std::cout << (Date(eh, em) - Date(sh, sm)).to_string() << std::endl;
  
  return 0;
}

#endif
