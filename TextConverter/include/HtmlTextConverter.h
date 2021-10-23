
#ifndef RACING_CAR_GMOCK_HTMLTEXTCONVERTER_HPP
#define RACING_CAR_GMOCK_HTMLTEXTCONVERTER_HPP

#include <fstream>
#include <string>

class FileReaderInterface {
public:
    virtual std::string get_content() = 0;
    virtual ~FileReaderInterface() = default;
};

class FileReader : public FileReaderInterface {
private:
    std::string m_lastFilename { "" };

public:
    FileReader(std::string const& filename): m_lastFilename{filename}{
        
    }
    std::string get_content() override;
    std::string get_last_filename() { return m_lastFilename; };
};

std::string convert_text_to_html(std::string const& text_to_convert);

std::string convert_file_to_html(FileReaderInterface& file_reader);

#endif
