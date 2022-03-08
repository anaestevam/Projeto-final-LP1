#include "../../include/userinterface/ui.hpp"

UserInterface::UserInterface(void)
{
	UiClearScreen();
	// UiLogo();
	UiLogo();
	cout << setfill(' ') << "|Inicializando Sistema..." << setw(49) << '|' << endl;
	UiLayer("bottom");
	UiPressToGo();

	UiStartMenu();
}

void UserInterface::UiStartMenu()
{
	bool control = true;
    int option;

	while (control)
    {
		UiLogo();
		cout << setfill(' ') << "|Escolha a opção desejada:" << setw(48) << "|" << endl;
		cout << setfill(' ') << "|1 - Entrar" << setw(63) << "|" << endl;
		cout << setfill(' ') << "|2 - Inscrever-se" << setw(57) << "|" << endl;
		cout << setfill(' ') << "|3 - Sair" << setw(65) << "|" << endl;
		UiLayer("bottom");
		cout << "==>  ";
		cin >> option;
		UiPressToGo();
        switch (option)
        {
            case 1:
                control = false;
				UiLogo();
				cout << setfill(' ') << "|Vamos fazer login" << setw(56) << '|' << endl;
				UiLayer("bottom");
                UiPressToGo();
                UiClientLogin();
            	break;
            case 2:
                control = false;
				UiLogo();
				cout << setfill(' ') << "|Faça sua inscrição aqui" << setw(50) << '|' <<  endl;
				UiLayer("bottom");
				UiPressToGo();
				UiClientRegister();
            	break;
            case 3:
                control = false;
				UiLogo();
                cout << setfill(' ') << "|vamos encerrar" << setw(59) << '|' << endl;
				UiLayer("bottom");
				UiPressToGo();
            	break;
            default:
				UiLogo();
                cout << setfill(' ') << "|Digite uma opção válida." << setw(49) << '|' << endl;
				UiLayer("bottom");
				UiPressToGo();
        }

    }
}


void UserInterface::UiClientRegister()
{
	system("clear");
	char option;
	string aux;
	bool control = true;
	bool isartist = false;


	while(control)
	{
		UiLogo();
		UiLayer("register");
		cout << setfill(' ') << "|Digite as informações a seguir" << setw(43) << '|' << endl;
		cout << setfill(' ') << "|Nome" << setw(69) << '|' << endl;
		UiLayer("bottom");
		cout << "==>  ";
		getline(cin, aux);
		client_atributes_.push_back(aux);
		aux.clear();

		UiLogo();
		UiLayer("register");
		cout << setfill(' ') << "|Email" << setw(68) << '|' << endl;
		UiLayer("bottom");
		cout << "==>  ";
		getline(cin, aux);
		client_atributes_.push_back(aux);
		aux.clear();
		string passc;
		UiLogo();
		UiLayer("register");
		cout << setfill(' ') << "|Senha" << setw(68) << '|' << endl;
		UiLayer("bottom");
		cout << "==>  ";
		getline(cin, aux);

		UiLogo();
		UiLayer("register");
		cout << setfill(' ') << "|Digite sua senha novamente para confirmar" << setw(32) << '|' << endl;
		UiLayer("bottom");
		cout << "==>  ";
		getline(cin, passc);

		if(passc == aux)
		{
			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|Sua senha foi confirmada!" << setw(48) << '|' << endl;
			UiLayer("bottom");
		}
		else
		{

			UiLogo();
			UiLayer("register");
			cerr << setfill(' ') << "|Senhas incompatíveis. Tente mais uma vez." << setw(32) << '|' << endl;
			cout << setfill(' ') << "|Senha" << setw(68) << '|' << endl;
			UiLayer("bottom");
			cout << "==>  ";
			getline(cin, aux);

			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|Digite sua senha novamente para confirmar" << setw(32) << '|' << endl;
			UiLayer("bottom");
			cout << "==>  ";
			getline(cin, passc);

			if(passc == aux)
			{
				UiLogo();
				UiLayer("register");
				cout << setfill(' ') << "|Sua senha foi confirmada!" << setw(48) << '|' << endl;
				UiLayer("bottom");
			}
			else
			{
				UiLogo();
				UiLayer("register");
				cout << setfill(' ') << "|Sua senha está incorreta mais uma vez!" << setw(35) << '|' << endl;
				cout << setfill(' ') << "|Voltando para o menu inicial" << setw(45) << '|' << endl;
				UiStartMenu();
				UiLayer("bottom");
			}

		}


		aux.clear();

		UiLogo();
		UiLayer("register");
		cout << setfill(' ') << "|Você é artista (S/n)?" << setw(52) << '|' << endl;
		cout << "==> ";
		cin.clear();
		cin >> option;
		if(option == 's' || option == 'S')
		{
			isartist = true;
			control = false;
			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|Quantos albuns você quer cadastrar?" << setw(38) << '|' << endl;
			cout << setfill(' ') << "|Caso não saiba o total de albuns, digite 0" << setw(31) << '|' << endl;
			UiLayer("bottom");
			cout << "==> ";
			cin.clear();

			getline(cin, aux);
			client_atributes_.push_back(aux);
			aux.clear();
		}
		else if (option == 'n' || option == 'N')
		{
			control = false;
			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|CPF" << setw(70) << '|' << endl;
			UiLayer("bottom");
			cout << "==> ";
			string cpf;
			getline(cin, cpf);

			client_atributes_.push_back(aux);
			aux.clear();

			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|Telefone" << setw(65) << '|' << endl;
			UiLayer("bottom");
			cout << "==> ";
			getline(cin, aux);
			client_atributes_.push_back(aux);
			aux.clear();

			UiLogo();
			UiLayer("register");
			cout << setfill(' ') << "|Email" << setw(68) << '|' << endl;
			UiLayer("bottom");
			cout << "==> ";
			getline(cin, aux);
			client_atributes_.push_back(aux);
			aux.clear();

			UiVipLogo("não");
			UiLayer("register");
			cout << setfill(' ') << "|Deseja se tornar um Usuário X-VIP (S/n)?" << setw(33) << '|' << endl;
			UiLayer("bottom");
			cout << "==> ";
			cin >> option;
			if(option == 's' || option == 'S')
				UiSetUserPremium();
			else
				cout << "\t\t\t¯" << "'\'" << "_(ツ)_/¯" << endl << "Tudo bem... Fica pra próxima!" << endl;
			UiPressToGo();


		}
	}
}

void UserInterface::UiClientLogin()

{
	UiClearScreen();
	string login;
	string senha;
	bool control = true;
	int option; // para teste e entrada no if

	cout << "===== Para continuar, faça login no XMUSIC =====" << endl;
	cout << "Login: ";
	cin >> login;

	cout << "Senha: ";
	cin >> senha;

	// verificar login e senha no vetor de pessoa/usuario.

	//criar vector de pessoa para realizar verificação
	//std::map<key, value> map;
	cout << "opção teste para entrar: ";
	//cin >> option;

	while (control)
    {
        if (cin >> option)
        {
            switch(option)
            {
                case 1:
                    control = false;
                    cout << "entrou no login aehoooo" << endl;
                    interfaceLogado();
                break;

                case 2:
                    control = false;
                    cout << "login incorreto" << endl;
                break;
            }
        }
	}
}

void UserInterface::interfaceLogado() {

	system("clear");
    bool control = true;
    int option;

	cout << "======== BEM VINDO FULANO ========" << endl << endl; // FULANO VAI SER O NOME DO USUÁRIO DADO NO CADASTRO
    cout << "1 - Pesquisar" << endl;    // pesquisa de usuário e playlist de outros?
    cout << "2 - Playlist" << endl;
    cout << "3 - Sair" << endl;

    while (control)
    {
		std::cout << "Escolha a opção desejada: ";
        if (cin >> option)
        {
            switch(option)
            {
                case 1:
                    control = false;
                    cout << "vamos pesquisar" << endl;
                    interfacePesquisar();
                break;

                case 2:
                    control = false;
                    cout << "vamos para playlist" << endl;
                    interfacePlaylist();
                break;

                case 3:
                    control = false;
                    cout << "vamos voltar" << endl;
                    //ANTES DE SAIR TEM QUE SALVAR TUDO QUE FOI FEITO ANTES
                    UiClientLogin();
                break;

                default:
                    cout << "Digite uma opção válida" << endl;
            }
        }
    }
}

void UserInterface::interfacePesquisar() {

	system("clear");
    bool control = true;
    int option;

    string music;
    string artist;
    string album;

	cout << "======== OPÇÕES DE BUSCA ========" << endl << endl; // FULANO VAI SER O NOME DO USUÁRIO DADO NO CADASTRO
    cout << "1 - Música" << endl;    // pesquisa de usuário e playlist de outros?
    cout << "2 - Artista" << endl;
    cout << "3 - Álbum" << endl;
    cout << "4 - Voltar" << endl;

    while (control)
    {
		cout << "Escolha a opção desejada: ";

        if (cin >> option)
        {
            switch(option)
            {
                case 1:
                    control = false;
                    cout << "Nome da música: " << endl;
                    cin >> music;

                    // LISTA TODAS AS MUSICAS COM A STRING DADA

                break;

                case 2:
                    control = false;
                    cout << "Nome do artista: " << endl;
                    cin >> artist;

                    // LISTA TODOS OS ARTISTAS COM A STRING DADA

                break;

                case 3:
                    control = false;
                    cout << "Nome do álbum: " << endl;
                    cin >> album;

                    // LISTA TODOS OS ALBUNS COM A STRING DADA

                    // POR PADRÃO, O PRIMEIRO INDICE DO VETOR SERA IMPRESSO E DEPOIS OS CORRESPONDENTES

                break;

                case 4:
                    control = false;
                    interfaceLogado();

                break;

                default:
                    cout << "Digite uma opção válida" << endl;
            }
        }
    }
}


void UserInterface::interfacePlaylist() {

    system("clear");
    bool control = true;
    int option;

    cout << "======== OPÇÕES DE PLAYLIST ========" << endl << endl; // FULANO VAI SER O NOME DO USUÁRIO DADO NO CADASTRO
    cout << "1 - Consultar" << endl;    // pesquisa de usuário e playlist de outros?
    cout << "2 - Criar" << endl;
    cout << "3 - Excluir" << endl;
    cout << "4 - Voltar" << endl;

    while (control)
    {
        std::cout << "Escolha a opção desejada: ";
        if (cin >> option)
        {
            switch(option)
            {
                case 1:
                    control = false;
                    cout << "CONSULTAR PLAYLIST" << endl;
                break;

                case 2:
                    control = false;
                    cout << "CRIAR PLAYLIST" << endl;
                    adicionarMusicaPlaylist();
                break;

                case 3:
                    control = false;
                    cout << "EXCLUIR PLAYLIST" << endl;
                break;

                case 4:
                    control = false;
                    cout << "VOLTAR" << endl;
                    interfaceLogado();
                break;

                default:
                    cout << "Digite uma opção válida" << endl;
            }
        }
    }
}

// como vai funcionar a questão de escolha de musicas? vai ser por opções numéricas?
void UserInterface::adicionarMusicaPlaylist()
{}

void UserInterface::AddLine(string line, PATH path)
{
    ofstream ofile(line);

    ofile.open(path.c_str(), ios::app);
    if (ofile.is_open())
    {
        ofile << line;
    }
    else
    {
        throw("Erro ao abrir arquivo");
    }
}

string UserInterface::ReadColumn(string line, int column)
{
	istringstream line_data(line);
    string data;
    for(auto i(0); i < column; i++)
    {
        getline(line_data, data, ';');
    }
    return data;
}



void UserInterface::UiLogo(void)
{
	UiClearScreen();
	cout << "|========================================================================|"<< endl;
	cout << "| ▀████    ▐████▀   ▄▄▄▄███▄▄▄▄   ███    █▄     ▄████████  ▄█   ▄████████|"<< endl;
	cout << "|  ███▌   ████▀  ▄██▀▀▀███▀▀▀██▄ ███    ███   ███    ███ ███  ███    ███ |"<< endl;
	cout << "|   ███  ▐███    ███   ███   ███ ███    ███   ███    █▀  ███▌ ███    █▀  |"<< endl;
	cout << "|   ▀███▄███▀    ███   ███   ███ ███    ███   ███        ███▌ ███        |"<< endl;
	cout << "|   ████▀██▄     ███   ███   ███ ███    ███ ▀███████████ ███▌ ███        |"<< endl;
	cout << "|  ▐███  ▀███    ███   ███   ███ ███    ███          ███ ███  ███    █▄  |"<< endl;
	cout << "| ▄███     ███▄  ███   ███   ███ ███    ███    ▄█    ███ ███  ███    ███ |"<< endl;
	cout << "|████       ███▄  ▀█   ███   █▀  ████████▀   ▄████████▀  █▀   ████████▀  |"<< endl;
	cout << "|========================================================================|"<< endl;

}

void UserInterface::UiVipLogo(string isvip)

{
	UiClearScreen();
	if(isvip == "não")
	{
		cout << "|========================================================================|" << endl;
		cout << "|                   ██╗  ██╗      ██╗   ██╗██╗██████╗                    |" << endl;
		cout << "|                   ╚██╗██╔╝      ██║   ██║██║██╔══██╗                   |" << endl;
		cout << "|                    ╚███╔╝ █████╗██║   ██║██║██████╔╝                   |" << endl;
		cout << "|                    ██╔██╗ ╚════╝╚██╗ ██╔╝██║██╔═══╝                    |" << endl;
		cout << "|                   ██╔╝ ██╗       ╚████╔╝ ██║██║                        |" << endl;
		cout << "|                   ╚═╝  ╚═╝        ╚═══╝  ╚═╝╚═╝                        |" << endl;
		cout << "|========================================================================|" << endl;
	}
	else if (isvip == "sim")
	{
		cout << "|========================================================================|" << endl;
		cout << "|    VOCÊ           ██╗  ██╗      ██╗   ██╗██╗██████╗                    |" << endl;
		cout << "| É UM              ╚██╗██╔╝      ██║   ██║██║██╔══██╗                   |" << endl;
		cout << "|   USÚARIO          ╚███╔╝ █████╗██║   ██║██║██████╔╝                   |" << endl;
		cout << "|     ----->         ██╔██╗ ╚════╝╚██╗ ██╔╝██║██╔═══╝                    |" << endl;
		cout << "|                   ██╔╝ ██╗       ╚████╔╝ ██║██║                        |" << endl;
		cout << "|                   ╚═╝  ╚═╝        ╚═══╝  ╚═╝╚═╝                        |" << endl;
		cout << "|========================================================================|" << endl;
	}
}

void UserInterface::UiClearScreen(void)
{
	system("clear");
}

void UserInterface::UiPressToGo(void)
{
	do
	{
		cout << "Pressione qualquer tecla para continuar..." << endl;
	} while (cin.get() != '\n');
}

void UserInterface::UiLayer(string layer)
{
	if(layer == "bottom")
		cout << "|========================================================================|"<< endl;
	else if(layer == "register")
		cout << "|================================CADASTRO================================|"<< endl;
	else if(layer == "login")
		cout << "|=================================LOGIN==================================|"<< endl;
	else if(layer == "addplaylist")
		cout << "|=============================NOVA PLAYLIST==============================|"<< endl;

	else
		cout << "$$$$$$layer##label##not##found%%$$$$$" << endl;

}

void UserInterface::UiSetUserPremium(void)
{
	auto opt(-1), cont(0);
	string aux;
	UiVipLogo("não");
	cout << "Você fez uma boa escolha" ;
	UiPressToGo();

	while (cont < 3)
	{
		UiVipLogo("não");
		cout << "Escolha sua forma de pagamento" << endl;
		cout << "1) Boleto\n2) Cartão de Crédito\n3) Código Promocional\n0) Cancelar" << endl;
		cin >> opt;
		if(opt < 0 or opt > 3)
		{
			cont++;
			UiVipLogo("não");
			cerr << "Opção inválida!\n\n\nTente novamente";
			UiPressToGo();
		}

	}
	switch (opt)
	{
		case 0:
			UiVipLogo("não");
			cout << "\t\t\t¯" << "'\'" << "_(ツ)_/¯" << endl;
			cout << "Tudo bem, fica pra próxima!" << endl;
			UiPressToGo();
			break;
		case 1:
			UiVipLogo("não");
			cout << "Digite seu CPF para continuarmos." << endl << "==> ";
			cin >> aux;
			if(UiInputValidation(client_atributes_, aux))
			{
				UiVipLogo("sim");
				cout << "CPF correto." << endl;
				cout <<"Seu boleto chegará no seu e-mail " << client_atributes_.at(6);
			}
			else
			{
				cout << "CPF Inválido!" << endl;
			}
			break;
		case 2:
			UiVipLogo("não");
			cout << setfill(' ') << "Digite seu CPF para continuarmos" << endl << "==> ";
			getline(cin, aux);
			if(UiInputValidation(client_atributes_, aux))
			{
				cout <<  setfill(' ') << "|CPF correto." << endl;
				cout <<  setfill(' ') << "|Digite o número de seu cartão de crédito" << endl;
				cout << "==>  ";
				aux.clear();
				getline(cin, aux);
				client_atributes_.push_back(aux);
			}
			else
			{
				cout << setfill(' ') << "|CPF Inválido!" << endl;
			}
			break;
		case 3:
			UiVipLogo("não");
			cout << setfill(' ') << "|Confirme seu email para continuarmos..." << setw(34) << "|" << endl;
			UiLayer("bottom");
			cout <<  "==>  ";
			aux.clear();
			getline(cin, aux);
			if(UiInputValidation(client_atributes_, aux))
			{
				cout <<  setfill(' ') << "|Email correto."  << endl;
				cout <<  setfill(' ') << "|Digite o código Promocional" << endl;
				UiLayer("bottom");
				cout << "==>  ";
				aux.clear();
				getline(cin, aux);
				if(UiInputValidation(promo_codes_, aux))
					cout << "Código promocional aceito! Acesse seu e-mail para confirmar a solicitação" << endl;
				else
					cout << "Código promocional inválido!" << endl;
			}
			else
			{
				cout << "Email incorreto!" << endl;

			}
			break;
	}

}

bool UserInterface::UiInputValidation(vector<string> v, string verify)
{
	vector<string>::iterator it;
	it = find (v.begin(), v.end(), verify);
	if(it != v.end())
		return true;
	return false;
}


Client* UserInterface::PushClient(bool isartist)
{
	vector<Client *> client;
	if(isartist == true)
	{
		client.push_back(new Artist(client_atributes_));
	}
	else
	{
		client.push_back(new User(client_atributes_));
	}

	return client[1];
}
