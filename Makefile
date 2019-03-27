test: test.cpp
	@g++ -o $@ $(shell geant4-config --cflags) $^ $(shell geant4-config --libs)

clean:
	@rm -f test
