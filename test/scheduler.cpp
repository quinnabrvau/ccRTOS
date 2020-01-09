#include "scheduler.hpp"
#include "TestHarness.h"

TEST_GROUP(scheduler)
{
    void setup() {

    }
    void teardown() {

    }
};

TEST(scheduler, initEmptyPrioQueue) {
    scheduler S;
    CHECK_EQUAL(0, S.total());
}
TEST(scheduler, addTaskSize1) {
    scheduler S;
    task t;
    S.add(t);
    CHECK_EQUAL(1, S.total());
}

