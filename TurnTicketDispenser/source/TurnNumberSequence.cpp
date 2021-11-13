
#include "../include/TurnNumberSequence.h"

int TurnNumberSequence::getNextTurnNumber()
{
    std::lock_guard<std::mutex> lock{ m_mutex };
    return m_turnNumber++;
}

int TurnNumberSequence::Get() { return getNextTurnNumber(); }
