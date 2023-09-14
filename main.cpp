#include <raylib.h>

#include <fstream>
#include <iostream>
#include <vector>
#include "utilities.h"

#include "Obstacle.h"

using namespace std;

int getNextValue(std::string line){
    int val;
    size_t delimiterPos = line.find('=');
    if (delimiterPos != string::npos) {
        // Split the line into two parts
        string key = line.substr(0, delimiterPos);
        string value = line.substr(delimiterPos + 1);
        val = stoi(value);

        // cout << "Key: " << key << ", Value: " << value << "\n";
    } else {
        // Handle lines without "=" delimiter as needed
        cout << "Invalid line: " << line << "\n";
    }
    return val;

}

void obstaclesFromText(string line, std::vector<Obstacle> &Obstacles){

    string value;
    size_t delimiterPos = line.find('=');
    if (delimiterPos != string::npos) {
        // Split the line into two parts
        string key = line.substr(0, delimiterPos);
        value = line.substr(delimiterPos + 1);
        // cout << "Key: " << key << ", Value: " << value << "\n";
    } else {
        // Handle lines without "=" delimiter as needed
        cout << "Invalid line: " << line << "\n";
    }
    cout<<value<<endl;

    delimiterPos = value.find(";");
    int count = 0;
    while (delimiterPos != string::npos){
        string obsString = value.substr(0, delimiterPos);
        size_t commaPos = obsString.find(",");
        int i = stoi(obsString.substr(0,commaPos));
        int j = stoi(obsString.substr(commaPos+1));
        if (!isObstacle(i, j, Obstacles)) {
                Obstacle obs(i, j);
                Obstacles.push_back(obs);
        }
        value = value.substr(delimiterPos + 1);
        delimiterPos = value.find(";");
        cout<<obsString<<"\ti: "<<i<<"\tj: "<<j<<endl;
        count++;
    }
    // cout<<count<<endl;
    
}

void openObstacleFile(const char* fileName, int &nodeM, int &nodeN, int &nodeSize, std::vector<Obstacle> &Obstacles) {
    ifstream myFile(fileName);
    string line;
    getline(myFile, line);
    nodeM = getNextValue(line);
    getline(myFile, line);
    nodeN = getNextValue(line);
    getline(myFile, line);
    nodeSize = getNextValue(line);
    getline(myFile, line);
    obstaclesFromText(line, Obstacles);




    
}

int main(int argc, const char** argv) {
    int nodeM, nodeN, nodeSize;
    vector<Obstacle> Obstacles;
    openObstacleFile("obstacles.txt", nodeM, nodeN, nodeSize, Obstacles);
    cout<<"Nodes: \n";
    cout<<nodeM<<endl;
    cout<<nodeN<<endl;
    cout<<nodeSize<<endl;
    cout<<Obstacles.size()<<endl;
    
    int screenWidth = nodeN * nodeSize;
    int screenHeight = nodeM * nodeSize;
    const char *windowTitle = "Path finding";

    InitWindow(screenWidth, screenHeight, windowTitle);

    // NOTE: The following only works after calling InitWindow() (i.e,. RayLib
    // is initialized)
    const Font font = GetFontDefault();

    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose()) {
        // Update the display
        BeginDrawing();
        ClearBackground(RAYWHITE);
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

    return 0;
}
