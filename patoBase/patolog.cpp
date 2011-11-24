#include "patolog.h"

PatoLog::PatoLog()
{
}

void PatoLog::setId(int id)
{
    m_idLog = id;
}

int PatoLog::getId()
{
    return m_idLog;
}

void PatoLog::setData(std::string& data)
{
    m_data = data;
}

std::string PatoLog::getData()
{
    return m_data;
}

void PatoLog::setMessage(std::string& msg)
{
    m_message = msg;
}

std::string PatoLog::getMessage()
{
    return m_message;
}

void PatoLog::setUser(PatoUser& user)
{
    m_user = user;
}

PatoUser PatoLog::getUser()
{
    return m_user;
}

std::string PatoLog::getNameUser()
{
    return m_user.getName();
}

void PatoLog::setVecFile(std::vector<PatoFile>& vecFile)
{
    m_vecFile = vecFile;
}

std::vector<PatoFile> PatoLog::getVecFile()
{
    return m_vecFile;
}

void PatoLog::insertFile(PatoFile& file)
{
    m_vecFile.push_back(file);
}
