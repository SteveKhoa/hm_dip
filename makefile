default:
	clang++ \
		*.cc \
		test.cpp \
	-o \
		test 

	./test
