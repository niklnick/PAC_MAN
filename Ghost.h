#ifndef PAC_MAN_GHOST_H
#define PAC_MAN_GHOST_H


#include "Character.h"
#include "Maze.h"

class Ghost : public Character {

public:
    Ghost() = delete;

    explicit Ghost(const unsigned int &, const Color &);

    void render(RenderTarget &, maze::Node *);
};


#endif //PAC_MAN_GHOST_H
