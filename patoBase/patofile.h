#ifndef FILE_H
#define FILE_H

#include <string>

class PatoFile
{
    public:
        PatoFile();

        void setId ( int id );
        int getId();

        void setNameFile( std::string& name );
        std::string getNameFile( );

        void setCodArmazenamento( std::string& cod );
        std::string getCodArmazenamento();

        void setStatus(std::string& status);
        std::string getStatus();

    private:
        int m_idFile;
        std::string m_nameFile;
        std::string m_status;
        std::string m_codArmazenamento;
};

#endif // FILE_H
