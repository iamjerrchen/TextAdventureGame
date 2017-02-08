EXENAME = adventure
OBJS = main.o room.o game.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp room.h game.h
	$(CXX) $(CXXFLAGS) main.cpp

room.o : room.cpp room.h events.h

game.o : game.cpp room.h game.h
	$(CXX) $(CXXFLAGS) game.cpp

clean :
	-rm -f *.o $(EXENAME)