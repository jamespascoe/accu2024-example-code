#include <iostream>
#include <stacktrace>

class fib_with_stacktrace {

  std::stacktrace::size_type max_depth = 0;
  std::stacktrace max_trace;

public:

  fib_with_stacktrace() = default;

  // Return the nth number in the fibonaci sequence
  unsigned int fib(unsigned int n)
  {
    auto trace = std::stacktrace::current();
    auto depth = trace.size();
    if (trace.size() > max_depth) {
      max_trace = trace;
      max_depth = depth;
    }

    return n < 2 ? n : fib(n-1) + fib(n-2);
  }

  std::stacktrace get_max_trace() const
  {
    return max_trace;
  }
};

int main(void)
{

  fib_with_stacktrace fib_wst;

  for (int i=0; i<10; ++i)
    std::cout << fib_wst.fib(i) << '\n';

  const std::stacktrace& trace = fib_wst.get_max_trace();
  std::cout << "Max Depth was: " << trace.size() << '\n';
}
