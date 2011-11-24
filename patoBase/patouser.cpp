#include "patouser.h"

PatoUser::PatoUser()
{
}

void PatoUser::setId(int id)
{
    m_idUser = id;
}

int PatoUser::getId()
{
    return m_idUser;
}

void PatoUser::setName( std::string& name )
{
    m_nameUser = name;
}

std::string PatoUser::getName( )
{
    return m_nameUser;
}
