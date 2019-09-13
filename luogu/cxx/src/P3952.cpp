#include <bits/stdc++.h>

std::string::iterator it, end;
bool variables[26];

auto next() -> void {
  ++ it;
}

auto nextNotEmpty() -> void {
  next();
  while (it != end && (*it == ' ' || *it == '\n')) ++ it;
}

auto readFullNumber() -> int {
  std::stringstream ss;
  while ('0' <= *it && *it <= '9') ss << *it ++;
  int i;
  ss >> i;
  return i;
}

/** 
 * -1: Parse Error
 * 0 : O(1)
 * else: O(n^w)
 */
auto parse() -> int {
  int value = 0, result;
  bool canInvoke = true;
  
  if (*it == 'F') {
    nextNotEmpty();
    char c = *it;
    if (variables[c - 'a']) return -1;
    variables[c - 'a'] = true;
    nextNotEmpty();
    if (*it == 'n') {
      nextNotEmpty();

      if (*it != 'n') {
	canInvoke = false;
	readFullNumber();
      }
      
      nextNotEmpty();
    } else {
      int ib = readFullNumber();
      nextNotEmpty();

      if (*it == 'n') {
	value = 1;
      } else {
	if (ib > readFullNumber()) canInvoke = false;
      }

      nextNotEmpty();
    }

    result = value;

    if (it == end) return -1;
    
    while (*it != 'E') { 
      int svalue = parse();
      if (canInvoke) {
	if (svalue == -1) return -1;
	int sresult = value + svalue;
	if (sresult > result) {
	  result = sresult;
	}
      }
    }

    nextNotEmpty();

    variables[c - 'a'] = false;
    return result;
  } else return -1;
}

auto parseSub() -> void {
  int len;
  std::string str, line, source = "F n 1 1\n", result;
  std::memset(variables, 0, sizeof(bool) * 26);
  std::cin >> len >> str;
  std::getline(std::cin, line);

  for (int i = 0; i < len; ++ i) {
    std::getline(std::cin, line);
    line += "\n";
    source += line;
  }

  source += "E";
  
  it = source.begin();
  end = source.end();
  
  int v = parse();
  if (v == -1) {
    std::cout << "ERR" << std::endl;
    return;
  } else if (v == 0) {
    result = "O(1)";
  } else {
    result = "O(n^" + std::to_string(v) + ")";
  }

  std::cout << "[DEBUG]: " << v << std::endl;
  std::cout << (str == result ? "Yes" : "No") << std::endl;
}

auto main(int, char **) -> int {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++ i) parseSub();
  
  return 0;
}
