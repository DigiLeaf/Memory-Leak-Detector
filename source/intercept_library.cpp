#include <iostream>
#include <dlfcn.h>
#include <unistd.h>
#include <cstring>


void * malloc(size_t size) {

    static void* (*malloc_ptr)(size_t) = reinterpret_cast<void* (*)(size_t)>(dlsym(RTLD_NEXT, "malloc"));

    const char * message = "My custom Malloc was Called\n";
    //std::cout << "My custom Malloc was Called" << std::endl;
    write(1,message, strlen(message));
    //call original malloc function to perform memory allocation
    void * allocAddress = malloc_ptr(size);

    return allocAddress;
}

void free(void *mem_ptr){
    static void (*free_ptr)(void *) = reinterpret_cast<void (*)(void *)>(dlsym(RTLD_NEXT, "free"));
    // std::cout << "My custom Free was called" <<std::endl;
    const char * message = "My custom Free was Called\n";

    write(1, message, strlen(message));
    //Call original free function to perform memory deallocation
    free_ptr(mem_ptr);
}