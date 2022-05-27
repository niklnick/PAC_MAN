#include <cmath>

#include "Pacman.h"

void Pacman::drawShape(const int &mouthOffset) {
    _shape.setPointCount(360 - 2 * mouthOffset);
    _shape.setPoint(0, Vector2f{});
    _shape.setPoint(1, Vector2f{32.f, 0.f});
    _shape.setPoint(2, Vector2f{32.f, 32.f});
    _shape.setPoint(3, Vector2f{0.f, 32.f});
    for (auto i = int(mouthOffset), index = 1; i < 360 - mouthOffset; i++, index++)
        _shape.setPoint(index, Vector2f{
                16.f * cos(static_cast<float>(i) * Deg2Rad),
                16.f * sin(static_cast<float>(i) * Deg2Rad)
        });
}

Pacman::Pacman(const float &radius, const float &movementSpeed) : Character(movementSpeed, Color::Yellow, radius) {
    drawShape(_mouthOffset = 30);
}

void Pacman::updateInput() {
    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        _shape.setRotation(180.f);
        _direction.x = -_movementSpeed;
        _direction.y = 0.f;
    } else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        _shape.setRotation(0.f);
        _direction.x = _movementSpeed;
        _direction.y = 0.f;
    } else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
        _shape.setRotation(270.f);
        _direction.x = 0.f;
        _direction.y = -_movementSpeed;
    } else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
        _shape.setRotation(90.f);
        _direction.x = 0.f;
        _direction.y = _movementSpeed;
    }
}

void Pacman::update(RenderTarget const &target) {
    updateInput();
    move(_direction);
    windowBoundsCollision(target);
}

void Pacman::animate() {
    if (_direction.x != 0.f || _direction.y != 0.f) {
        drawShape(int(abs(static_cast<float>(_mouthOffset) * cos(_clock.getElapsedTime().asSeconds() * Deg2Rad * 500))));
    } else drawShape(_mouthOffset);
}

void Pacman::render(RenderTarget &target) {
    animate();
    target.draw(_shape, _transform);
}
