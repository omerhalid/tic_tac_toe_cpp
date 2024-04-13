CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = TicTacToe
SRCS = main.cpp Game.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

clean:
    $(RM) $(OBJS) $(TARGET)

.PHONY: all clean
