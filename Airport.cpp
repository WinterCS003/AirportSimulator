#include "Airport.h"

#include <cstdlib>
#include <ctime>

/**********************************************************
 *
 * CONSTRUCTOR Airport
 *_________________________________________________________
 * This function receives values to assign the attributes
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     landing: int - time spent landing
 *     takingoff: int - time spent taking off
 *     new_land: int - time between landings
 *     new_takeoff: int - time between takeoffs
 *     fuel: int - fuel left till crash
 *     time: int - total time for simulation
 *
 * POST-CONDITIONS
 *   This function will create a new Airport object and run
 *   a simulation based off of the given parameters
 ***********************************************************/
Airport::Airport(int landing,     // IN - time spent landing
                 int takingoff,   // IN - time spent taking off
                 int new_land,    // IN - time between landing
                 int new_takeoff, // IN - time between takeoffs
                 int fuel,        // IN - total fuel of a plane
                 int time){       // IN - total time to simulate{
    _landing_time = landing;
    _takeoff = takingoff;
    _new_landing = new_land;
    _new_takeoff = new_takeoff;
    _fuel = fuel;
    _time = time;
}

/**********************************************************
 *
 * FUNCTION run
 *_________________________________________________________
 * This function receives nothing and runs the simulation.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will run a simulation based off of the
 *   values given to the constructor.
 ***********************************************************/
void Airport::run(){
    srand(time(NULL));
    for(unsigned int timeElapsed = 1; timeElapsed <= _time; timeElapsed++){
        // add 1 to time of all planes spent in queue
        _landing_Queue.incrementObjects();
        _takeoff_Queue.incrementObjects();

        // randomly generate arrival and departure times
        if(rand()%_time < _time/_new_landing){
            Airplane land(_landing_time, -1, _fuel);
            _landing_Queue.insert(land);
        }
        if(rand()%_time < _time/_new_takeoff){
            Airplane takeOff(-1, _takeoff, -1);
            _takeoff_Queue.insert(takeOff);
        }

        if(_landing_Queue.isEmpty() && !_takeoff_Queue.isEmpty())
        {
            _takeoff_Queue.head().add_takeOff();
            if(_takeoff_Queue.head().takeoff_time() == _takeoff){
                _count_takeoff++;
                _time_spent_takeoff += _takeoff_Queue.head().overall_time();
                _takeoff_Queue.remove();
            }
        }
        else if(!_landing_Queue.isEmpty())
        {
            if(_landing_Queue.head().crashed()){
                _crashed++;
                _landing_Queue.remove();
            }
            if(!_landing_Queue.isEmpty())
            {
                _landing_Queue.head().add_landing();
                if(_landing_Queue.head().landing_time() == _landing_time){
                    _count_landing++;
                    _time_spent_landing += _landing_Queue.head().overall_time();
                    _landing_Queue.remove();
                }
            }
        }
    }

    while(!_landing_Queue.isEmpty()){
        if(_landing_Queue.head().crashed()){
            _crashed++;
        }
        _landing_Queue.remove();
    }

    double average = 0.0;
    std::cout << "--------------Begin Report--------------\n\n";
    std::cout << "Total time simulated: " << _time << "\n";
    std::cout << "Total number of planes that took off: " << _count_takeoff << "\n";
    std::cout << "Total number of planes that landed: " << _count_landing<< "\n";
    std::cout << "Total number of planes that crashed: " << _crashed << "\n";
    _count_takeoff == 0 ? average = 0 : average = (double)_time_spent_takeoff/_count_takeoff;
    std::cout << "Average time spent waiting in takeoff queue: " << average << "\n";
    _count_landing== 0 ? average = 0 : average = (double)_time_spent_landing/_count_landing;
    std::cout << "Average time spent waiting in landing queue: " << average << "\n\n";
    std::cout << "--------------End Report---------------\n";

    generate_report();
}

/**********************************************************
 *
 * FUNCTION generate_report
 *_________________________________________________________
 * This function receives nothing and generates a report
 * to a txt file after the simulation is run.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will generate a report of the total time
 *   simulated, the number of planes that took off, the
 *   number of planes that landed, number of planes that
 *   crashed, the average time spent waiting in the takeoff
 *   queue and the average time spent waiting in the landing
 *   queue.
 ***********************************************************/
void Airport::generate_report() const
{
    std::ofstream report("report.txt", std::ios_base::app);
    double average = 0.0;
    if(report.is_open()){
        report << "--------------Begin Report--------------\n\n";
        report << "INPUTS:\n";
        report << "Total time simulated: " << _time << "\n";
        report << "Amount needed for one plane to land: " << _landing_time << "\n";
        report << "Amount needed for one plane to take off: " << _takeoff << "\n";
        report << "Time between arrival of landing planes: " << _new_landing << "\n";
        report << "Time between arrival of planes taking off: " << _new_takeoff<< "\n";
        report << "Time until plane runs out of fuel: " << _fuel << "\n\n";

        report << "OUTPUT:\n";
        report << "Total number of planes that took off: " << _count_takeoff << "\n";
        report << "Total number of planes that landed: " << _count_landing<< "\n";
        report << "Total number of planes that crashed: " << _crashed << "\n";
        _count_takeoff == 0 ? average = 0 : average = (double)_time_spent_takeoff/_count_takeoff;
        report << "Average time spent waiting in takeoff queue: " << average << "\n";
        _count_landing== 0 ? average = 0 : average = (double)_time_spent_landing/_count_landing;
        report << "Average time spent waiting in landing queue: " << average << "\n\n";
        report << "--------------End  Report---------------\n\n";
    } else{
        std::cerr << "Could not generate report" << std::endl;
    }
}
