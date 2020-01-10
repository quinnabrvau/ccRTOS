#include "pqNode.hpp"
#include "TestHarness.h"

TEST_GROUP(pqNode)
{
    pqNode<int> N;
    pqNode<int> A;
    pqNode<int> B;
    pqNode<int> C;
    void setup() {
        N = pqNode<int>();
        A = pqNode<int>(0,1);
        B = pqNode<int>(1,1);
        C = pqNode<int>(1,2);
    }
    void teardown() {

    }
};

TEST(pqNode, createNoNext) {
    pqNode<int> N = pqNode<int>();
    POINTERS_EQUAL(NULL, N.next);
}
TEST(pqNode, createNoPrev) {
    pqNode<int> N = pqNode<int>();
    POINTERS_EQUAL(NULL, N.prev);
}
TEST(pqNode, templateStorePointer) {
    int val;
    pqNode<int*> I = pqNode<int*>(0, &val);
    POINTERS_EQUAL(&val, *I);
}
TEST(pqNode, AgreaterB) {
    CHECK_TRUE(A  > B);
    CHECK_FALSE(A > A);
}
TEST(pqNode, AgreaterBequalA) {
    CHECK_TRUE(A >= B);
    CHECK_TRUE(A >= A);
}
TEST(pqNode, AequalA) {
    CHECK_TRUE(A == A);
}
TEST(pqNode, BlessA) {
    CHECK_TRUE(B < A);
    CHECK_FALSE(B < B);
}
TEST(pqNode, BlessAequalB) {
    CHECK_TRUE(B <= A);
    CHECK_TRUE(B <= B);
}
TEST(pqNode, BnotA) {
    CHECK_TRUE(B != A);
    CHECK_TRUE(A != B);
}
TEST(pqNode, Aequal0) {
    CHECK_FALSE(A == 1);
    CHECK_TRUE(A == 0);
}
TEST(pqNode, AnotEqual0) {
    CHECK_FALSE(A != 0);
    CHECK_TRUE(A != 1);
}


TEST(pqNode, BisBnotCnotA) {
    CHECK_TRUE(B.is(B));
    CHECK_FALSE(B.is(C));
    CHECK_FALSE(B.is(A));
}

TEST(pqNode, storeNext) {
    A.next = &B;
    POINTERS_EQUAL(&B, A.next);
}
TEST(pqNode, storePrev) {
    B.prev = &A;
    POINTERS_EQUAL(&A, B.prev);
}

