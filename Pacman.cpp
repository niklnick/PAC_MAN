#include "Pacman.h"

Pacman::Pacman(const unsigned int &posIndex) : Character(posIndex, RADIUS, Color::Yellow) {

}

void Pacman::render(RenderWindow &target, maze::Node *nodeList) {
    maze::Node *node = &nodeList[_posIndex];
    node->character = this;
}
