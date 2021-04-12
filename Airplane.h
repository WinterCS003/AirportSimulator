#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane{
    private:
        int _takeoff_time;  // IN - time spent taking off
        int _landing_time;  // IN - time spent landing
        int _time_in_queue; // IN - time spent in queue
        int _fuel;          // IN - total fuel in plane

    public:
        /*****************
         ** CONSTRUCTOR **
         *****************/
        Airplane();
        Airplane(int takeoff, // IN - time spent taking off
                 int land,    // IN - time spent landing
                 int fuel);   // IN - fuel left in plane

        /***************
         ** MUTATORS **
         ***************/
        void add_takeOff(){ _takeoff_time++; };
        void add_landing(){ _landing_time++; };
        int operator++();

        /***************
         ** ACCESSORS **
         ***************/
        // spent more time in queue than you have fuel/ run out of fuel
        bool crashed() const { return _time_in_queue > _fuel; };
        int overall_time() const { return _time_in_queue; };
        int landing_time() const { return _landing_time; };
        int takeoff_time() const { return _takeoff_time; };
};

#endif // AIRPLANE_H

/****************************************************************
 * Airplane Class
 *   This class represents an airplane object. It manages 4
 *   attributes, the time spent taking off, time spent landing
 *   time spent in the queue and the total fuel left in the
 *   plane.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * Airplane();
 *   Constructor; Initialize class to 0;
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * Airplane(int takeoff,
 *          int land,
 *          int fuel);
 *   Constructor; Initialize class to the parameters
 *   Parameters: int takeoff, // IN - time spent taking off
 *               int land,    // IN - time spent landing
 *               int fuel);   // IN - fuel left in plane
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void add_takeOff();
 *
 *   Mutator; This method will increment the time spent taking off
 *   attribute by 1
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void add_landing();
 *
 *   Mutator; This method will increment the time spent landing
 *   attribute by 1
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * int operator++();
 *
 *   Mutator; This method overrides the prefix increment operator.
 *   It increasee the time spent in queue attribute by 1.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: _time_in_queue (int)
 *******************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/****************************************************************
 * bool crashed() const;
 *
 *   Accessor; This method will return true if the plane has
 *   ran out of fuel and crashed
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: bool - true if the time spent in the queue is greater
 *   that the fuel.
 ***************************************************************/

/****************************************************************
 * int overall_time() const;
 *
 *   Accessor; This method will return the total amount of time
 *   spent in the queue by the plane.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _time_in_queue (int) // IN - total time spent in
 *   the queue.
 ***************************************************************/

/****************************************************************
 * int landing_time() const;
 *
 *   Accessor; This method will return the total amount of time
 *   spent landing by the plane.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _landing_time (int) // IN - total time spent in
 *   the queue.
 ***************************************************************/

/****************************************************************
 * int takeoff_time() const;
 *
 *   Accessor; This method will return the total amount of time
 *   spent taking off by the plane.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _takeoff_time (int) // IN - total time spent in
 *   the queue.
 ***************************************************************/
