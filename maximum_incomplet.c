#include "maximum_incomplet.h"


//Cette fonction retourne l'indice de l'element avec le plus d'arcs.
int max_arcs (int tailleGraphe, int graphe[tailleGraphe][tailleGraphe], int sousGraphe[tailleGraphe]) {
	int maxArc == 0
	int maxArcsIndice == -1;
	int compteurArcs;
	
	for(int i = 0; i<tailleGraphe; i++) {
		if(sousGraphe[i] == 1) {
			compteurArcs = 0
			for(int j = 0; j < tailleGraphe; j++) {
				if((graphe[i][j] == 1) && (sousGraphe[j] == 1)) compteurArcs++;
			}
			if(maxArcsIndice == -1) {
				maxArc = compteurArcs;
				maxArcsIndice = i; 
			}
			else {
				if (compteurArcs > maxArc) {
					maxArc = compteurArcs;
					maxArcsIndice = i;
				}
			}
		}
	}
	return maxArcsIndice;
}

int[] maximum_incomplet(int tailleGraphe, int graphe[tailleGraphe][tailleGraphe]) {
	int cp = 0;
	int sousGraphe[tailleGraphe]; // Tableau de booleans representant la liste des sommets du sous-graphe résltat.
	int removableElement;
	
	//initialistation du tableau sousGraphe.
	for(int i = 0; i<tailleGraphe ; i++) {
		sousGraphe[i] == 1;
	}
	
	//On retire Element par element en commançant par l'element avec le plus d'arcs vers les elements du sous-graphe (résultat obtenu avec la fonction MaxArcs).
	if(is_desert(tailleGraphe,graphe,sousGraphe) == 1) return sousGraphe;
	
	else {
		for(int i = 0 ; i < tailleGraphe ; i++) {
			removableElement = max_arcs(tailleGraphe,graphe,sousGraphe);
			sousGraphe[removableElement] = 0;
			if((is_desert(tailleGraphe,graphe,sousGraphe) == 1) return sousGraphe;
		}
	}
}
