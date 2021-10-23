#ifndef RACING_CAR_GMOCK_FILEREADER_HPP
#define RACING_CAR_GMOCK_FILEREADER_HPP
#include "FileReaderInterface.hpp"

class FileReader : public FileReaderInterface {
private:
    std::string m_lastFilename { "" };

public:
    FileReader(std::string const& filename)
        : m_lastFilename { filename }
    {
    }
    std::string get_content() override;
    std::string get_last_filename() const { return m_lastFilename; };
};

#include "FileReaderInterface.hpp"
#include "HtmlTextConverter.h"

#endif // RACING_CAR_GMOCK_FILEREADER_HPP
