CC  	= gcc
CCLIBS	= -lGL -lGLU -lglut
CCFLAGS	= -Wall -Wextra
PROGRAM	= endlessFlight
OBJ 	=		\
	main.o		\
	init.o		\
	callbacks.o		 
VPATH 	= src


%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CCLIBS) $(CCFLAGS)


.PHONY: clean

clean:
	rm -f src/*.swp *.swp *~ src/*~ *.o
