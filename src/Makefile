IDIR=-I. -Isearch_algorithms -Isearch_algorithms/random_search -Isearch_algorithms/tabu_search
CFLAGS=$(IDIR) -std=c++20

build:
	[ ! -d "../build" ] && mkdir ../build; \
	[ ! -d "../output" ] && mkdir ../output; \
	g++ vectorUtils.cpp secondFunction.cpp firstFunction.cpp search_algorithms/result.cpp search_algorithms/random_search/randomSearch.cpp search_algorithms/tabu_search/tabuSearch.cpp main.cpp -o ../build/main $(CFLAGS)
	g++ -fopenmp vectorUtils.cpp secondFunction.cpp firstFunction.cpp search_algorithms/result.cpp search_algorithms/random_search/randomSearch.cpp search_algorithms/tabu_search/tabuSearch.cpp main.cpp -o ../build/mainOpenMp $(CFLAGS)
	
buildAndRun: build
	../build/main
