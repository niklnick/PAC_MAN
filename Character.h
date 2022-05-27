#ifndef PAC_MAN_CHARACTER_H
#define PAC_MAN_CHARACTER_H


#include <cmath>
#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#define PI 3.1415926535f
#define Deg2Rad PI / 180

using namespace std;
using namespace sf;

class Character {
protected:
    float _xPos, _yPos;
    Transform _transform;

    float _radius;
    ConvexShape _shape;

    float _movementSpeed;
    Vector2f _direction;

public:
    explicit Character(const float &, const Color &, const float &);

    virtual ~Character() = default;

    virtual void setPosition(const float &, const float &);

    virtual void move(const Vector2f &offset);

    virtual void collision(const RenderTarget &target);

    virtual void windowBoundsCollision(const RenderTarget &target);

    virtual void update(const RenderTarget &);

    virtual void render(RenderTarget &) = 0;

    virtual Vector2f getPosition() const;

    const float &getRadius() const;
};


#endif //PAC_MAN_CHARACTER_H
