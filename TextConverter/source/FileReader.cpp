#include "FileReader.hpp"
#include <filesystem>
#include <fstream>

std::string FileReader::get_content()
{
    std::filesystem::path file_path {m_lastFilename};
    std::ifstream file {file_path};
    return "";
}