.SILENT:
default:
	clang++ -std=c++11 hotdesk.cpp -o bin/hotrun
	./bin/hotrun