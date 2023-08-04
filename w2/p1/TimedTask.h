#ifndef __SDDS_TIMEDTASK_H__
#define __SDDS_TIMEDTASK_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include <chrono>

namespace sdds
{
    class TimedTask
    {
        

        int numOfrec;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        struct Task
        {
            std::string task_name;
            std::string unitsOfTime;
            std::chrono::steady_clock::duration duration;
        } *tasks;

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char *name);
        friend std::ostream &operator<<(std::ostream &os, const TimedTask &task);
        ~TimedTask();
    };
}

#endif