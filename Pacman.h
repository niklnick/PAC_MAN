#ifndef PAC_MAN_PACMAN_H
#define PAC_MAN_PACMAN_H


#include "Character.h"

class Pacman : public Character {

public:
    Pacman() = delete;

    explicit Pacman(const unsigned int &);
};


#endif //PAC_MAN_PACMAN_H
