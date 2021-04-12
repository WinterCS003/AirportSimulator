#include "Airport/Airport.h"

Airport::Airport(int landing, int takingoff, int new_land, int newTakeoff, int fuel, int time){
    _landing_time = landing;
    _takeoff = takingoff;
    _new_landing = new_land;
    _new_takeoff = newTakeoff;
    _fuel = fuel;
    _time = time;
}

void Airport::run(){
    for(int timeElapsed = 1; timeElapsed <= _time; timeElapsed++){
        // add 1 to time of all planes spent in queue
        _landing_Queue.incrementObjects();
        _takeoff_Queue.incrementObjects();

        // generate new planes - should be random?
        if(timeElapsed%_new_landing == 0){
            Airplane land(_landing_time, -1, _fuel);
            _landing_Queue.insert(land);
        }
        if(timeElapsed%_new_takeoff == 0){
            Airplane takeOff(-1, _takeoff, -1);
            _takeoff_Queue.insert(takeOff);
        }

        if(_landing_Queue.isEmpty())
        {
            _takeoff_Queue.head().add_takeOff();
            if(_takeoff_Queue.head().takeoff_time() == _takeoff){
                _count_takeoff++;
                _time_spent_takeoff += _takeoff_Queue.head().overall_time();
                _takeoff_Queue.remove();
            }
        }
        else
        {
            if(_landing_Queue.head().crashed()){
                _crashed++;
                _landing_Queue.remove();
            }

            _landing_Queue.head().add_landing();
            if(_landing_Queue.head().landing_time() == _landing_time){
                _count_landing++;
                _time_spent_landing += _landing_Queue.head().overall_time();
                _landing_Queue.remove();
            }
        }
    }

    generate_report();
}

void Airport::generate_report(){
    std::ofstream report("report.txt");
    if(report.is_open()){
        report << "--------------Begin Report--------------\n\n";
        report << "Total time simulated: " << _time << "\n";
        report << "Total number of planes that took off: " << _count_takeoff << "\n";
        report << "Total number of planes that landed: " << _count_landing<< "\n";
        report << "Total number of planes that crashed: " << _crashed << "\n";
        double average = (double)_time_spent_takeoff/_count_takeoff;
        report << "Average time spent waiting in takeoff queue: " << average << "\n";
        average = (double)_time_spent_landing/_count_landing;
        report << "Average time spent waiting in landing queue: " << average << "\n\n";
        report << "--------------End Report---------------\n";
    } else{
        std::cerr << "Could not generate report" << std::endl;
    }
}
