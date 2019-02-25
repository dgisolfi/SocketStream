
PROG = server
SRC = server.c
CPP = cppserver

CFLAGS = -I$(TOP)/include $(COPT)
LIBS = -lpthread

ifeq ($(TARGET_OS),LINUX) 
	LIBS += -ldl
endif

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

$(CPP): $(SRC)
	g++ -o $@ $(SRC)

.PHONY: all $(PROG)