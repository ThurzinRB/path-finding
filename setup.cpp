#include <raylib.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Obstacle.h"
#include "utilities.h"

using namespace std;

int main(int argc, const char **argv) {
    // Initialization
    int nodeM = 30;           // number of rows
    int nodeN = 50;           // number of columns
    const int nodeSize = 20;  // size of each node
    int screenWidth = nodeN * nodeSize;
    int screenHeight = nodeM * nodeSize;
    const char *windowTitle = "Path finding";

    InitWindow(screenWidth, screenHeight, windowTitle);

    // NOTE: The following only works after calling InitWindow() (i.e,. RayLib
    // is initialized)
    const Font font = GetFontDefault();

    SetTargetFPS(60);

    // Main loop

    vector<Obstacle> Obstacles;
    while (!WindowShouldClose()) {
        // Update the display
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int i = GetMousePosition().y / nodeSize;
            int j = GetMousePosition().x / nodeSize;
            if (!isObstacle(i, j, Obstacles)) {
                Obstacle obs(i, j);
                Obstacles.push_back(obs);
            }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Obstacles.clear();
        }

        for (int i = 0; i < nodeM; i++) {
            for (int j = 0; j < nodeN; j++) {
                DrawRectangleLines(j * nodeSize, i * nodeSize, nodeSize,
                                   nodeSize, BLACK);

                if (isObstacle(i, j, Obstacles)) {
                    DrawRectangle(j * nodeSize, i * nodeSize, nodeSize,
                                  nodeSize, BLACK);
                }
            }
        }

        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    ofstream myFile;
    myFile.open("obstacles.txt");
    myFile << "nodeM=" << nodeM << "\n";
    myFile << "nodeN=" << nodeN << "\n";
    myFile << "nodeSize=" << nodeSize << "\n";
    myFile << "Obstacles=";
    for (auto obs : Obstacles) {
        myFile << obs.getPos().xPos << "," << obs.getPos().yPos << ";";
    }
    myFile << "\n";

    // nodeM = 30; // number of rows
    // nodeN = 50; // number of columns
    // nodeSize = 20;
    myFile.close();

    return 0;
}
