//
// Created by pk on 10/23/2021.
//

#ifndef RACING_CAR_GMOCK_FILEREADER_HPP
#define RACING_CAR_GMOCK_FILEREADER_HPP
#include "FileReaderInterface.hpp"

class FileReader : public FileReaderInterface {
private:
    std::string m_lastFilename { "" };

public:
    FileReader(std::string const& filename): m_lastFilename{filename}{

    }
    std::string get_content() override;
    std::string get_last_filename() { return m_lastFilename; };
};

#include "HtmlTextConverter.h"
#include "FileReaderInterface.hpp"

#endif //RACING_CAR_GMOCK_FILEREADER_HPP
