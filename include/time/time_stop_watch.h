//
// Created by uig61636 on 31.12.2023.
//

#ifndef ECAL_SHM_LAYER_TIME_STOP_WATCH_H
#define ECAL_SHM_LAYER_TIME_STOP_WATCH_H
#include <chrono>
#include <iostream>
#include <string>

template<typename T>
class StopWatch{
private:
    long long start_time = 0;
    std::string name;
public:
    StopWatch(std::string name):name(name){start_time = std::chrono::duration_cast<T>(std::chrono::steady_clock::now().time_since_epoch()).count();}
    ~StopWatch(){auto end_time = std::chrono::duration_cast<T>(std::chrono::steady_clock::now().time_since_epoch()).count();
                 std::cout << end_time - start_time;}
};
#endif //ECAL_SHM_LAYER_TIME_STOP_WATCH_H
