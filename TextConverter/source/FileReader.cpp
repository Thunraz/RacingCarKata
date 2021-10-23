#include "FileReader.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

std::string FileReader::get_content()
{
    std::filesystem::path file_path { m_lastFilename };
    std::ifstream file { file_path };
    std::stringstream file_buffer;

    file_buffer << file.rdbuf();
    return file_buffer.str();
}
