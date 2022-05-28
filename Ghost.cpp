#include "Ghost.h"

Ghost::Ghost(const unsigned int &posIndex, const Color &color) : Character(posIndex, RADIUS, color) {

}

bool Ghost::updateInput(maze::Node *nodeList, const unsigned int &random) {
    switch (random) {
        case 0:
            return updateDir(nodeList, 0, -1);
            break;
        case 1:
            return updateDir(nodeList, 1, 0);
            break;
        case 2:
            return updateDir(nodeList, 0, 1);
            break;
        case 3:
            return updateDir(nodeList, -1, 0);
            break;
        default:
            break;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
        return updateDir(nodeList, 0, -1);
    else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
        return updateDir(nodeList, 1, 0);
    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
        return updateDir(nodeList, 0, 1);
    else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        return updateDir(nodeList, -1, 0);
}

bool Ghost::updateDir(maze::Node *nodeList, int x, int y) {
    unsigned int toPosIndex = ((_posIndex + x) % GRID_WIDTH) + (GRID_WIDTH * (_posIndex / GRID_WIDTH) + GRID_WIDTH * y);
    maze::Node *toNode = &nodeList[toPosIndex];
    if (!toNode->wall) {
        _dir = Vector2i{x, y};
        return true;
    } else return false;
}

void Ghost::move(maze::Node *nodeList) {
    unsigned int toPosIndex = ((_posIndex + _dir.x) % GRID_WIDTH) + (GRID_WIDTH * (_posIndex / GRID_WIDTH) + GRID_WIDTH * _dir.y);
    maze::Node *fromNode = &nodeList[_posIndex], *toNode = &nodeList[toPosIndex];
    if (!toNode->wall) {
        fromNode->character = nullptr;
        toNode->character = this;
        _posIndex = toPosIndex;
    } else _dir = Vector2i{0, 0};
}

void Ghost::update(const RenderTarget &target, maze::Node *nodeList) {
    if (_clock.getElapsedTime().asMilliseconds() % 240 < 16 && (_dir.x != 0 || _dir.y != 0)) move(nodeList);
}

void Ghost::render(RenderTarget &target, maze::Node *nodeList) {
    maze::Node *node = &nodeList[_posIndex];
    node->character = this;
}
