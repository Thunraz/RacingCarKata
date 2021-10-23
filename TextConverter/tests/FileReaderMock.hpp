#ifndef RACING_CAR_GMOCK_FILEREADERMOCK_HPP
#define RACING_CAR_GMOCK_FILEREADERMOCK_HPP
#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

class FileReaderMock : public FileReaderInterface {
public:
    MOCK_METHOD(std::string, get_content, (), (override));
};

#endif // RACING_CAR_GMOCK_FILEREADERMOCK_HPP
