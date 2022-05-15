
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

.
├── bin
├── data
│   └── tiles.json
├── doc
│	├── UML_Univopoly.drawio
│   └── univopoly.doxy
├── img
│   ├── build.png
│   ├── buy.png
│   ├── dontBuy.png
│   ├── player1.png
│   ├── player2.png
│   ├── player3.png
│   ├── player4.png
│   ├── player5.png
│   ├── player6.png
│   ├── player7.png
│   ├── player8.png
│   ├── roll_dice.png
│   ├── sell.png
│   ├── turnPass.png
│   ├── UCBL_logo.png
│   ├── UML_v1.png
│   ├── UML_v2.png
│   ├── Univopoly_Board.png
│   └── Univopoly_noshadow.png
├── obj
├── src
│   ├── core
│   │   ├── ai.cpp
│   │   ├── ai.h
│   │   ├── Board.cpp
│   │   ├── Board.h
│   │   ├── Dice.cpp
│   │   ├── Dice.h
│   │   ├── Game.cpp
│   │   ├── Game.h
│   │   ├── Gare.cpp
│   │   ├── Gare.h
│   │   ├── Inventory.cpp
│   │   ├── Inventory.h
│   │   ├── Player.cpp
│   │   ├── Player.h
│   │   ├── Property.cpp
│   │   ├── Property.h
│   │   ├── Tile.cpp
│   │   └── Tile.h
│   ├── qt
│   │   ├── extensions
│   │   │   ├── components
│   │   │   │   ├── mainView
│   │   │   │   │   ├── Board_qt.cpp
│   │   │   │   │   ├── Board_qt.h
│   │   │   │   │   ├── Lobby.cpp
│   │   │   │   │   ├── Lobby.h
│   │   │   │   │   ├── Tile_qt.cpp
│   │   │   │   │   └── Tile_qt.h
│   │   │   │   └── sideBar
│   │   │   │       ├── Controllers.cpp
│   │   │   │       ├── Controllers.h
│   │   │   │       ├── Dice_qt.cpp
│   │   │   │       ├── Dice_qt.h
│   │   │   │       ├── Player_qt.cpp
│   │   │   │       ├── Player_qt.h
│   │   │   │       ├── Players.cpp
│   │   │   │       └── Players.h
│   │   │   ├── mainView.cpp
│   │   │   ├── mainView.h
│   │   │   ├── sideBar.cpp
│   │   │   └── sideBar.h
│   │   ├── main_qt.cpp
│   │   ├── mainWindow.cpp
│   │   └── mainWindow.h
│   ├── txt
│   │   ├── Gametxt.cpp
│   │   ├── Gametxt.h
│   │   └── mainTxt.cpp
│   └── mainTest.cpp
├── .qmake.stash
├── makefile.txt
├── README.md
├── univopoly_qt.pro
```

  

## Contribution et License

  

Contributeur :

  

- Enzo Ephrem p2019298

- Edouard Thinot p1909945
