#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <fstream>

#include "Queue/Queue.h"
#include "Airplane/Airplane.h"

class Airport{
    private:
        Queue<Airplane> _takeoff_Queue;
        Queue<Airplane> _landing_Queue;
        int _landing_time = -1;
        int _takeoff = -1;
        int _new_landing = -1;
        int _new_takeoff = -1;
        int _fuel = -1;
        int _time = -1;

        int _crashed = 0;
        int _count_takeoff = 0;
        int _count_landing = 0;
        int _time_spent_landing = 0;
        int _time_spent_takeoff = 0;

    public:
        Airport(int, int, int, int, int, int);
        void run();
        void generate_report();
};

#endif // AIRPORT_H
