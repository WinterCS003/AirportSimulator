CC = g++
FLAGS = -g -Wall

AirportSim.exe: main.o Airplane.o Airport.o
	$(CC) $(FLAGS) $^ -o $@
main.o: main.cpp
	$(CC) $(FLAGS) -c $<
Airport.o: Airport.cpp
	$(CC) $(FLAGS) -c $<
Airplane.o: Airplane.cpp
	$(CC) $(FLAGS) -c $<
clean:
	rm *.o AirportSim.exe report.txt