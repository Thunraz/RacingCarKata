#pragma once
#include "TurnNumberSequenceInterface.hpp"

class TurnNumberSequence : public TurnNumberSequenceInterface {
    int m_turnNumber { 0 };

public:
    int Get() override;

public:
    int getNextTurnNumber();
};
