
#ifndef RACING_CAR_GMOCK_HTMLTEXTCONVERTER_HPP
#define RACING_CAR_GMOCK_HTMLTEXTCONVERTER_HPP

#include <fstream>
#include <string>

class FileReaderInterface;

std::string convert_text_to_html(std::string const& text_to_convert);

std::string convert_file_to_html(FileReaderInterface& file_reader);

#endif
