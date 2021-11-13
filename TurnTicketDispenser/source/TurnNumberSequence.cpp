
#include "../include/TurnNumberSequence.h"

int TurnNumberSequence::getNextTurnNumber()
{
    auto lock = std::unique_lock<std::mutex> { m_mutex };
    return m_turnNumber++;
}

int TurnNumberSequence::Get() { return getNextTurnNumber(); }
