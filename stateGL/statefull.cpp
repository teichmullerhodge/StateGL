#include "statefull.hpp"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

StateV<float> Statefull::size;
StateV<float> Statefull::e;
StateV<float> Statefull::x1, Statefull::x2, Statefull::x3, Statefull::x4;
StateV<float> Statefull::y1, Statefull::y2, Statefull::y3, Statefull::y4;
std::string Statefull::savePath;
bool Statefull::savePathLoaded;
bool Statefull::shouldReload;
fs::file_time_type Statefull::timestamp;

bool Statefull::init(const char *path) {
    shouldReload = false;
    savePath = path;
    timestamp = fs::file_time_type::clock::now();


    size.value = 0;
    size.index = 0;

    e.value = 0;
    e.index = 1;

    x1.value, x2.value, x3.value, x4.value = 0.0f;
    y1.value, y2.value, y3.value, y4.value = 0.0f;
    
    x1.index = 2;
    y1.index = 3;

    x2.index = 4;
    y2.index = 5;
    
    x3.index = 6;
    y3.index = 7;

    x4.index = 8;
    y4.index = 9;

    
    std::ifstream stateFile(path);
    savePathLoaded = stateFile.is_open();
    if (!stateFile.is_open()) {
        return false;
    }

    std::string contents;
    int currentLine = 0;
    while (std::getline(stateFile, contents)) {
        if (currentLine == size.index) {
            float value = std::stof(contents);
            if (value != 0.0f) {
                size.value = value;
            }
        }
        if (currentLine == e.index) {
            float value = std::stof(contents);
            if (value != 0.0f) {
                e.value = value;
            }
        }
        currentLine++;
    }

    return size.value != 0 || e.value != 0;
}


bool Statefull::watch_state() {
    fs::path filePath = Statefull::savePath;
    if (fs::exists(filePath)) {
        auto lastWriteTime = fs::last_write_time(filePath);
        if(lastWriteTime != timestamp){
            timestamp = lastWriteTime;
            std::ifstream file(filePath);            
            return reload_state(file);
        }
    }

    return false;

}

bool Statefull::reload_state(std::ifstream &f){

    std::string contents;
    bool hasChanges = false;
    int currentLine = 0;
    while (std::getline(f, contents)) {
        if (currentLine == size.index) {
            float value = std::stof(contents);
            if (value != 0.0f) {
                size.value = value;
                hasChanges = true;
            }
        }
        if (currentLine == e.index) {
            float value = std::stof(contents);
            if (value != 0.0f) {
                e.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == x1.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                x1.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == y1.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                y1.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == x2.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                x2.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == y2.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                y2.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == x3.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                x3.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == y3.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                y3.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == x4.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                x4.value = value;
                hasChanges = true;
            }
        }
        if(currentLine == y4.index){
            float value = std::stof(contents);
            if(value != 0.0f){
                y4.value = value;
                hasChanges = true;
            }
        }        
        currentLine++;
    }
    
    return hasChanges;


}
