#ifndef RACING_CAR_GMOCK_FILEREADERMOCK_HPP
#define RACING_CAR_GMOCK_FILEREADERMOCK_HPP
#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

class FileReaderMock : public FileReaderInterface {
public:
    std::string get_last_filename() override { return ""; }
    MOCK_METHOD(std::string, get_content, (std::string const&), (override));
};

#endif // RACING_CAR_GMOCK_FILEREADERMOCK_HPP
