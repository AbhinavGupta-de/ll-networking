#pragma once
class Producer
{
    std::string SHM_name;
    public:
    Producer(const std::string& shm_name);
    void toString() const;
};