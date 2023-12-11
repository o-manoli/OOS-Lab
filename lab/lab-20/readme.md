# AUFGABE 20 (BIS 30.11.2023, 13:30 UHR)

## THEMEN:

Interfaces, Dependency Inversion Principle

## IHRE AUFGABE:

Setzen Sie das Dependency Inversion Principle um.

Implementieren Sie eine Klasse "AuthenticationResult" mit den konstanten Attributen "_authenticated" von Typ bool und "_username" vom typ string, einem parametrisierten Kontruktor, der die Attribute initialisiert sowie getter-Methoden um die jeweilingen Werte auszulesen. Der Parameter für den Usernamen soll den default-Wert "unauthenticated_user" enthalten.

Schreiben Sie ein Interface "IAuthenticationProcedure", das die rein virtuelle Methode "authenticate" mit dem Rückgabewert "AuthenticationResult" enthält.

Schreiben Sie eine Klasse "Client" mit dem Attribut "_auth" vom Typ Pointer auf "IAuthenticationProcedure". Die Methode "set_authentication" nimmt einen Pointer auf "IAuthenticationProcedure" entgegen und setzt das Attribut "_auth_procedure" entsprechend. Die methode "execute" nimmt keine Parameter entgegen und führt die folgende Logik aus: Es führt zunächst auf dem "_auth_procedure"-Attribut die Methode "authenticate" aus und weist das Ergebnis einer konstanten vom Typ "AuthenticationResult" zu. Weist das "AuthenticationResult" ein positives Ergebnis aus, so wird auf der Konsole folgendes ausgegeben:

```bash
Das Programm wird ausgeführt für [user].
```

War die Authentifizierung nicht erfolgreich so wird folgendes ausgegeben:

```bash
Das Programm konnte nicht ausgeführt werden.
```

Schreiben Sie drei verschiedene Implementierungen des Interfaces "IAuthenticationProcedure": "MockAuth", "UsernamePassword" und "Certificate".

Die Klasse "MockAuth" gibt in jedem Fall ein positives "AuthenticationResult" für den Username "Default" zurück.

Die Klasse "UsernamePassword" liest nacheinander zunächst den Usernamen und das Passwort ein. Dazu wird der Anwender jeweils über die Konsole zur Eingabe aufgefordert:

```bash
Username:
```

bzw.

```bash
Password:
```

Sind Username und Passwort identisch, so gibt die Klasse ein positives "AuthenticationResult" für den entsprechenden Username zurück. Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.

Die Klasse "Certificate" liest den Zertifikatsaussteller von der Konsole ein. Der Anwender wird hierzu folgendermaßen aufgefordert:

```bash
Zertifikatsaussteller:
```

Ist der Zertifikatsaussteller "hs-esslingen" so gibt die Klasse ein positives "AuthenticationResult" zurück mit dem Usernamen "certificate.owner". Andernfalls wird ein negatives "AuthenticationResult" zurückgegeben.

Für die Eingaben:

```bash
Username:
Maier
Passwort:
Maier

Zertifikatsaussteller:
hs-esslingen
```

erzeugt das Programm die folgende (Ein-)Ausgabe:

```bash
Authentifizierung über MockAuth
Das Programm wird ausgeführt für Default.
Authentifizierung über UsernamePassword
Username:
Maier
Password:
Maier
Das Programm wird ausgeführt für Maier.
Authentifizierung über Zertifikat
Zertifikatsaussteller:
hs-eslingen
Das Programm wird ausgeführt für certificate.owner.
```

```cpp


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


```


## ANS:

```cpp

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

```