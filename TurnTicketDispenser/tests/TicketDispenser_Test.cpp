#include "TicketDispenser.h"
#include <TurnNumberSequence.h>
#include <gmock/gmock.h>
#include <thread>
#include <future>

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

TEST(TurnNumberSequenceTest, TwoDispensersWontReturnSameNumber)
{
    TurnNumberSequence sequence;

    TicketDispenser dispenser1 { sequence };
    TicketDispenser dispenser2 { sequence };

    auto result1 = dispenser1.getTurnTicket();
    auto result2 = dispenser2.getTurnTicket();

    EXPECT_NE(result1.getTurnNumber(), result2.getTurnNumber());
}

TEST(TurnNumberSequenceTest, TwoDispensersWorkInMultiprocessing)
{
    TurnNumberSequence sequence;

    std::promise<int> p1;
    std::thread t1{ [&sequence, &p1](){
        TicketDispenser dispenser { sequence };
        auto result = dispenser.getTurnTicket();

        p1.set_value(result.getTurnNumber());
    } };
    t1.detach();

    std::promise<int> p2;
    std::thread t2{ [&sequence, &p2](){
        TicketDispenser dispenser { sequence };
        auto result = dispenser.getTurnTicket();

        p2.set_value(result.getTurnNumber());
    } };
    t2.detach();

    auto result1 = p1.get_future().get();
    auto result2 = p2.get_future().get();

    EXPECT_NE(result1, result2);
}

} // namespace
