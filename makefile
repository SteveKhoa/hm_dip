.SILENT:
default:
	clang++ source/*.cc ready.cpp -o ready
	./ready

op:
	./$(tg)