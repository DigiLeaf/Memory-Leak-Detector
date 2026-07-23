#include <iostream>
#include <cstdlib>
int main() {
    std::cout << "Testing Malloc!" << std::endl;
    void * allocatedMem = malloc(10);

    std::cout << "Testing Free!" << std::endl;
    free(allocatedMem);
    return 0;
}
