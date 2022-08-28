.SILENT:
default:
	clang++ -std=c++11 source/*.cc ready.cpp -o ready
	./ready

op:
	./$(tg)