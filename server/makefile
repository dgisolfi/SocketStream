
PROG = server
SRC = server.c

CFLAGS = -I$(TOP)/include $(COPT)
LIBS = -lpthread

# include $(TOP)/resources/Makefile.in-os

ifeq ($(TARGET_OS),LINUX) 
	LIBS += -ldl
endif

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

.PHONY: all $(PROG)