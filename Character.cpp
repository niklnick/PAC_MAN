#include "Character.h"

Character::Character(const float &radius, const Color &color, const float &movementSpeed) {
    _xPos = _yPos = 0;

    _radius = radius;
    _shape.setFillColor(color);

    _shape.setPointCount(360);
    for (auto i = 0; i < 360; i++)
        _shape.setPoint(i, Vector2f{
                _radius * cos(static_cast<float>(i) * Deg2Rad),
                _radius * sin(static_cast<float>(i) * Deg2Rad)
        });

    _movementSpeed = movementSpeed;
}

void Character::setPosition(const float &xPos, const float &yPos) {
    _transform.translate(xPos - _xPos, yPos - _yPos);
    _xPos = xPos;
    _yPos = yPos;
}

void Character::move(const Vector2f &offset) {
    _xPos += offset.x;
    _yPos += offset.y;
    _transform.translate(offset);
}

void Character::collision(const RenderTarget &target) {

}

void Character::windowBoundsCollision(const RenderTarget &target) {
    if (_xPos - _radius < 0.f) {
        _direction.x = 0.f;
        setPosition(_radius, _yPos);
    } else if (_xPos + _radius > static_cast<float>(target.getSize().x)) {
        _direction.x = 0.f;
        setPosition(static_cast<float>(target.getSize().x) - _radius, _yPos);
    }
    if (_yPos - _radius < 0.f) {
        _direction.y = 0.f;
        setPosition(_xPos, _radius);
    } else if (_yPos + _radius > static_cast<float>(target.getSize().y)) {
        _direction.y = 0.f;
        setPosition(_xPos, static_cast<float>(target.getSize().y) - _radius);
    }
}

void Character::update(const RenderTarget &target) {
    move(_direction);
    collision(target);
    windowBoundsCollision(target);
}


Vector2f Character::getPosition() const {
    return Vector2f{_xPos, _yPos};
}

const float &Character::getRadius() const {
    return _radius;
}
