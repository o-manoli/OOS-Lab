#include <iostream>
#include <string>
using namespace std;

class AuthenticationResult{
	bool _authenticated;
	string _username;

	public:

	AuthenticationResult(
		bool authenticated,
		string username = "unauthenticated_user"
	) : _authenticated(authenticated), _username(username) {}

	bool authenticated() {return _authenticated;}
	string username() {return _username;}
};

class IAuthenticationProcedure {

	public:

	virtual AuthenticationResult authenticate() = 0;
};

class MockAuthentication : public IAuthenticationProcedure {

	public:

	AuthenticationResult authenticate()
	{
		return AuthenticationResult(true, "Default");
	}
};

class UsernamePassword : public IAuthenticationProcedure {
	string _username;
	string _password;

	public:

	AuthenticationResult authenticate()
	{
		cout << "Username: " << endl;
		cin >> _username;
		cout << "Password: " << endl;
		cin >> _password;

		if (_username == _password)
			return AuthenticationResult(true, _username);
		return AuthenticationResult(false);
	}
};

class Certificate : public IAuthenticationProcedure {
	string _zertifikataussteller;

	public:

	AuthenticationResult authenticate()
	{
		cout << "Zertifikatsaussteller: " << endl;
		cin >> _zertifikataussteller;

		if (_zertifikataussteller == "hs-esslingen")
			return AuthenticationResult(true, "certificate.owner");
		return AuthenticationResult(false);
	}
};

class Client {
	IAuthenticationProcedure* _authentication_procedure;

	public:

	void set_authentication_procedure(
		IAuthenticationProcedure* authentication_procedure
	){
		_authentication_procedure = authentication_procedure;
	}

	void execute()
	{
		AuthenticationResult result = _authentication_procedure->authenticate();

		if (result.authenticated() == true)
			cout
			<< "Das Programm wird ausgeführt für "
			<< result.username()
			<< "."
			<< endl;
		else
			cout
			<< "Das Programm konnte nicht ausgeführt werden."
			<< endl;
		}
};


int main(int argc, char* argv[]) {
	Client client;

	cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
	IAuthenticationProcedure* mock_authentication = new MockAuthentication();
	client.set_authentication_procedure(mock_authentication);
	client.execute();

	cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
	IAuthenticationProcedure* username_password = new UsernamePassword();
	client.set_authentication_procedure(username_password);
	client.execute();

	cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
	IAuthenticationProcedure* certificate = new Certificate();
	client.set_authentication_procedure(certificate);
	client.execute();
	return 0;
}



