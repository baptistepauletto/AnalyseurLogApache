ECHO=@echo
RM=@rm
COMP=g++
EDL=g++
CPPFLAGS=-g -Wall -ansi -std=c++11 -pedantic -o0
EDLFLAGS=
RMFLAGS=-f
INT= GestionnaireFichier.h Enregistrement.h Graphe.h Noeud.h 
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
INCPATH=
LIBPATH=
EXE=executable
LIBS=

.PHONY: clean

$(EXE) : $(OBJ) $(EXE).o
	$(ECHO) "EDL de $(EXE)"
	$(EDL) $(EDLFLAGS)-o $(EXE) $(OBJ) $(EXE).o
%.o : %.cpp
	$(ECHO) "Compilation de $<"
	$(COMP) $(CPPFLAGS) -o $@ -c $<
clean :
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core executable.o
