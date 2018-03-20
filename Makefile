CC =g++
CFLAGS =-W -Wall -ansi -pedantic
LDFLAGS=
EXEC =monAppRun

all:$(EXEC)

monAppRun: application.o etudiant.o matiere.o section.o evaluation.o note.o bulletin.o main.o
	$(CC) -o monAppRun application.o etudiant.o matiere.o section.o evaluation.o note.o bulletin.o main.o 

application.o: application.cpp
	$(CC) -o application.o -c application.cpp $(CFLAGS)

etudiant.o: etudiant.cpp
	$(CC) -o etudiant.o -c etudiant.cpp $(CFLAGS)

matiere.o: matiere.cpp
	$(CC) -o matiere.o -c matiere.cpp $(CFLAGS)

section.o: section.cpp
	$(CC) -o section.o -c section.cpp $(CFLAGS)

evaluation.o: evaluation.cpp
	$(CC) -o evaluation.o -c evaluation.cpp $(CFLAGS)

note.o: note.cpp
	$(CC) -o note.o -c note.cpp $(FLAGS)

bulletin.o: bulletin.cpp
	$(CC) -o bulletin.o -c bulletin.cpp $(FLAGS)

main.o: main.cpp application.cpp etudiant.cpp matiere.cpp section.cpp evaluation.cpp 
	$(CC) -o main.o -c main.cpp $(CFLAGS)

clean:
	rm *.o monAppRun

exe : 
	./monAppRun 
