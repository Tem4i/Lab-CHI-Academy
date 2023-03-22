#include "Txt.h"
#include <vector>
#include <fstream>

namespace l1 {
    Txt::Txt()
    {
    }

    Txt::Txt(char* fileName)
    {
        FileLoader::load(fileName, data);
    }
    
    Txt::Txt(const Txt& other)
    {
        this->data = other.data;
    }
    
    Txt::Txt(Txt&& other)noexcept
    {
        this->data.clear();
    
        this->data = std::move(other.data);
    }
    
    Txt& Txt::operator=(const Txt& other)
    {
        if (this != &other)
        {
            data.clear();
   
            this->data = other.data;
        }
        return *this;
    }
    
    Txt& Txt::operator=(Txt&& other)noexcept
    {
        if (&other == this)
        {
            data.clear();
            this->data = std::move(other.data);
        
            other.data.clear();
        }
       
        return *this;
    }
    
    Txt::~Txt()
    {
        data.clear();
    }
    
    size_t Txt::size() const
    {
        return data.size();
    }

    void FileLoader::load(char* fileName, std::vector<std::string>& data)
    {
        std::ifstream file;
        file.open(fileName);
        if (file.is_open())
        {
            std::string temp;
            while (std::getline(file, temp, '\n'))
                data.push_back(temp);
        }
        file.close();
    }
}