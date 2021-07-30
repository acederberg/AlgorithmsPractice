all: 
	make build && make run;
all_sorting:
	make build_sorting && make run_sorting;
mk:
	@echo "\nBuilding...\n";
	[ -d Build ] || mkdir Build;
build:
	make mk
	g++ Stack.h -o Build/Stack.h.gch;
	g++ Main.c -o Build/a.out;
build_sorting:
	make mk
	g++ Sorting.h -o Build/Sorting.h.gch;
	g++ SortingMain.c -o Build/b.out;
clean:
	
	[ -d Build ] && rm -r Build
	python3 cleanup.py Stacks	

main: 
	g++ Main.c -o Build/a.out;
run:
	@echo "\nRunning compiled Main.c.\n";
	./Build/a.out;
run_sorting:
	@echo "\nRunning compiled SortingMain.c\n";
	./Build/b.out;
