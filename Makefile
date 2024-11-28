# Variables
CXX = g++
CXXFLAGS = -ansi -pedantic –Wall –std=c++11
OBJ = main.o catalogue.o trajet.o trajetSimple.o trajetCompose.o
EXEC = programme

# Règle par défaut
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers objets
main.o: main.cpp catalogue.h trajet.h trajetSimple.h trajetCompose.h
	$(CXX) $(CXXFLAGS) -c $<

catalogue.o: catalogue.cpp catalogue.h trajet.h trajetSimple.h trajetCompose.h
	$(CXX) $(CXXFLAGS) -c $<

trajet.o: trajet.cpp trajet.h
	$(CXX) $(CXXFLAGS) -c $<

trajetSimple.o: trajetSimple.cpp trajetSimple.h trajet.h
	$(CXX) $(CXXFLAGS) -c $<

trajetCompose.o: trajetCompose.cpp trajetCompose.h trajet.h
	$(CXX) $(CXXFLAGS) -c $<

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Nettoyage complet (inclut les fichiers temporaires)
distclean: clean
	rm -f *~
