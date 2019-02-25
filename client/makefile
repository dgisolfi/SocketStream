PROG = client
SRC = client.c
CPP = cppclient

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(SRC)

$(CPP): $(SRC)
	g++ -o $@ $(SRC)

.PHONY: all $(PROG)