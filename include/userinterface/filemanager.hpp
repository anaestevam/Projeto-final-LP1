#ifndef FILE_MANAGER_HPP
#define FINE_MANAGER_HPP

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::istringstream;

#include <iomanip>
using std::setw;
using std::setfill;
using std::ios;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

using std::stoi;



typedef const string FILE_PATH;


class FileManager
{
    private:
        vector<string> lines_;
        string path_;
    public:
        FileManager();
        FileManager(int path_id);
        void AddLine(string line);
        void ReadLine();
        string ReadColumn(string line, int column);
        bool Find(string target);
        void SetPath(int path_id);
        FILE_PATH GetPath(void);
};



#endif
