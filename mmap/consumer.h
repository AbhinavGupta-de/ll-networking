#pragma once
class Consumer
{
    std::string SHM_name;
    public:
    Consumer(const std::string& shm_name);
    void toString() const;
};