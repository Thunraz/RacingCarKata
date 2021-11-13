#include "TicketDispenser.h"
#include <TurnNumberSequence.h>
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

class TurnNumberSequenceMock : public TurnNumberSequenceInterface {
public:
    MOCK_METHOD(int, Get, (), (override));
};

TEST(TicketDispenser, InitialTicketHasNumber0)
{
    TurnNumberSequenceMock sequence;
    EXPECT_CALL(sequence, Get).WillOnce(::testing::Return(0));
    TicketDispenser ticket_dispenser { sequence };
    auto ticket = ticket_dispenser.getTurnTicket();

    ASSERT_EQ(ticket.getTurnNumber(), 0);
}

TEST(TicketDispenser, SecondTicketHasNumber1)
{
    TurnNumberSequenceMock sequence;
    EXPECT_CALL(sequence, Get).WillOnce(::testing::Return(1));
    TicketDispenser ticket_dispenser { sequence };
    auto ticket = ticket_dispenser.getTurnTicket();

    ASSERT_EQ(ticket.getTurnNumber(), 1);
}

TEST(TurnNumberSequenceTest, InitialReturnsZero)
{
    TurnNumberSequence sequence;
    EXPECT_EQ(sequence.Get(), 0);
}

TEST(TurnNumberSequenceTest, SecondCallReturnsOne)
{
    TurnNumberSequence sequence;
    (void)sequence.Get();
    EXPECT_EQ(sequence.Get(), 1);
}

} // namespace
