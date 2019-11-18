# Flags de compilação
CPP = g++
OBJ = g++ -c
CFLAGS = -g -Wall -I../inc/
OUT = -o main.out
DONT_MAKE = main.cpp compra_ingresso.cpp
SOURCES = $(filter-out $(DONT_MAKE),$(wildcard *.cpp))
OBJETOS = $(SOURCES:.cpp=.o)

all: main clear

# Compilar arquivo executavel
main: $(OBJETOS)
	$(CPP) main.cpp $(OBJETOS) $(OUT) $(CFLAGS)

# Compilar arquivos obj
%.o: %.cpp
	$(CPP) -c $(CFLAGS) $< -o $@

# Deletar arquivos objeto
clear:
	rm *.o
