all: temperature clean

temperature: temperature.o sample.o
	g++ -o temperature temperature.o sample.o

temperature.o: temperature.cpp temperature.h
	g++ -c temperature.cpp

sample.o: sample.cpp temperature.h
	g++ -c sample.cpp

clean:
	rm -f *.o
