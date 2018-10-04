IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs
TESTFLAGS= -l gtest -l pthread -ftest-coverage -fprofile-arcs
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = codeline_counter.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = codeline_counter.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tests:  $(OBJ)
	$(CC) -o $@ test_code_counter.cpp $^ $(TESTFLAGS)

.PHONY: clean

run: 
	./tests

cov: 
	gcov obj/codeline_counter.

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ tests obj/codeline_counter.* *.gcda *.gcno *.gcov

