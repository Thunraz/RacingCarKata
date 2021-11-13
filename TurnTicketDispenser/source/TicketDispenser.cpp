
#include "../include/TicketDispenser.h"
#include "../include/TurnNumberSequence.h"

TurnTicket TicketDispenser::getTurnTicket()
{
    int newTurnNumber = m_sequenceInterface.Get();
    return TurnTicket(newTurnNumber);
}

TicketDispenser::TicketDispenser(TurnNumberSequenceInterface& sequenceInterface)
    : m_sequenceInterface { sequenceInterface }
{
}
