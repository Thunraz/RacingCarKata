#include <regex>

#include "../include/HtmlTextConverter.h"
#include "../include/StringEscapeUtils.h"

class FileReaderInterface {
    virtual std::string get_content(std::string const& filename) = 0;
    virtual std::string get_last_filename() = 0;
};

class FileReader : public FileReaderInterface{
public:
    std::string get_content(std::string const& filename) override{
        return "";
    }
    std::string get_last_filename() {
        return "";
    };
};


std::string convert_text_to_html(std::string const& text_to_convert)
{
    std::string output = text_to_convert;
    output = StringEscapeUtils::escapeHtml(output);
    output = std::regex_replace(output, std::regex("[\n]"), "<br />\n");
    return output;
}
