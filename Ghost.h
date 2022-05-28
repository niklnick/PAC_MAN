#ifndef PAC_MAN_GHOST_H
#define PAC_MAN_GHOST_H


#include "Character.h"
#include "Maze.h"

class Ghost : public Character {
    Vector2i _dir;

public:
    Ghost() = delete;

    explicit Ghost(const unsigned int &, const Color &);

    bool updateInput(maze::Node *, const unsigned int &);

    bool updateDir(maze::Node *, int, int);

    void move(maze::Node *);

    void update(const RenderTarget &, maze::Node *);

    void render(RenderTarget &, maze::Node *);
};


#endif //PAC_MAN_GHOST_H
