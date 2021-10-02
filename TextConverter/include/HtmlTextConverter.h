
#include <fstream>
#include <string>

class FileReaderInterface {
    virtual std::string get_content(std::string const& filename) = 0;
    virtual std::string get_last_filename() = 0;
};

class FileReader : public FileReaderInterface {
private:
    std::string m_lastFilename { "" };

public:
    std::string get_content(std::string const& filename) override
    {
        m_lastFilename = filename;
        return "";
    }

    std::string get_last_filename() { return m_lastFilename; };
};

std::string convert_text_to_html(std::string const& text_to_convert);
