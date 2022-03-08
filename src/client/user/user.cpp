#include "../../../include/client/user/user.hpp"

/*******************************
** Construtores & Destrutores **
********************************/

User::User()
{
    Clean();
}

User::User(string istreamfile)
{
    istringstream strg(istreamfile);
    getline(strg, name_, ';');
    getline(strg, id_, ';');
    getline(strg, password_, ';');
    getline(strg, cpf_, ';');
    getline(strg, email_, ';');
    getline(strg, premium_, ';');
}

User::User(vector<string> in)
{
        name_ = in.at(1);
        id_ = in.at(2);
        password_ = in.at(3);
        cpf_ = in.at(4);
        email_ = in.at(5);
        premium_ = in.at(6);
}


/******************************
********* Métodos SET *********
*******************************/

/**
 *@brief          Método 'Set' para alterar o CPF do usuário comum
 *@param cpf      CPF do Usuário comum
**/
void User::SetUserCPF(string cpf)
{
    cpf_ = cpf;
}

/**
 *@brief          Método 'Set' para alterar o telefone do usuário comum
 *@param phone    Telefone do Usuário comum
**/
void User::SetUserPhone(string phone)
{
    phone_ = phone;
}

/**
 *@brief          Método 'Set' para alterar o email do usuário comum
 *@param email    email do Usuário comum
**/
void User::SetUserEmail(string email)
{
    email_ = email;
}

/**
 *@brief          Método 'Set' para alterar o status de premium do usuário comum
 *@param premium  'true' se o usuário estiver com serviço premium, 'false' caso contrário
**/
void User::SetUserPremium(string premium)
{
    premium_ = premium;
}


/******************************
********* Métodos GET *********
*******************************/

/**
 *@brief            Método 'Get' para retorno do CPF do usuário comum
 *@return cpf_      CPF do Usuário comum
**/
string User::GetUserCPF(void)
{
    return cpf_;
}

/**
 *@brief            Método 'Get' para retorno do telefone do usuário comum
 *@return phone_    Telefone do Usuário comum
**/
string User::GetUserPhone(void)
{
    return phone_;
}

/**
 *@brief            Método 'Get' para retorno do email do usuário comum
 *@return email_    Email do Usuário comum
**/
string User::GetUserEmail(void)
{
    return email_;
}

/**
 *@brief            Método 'Get' para retorno do status de 'premium' do usuário comum
 *@return premium_  'true' se o usuário estiver com serviço premium, 'false' caso contrário
**/
string User::GetUserPremium(void)
{
    return premium_;
}

/******************************
****** Métodos Virtuais *******
*******************************/
void User::Clean()
{
    name_ = "";
    id_ = "";
    password_ = "";
    cpf_ = "";
    phone_ = "";
    email_ = "";
    premium_ = "Não";
    playlists_.clear();
}

string User::GetCSV(void)
{
    stringstream input;
    input << name_ << ";";
    input << id_ << ";";
    input << password_ << ";";
    input << cpf_ << ";";
    input << phone_ << ";";
    input << email_ << ";";
    input << premium_ << ";";
    input << endl;

    return input.str();
}


/******************************
***** Métodos Adicionais ******
*******************************/
vector<Playlist *> User::AddPlaylist()
{
    Playlist aux;

}
