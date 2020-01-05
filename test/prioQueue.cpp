#include "prioQueue.hpp"
#include "TestHarness.h"

TEST_GROUP(prioQueue)
{
    prioQueue<int> pq;
    prioQueue<int>::node N, M, A, B, C;
    prioQueue<int>::node *pN, *pM, *pA, *pB, *pC;
    void setup() {
        N = prioQueue<int>::node();
        M = prioQueue<int>::node();
        A = prioQueue<int>::node(0,1);
        B = prioQueue<int>::node(1,1);
        C = prioQueue<int>::node(1,2);
        pN = pM = pA = pB = pC = NULL;
    }
    void teardown() {

    }
};

TEST(prioQueue, initToEmpty) {
    prioQueue<int> pq = prioQueue<int>();
    CHECK_EQUAL(0, pq.size());
}

TEST(prioQueue, push1Node) {
    prioQueue<int>::node N;
    pq.push(&N);
    CHECK_EQUAL(1, pq.size());
}
TEST(prioQueue, push2Nodes) {
    prioQueue<int>::node N, M;
    pq.push(&N);
    pq.push(&M);
    CHECK_EQUAL(2, pq.size());
}
TEST(prioQueue, pushSkipDuplicats) {
    pq.push(&N);
    pq.push(&N);
    CHECK_EQUAL(1, pq.size());
}

TEST(prioQueue, pushReturnTrueOnAdd) {
    CHECK_TRUE(pq.push(&N));
}
TEST(prioQueue, pushReturnFalseIfCopy) {
    CHECK_TRUE(pq.push(&N));
    CHECK_FALSE(pq.push(&N));
}

TEST(prioQueue, popFirst) {
    pq.push(&N);
    pN = pq.pop();
    POINTERS_EQUAL(&N, pN);
}


TEST(prioQueue, popFirst2) {
    pq.push(&N); pq.push(&M);
    pN = pq.pop(); pM = pq.pop();
    POINTERS_EQUAL(&N, pN);
    POINTERS_EQUAL(&M, pM);
}

// TEST(prioQueue, initToNullHeader) {
//     prioQueue<int> pq = prioQueue<int>();
//     POINTERS_EQUAL(NULL, pq.get());
// }
