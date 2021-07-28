all: 
	make build && make run;
build:
	@echo "\nBuilding...\n";
	[ -d Build ] || mkdir Build;
	g++ Stack.h -o Build/Stack.h.gch;
	g++ Main.c -o Build/a.out;
clean:
	rm -r Build;
main:
	g++ Main.c -o Build/a.out;
run:
	@echo "\nRunning compiled Main.c.\n";
	./Build/a.out;
