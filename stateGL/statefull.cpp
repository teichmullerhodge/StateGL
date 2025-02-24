#include "statefull.hpp"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

StateV<float> Statefull::size;
StateV<float> Statefull::e;
std::string Statefull::savePath;
bool Statefull::savePathLoaded;
fs::file_time_type Statefull::timestamp;

bool Statefull::init(const char *path) {

    savePath = path;
    timestamp = fs::file_time_type::clock::now();


    size.value = 0;
    size.index = 0;

    e.value = 0;
    e.index = 1;
    
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


void Statefull::watch_state() {
    fs::path filePath = Statefull::savePath;
    if (fs::exists(filePath)) {
        auto lastWriteTime = fs::last_write_time(filePath);
        if(lastWriteTime != timestamp){
            timestamp = lastWriteTime;
            std::ifstream file(filePath);            
            reload_state(file);
        }
    }

}

void Statefull::reload_state(std::ifstream &f){

    std::string contents;
    int currentLine = 0;
    while (std::getline(f, contents)) {
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


}
