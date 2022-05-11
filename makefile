OUTPUT :=UkladRownanLiniowych

#*.hh dir
IDIR :=inc
#*.o dir
ODIR :=obj
#*.cpp dir
SDIR :=src

CC :=g++
CFLAGS :=-I$(IDIR) -Wall -pedantic -std=c++17

#*.h
_DEPS := main.hh wektor.hh macierz.hh ukladRownanLiniowych.hh rozmiar.hh swektor.hh
DEPS := $(patsubst %,$(IDIR)/%,$(_DEPS))

#*.o
_OBJ := main.o wektor.o macierz.o ukladRownanLiniowych.o
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))

__start__: $(OUTPUT)
	./$(OUTPUT) < rownanie_liczb_rzeczywistych.dat

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o

test:
	./$(OUTPUT) < rownanie_liczb_rzeczywistych.dat
	./$(OUTPUT) < rownanie_liczb_zespolone.dat
