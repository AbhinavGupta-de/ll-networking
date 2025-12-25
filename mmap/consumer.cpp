#include <iostream>
#include <string>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "consumer.h"


Consumer::Consumer(const std::string& shm_name) : shm_name(shm_name) {};

void Consumer::toString() const
{
    std::cout << shm_name << std::endl;
}

void Consumer::run() const
{
    int fd = shm_open(shm_name.c_str(), O_RDONLY, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    void *ptr = mmap(nullptr, 16 * 1024 * 1024, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    char* charPtr = static_cast<char*>(ptr);
    std::cout << "Read from shared memory: " << charPtr[0] << std::endl;
}