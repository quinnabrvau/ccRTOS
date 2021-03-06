#include "prioQueue.hpp"
#include "TestHarness.h"

TEST_GROUP(prioQueue)
{
    prioQueue<int> pq;
    prioQueue<int>::node N, M, A, B, C, D;
    void setup() {
        N = prioQueue<int>::node();
        M = prioQueue<int>::node();
        A = prioQueue<int>::node(0,1);
        B = prioQueue<int>::node(1,1);
        C = prioQueue<int>::node(1,2);
        D = prioQueue<int>::node(2,2);
        pq = prioQueue<int>();
    }
    void teardown() {

    }
};

TEST(prioQueue, initToEmpty) {
    prioQueue<int> pq = prioQueue<int>();
    CHECK_EQUAL(0, pq.size());
}

TEST(prioQueue, initToNullHeader) {
    pq.push(&N);
    pq = prioQueue<int>();
    POINTERS_EQUAL(NULL, pq.pop());
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
TEST(prioQueue, pushBAgetAB) {
    pq.push(&B); pq.push(&A);
    POINTERS_EQUAL(&A, pq.pop());
    POINTERS_EQUAL(&B, pq.pop());
}
TEST(prioQueue, pushSkipNull) {
    CHECK_FALSE(pq.push(NULL));
}
TEST(prioQueue, pushMiddle) {
    pq.push(&D); pq.push(&A); pq.push(&B);// pq.push(&C);
    POINTERS_EQUAL(&A, pq.pop());
    POINTERS_EQUAL(&B, pq.pop());
    // POINTERS_EQUAL(&C, pq.pop());
    POINTERS_EQUAL(&D, pq.pop());
}



TEST(prioQueue, popFirst) {
    pq.push(&N);
    POINTERS_EQUAL(&N, pq.pop());
}
TEST(prioQueue, popFirst2PrioEquivilantAddBack) {
    pq.push(&N); pq.push(&M);
    POINTERS_EQUAL(&N, pq.pop());
    POINTERS_EQUAL(&M, pq.pop());
}
TEST(prioQueue, popFirst2Length0) {
    pq.push(&N); pq.push(&M);
    pq.pop(); pq.pop();
    CHECK_EQUAL(0, pq.size());
}
TEST(prioQueue, popNullIfEmpty) {
    POINTERS_EQUAL(NULL, pq.pop());
}
TEST(prioQueue, popNullAllPopped) {
    pq.push(&N); pq.push(&M);
    pq.pop(); pq.pop();
    POINTERS_EQUAL(NULL, pq.pop());
}

TEST(prioQueue, popN) {
    pq.push(&N);
    POINTERS_EQUAL(&N, pq.pop(&N));
    CHECK_EQUAL(0, pq.size());
}
TEST(prioQueue, popNEmpty) {
    POINTERS_EQUAL(NULL, pq.pop(&N));
    CHECK_EQUAL(0, pq.size());
}
TEST(prioQueue, popNMissing) {
    pq.push(&N);
    POINTERS_EQUAL(NULL, pq.pop(&M));
    CHECK_EQUAL(1, pq.size());
}
TEST(prioQueue, popLast) {
    pq.push(&N); pq.push(&M);
    POINTERS_EQUAL(&M, pq.pop(&M));
    CHECK_EQUAL(1, pq.size());
}
TEST(prioQueue, popMiddle) {
    pq.push(&A); pq.push(&B); pq.push(&C);
    POINTERS_EQUAL(&B, pq.pop(&B));
    POINTERS_EQUAL(&C, pq.pop(&C)); // test that the list is still linked
    POINTERS_EQUAL(&A, pq.pop());
    CHECK_EQUAL(0, pq.size());
}

TEST(prioQueue, initStartIsEnd) {
    prioQueue<int> pq = prioQueue<int>();
    CHECK_TRUE(pq.begin() == pq.end());
}
TEST(prioQueue, initEndisNull) {
    prioQueue<int> pq = prioQueue<int>();
    POINTERS_EQUAL(NULL, *pq.end());
}
TEST(prioQueue, push1BeginNotNull) {
    pq.push(&N);
    CHECK_FALSE(pq.begin() == pq.end());
}
TEST(prioQueue, push1StartatHead) {
    pq.push(&N);
    POINTERS_EQUAL(&N, *pq.begin());
}
TEST(prioQueue, itterIncCantPassEnd) {
    auto i = pq.begin();
    ++i;
    POINTERS_EQUAL(NULL, *i);
    i++;
    POINTERS_EQUAL(NULL, *i);
}
TEST(prioQueue, itterInc1) {
    pq.push(&N); pq.push(&M);
    auto i = pq.begin();
    POINTERS_EQUAL(&N, *i);
    i++;
    POINTERS_EQUAL(&M, *i);
}

TEST(prioQueue, itterate) {
    pq.push(&N);
    POINTERS_EQUAL(&N, *pq.begin());
    pq.push(&A); pq.push(&B); pq.push(&C);
    auto i = pq.begin();
    POINTERS_EQUAL(&A, *i++);
    POINTERS_EQUAL(&B, *i++);
    POINTERS_EQUAL(&C, *i++);
    POINTERS_EQUAL(*pq.end(), *i++);
    POINTERS_EQUAL(NULL, *i++);
    POINTERS_EQUAL(NULL, *i);
}


