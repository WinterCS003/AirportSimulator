#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane{
    private:
        int _takeoff_time;
        int _landing_time;
        int _time_in_queue;
        int _fuel;

    public:
        Airplane();
        Airplane(int, int, int);

        // time spent in queue
        void add_time(){ _time_in_queue++; };

        // time spent on runway
        void add_takeOff(){ _takeoff_time++; };
        void add_landing(){ _landing_time++; };
        int operator++();

        // spent more time in queue than you have fuel/ run out of fuel
        bool crashed(){ return _time_in_queue > _fuel; };
        int overall_time(){ return _time_in_queue; };
        int landing_time(){ return _landing_time; };
        int takeoff_time(){ return _takeoff_time; };
};

#endif // AIRPLANE_H
