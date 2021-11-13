#ifndef RACING_CAR_GMOCK_TURNNUMBERSEQUENCEINTERFACE_HPP
#define RACING_CAR_GMOCK_TURNNUMBERSEQUENCEINTERFACE_HPP

class TurnNumberSequenceInterface {
public:
    virtual ~TurnNumberSequenceInterface() = default;

    virtual int Get() = 0;
};

#endif // RACING_CAR_GMOCK_TURNNUMBERSEQUENCEINTERFACE_HPP
