a.out: p.o cuac.o fecha.o DiccionarioCuacs.o
	g++ p.o cuac.o fecha.o DiccionarioCuacs.o

p.o: p.cpp cuac.h fecha.h DiccionarioCuacs.h
	g++ -c p.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h cuac.h fecha.h
	g++ -c DiccionarioCuacs.cpp

cuac.o: cuac.cpp cuac.h fecha.h
	g++ -c cuac.cpp

fecha.o: fecha.cpp fecha.h
	g++ -c fecha.cpp

