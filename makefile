all:  test tavl

test: clean
	g++ test_tavl1.cc -o test
	./test

tavl: clean
	g++ test_class.cpp -o tavl
	./tavl

clean:
	rm test tavl -f
