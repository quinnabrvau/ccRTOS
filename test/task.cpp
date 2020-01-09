#include "task.hpp"
#include "TestHarness.h"

///@todo
TEST_GROUP(task)
{
    void setup() {

    }
    void teardown() {

    }
};

TEST(task, initEmptyPointSelf) {
    task t;
    POINTERS_EQUAL(&t, **t.get_node());
}
TEST(task, initEmptyPrio0) {
    task t;
    CHECK_TRUE(  *t.get_node() == 0 );
    CHECK_FALSE( *t.get_node() == 1 );
}
TEST(task, initPrio) {
    task t(1);
    POINTERS_EQUAL(&t, **t.get_node());
    CHECK_TRUE(  *t.get_node() == 1 );
    CHECK_FALSE( *t.get_node() == 0 );
}
