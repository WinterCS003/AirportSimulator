#include "Airplane.h"

Airplane::Airplane(){
    _takeoff_time = -1;
    _landing_time = -1;
    _time_in_queue = -1;
    _fuel = -1;
}

Airplane::Airplane(int takeoff, int land, int fuel){
    _takeoff_time = takeoff;
    _landing_time = land;
    _time_in_queue = 0;
    _fuel = fuel;
}

int Airplane::operator++(){
    ++_time_in_queue;
    return _time_in_queue;
}
