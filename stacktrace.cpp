#include <stacktrace>
#include <iostream>

void foo() {
    auto trace = std::stacktrace::current();
    std::cout << std::to_string(trace) << '\n';
}

int main(void)
{
  std::cout << "Test" << std::endl;
  foo();

  return 0;
}
