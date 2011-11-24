#ifndef USER_H
#define USER_H

#include <string>

class PatoUser
{
    public:
        PatoUser();


        void setId(int id);
        int getId();
        void setName( std::string& name );
        std::string getName( );

    private:
        int m_idUser;
        std::string m_nameUser;
};

#endif // USER_H
