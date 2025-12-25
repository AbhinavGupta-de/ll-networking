#pragma once
#include <string>

class Consumer
{
    std::string shm_name;
    public:
    Consumer(const std::string& shm_name);
    void toString() const;
    void run() const;
};