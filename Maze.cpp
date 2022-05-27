#include "Maze.h"

unsigned int maze::column(unsigned int index) {
    return index % GRID_WIDTH;
}

unsigned int maze::row(unsigned int index) {
    return index / GRID_WIDTH;
}

void maze::drawNode(RenderWindow &window, Node *nodeList, unsigned int index) {
    Node *node = &(nodeList[index]);

    RectangleShape cell;
    cell.setPosition(float(column(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH,
                     float(row(index)) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE / 4 + NODE_BORDER_WIDTH);
    cell.setSize(Vector2f(NODE_SIZE / 2, NODE_SIZE / 2));
    cell.setFillColor(node->wall ? Color::Blue : Color::Black);
    window.draw(cell);
}

void maze::drawMaze(RenderWindow &window, Node *nodeList) {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++)
        drawNode(window, nodeList, i);
}
