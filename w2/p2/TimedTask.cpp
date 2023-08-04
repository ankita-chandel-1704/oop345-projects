//
//  TimedTask.cpp
//  ws2


#include <stdio.h>
#include "TimedTask.h"
//using namesapce std;
namespace sdds
{
    TimedTask::TimedTask()
    {
        num_of_records = 0;
        for (int i=0;i<10;i++)
            t[i] = { {0} };
        start_time = std::chrono::steady_clock::now();
        end_time = std::chrono::steady_clock::now();
    }
    void TimedTask::startClock()
    {
        start_time = std::chrono::steady_clock::now();
    }
    void TimedTask:: stopClock()
    {
        end_time = std::chrono::steady_clock::now();
    }
    void TimedTask::addTask(std::string k)
    {
        
        t[num_of_records].name =k;
        t[num_of_records].unit_of_type="nanoseconds";
        t[num_of_records].duration=end_time - start_time;
        num_of_records++;
    }
    ostream& operator<<(ostream & COUT ,const TimedTask &k )
    {
        COUT<<"--------------------------"<<endl;
        COUT<<"Execution Times:"<<endl;
        COUT<<"--------------------------"<<endl;
        for(int i=0;i<k.num_of_records;i++)
        {
            cout<<left<<setw(21)<<k.t[i].name<<" "<<right<<setw(13)<<std::chrono::duration_cast<std::chrono::nanoseconds>(k.t[i].duration).count()<<" "<<k.t[i].unit_of_type<<endl;
        }
        COUT<<"--------------------------"<<endl;
        return COUT;
    }
};
