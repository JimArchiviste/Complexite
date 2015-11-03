is_desert : main_is_desert.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o maximum_partial.o
	gcc $^ -o $@
	
is_maximal : main_is_maximal.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o maximum_partial.o
	gcc $^ -o $@
	
gen_maximal : main_maximal.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o maximum_partial.o
	gcc $^ -o $@
	
gen_maximum_ex : main_maximum_exact.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o maximum_partial.o
	gcc $^ -o $@
	
gen_maximum_part : main_maximum_partial.o tools.o verification.o maximal.o generate_graph.o maximum_exact.o maximum_partial.o
	gcc $^ -o $@
	
main_is_desert.o : main_is_desert.c
	gcc -c $< -o $@
	
main_is_maximal.o : main_is_maximal.c
	gcc -c $< -o $@

main_maximal.o : main_maximal.c
	gcc -c $< -o $@
	
main_maximum_exact.o : main_maximum_exact.c
	gcc -c $< -o $@
	
main_maximum_partial.o : main_maximum_partial.c
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

maximum_partial.o : maximum_partial.c maximum_partial.h
	gcc -c $< -o $@

clean :
	rm -rf *.o
	rm -rf gen_maximal
	rm -rf gen_maximum_ex
	rm -rf gen_maximum_part
	rm -rf is_desert
	rm -rf is_maximal
	rm -rf maximal

mrproper: clean
	rm -rf *.txt


# $< est la première dépendance
# $@ est la cible
# $^ est la liste des dépendances
