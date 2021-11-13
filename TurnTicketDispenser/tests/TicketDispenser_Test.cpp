#include "TicketDispenser.h"
#include <gmock/gmock.h>

namespace {

class TurnTicketTestFixture : public ::testing::TestWithParam<int> {
};

TEST_P(TurnTicketTestFixture, TicketReturnsTicketNumber)
{
    auto const ticket_number = GetParam();
    TurnTicket ticket { ticket_number };
    ASSERT_EQ(ticket.getTurnNumber(), ticket_number);
}

INSTANTIATE_TEST_SUITE_P(TurnTicketTest, TurnTicketTestFixture, ::testing::Values(5, 42, 125));

TEST(TicketDispenser, InitialTicketHasNumber0)
{
    TicketDispenser ticket_dispenser;
    auto ticket = ticket_dispenser.getTurnTicket();

    ASSERT_EQ(ticket.getTurnNumber(), 0);
}

TEST(TicketDispenser, SecondTicketHasNumber1)
{
    TicketDispenser ticket_dispenser;
    auto ticket = ticket_dispenser.getTurnTicket();

    ASSERT_EQ(ticket.getTurnNumber(), 1);
}

} // namespace
