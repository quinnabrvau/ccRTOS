#include "node.hpp"
#include "TestHarness.h"

TEST_GROUP(node)
{
    node<int> N;
    void setup() {
        N = node<int>();
    }
    void teardown() {

    }
};

TEST(node, createNoNext) {
    POINTERS_EQUAL(NULL, N.next);
}
TEST(node, createNoPrev) {
    POINTERS_EQUAL(NULL, N.prev);
}
TEST(node, templateStorePointer) {
    int val;
    node<int*> I = node<int*>(&val);
    POINTERS_EQUAL(&val, *I);
}
