programme : main.o check.o generate.o tools.o desert_maximal.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $< -o $@

check.o : check.c check.h
	gcc -c $< -o $@

generate.o : generate.c generate.h
	gcc -c $< -o $@

tools.o : tools.c tools.h
	gcc -c $< -o $@
	
desert_maximal.o : desert_maximal.c desert_maximal.h
	gcc -c $< -o $@


clean :
	rm -rf *.o
	rm -rf programme

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
