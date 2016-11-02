CXXFLAGS := -g -std=c++11 -Wall -Werror

all: test

unittest: test
	valgrind --leak-check=full --track-fds=yes --log-file=valgrind.log ./tester
	cat valgrind.log

test: tester
	./tester

tester: tester.cpp Strand.o sequence.o
	g++ $(CXXFLAGS) -o $@ $^

Strand.o: Strand.cpp Strand.h
	g++ $(CXXFLAGS) -c $<

sequence.o: sequence.cpp sequence.h
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o *~

spotless: clean
	rm -f test tester
	# I'm not sure why, but this directory keeps showing up when I build
	rm -rf tester.dSYM/

