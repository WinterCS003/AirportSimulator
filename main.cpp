#include <iostream>
#include <cstring>

#include "Airport/Airport.h"

void show_usage();

int main(int argc, char* argv[]){
    if(argc != 2 && argc != 13)
    {
        std::cerr << "Incorrect syntax\n"
                  << "Use the -h or --help flag for documentation\n";
        return 1;
    }

    int landing_time = -1;
    int takeoff = -1;
    int new_landing = -1;
    int new_takeoff = -1;
    int fuel = -1;
    int time = -1;
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if(arg == "-h" || arg == "--help")
        {
            show_usage();
            return 0;
        } else if(arg == "-l" || arg == "--landing-time"){
            if(i+1 < argc){
                try {
                    landing_time = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--landing-time requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--landing-time requires an integer value" << std::endl;
                return 1;
            }
        } else if(arg == "-t" || arg == "--takeoff-time"){
            if(i+1 < argc){
                try {
                    takeoff = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--takeoff-time requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--takeoff-time requires an integer value" << std::endl;
                return 1;
            }
        } else if(arg == "-nl" || arg == "--new-landing"){
            if(i+1 < argc){
                try {
                    new_landing = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--new-landing requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--new-landing requires an integer value" << std::endl;
                return 1;
            }
        } else if(arg == "-nt" || arg == "--new-takeoff"){
            if(i+1 < argc){
                try {
                    new_takeoff = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--new-takeoff requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--new-takeoff requires an integer value" << std::endl;
                return 1;
            }
        } else if(arg == "-f" || arg == "--fuel"){
            if(i+1 < argc){
                try {
                    fuel = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--fuel requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--fuel requires an integer value" << std::endl;
                return 1;
            }
        } else if(arg == "-T" || arg == "--total-time"){
            if(i+1 < argc){
                try {
                    time = std::stoi(argv[++i]);
                }  catch (const std::invalid_argument& ia) {
                    std::cerr << "--total-time requires an integer value" << std::endl;
                    return 1;
                }
            } else{
                std::cerr << "--total-time requires an integer value" << std::endl;
                return 1;
            }
        } else{
            std::cerr << "Bad option: " << arg << std::endl;
            show_usage();
            return 0;
        }
    }

    Airport simulation(landing_time, takeoff, new_landing, new_takeoff, fuel, time);
    simulation.run();

    return 0;
}

void show_usage()
{
    std::cerr << "Usage: ./AirportSim.exe [-h] [-l <time>] [-t <time>] [-nl <time>] [-tl <time>] [-f <fuel>] [-T <total_time>] \n\n"
              << "Options:\n"
              << "\t-h, --help                 Show this help message\n"
              << "\t-l, --landing-time         Amount of time needed for one plane to land\n"
              << "\t-t, --takeoff-time         Amount of time needed for one plane to take off\n"
              << "\t-nl, --new-landing         Average amount of time between arrival of planes to the landing queue\n"
              << "\t-nt, --new-takeoff         Average amount of time between arrival of planes to the takeoff queue\n"
              << "\t-f, --fuel                 Amount of time a plane can stay in the landing queue before it runs out of fuel\n"
              << "\t-T, --total-time           Total length of time to simulate\n";
}
