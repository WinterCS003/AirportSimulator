#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <fstream>

#include "queue.h"
#include "Airplane.h"

class Airport{
    private:
        Queue<Airplane> _takeoff_Queue; // IN - queue of planes taking off
        Queue<Airplane> _landing_Queue; // IN - queue of planes landing
        int _landing_time = -1; // IN - time spent landing
        int _takeoff = -1;      // IN - time spent taking off
        int _new_landing = -1;  // IN - time between landings
        int _new_takeoff = -1;  // IN - time between takeoffs
        int _fuel = -1;         // IN - total fuel of plane
        unsigned int _time = -1;         // IN - total time to simulate

        // For creating new Airplanes
        int _crashed = 0;            // CALC - total planes that crashed
        int _count_takeoff = 0;      // CALC - number of takeoffs
        int _count_landing = 0;      // CALC - number of landings
        int _time_spent_landing = 0; // CALC - time spent in landing queue
        int _time_spent_takeoff = 0; // CALC - time spent in takeoff queue

    public:
        /*****************
         ** CONSTRUCTOR **
         *****************/
        Airport(int landing,     // IN - time spent landing
                int takingoff,   // IN - time spent taking off
                int new_land,    // IN - time between landing
                int new_takeoff, // IN - time between takeoffs
                int fuel,        // IN - total fuel of a plane
                int time);       // IN - total time to simulate
        /**************
         ** MUTATORS **
         **************/
        void run();
        /***************
         ** ACCESSORS **
         ***************/
        void generate_report() const;
};

#endif // AIRPORT_H

/****************************************************************
 * Airport Class
 *   This class represents an airport with 1 runway. It manages
 *   13 attributes to create new airplanes and generate
 *   reports.
 ***************************************************************/


/*****************
 ** CONSTRUCTOR **
 *****************/

/****************************************************************
 * Airport::Airport(int landing,
                    int takingoff,
                    int new_land,
                    int new_takeoff,
                    int fuel,
                    int time)
 *   Constructor; Initialize class attributes
 *   Parameters: landing (int)     // IN - time spent landing
                 takingoff (int)   // IN - time spent taking off
                 new_land (int)    // IN - time between landing
                 new_takeoff (int) // IN - time between takeoffs
                 fuel (int)        // IN - total fuel of a plane
                 time (int)        // IN - total time to simulate
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void run();
 *
 *   Mutator; This method will run the simulation based off of the
 *   given values and update the _crashed, _count_takeoff,
 *   _count_landing, _time_spent_landing, and _time_spent_takeoff
 *   attributes accordingly.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none - a report is generated to a txt file.
 *******************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/****************************************************************
 * void generate_report() const;
 *
 *   Accessor; This method will generate a report of the total
 *   number of crashed planes, how many takeoffs and landings
 *   occurred, and the total time spent by each plane waiting
 *   in the queue.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated to a txt file
 ***************************************************************/
