programme : main.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $< -o $@

tools.o : tools.c tools.h
	gcc -c $< -o $@

verification.o : verification.c verification.h
	gcc -c $< -o $@

maximal.o : maximal.c maximal.h
	gcc -c $< -o $@

generate_graph.o : generate_graph.c generate_graph.h
	gcc -c $< -o $@
	
maximum_exact.o : maximum_exact.c maximum_exact.h
	gcc -c $< -o $@

#maximum_incomplet.o : maximum_incomplet.c maximum_incomplet.h
#	gcc -c $< -o $@

clean :
	rm -rf *.o
	rm -rf programme

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
