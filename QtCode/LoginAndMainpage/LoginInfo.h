#ifndef LOGININFO_H
#define LOGININFO_H

#include <QString>

class LoginInfo
{
private:
    static bool loginState;
    static int id;
    static QString username;
    static QString session;

public:
    LoginInfo();
    ~LoginInfo();
    static int isLogin() { return loginState; }
    static int getId() { return id; }
    static QString getUsername() { return username; }
    static QString getSession() { return session; }
    static void setLoginInfo(int idIn, QString usernameIn, QString sessionIn) 
        { id = idIn; username = usernameIn; session = sessionIn; loginState = true; }
    static void saveLoginInfo();
    static void readLoginInfo();
    static void cleanLoginInfo();
};

#endif
