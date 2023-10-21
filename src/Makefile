IDIR=-I. -Isearch_algorithms -Isearch_algorithms/random_search
CFLAGS=$(IDIR) -std=c++20

build:
	[ ! -d "../build" ] && mkdir ../build; \
	g++ vectorUtils.cpp secondFunction.cpp firstFunction.cpp search_algorithms/result.cpp search_algorithms/random_search/randomSearch.cpp main.cpp -o ../build/main $(CFLAGS)

buildAndRun: build
	../build/main
