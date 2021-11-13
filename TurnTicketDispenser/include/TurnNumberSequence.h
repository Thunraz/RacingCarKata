#pragma once
#include "TurnNumberSequenceInterface.hpp"
#include <mutex>

class TurnNumberSequence : public TurnNumberSequenceInterface {
private:
    std::mutex m_mutex;
    int m_turnNumber { 0 };

public:
    int getNextTurnNumber();
    int Get() override;
};
