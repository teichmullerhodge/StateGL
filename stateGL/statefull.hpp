#pragma once 
#include <GL/glut.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
template <typename T>
struct StateV {

    T value;
    int index;

};


class Statefull {

public:

    static StateV<float> size;
    static StateV<float> e;
    static StateV<float> x1, x2, x3, x4;
    static StateV<float> y1, y2, y3, y4;

    static std::string savePath;
    static bool savePathLoaded;
    static bool shouldReload;
    static std::filesystem::file_time_type timestamp;

    // ? methods 
    static bool init(const char *path);
    static bool watch_state();
    static bool reload_state(std::ifstream &f);
    
};