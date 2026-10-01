#include <gtest/gtest.h>

#include "array_ops.h"

TEST(ArrayCreateTest, CreateNormalSize) {
    int* arr = array_create(5);
    
    ASSERT_NE(arr, nullptr); 
    
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], 0);
    }
    
    array_delete(arr);
}

TEST(ArrayCreateTest, CreateZeroSize) {
    int* arr = array_create(0);
    EXPECT_EQ(arr, nullptr);
}

TEST(ArrayInsertTest, InsertMiddle) {
    std::size_t size = 3;
    int* arr = array_create(size);

    arr[0] = 1; 
    arr[1] = 2; 
    arr[2] = 3;

    arr = array_insert(arr, size, 1, 99);

    EXPECT_EQ(size, 4);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 99);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    
    array_delete(arr);
}

TEST(ArrayInsertTest, InsertOutOfBounds) {
    std::size_t size = 2;
    int* arr = array_create(size);

    arr[0] = 10;
    arr[1] = 20;

    arr = array_insert(arr, size, 100, 30);

    EXPECT_EQ(size, 3);
    EXPECT_EQ(arr[2], 30);
    
    array_delete(arr);
}

TEST(ArrayRemoveTest, RemoveMiddle) {
    std::size_t size = 3;
    int* arr = array_create(size);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    arr = array_remove(arr, size, 1);

    EXPECT_EQ(size, 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
    
    array_delete(arr);
}

TEST(ArrayRemoveTest, RemoveInvalidPosition) {
    std::size_t size = 2;
    int* arr = array_create(size);

    arr[0] = 1;
    arr[1] = 2;

    int* original_ptr = arr;

    arr = array_remove(arr, size, 5);

    EXPECT_EQ(arr, original_ptr);
    EXPECT_EQ(size, 2);
    
    array_delete(arr);
}

TEST(ArrayResizeTest, ResizeExpand) {
    std::size_t size = 2;
    int* arr = array_create(size);

    arr[0] = 5;
    arr[1] = 10;

    std::size_t new_size = 4;
    arr = array_resize(arr, size, new_size);
    size = new_size;

    ASSERT_NE(arr, nullptr);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 10);
    EXPECT_EQ(arr[2], 0);
    EXPECT_EQ(arr[3], 0);
    
    array_delete(arr);
}

TEST(ArrayResizeTest, ResizeToZero) {
    std::size_t size = 3;
    int* arr = array_create(size);

    arr = array_resize(arr, size, 0);

    EXPECT_EQ(arr, nullptr);
}

TEST(ArrayMergeTest, MergeTwoSortedArrays) {
    int a[] = {0, 2, 4};
    int b[] = {1, 3, 5};

    std::size_t out_size = 0;

    int* merged = array_merge(a, 3, b, 3, out_size);

    EXPECT_EQ(out_size, 6);

    for (size_t i = 0; i < out_size; ++i) {
        EXPECT_EQ(merged[i], i);
    }
    
    array_delete(merged);
}

TEST(ArrayMergeTest, MergeWithEmptyArray) {
    int a[] = {6, 7};
    std::size_t out_size = 0;

    int* merged = array_merge(a, 2, nullptr, 0, out_size);

    EXPECT_EQ(out_size, 2);
    EXPECT_EQ(merged[0], 6);
    EXPECT_EQ(merged[1], 7);
    
    array_delete(merged);
}
