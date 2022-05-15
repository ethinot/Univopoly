
#

  

Ce depot est un module (fichiers .h et .cpp) de notre Monopoly personaliser.

  

Il peut se compiler sous Linux, Windows, MacOS, en ligne de commande avec un IDE (codeblocks, visual code, QtCreator, etc..).

Il fait appel à la bibliothèque _**QT**_ une API orientée objet

  

# Pour compiler

  

### Préambule : si vous voulez un Linux sous Windows, installez WSL !

  

Voir la page de l'UE : https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows  

C'est léger, pratique, rapide et suffisant pour de nombreuses applications.

Windows/WSL est exactement comme une machine Linux avec des drivers minimalistes,
donc la gestion de certains périphériques commes la carte son ou l'accélération 3D peut ne pas marcher mais pour cette application ca peut être suffisant.
Il faut parcontre que vous ayez installé XMing pour pouvoir ouvrir des fenêtres comme expliqué sur la page du lien fournis.
Valgrind marche aussi !

*(partie prise du Readme.md de Pacman)*

  

### Pour installer QT

  

Pour installer Qt sous Linux ou avec WSL/Windows

```
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt-get install qt5-default
```

Pour installer Qt sous MacOS

```brew install qt5```



### Compilation de l'application en mode text

  

Compilation + Creation de l'executable dans ./bin/txt

 ```make -f makefile.txt```


Lancer l'executable exemple ```./bin/txt ```

*Univopoly en mode text narrative un peu de display au niveau des propriétés*
  

### Compilation de l'applicatiom en mode graphic Qt


Creation du makfile et les fichiers Qt necessaire 
```qmake```
Compilation + Creation de lexecutable a la racine du fichier 
```make```
Lancer l'executable exemple ```./univopoly_qt ```

*Une fenêtre Qt est ouverte, laissez-vous guider par les boutons et amusez vous bien*

  

## Arborescence

L'organistion des fichiers est la suivante.

```

module_image/

├─ bin/ (les executable)

├─ data/ (les assetes: image, donées, etc...)

├─ doc/ (documentation doxygen)

│ ├─ image.doxy

├─ obj/ (les compilations intermédiaires "fichiers objets" .o)

├─ src/ (les modules Image, Pixel, et les main)

│ ├─ mainAffichage.cpp

│ ├─ mainExemple.cpp

│ ├─ mainTest.cpp

│ ├─ Image.cpp

│ ├─ Image.h

│ ├─ Pixel.cpp

│ ├─ Pixel.h

├─ .gitignore

├─ makefile

├─ README.md
```

  

## Contribution et License

  

Contributeur :

  

- Enzo Ephrem p2019298

- Edouard Thinot p1909945
