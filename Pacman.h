#ifndef PAC_MAN_PACMAN_H
#define PAC_MAN_PACMAN_H


#include "Character.h"

class Pacman : public Character {
    Clock _clock;
    int _mouthOffset;

    void drawShape(const int &);

public:
    Pacman(const float &, const float &);

    void updateInput();

    void update(RenderTarget const &) override;

    void animate();

    void render(RenderTarget &) override;
};


#endif //PAC_MAN_PACMAN_H
