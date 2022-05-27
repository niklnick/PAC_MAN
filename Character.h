#ifndef PAC_MAN_CHARACTER_H
#define PAC_MAN_CHARACTER_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#define RADIUS 32.f

using namespace std;
using namespace sf;

class Character {
protected:
    unsigned int _posIndex;
    float _radius;
    Color _color;

public:
    Character() = delete;

    explicit Character(const unsigned int &, const float &, const Color &);

    virtual ~Character() = default;

    [[nodiscard]] virtual const unsigned int &getPosIndex() const;

    [[nodiscard]] virtual const float &getRadius() const;

    [[nodiscard]] virtual const Color &getColor() const;
};


#endif //PAC_MAN_CHARACTER_H
