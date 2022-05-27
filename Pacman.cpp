#include "Pacman.h"

Pacman::Pacman(const unsigned int &posIndex) : Character(posIndex, RADIUS, Color::Yellow) {
    _dir = Direction::IDLE;
}

void Pacman::move(maze::Node *nodeList) {
    maze::Node *fromNode = &nodeList[_posIndex], *toNode = &nodeList[_posIndex + _dir];
    if (!toNode->wall) {
        fromNode->character = nullptr;
        toNode->character = this;
        _posIndex += _dir;
    } else _dir = Direction::IDLE;
}

void Pacman::updateInput() {
    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
        _dir = Direction::UP;
    else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
        _dir = Direction::RIGHT;
    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
        _dir = Direction::DOWN;
    else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        _dir = Direction::LEFT;
}

void Pacman::update(const RenderTarget &target, maze::Node *nodeList) {
    move(nodeList);
    updateInput();
}

void Pacman::render(RenderTarget &target, maze::Node *nodeList) {
    maze::Node *node = &nodeList[_posIndex];
    node->character = this;
}
