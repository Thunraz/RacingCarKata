#pragma once

#include "TurnNumberSequenceInterface.hpp"
#include "TurnTicket.h"

class TicketDispenser
{
private:
    TurnNumberSequenceInterface& m_sequenceInterface;

public:
    TicketDispenser(TurnNumberSequenceInterface& sequenceInterface);
    TurnTicket getTurnTicket();
};
