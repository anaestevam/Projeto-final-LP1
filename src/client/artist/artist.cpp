/* *
 * @file User.hpp
 * @brief Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @autoras Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @data 30/10/2019
* */

#include "../../../include/client/artist/artist.hpp"
class Client;
Artist::Artist()
{
    Clean();
}

Artist::Artist(string istreamfile)
{
    string temp;
    istringstream strg(istreamfile);
    getline(strg, name_, ';');
    getline(strg, id_, ';');
    getline(strg, password_, ';');
    getline(strg, temp, ';');

    albuns_count_ = stoi(temp);
}

Artist::Artist(vector<string> in)
{
    name_ = in.at(1);
    id_ = in.at(2);
    password_ = in.at(3);
    albuns_count_ = stoi(in.at(4));
}

/******************************
********* Métodos SET *********
*******************************/
void Artist::SetAlbunsCount(int albuns_count)
{
    albuns_count_ = albuns_count;
}

/******************************
********* Métodos GET *********
*******************************/
int Artist::GetAlbunsCount(void)
{
    return albuns_count_;
}


/******************************
****** Métodos Virtuais *******
*******************************/
void Artist::Clean()
{
    name_ = "";
    id_ = "";
    password_ = "";
    albuns_.clear();
}

string Artist::GetCSV(void)
{
    stringstream input;
    input << name_ << ";";
    input << id_ << ";";
    input << password_ << ";";

    return input.str();
}

/******************************
***** Métodos Adicionais ******
*******************************/
vector<Album*> AddAlbum();
