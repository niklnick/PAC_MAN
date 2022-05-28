#ifndef PAC_MAN_MAZE_H
#define PAC_MAN_MAZE_H


#include <string>

#include "Character.h."

#define GRID_WIDTH 19
#define GRID_HEIGHT 21

#define NODE_SIZE 32.f
#define NODE_BORDER_WIDTH 2.f

#define MAZE_LAYOUT \
"1111111111111111111" \
"1000000001000000001" \
"1011011101011101101" \
"1000000000000000001" \
"1011010111110101101" \
"1000010001000100001" \
"1111011101011101111" \
"1111010000000101111" \
"1111010110110101111" \
"0000000100010000000" \
"1111010111110101111" \
"1111010000000101111" \
"1111010111110101111" \
"1000000001000000001" \
"1011011101011101101" \
"1001000000000001001" \
"1101010111110101011" \
"1000010001000100001" \
"1011111101011111101" \
"1000000000000000001" \
"1111111111111111111"

namespace maze {
    struct Node {
        bool wall{false};
        Character *character{nullptr};
    };

    unsigned int column(unsigned int);

    unsigned int row(unsigned int);

    void drawNode(RenderWindow &, Node *, unsigned int);

    void drawMaze(RenderWindow &, Node *);
}


#endif //PAC_MAN_MAZE_H
