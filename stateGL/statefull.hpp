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
    static std::string savePath;
    static bool savePathLoaded;

    static std::filesystem::file_time_type timestamp;

    // ? methods 
    static bool init(const char *path);
    static void watch_state();
    static void reload_state(std::ifstream &f);
    
};