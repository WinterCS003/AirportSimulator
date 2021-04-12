#include "Airplane.h"

/**********************************************************
 *
 * CONSTRUCTOR AIRPLANE
 *_________________________________________________________
 * This constructor receives nothing and initializes the
 * values to -1 to indicate that it is not a valid
 * plane.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This constructor is called when an empty queue is
 *   created.
 ***********************************************************/
Airplane::Airplane(){
    _takeoff_time = -1;
    _landing_time = -1;
    _time_in_queue = -1;
    _fuel = -1;
}

/**********************************************************
 *
 * CONSTRUCTOR Airplane
 *_________________________________________________________
 * This constructor receives a time spent taking off, time
 * spent landing, and total fuel until a plane crashes
 * and initializes the object with these values.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     takeoff: int - time spent taking off
 *     land: int - time spent landing
 *     fuel: int - fuel left in plane
 *
 * POST-CONDITIONS
 *   This constructor will create a new Airplane object
 *   based off of the given parameters.
 ***********************************************************/
Airplane::Airplane(int takeoff, // IN - time spent taking off
                   int land,    // IN - time spent landing
                   int fuel)    // IN - fuel left in plane{
{
    _takeoff_time = takeoff;
    _landing_time = land;
    _time_in_queue = 0;
    _fuel = fuel;
}

/**********************************************************
 *
 * FUNCTION operator++
 *_________________________________________________________
 * This function overrides the prefix increment operator
 * and increments the time spent in the queue by 1.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will increment the time spent in queue
 *   attribute by 1.
 ***********************************************************/
int Airplane::operator++(){
    ++_time_in_queue;
    return _time_in_queue;
}
