CC = g++
CFLAGS = -g -O

SRC = test.cpp linkstack.h linkqueue.h
OBJS = test

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) .*.sw?
