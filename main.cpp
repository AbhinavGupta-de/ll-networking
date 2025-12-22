#include <iostream>
#include <ostream>
#include "mmap/consumer.h"
#include "mmap/producer.h"

int main(int argSize, char** args) {
    auto app_type = args[1];
    auto shm_name = args[2];

    if (app_type == "producer")
    {
        Producer producer(shm_name);
        producer.toString();
    }
    else
    {
        Consumer consumer(shm_name);
        consumer.toString();
    }

}
