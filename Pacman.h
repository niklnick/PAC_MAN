#ifndef PAC_MAN_PACMAN_H
#define PAC_MAN_PACMAN_H


#include "Character.h"
#include "Maze.h"

class Pacman : public Character {

public:
    Pacman() = delete;

    explicit Pacman(const unsigned int &);

    void render(RenderWindow &, maze::Node *);
};


#endif //PAC_MAN_PACMAN_H
