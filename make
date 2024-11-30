# # Class trajet
# g++ -c main.cpp -o bin/main.o
# g++ -c trajet.cpp -o bin/trajet.o
# g++ bin/main.o bin/trajet.o -o bin/programme
# ./bin/programme

# # Class trajetSimple
# g++ -c main.cpp -o bin/main.o
# g++ -c trajetSimple.cpp -o bin/trajetSimple.o
# g++ -c trajet.cpp -o bin/trajet.o
# g++ bin/main.o bin/trajet.o bin/trajetSimple.o -o bin/programme
# ./bin/programme

# Class trajetCompose
g++ -c main.cpp -o bin/main.o
g++ -c trajetSimple.cpp -o bin/trajetSimple.o
g++ -c trajetCompose.cpp -o bin/trajetCompose.o
g++ -c trajet.cpp -o bin/trajet.o
g++ bin/main.o bin/trajet.o bin/trajetSimple.o bin/trajetCompose.o -o bin/programme
./bin/programme