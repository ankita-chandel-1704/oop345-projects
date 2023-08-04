//
//  TimedTask.h
//  ws2
//

#ifndef TimedTask_h
#define TimedTask_h
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
using namespace std;
namespace sdds
{
    const int max_obj= 10;
    struct Task
    {
        string name;
        string unit_of_type;
        std::chrono::steady_clock::duration duration;
    };
    class TimedTask
    {
        int num_of_records;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        Task t[max_obj];
        public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const std::string);
        friend ostream& operator<<(ostream & COUT ,const TimedTask&k );
    };
    //std::ostream& operator<<(std::ostream& COUT ,const TimedTask& t);
};
#endif /* TimedTask_h */
