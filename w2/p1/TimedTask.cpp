#include "TimedTask.h"

using namespace std;

namespace sdds
{
    TimedTask::TimedTask()
    {
        numOfrec = 0;
        tasks = nullptr;
    }

    void TimedTask::startClock()
    {
        start_time = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock()
    {
        end_time = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char *task_name)
    {
        Task *temp = nullptr;
        temp = new Task[numOfrec + 1];
        for (int i = 0; i < numOfrec; i++)
        {
            temp[i] = tasks[i];
        }
        temp[numOfrec].task_name = task_name;
        temp[numOfrec].unitsOfTime = "nanoseconds";
        temp[numOfrec].duration = end_time - start_time;
        numOfrec++;
        delete[] tasks;
        tasks = temp;
    }

    std::ostream &operator<<(std::ostream &os, const TimedTask &tt)
    {
        os << "--------------------------" << endl;
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;
        for (int i = 0; i < tt.numOfrec; i++)
        {
            os << setw(20) << left << tt.tasks[i].task_name << " "
               << setw(13) << right << tt.tasks[i].duration.count() << " "
               << tt.tasks[i].unitsOfTime << endl;
        }
        os << "--------------------------" << endl;
        return os;
    }

    TimedTask::~TimedTask()
    {
        if (tasks != nullptr)
            delete[] tasks;
        tasks = nullptr;
    }
}
