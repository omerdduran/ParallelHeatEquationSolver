#include <iosstream>
#include <omp.h>
#include <sstream>

int main() {
#pragma omp parallel
  {
    int thread_id = omp_get_thread_num();
    std::cout << "Hello from thread " << thread_id << std::endl;
  }
  return 0;
}
