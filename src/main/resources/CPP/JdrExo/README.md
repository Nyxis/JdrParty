Dans le but d'animer une soirée de JdR, un Game Master emmène un ensemble de matériel pour gérer les tirages aléatoires conséquents aux choix des joueurs.

À chaque action, le Game Master choisira au hasard l'un des éléments en sa possession pour tirer la valeur.
Cette valeur pourra être une réussite, un échec, une réussite critique ou un fumble. Selon l'action, le taux de réussite, de critique et de fumble sera variable.

1/ Modéliser une classe qui représente un résultat de tirage aléatoire.

2/ Modéliser un comportement correspondant au tirage de ces valeurs aléatoires.

3/ Le GM a à sa disposition 3 types de matériel. Créez et implémentez les classes correspondantes, en utilisant le comportement créé précédemment.
- le dé : il peut être créé avec une liste de faces, ou un nombre de face. Il génère une valeur correspondante à l'une de ses faces lors du tirage
- une pièce : elle ne peut renvoyer que deux valeurs, mais est dépendante d'un nombre de lancés : la génération ne renverra 1 que si les x lancés valent 1 (tips: utilisez une fonction récursive)
- un deck de cartes : il est dépendant d'un nombre de couleurs et de valeurs, sa méthode de génération renvoie une valeur entre 1 et nombre couleurs * nombres valeurs, après deux tirages le premier sur la couleur, le second sur la valeur.

4/ Créez maintenant une classe GameMaster.
- Un GameMaster dispose d'un nombre de dés conséquents de différents types, de deux decks de cartes l'un de trois couleurs de et 18 valeurs, le deuxième de 4 couleurs de 13 valeurs, et de deux pièces.
- un GameMaster peut effectuer des tirages via la méthode `pleaseGiveMeACrit`, avec les 3 taux (succès, critique, fumble) en paramètre exprimée en pourcentage. Le GameMaster sélectionne l'une des instances de Dice / Deck et Coin au hasard et renvoie une constante correspondant au type de résultat.

5/ Afin d'observer l'exécution de votre programme, proposez une implémentation d'une classe et d'une ou plusieurs méthodes pour écrire des messages dans la ligne de commande depuis vos classes, au lieu d'utiliser directement la librairie cout.
Proposition : une fonction log(message) doit être disponible dans cette classe.
Attention : vous devez trouver un moyen d'utiliser cette classe dans vos objets sans pour autant le passer en paramètres à la construction.


Implémentez ces 4 classes en C++, en respectant les principes SOLID; ainsi que le fichier main.