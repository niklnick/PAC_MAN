#ifndef PAC_MAN_PACMAN_H
#define PAC_MAN_PACMAN_H


#include "Character.h"
#include "Maze.h"

class Pacman : public Character {
    Vector2i _dir;

public:
    Pacman() = delete;

    explicit Pacman(const unsigned int &);

    bool updateInput(maze::Node *);

    bool updateDir(maze::Node *, int, int);

    void move(maze::Node *);

    void update(const RenderTarget &, maze::Node *);

    void render(RenderTarget &, maze::Node *);
};


#endif //PAC_MAN_PACMAN_H
