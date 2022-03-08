#include "../../include/filemanager/filemanager.hpp"

FileManager::FileManager(int path_id)
{
    SetPath(1);
    ifstream ifile;
    ifile.open(GetPath().c_str());
    string line;
    while(!ifile.eof())
    {
        getline(ifile, line);
        vector<string>::iterator it;
        it = lines_.begin();
        lines_.insert(it,line);
        // string column = ReadColumn(line, 1);
    }
}
void FileManager::AddLine(string line)
{
    ofstream ofile;
    ofile.open(path_.c_str(), ios::app);
    if (ofile.is_open())
    {
        ofile << line;
    }
    else
    {
        throw("Erro ao abrir arquivo");
    }
}

// template <class CLASS>
// void ReadLine()
// {
//
// }


string FileManager::ReadColumn(string line, int column)
{
    istringstream line_data(line);
    string data;
    for(auto i(0); i < column; i++)
    {
        getline(line_data, data, ';');
    }
    return data;
}

bool FileManager::Find(string target)
{
    vector<string>::iterator it;
    it = find (lines_.begin(), lines_.end(), target);
    if(it != lines_.end())
        return false;
    return true;
}

void FileManager::SetPath(int path_id)
{
    switch (path_id)
    {
        case 1:
            path_ = "../../CSV/itracks.csv";
            break;
        case 2:
            path_ = "../../CSV/iartists.csv";
            break;
        case 3:
            path_ = "../../CSV/iusers.csv";
            break;
        case 4:
            path_ = "../../CSV/otracks.csv";
            break;
        case 5:
            path_ = "../../CSV/oartists.csv";
            break;
        case 6:
            path_ = "../../CSV/ousers.csv";
            break;
    }
}

FILE_PATH GetPath(void)
{
    return path_;
}
