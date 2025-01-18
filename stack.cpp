#include <iostream>
#include <queue>
#include <stack>
#include <string>

int isBalanced(std::string a) {
  std::stack<char> st;
  for (char element : a) {
    if (element == '{' || element == '[' || element == '(') {
      st.push(element);
    } else {
      if (st.empty()) {
        return 0;
      } else if ((element == '}' && st.top() != '{') ||
                 (element == ')' && st.top() != '(') ||
                 (element == ']' && st.top() != '[')) {
        return 0;
      } else {
        st.pop();
      }
    }
  }
  return 1;
}
int main(int argc, char const *argv[]) {
  std::string test = "()[]{}}";
  std::cout << (isBalanced(test) ? "True" : "False") << std::endl;

  return 0;
}
