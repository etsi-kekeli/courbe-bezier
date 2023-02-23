test.o: test.cpp
	g++ -c test.cpp
ConstruitCourbe.o: ConstruitCourbe.cpp
	g++ -c ConstruitCourbe.cpp
CourbeBezier.o: CourbeBezier.cpp
	g++ -c CourbeBezier.cpp
Matrice.o: Matrice.cpp
	g++ -c Matrice.cpp
Vecteur3d.o: Vecteur3d.cpp
	g++ -c Vecteur3d.cpp
test_program: test.o ConstruitCourbe.o Matrice.o Vecteur3d.o CourbeBezier.o
	g++ -std=c++17 *.o -lboost_iostreams -lboost_system -lboost_filesystem -o test_program