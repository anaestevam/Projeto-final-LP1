#include "../../../../include/media/track/podcast/podcast.hpp"
/*******************************
** Construtores e Destrutores **
********************************/

Podcast::Podcast()
{
    Clean();
}

Podcast::Podcast(string istreamfile)
{
    string temp;

    istringstream strg(istreamfile);
    getline(strg, track_type_, ';');
    getline(strg, title_, ';');
    getline(strg, artist_, ';');
    getline(strg, album_, ';');
    getline(strg, category_, ';');
    getline(strg, release_date_, ';');
    getline(strg, temp, ';');
    duration_ = DurationConverter(temp);


}


/******************************
********* Métodos SET *********
*******************************/

void Podcast::SetCategory(string category)
{
    category_ = category;
}

void Podcast::SetReleaseDate(string release_date)
{
    release_date_ = release_date;
}


/******************************
********* Métodos GET *********
*******************************/

string Podcast::GetCategory(void)
{
    return category_;
}

string Podcast::GetReleaseDate(void)
{
    return release_date_;
}

/******************************
****** Métodos Virtuais *******
*******************************/

void Podcast::Clean()                             ///Método para limpar a Class Podcast
{
    title_ = "notitle";
    artist_ = "noartist";
    album_ = "noalbum";
    category_ = "nogender";
    release_date_ = "";
    duration_ = 0.0;
}


string Podcast::ReadCSVTrackInfo(void)
{
    stringstream input;
    input << title_ << ";";
    input << artist_ << ";";
    input << album_ << ";";
    input << category_ << ";";
    input << release_date_ << ";";
    input << duration_ << ";";

    return input.str();
}


/******************************
********* Operadores **********
*******************************/


istream& operator>> (istream& in, Podcast &p)                             ///Operador para inserir informações de podcast
{
    string comma = ";";
    p.track_type_ = "Podcast;";
    cout << "Adicionando Podcast\n\n\nDigite o nome do Podcast: ";
    in >> p.track_type_ >> comma;
    cout << "Digite o nome do artista: ";
    in >> p.artist_ >> comma;
    cout << "Digite o nome do album: ";
    in >> p.album_ >> comma;
    cout << "Digite a categoria do podcast: ";
    in >> p.category_ >> comma;
    cout << "Informe a data de publicação do podcast";
    in >> p.release_date_ >> comma;
    cout << "Digite a duração da faixa de Podcast";
    in >> p.duration_ >> comma;

    return in;
}

ostream& Podcast::PrintTrackInfo(ostream& out) const                    ///Sobrecarga para saída formatada
{
    out << "Detalhes da faixa de podcast" << endl << endl;
    out << "Título:" << title_ << endl;
    out << "Artista:\t" << artist_ << endl;
    out << "Album:\t " << album_ << endl;
    out << "Categoria:\t" << category_ << endl;
    out << "Data de postagem:\t" << release_date_ << endl;
    out << "Duração:\t" << duration_ << endl;

    return out;
}
