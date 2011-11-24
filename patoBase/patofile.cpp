#include "patofile.h"

PatoFile::PatoFile()
{
}


void PatoFile::setId ( int id )
{
    m_idFile = id;
}

int PatoFile::getId()
{
    return m_idFile;
}




void PatoFile::setNameFile( std::string& name )
{
    m_nameFile = name;
}

std::string PatoFile::getNameFile( )
{
    return m_nameFile;
}

void PatoFile::setCodArmazenamento( std::string& cod )
{
    m_codArmazenamento = cod;
}

std::string PatoFile::getCodArmazenamento()
{
    return m_codArmazenamento;
}

void PatoFile::setStatus(std::string& status)
{
    m_status = status;
}

std::string PatoFile::getStatus()
{
    return m_status;
}
