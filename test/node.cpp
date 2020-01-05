#include "node.hpp"
#include "TestHarness.h"

TEST_GROUP(node)
{
    node N;
    void setup() {
        N = node();
    };
    void teardown() {

    };
};

TEST(node, create) {
    POINTERS_EQUAL(NULL, N.next);
};