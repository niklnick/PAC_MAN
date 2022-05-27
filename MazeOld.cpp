#include "MazeOld.h"

void Maze::drawNode(RenderWindow &window, Node *nodeList, int col, int row) {
    Node *node = &(nodeList[col + row * GRID_WIDTH]);

    RectangleShape cell;
    cell.setPosition(float(col) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH,
                     float(row) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH);
    cell.setSize(Vector2f(NODE_SIZE, NODE_SIZE));
    cell.setFillColor(Color{16, 16, 16});
    window.draw(cell);

    RectangleShape wall;
    wall.setFillColor(Color::Blue);
    if (node->_wall) {
        // top wall
        wall.setPosition(float(col) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH,
                         float(row) * (NODE_SIZE + NODE_BORDER_WIDTH));
        wall.setSize(Vector2f(NODE_SIZE, NODE_BORDER_WIDTH));
        window.draw(wall);
        // right wall
        wall.setPosition(float(col) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE + NODE_BORDER_WIDTH,
                         float(row) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH);
        wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE));
        window.draw(wall);
        // bottom wall
        wall.setPosition(float(col) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH,
                         float(row) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_SIZE + NODE_BORDER_WIDTH);
        wall.setSize(Vector2f(NODE_SIZE, NODE_BORDER_WIDTH));
        window.draw(wall);
        // left wall
        wall.setPosition(float(col) * (NODE_SIZE + NODE_BORDER_WIDTH),
                         float(row) * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH);
        wall.setSize(Vector2f(NODE_BORDER_WIDTH, NODE_SIZE));
        window.draw(wall);
    }
}

void Maze::drawMaze(RenderWindow &window, Node *nodeList) {
    for (int col = 0; col < GRID_WIDTH; ++col)
        for (int row = 0; row < GRID_HEIGHT; ++row)
            drawNode(window, nodeList, col, row);
}
