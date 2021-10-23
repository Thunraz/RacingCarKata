#ifndef RACING_CAR_GMOCK_FILEREADER_HPP
#define RACING_CAR_GMOCK_FILEREADER_HPP
#include <filesystem>

#include "FileReaderInterface.hpp"

class FileReader : public FileReaderInterface {
private:
    std::filesystem::path m_lastFilename;

public:
    FileReader(std::filesystem::path const& filename)
        : m_lastFilename { filename }
    {
    }
    std::string get_content() override;
    std::string get_last_filename() const { return m_lastFilename.string(); };
};

#endif // RACING_CAR_GMOCK_FILEREADER_HPP
