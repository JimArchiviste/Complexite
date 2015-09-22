programme : main.o verification.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $< -o $@

verification.o : verification.cpp verification.h
	gcc -c $< -o $@


clean :
	rm -rf *.o
	rm -rf programme

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
