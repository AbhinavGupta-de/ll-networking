#include <string>
#include "producer.h"

#include <iostream>
#include <ostream>

Producer::Producer(const std::string& shm_name) : SHM_name(shm_name) {};

void Producer::toString() const
{
    std::cout << SHM_name << std::endl;
}