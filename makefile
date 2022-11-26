password-manager: build/main.o build/utils.o
	g++ build/main.o build/utils.o -o password-manager
build/main.o:
	mkdir -p build
	g++ -c src/main.cpp -o build/main.o
build/utils.o:
	g++ -c src/utils.cpp -o build/utils.o
clean:
	rm -r build/ password-manager
run:
	./password-manager