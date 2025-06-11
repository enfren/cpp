CC = g++
CFLAGS = -Iinclude
SRCS = main.cpp src/pointers.cpp src/references.cpp src/classes.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)