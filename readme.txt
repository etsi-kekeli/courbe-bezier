Les fichiers d'entête contiennent des commentaires succincts du programme. Pour plus de 
détails, veuillez consulter les .cpp.
La bibliotèque gnuplot-iostream a été utilisé pour l'affichage graphique de la courbe de
bezier. Elle dépend de certaines bibliotèques dynamiques procurées par le package 'libgnuplot-iostream-dev'
pour fonctionner. Pour les installer sous 'ubuntu', exécutez :
sudo apt (votre gestionnaire de paquets) install libgnuplot-iostream-dev
Si vous êtes sous un autre système d'exploitation veuillez chercher et installé ce package.

Pour avoir un rendu plus interactif, veuillez installer gnuplot

Le programme résultant demande les coordonnées de 3 points par lesquels la courbe de bezier doit
passer. Le programme effectue 3 demandes. A chacune d'elle, entrez les coordonnées de même
nature (abscisse en 1er, ordonnées en 2e puis côte en dernier) de ces 3 points.
Si les points sont (1, 1, 1), (2, 4, 8) et (3, 2, 3), on entre 
1 2 3
1 4 2
1 8 3

La courbe de bezier appropriée est alors affichée à l'écran

On demande ensuite une valeur de t pour évaluer un point de la courbe de bezier.
