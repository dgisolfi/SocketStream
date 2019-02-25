
PROG = server
SRC = server.c
CPP = cppserver

CFLAGS = -I$(TOP)/include $(COPT)
LIBS = -lpthread

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

$(CPP): $(SRC)
	g++ -o $@ $(SRC)

.PHONY: all $(PROG)