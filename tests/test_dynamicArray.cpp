#include "gtest/gtest.h"
#include "DynamicArray.h"

using namespace oop;

// Test default constructor and size
TEST(DynamicArrayTest, DefaultConstructor) {
    DynamicArray a(5); // Create DynamicArray with size 5
    EXPECT_EQ(a.size(), 5); // Size should be 5
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(a[i], 0); // Each element should be initialized to 0
    }
}

// Test constructor with size and value
TEST(DynamicArrayTest, ConstructorWithValue) {
    DynamicArray a(5, 3); // Create DynamicArray with size 5, all elements initialized to 3
    EXPECT_EQ(a.size(), 5); // Size should be 5
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(a[i], 3); // Each element should be initialized to 3
    }
}

// Test copy constructor
TEST(DynamicArrayTest, CopyConstructor) {
    DynamicArray a(5, 1);
    DynamicArray b(a); // Copy constructor
    EXPECT_EQ(b.size(), a.size()); // Sizes should match
    for (int i = 0; i < b.size(); i++) {
        EXPECT_EQ(b[i], a[i]); // Elements should match
    }
}

// Test copy assignment operator
TEST(DynamicArrayTest, CopyAssignmentOperator) {
    DynamicArray a(5, 1);
    DynamicArray b(3, 2);
    b = a; // Copy assignment
    EXPECT_EQ(b.size(), a.size()); // Sizes should match
    for (int i = 0; i < b.size(); i++) {
        EXPECT_EQ(b[i], a[i]); // Elements should match
    }
}

// Test move constructor
TEST(DynamicArrayTest, MoveConstructor) {
    DynamicArray a(5, 1);
    DynamicArray b(std::move(a)); // Move constructor
    EXPECT_EQ(b.size(), 5); // b should take over the size
    EXPECT_EQ(a.size(), 0); // a should be empty
}

// Test move assignment operator
TEST(DynamicArrayTest, MoveAssignmentOperator) {
    DynamicArray a(5, 1);
    DynamicArray b(3, 2);
    b = std::move(a); // Move assignment
    EXPECT_EQ(b.size(), 5); // b should take over the size
    EXPECT_EQ(a.size(), 0); // a should be empty
}

// Test addition operator
TEST(DynamicArrayTest, AdditionOperator) {
    DynamicArray a(3, 1); // [1, 1, 1]
    DynamicArray b(2, 2); // [2, 2]
    DynamicArray c = a + b; // Concatenation

    EXPECT_EQ(c.size(), a.size() + b.size()); // Size of c should be the sum of sizes
    EXPECT_EQ(c[0], 1);
    EXPECT_EQ(c[1], 1);
    EXPECT_EQ(c[2], 1);
    EXPECT_EQ(c[3], 2);
    EXPECT_EQ(c[4], 2);
}

// Test stream insertion operator
TEST(DynamicArrayTest, StreamInsertionOperator) {
    DynamicArray a(3, 5);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "[5, 5, 5]"); // Check if the output matches expected string
}

// Test element access operator
TEST(DynamicArrayTest, ElementAccessOperator) {
    DynamicArray a(3, 5);
    EXPECT_EQ(a[0], 5);
    EXPECT_EQ(a[1], 5);
    EXPECT_EQ(a[2], 5);

    a[0] = 10; // Modify first element
    EXPECT_EQ(a[0], 10); // Check if the modification works
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
