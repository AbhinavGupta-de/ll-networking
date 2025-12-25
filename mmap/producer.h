#pragma once
#include <string>

class Producer
{
    std::string shm_name;
    public:
    Producer(const std::string& shm_name);
    void toString() const;
    void run() const;
};