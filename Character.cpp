#include "Character.h"

Character::Character(const unsigned int &posIndex, const float &radius, const Color &color) {
    _posIndex = posIndex;
    _radius = radius;
    _color = color;
}

const unsigned int &Character::getPosIndex() const {
    return _posIndex;
}

const float &Character::getRadius() const {
    return _radius;
}

const Color &Character::getColor() const {
    return _color;
}
