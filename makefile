programme : main.o verification.o generate_graphe.o tools.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $< -o $@

verification.o : verification.c verification.h
	gcc -c $< -o $@

generate_graphe.o : generate_graphe.c generate_graphe.h
	gcc -c $< -o $@

tools.o : tools.c tools.h
	gcc -c $< -o $@


clean :
	rm -rf *.o
	rm -rf programme

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
