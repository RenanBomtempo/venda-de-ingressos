# Flags de compilação
CPP = g++ 
OBJ = g++ -c 
CFLAGS = -g -Wall -I../inc/ 
OUT = -o main.out

all: main clear

# Compilar arquivo executavel
main: usuario.o evento.o crianca.o adulto.o idoso.o eventoinfantil.o teatrofantoche.o cinema.o eventoadulto.o show.o boate.o csvprocessor.o
	$(CPP) main.cpp usuario.o evento.o crianca.o adulto.o idoso.o eventoinfantil.o teatrofantoche.o cinema.o eventoadulto.o show.o boate.o csvprocessor.o $(OUT) $(CFLAGS)

# Compilar arquivos obj
crianca.o:
	$(OBJ) crianca.cpp $(CFLAGS)

adulto.o:
	$(OBJ) adulto.cpp $(CFLAGS)

idoso.o:
	$(OBJ) idoso.cpp $(CFLAGS)

eventoinfantil.o:
	$(OBJ) eventoinfantil.cpp $(CFLAGS)

cinema.o:
	$(OBJ) cinema.cpp $(CFLAGS)

eventoadulto.o:
	$(OBJ) eventoadulto.cpp $(CFLAGS)

show.o:
	$(OBJ) show.cpp $(CFLAGS)

boate.o:
	$(OBJ) boate.cpp $(CFLAGS)

teatrofantoche.o:
	$(OBJ) teatrofantoche.cpp $(CFLAGS)

usuario.o:
	$(OBJ) usuario.cpp $(CFLAGS)

evento.o:
	$(OBJ) evento.cpp $(CFLAGS)

csvprocessor.o:
	$(OBJ) csvprocessor.cpp $(CFLAGS)

# Deletar arquivos objeto
clear:
	rm *.o