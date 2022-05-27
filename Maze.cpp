#include "Maze.h"

unsigned int Maze::column(unsigned int index) {
    return index % GRID_WIDTH;
}

unsigned int Maze::row(unsigned int index) {
    return index / GRID_WIDTH;
}

void Maze::drawNode(RenderWindow &window, Node *nodeList, unsigned int index) {
    Node *node = &(nodeList[index]);

//    RectangleShape cell;
//    cell.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH,
//                     float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH);
//    cell.setSize(Vector2f(NODE_SIZE / 2, NODE_SIZE / 2));
//    cell.setFillColor(node->wall ? Color{16, 16, 16} : Color::Black);
//    window.draw(cell);

    RectangleShape wall;
    wall.setFillColor(Color::Blue);
    if (node->wall) {
        // top wall
        if (!nodeList[index - GRID_WIDTH].wall) {
            wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                             float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4);
            wall.setSize(Vector2f(NODE_SIZE / 2, NODE_BORDER_WIDTH));
            window.draw(wall);
            // top right wall
            if ((index + 1) % GRID_WIDTH != 0 && nodeList[index + 1].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4);
                wall.setSize(Vector2f(NODE_SIZE / 4, NODE_BORDER_WIDTH));
                window.draw(wall);
            }
            // top left wall
            if ((index + 1) % GRID_WIDTH != 1 &&nodeList[index - 1].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4);
                wall.setSize(Vector2f(NODE_SIZE / 4, NODE_BORDER_WIDTH));
                window.draw(wall);
            }
        }
        // right wall
        if ((index + 1) % GRID_WIDTH == 0 || !nodeList[index + 1].wall) {
            wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                             float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH);
            wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 2));
            window.draw(wall);
            // right top wall
            if (index > GRID_WIDTH - 1 && nodeList[index - GRID_WIDTH].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 4));
                window.draw(wall);
            }
            // right bottom wall
            if (index < (GRID_WIDTH * GRID_HEIGHT) - GRID_HEIGHT && nodeList[index + GRID_WIDTH].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 4));
                window.draw(wall);
            }
        }
        // bottom wall
        if (!nodeList[index + GRID_WIDTH].wall) {
            wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                             float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH);
            wall.setSize(Vector2f(NODE_SIZE / 2, NODE_BORDER_WIDTH));
            window.draw(wall);
            // bottom right wall
            if ((index + 1) % GRID_WIDTH != 0 &&nodeList[index + 1].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_SIZE / 4, NODE_BORDER_WIDTH));
                window.draw(wall);
            }
            // bottom left wall
            if ((index + 1) % GRID_WIDTH != 1 && nodeList[index - 1].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_SIZE / 4, NODE_BORDER_WIDTH));
                window.draw(wall);
            }
        }
        // left wall
        if ((index + 1) % GRID_WIDTH == 1 || !nodeList[index - 1].wall) {
            wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4,
                             float(row(index))* (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH);
            wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 2));
            window.draw(wall);
            // left top wall
            if (index > GRID_WIDTH - 1 && nodeList[index - GRID_WIDTH].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 4));
                window.draw(wall);
            }
            // left bottom wall
            if (index < (GRID_WIDTH * GRID_HEIGHT) - GRID_HEIGHT && nodeList[index + GRID_WIDTH].wall) {
                wall.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4,
                                 float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + 3 * NODE_SIZE / 4 + NODE_BORDER_WIDTH);
                wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE / 4));
                window.draw(wall);
            }
        }
    }
}

void Maze::drawMaze(RenderWindow &window, Node *nodeList) {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
        drawNode(window, nodeList, i);
}
