programme : main.o tools.o check.o extract.o generate_graph.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $< -o $@

tools.o : tools.c tools.h
	gcc -c $< -o $@

check.o : check.c check.h
	gcc -c $< -o $@

extract.o : extract.c extract.h
	gcc -c $< -o $@

generate_graph.o : generate_graph.c generate_graph.h
	gcc -c $< -o $@

clean :
	rm -rf *.o
	rm -rf programme

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
