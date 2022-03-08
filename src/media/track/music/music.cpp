#include "../../../../include/media/track/music/music.hpp"
/*******************************
** Construtores e Destrutores **
********************************/

Music::Music()
{
    Clean();
}

Music::Music(string istreamfile)
{
    string temp;

    istringstream strg(istreamfile);
    getline(strg, track_type_, ';');
    getline(strg, title_, ';');
    getline(strg, artist_, ';');
    getline(strg, album_, ';');
    getline(strg, gender_, ';');
    getline(strg, year_, ';');
    getline(strg, temp, ';');

    duration_ = DurationConverter(temp);
}


/******************************
********* Métodos SET *********
*******************************/

void Music::SetGender(string gender)
{
    gender_ = gender;
}

void Music::SetYear(string year)
{
    year_ = year;
}


/******************************
********* Métodos GET *********
*******************************/

string Music::GetGender(void)
{
    return gender_;
}

string Music::GetYear(void)
{
    return year_;
}


/******************************
****** Métodos Virtuais *******
*******************************/

void Music::Clean()                         ///Método para limpar a Class Music
{
    title_ = "notitle";
    artist_ = "noartist";
    album_ = "noalbum";
    gender_ = "nogender";
    year_ = "noyear";
    duration_ = 0.0;
}


string Music::ReadCSVTrackInfo(void)
{
    stringstream input;

    input << &title_ << ";";
    input << artist_ << ";";
    input << album_ << ";";
    input << gender_ << ";";
    input << year_ << ";";
    input << duration_ << ";";

    return input.str();
}


/******************************
********* Operadores **********
*******************************/


istream& operator>> (istream& in, Music &m)                         ///Operador para inserir informações de música e podcast
{
    string comma = ";";
    m.track_type_ = "Music;";
    cout << "Adicionando Música\n\n\nDigite o nome da Música: ";
    in >> m.track_type_ >> comma;
    cout << "Digite o nome do artista: ";
    in >> m.artist_ >> comma;
    cout << "Digite o nome do album: ";
    in >> m.album_ >> comma;
    cout << "Digite a categoria do podcast: ";
    in >> m.gender_ >> comma;
    cout << "Informe a data de publicação do podcast";
    in >> m.year_ >> comma;
    cout << "Digite a duração da faixa de Podcast";
    in >> m.duration_ >> comma;

    return in;
}

ostream& Music::PrintTrackInfo(ostream& out) const              ///Sobrecarga para saída formatada
{
    out << "Detalhes da faixa de Música" << endl << endl;
    out << "Título:" << title_ << endl;
    out << "Artista:\t" << artist_ << endl;
    out << "Album:\t " << album_ << endl;
    out << "Gênero:\t" << gender_ << endl;
    out << "Ano de gravação:\t" << year_ << endl;
    out << "Duração:\t" << duration_ << endl;

    return out;
}
