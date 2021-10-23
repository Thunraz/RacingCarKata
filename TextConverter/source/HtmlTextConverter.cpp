#include <regex>

#include "../include/HtmlTextConverter.h"
#include "../include/StringEscapeUtils.h"
#include "FileReader.hpp"
#include "FileReaderInterface.hpp"

std::string convert_text_to_html(std::string const& text_to_convert)
{
    std::string output = text_to_convert;
    output = StringEscapeUtils::escapeHtml(output);
    output = std::regex_replace(output, std::regex("[\n]"), "<br />\n");
    return output;
}

std::string convert_file_to_html(FileReaderInterface& file_reader)
{
    return convert_text_to_html(file_reader.get_content());
}
