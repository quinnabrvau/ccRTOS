#include "pqNode.hpp"
#include "TestHarness.h"

TEST_GROUP(pqNode)
{
    pqNode<int> N;
    void setup() {
        N = pqNode<int>();
    }
    void teardown() {

    }
};

TEST(pqNode, createNoNext) {
    POINTERS_EQUAL(NULL, N.next);
}
TEST(pqNode, createNoPrev) {
    POINTERS_EQUAL(NULL, N.prev);
}
TEST(pqNode, templateStorePointer) {
    int val;
    pqNode<int*> I = pqNode<int*>(&val);
    POINTERS_EQUAL(&val, *I);
}
