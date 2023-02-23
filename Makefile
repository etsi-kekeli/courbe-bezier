CC = g++
DLINK = -lboost_iostreams -lboost_system -lboost_filesystem

test.o: test.cpp
	$(CC) -c test.cpp
ConstruitCourbe.o: ConstruitCourbe.cpp
	$(CC) -c ConstruitCourbe.cpp
CourbeBezier.o: CourbeBezier.cpp
	$(CC) -c CourbeBezier.cpp
Matrice.o: Matrice.cpp
	$(CC) -c Matrice.cpp
Vecteur3d.o: Vecteur3d.cpp
	$(CC) -c Vecteur3d.cpp
test_program: test.o ConstruitCourbe.o Matrice.o Vecteur3d.o CourbeBezier.o
	$(CC) -std=c++17 $^ $(DLINK) -o $@

clean:
	rm -f *.o test_program

.PHONY: clean rebuild

rebuild: clean test_program