#include <string>
#include "producer.h"

#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

Producer::Producer(const std::string& shm_name) : shm_name(shm_name) {};

void Producer::toString() const
{
    std::cout << shm_name << std::endl;
}


void Producer::run() const
{
    int fd = shm_open(shm_name.c_str(), O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    if (ftruncate(fd, 16 * 1024 * 1024) == -1)
    {
        perror("ftruncate");
        exit(1);
    }

    void *ptr = mmap(nullptr, 16 * 1024 * 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    char* charPtr = static_cast<char*>(ptr);
    charPtr[0] = 'A';
}