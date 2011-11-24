#ifndef LOG_H
#define LOG_H

#include "patofile.h"
#include "patouser.h"
#include <string>
#include <vector>

class PatoLog
{
    public:
        PatoLog();


        void setId(int id);
        int getId();

        void setData(std::string& data);
        std::string getData();

        void setMessage(std::string& msg);
        std::string getMessage();

        void setUser(PatoUser& user);
        PatoUser getUser();
        std::string getNameUser();

        void setVecFile(std::vector<PatoFile>& vecFile);
        std::vector<PatoFile> getVecFile();

        void insertFile(PatoFile& file);



    private:
        int                     m_idLog;
        std::string             m_data;
        std::string             m_message;
        PatoUser                m_user;
        std::vector<PatoFile>   m_vecFile;
};

#endif // LOG_H
