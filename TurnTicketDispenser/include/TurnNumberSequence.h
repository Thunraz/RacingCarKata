#pragma once
#include "TurnNumberSequenceInterface.hpp"

class TurnNumberSequence : public TurnNumberSequenceInterface
{
    static int s_turnNumber;

public:
    int Get() override;

public:
    static int getNextTurnNumber();
};
