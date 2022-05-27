#ifndef PAC_MAN_MAZEOLD_H
#define PAC_MAN_MAZEOLD_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#define GRID_WIDTH 22
#define GRID_HEIGHT 25

#define NODE_SIZE 32
#define NODE_BORDER_WIDTH 2

#define BORDER_TOP 0
#define BORDER_RIGHT 1
#define BORDER_BOTTOM 2
#define BORDER_LEFT 3

using namespace std;
using namespace sf;

namespace Maze {
    struct Node {
        bool _wall{false};
//        bool _walls[4]{false, false, false, false};
//        bool _paths[4]{true, true, true, true};
    };

    void drawNode(RenderWindow &, Node [], int, int);

    void drawMaze(RenderWindow &, Node []);
}


#endif //PAC_MAN_MAZEOLD_H
