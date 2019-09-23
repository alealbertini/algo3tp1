all:
	g++ -o fuerzabruta fuerzabruta.cpp
	g++ -o backtracking backtracking.cpp
	g++ -o backtrackingSinPoda backtrackingSinPoda.cpp
	g++ -o experimentacion experimentacion.cpp
	g++ -o experimentacion-backtracking experimentacion-backtracking.cpp
	g++ -o experimentacion-bt-vs-dinamica experimentacion-bt-vs-dinamica.cpp
	g++ -o programaciondinamica programaciondinamica.cpp

fb:
	g++ -o fb fuerzabruta.cpp

bt:
	g++ -o bt backtracking.cpp

btsp:
	g++ -o btsp backtrackingSinPoda.cpp

exp:
	g++ -o exp experimentacion.cpp

expbt:
	g++ -o expbt experimentacion-backtracking.cpp

expvs:
	g++ -o expvs experimentacion-bt-vs-dinamica.cpp

pd:
	g++ -o pd programaciondinamica.cpp

clean:
	rm -f fb
	rm -f bt
	rm -f exp
	rm -f experimentacion
	rm -f expbt
	rm -f expvs
	rm -f pd

