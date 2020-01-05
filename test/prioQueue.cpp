#include "prioQueue.hpp"
#include "TestHarness.h"

TEST_GROUP(prioQueue)
{
    prioQueue<int> pq;
    void setup() {
        pq = prioQueue<int>();
    }
    void teardown() {

    }
};

TEST(prioQueue, initToEmpty) {
    CHECK_EQUAL(0, pq.size());
}

TEST(prioQueue, initToEmpty) {
    CHECK_EQUAL(0, pq.size());
}