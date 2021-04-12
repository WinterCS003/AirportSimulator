/******************************************************************
 * AUTHOR   : Jaemok C. Lee
 * ASSIGNMENT #5 : Queues
 * CLASS    : CS 008 Data Structures
 * SECTION  : 6:30p - 8:35
 * DUE DATE : 04/14/2021
 ******************************************************************/
#include <iostream>
#include <cstring>

#include "Airport.h"

/****************************************************************
 * show_usage
 *   This function receives nothing and prints the help
 *   documentation for this executable.
 *   -returns  nothing -> This will output the help documentation
 ***************************************************************/
void show_usage();

/************************************************************
*
* AirportSim
*___________________________________________________________
* This program simulates an airport with 1 runway. It
* generates a report of all planes that crashed, landed
* and took off as well as some other information.
*___________________________________________________________
* INPUTS:
*   landing_time: int - time spent landing by plane
*   takeoff: int - time spent taking off by plane
*   new_landing: int - time between landings
*   new_takeoff: int - time between takeoffs
*   fuel: int - fuel of plane before it crashes
*   time: int - total time to simulate
*
* OUTPUTS:
*   txt file of report.
*************************************************************/
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

    try{
        Airport simulation(landing_time, takeoff, new_landing, new_takeoff, fuel, time);
        simulation.run();
    } catch(const char* msg){
        std::cerr << msg << std::endl;
    }

    return 0;
}

/****************************************************************
 * show_usage
 *   This function receives nothing and prints the help
 *   documentation for this executable.
 *   -returns  nothing -> This will output the help documentation
 ***************************************************************/
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
