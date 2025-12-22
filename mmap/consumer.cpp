#include <iostream>
#include <ostream>
#include <string>
#include "consumer.h"


Consumer::Consumer(const std::string& shm_name) : SHM_name(shm_name) {};
void Consumer::toString() const
{
    std::cout << SHM_name << std::endl;
}