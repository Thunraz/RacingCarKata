
#include "../include/TurnNumberSequence.h"

int TurnNumberSequence::getNextTurnNumber() { return m_turnNumber++; }

int TurnNumberSequence::Get() { return getNextTurnNumber(); }
