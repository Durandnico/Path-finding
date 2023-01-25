# README
## Project : ING1-PathFinding

### Lancement :
  ```
make && ./bin/PathFinding
  ```

### Table des matières
1. [Sujet](#Sujet)
2. [Les technologies que j'ai appris](#Les-technologies-que-j'ai-appris)
3. [Supprimer l'éxécutable et les .o](#Supprimer-l'éxécutable-et-les-.o)
4. [Documentation Doxygen](#Documentation-Doxygen)

#### Sujet
***
Sujet personnel ayant pout but :
    -Faire un algorithme de pathfinding en recodant ma propre version de algorithme de Dijkstra en C
    -Faire une interface graphique en utilisant minilibx (librairie de l'école 42)
    
#### Les technologies que j'ai appris
***
Technique de vérification des leaks mémoires
    -Quantité de mémoire perdu : ```valgrind ./bin/Pathfindg```
    -Trouver facilement les mallocs avec ```grep "malloc" src/*``` 
#### Supprimer l'éxécutable et les .o
***
Pour supprimer les dossiers bin (executable), obj (fichiers .o) et doc (DoxyFile) :
```sh
make clean
```
#### Documentation Doxygen
***
En lançant cette commande :
```sh
make doc
```
La documentation Doxygen sera créée ou mise à jour si elle existe déjà.

Pour l'ouvrir dans Firefox faire :
```sh
make docHtml
```

### Crédits
***
Auteur : DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
