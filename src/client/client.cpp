/* *
 * @file User.hpp
 * @brief Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @autoras Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @data 30/10/2019
* */

#include "../../include/client/client.hpp"


/******************************
********* Métodos SET *********
*******************************/

/**
 *@brief          Método 'Set' para alterar o nome do cliente
 *@param name     Nome do cliente
**/
void  Client::SetClientName (string name)
{
    name_ = name;
}

/**
 *@brief          Método 'Set' para alterar o ID do cliente
 *@param id       ID do cliente
**/
void  Client::SetClientID (string id)
{
    id_ = id;
}

/**
 *@brief          Método 'Set' para alterar a senha do cliente
 *@param password Senha do cliente
**/
void  Client::SetClientPassword (string password)
{
    password_ = password;
}

/******************************
********* Métodos GET *********
*******************************/

/**
 *@brief            Método 'Get' para retorno do nome do cliente
 *@return name_     Nome do cliente
**/
string Client::GetClientName (void)
{
    return name_;
}

/**
 *@brief          Método 'Get' para retorno do ID do cliente
 *@return id_     ID do cliente
**/
string  Client::GetClientID (void)
{
    return id_;
}

/**
 *@brief            Método 'Get' para retorno da senha do cliente
 *@return password_ Senha do cliente
**/
string Client::GetClientPassword (void)
{
    return password_;
}
