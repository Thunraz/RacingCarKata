#ifndef RACING_CAR_GMOCK_FILEREADERINTERFACE_HPP
#define RACING_CAR_GMOCK_FILEREADERINTERFACE_HPP
#include <string>

class FileReaderInterface {
public:
    virtual std::string get_content() = 0;
    virtual ~FileReaderInterface() = default;
};

#include <fstream>
#include <string>

#endif //RACING_CAR_GMOCK_FILEREADERINTERFACE_HPP
