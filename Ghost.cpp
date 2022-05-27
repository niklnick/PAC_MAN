#include "Ghost.h"

Ghost::Ghost(const unsigned int &posIndex, const Color &color) : Character(posIndex, RADIUS, color) {

}

void Ghost::render(RenderWindow &target, maze::Node *nodeList) {
    maze::Node *node = &nodeList[_posIndex];
    node->character = this;
}
