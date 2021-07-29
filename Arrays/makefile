all:
	make clean && make build && make run;
build:
	make mk;
	g++ -o Build/a.out Main.c;
	g++ -o Build/Array.h.ghc Array.h;
clean:
	rm -r Build;
mk:
	[ -d Build ] || mkdir Build;
run:
	@echo "\nRunning the compiled Main.c";
	./Build/a.out;

