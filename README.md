# cub3D
**This project is currently under construction and shared with [Yacine Bentayeb](https://github.com/yace1)**

---

Ce projet est inspiré du jeu Wolfeinstein3D, considéré comme le premier FPS
jamais développé. Il vous permettra d’explorer la technique du ray-casting. Votre objectif
est de faire une vue dynamique au sein d’un labyrinthe, dans lequel vous devrez trouver
votre chemin.

## Objectifs
- [x] Utiliser la mlx
- [x] Gestion de la fenêtre (minimalisation, passage d'une autre fenêtre, ...)
- [x] Afficher des textures selon la cardinalité
- [x] Le sol et le plafond doivent être des couleurs différentes (texture ?)
- [x] Le programme doit afficher une page d'accueil avec les règles du jeu
- [x] <- et -> du clavier permettent de modifier la angle de la caméra
- [x] W A S D permettent de déplacer le joueur
- [x] ESC quitte le programme proprement
- [x] La croix rouge aussi
- [x] Le programme doit prendre en arg un ***.cub***
- [x] La map .cub est compose de 6 caractères:
    - 0 les espaces vides
    - 1 les murs
    - N, S, W, E position de départ selon le sens du joueur
- [x] la map doit être entourée de murs et fermée
- [x] En cas de problème, le msg d'erreur **Error\n** suivi d'une explication de notre choix doit être afficher

## Map
    NO ./path_to_the_north_texture
    SO ./path_to_the_south_texture
    WE ./path_to_the_west_texture
    EA ./path_to_the_east_texture

    F 220,100,0
    C 225,30,0

            1111111111111111111111111
            1000000000110000000000001
            1011000001110000000000001
            1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001
    11110111111111011101010010001
    11000000110101011100000010001
    10000000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111

## Bonus
- [x] Gérer les collision contre les murs
- [x] Système de minicarte
- [x] Porte qui s'ouvre/ferme
- [x] Animation
- [x] faire pivoter le pov selon la souris et <- et ->
- [x] Le format de la map peut être modifier selon les besoin
