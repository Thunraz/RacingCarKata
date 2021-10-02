
#include <fstream>
#include <string>

class HtmlTextConverter {
    std::string m_fullFilenameWithPath;

public:
    HtmlTextConverter(std::string const& fullFilenameWithPath);

    std::string convertToHtml();

    std::string getFilename() const;

    std::string convert(std::string const& text_to_convert) const;
};
