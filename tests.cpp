#include <iostream>
#include "sorts.cpp"
#include "gtest/gtest.h"
#include "string"

using std::string;

class TestSort : public ::testing::Test {
public:
    void SetUp(string order) {
        arr = new int[size];
        CreateArray(arr);
        arr_seq = ArraySequence<int>(arr, size);
        arr_seq2 = ArraySequence<int>(arr, size);
        list_seq = ListSequence<int>(arr, size);
        list_seq2 = ListSequence<int>(arr, size);
        if (order == "reversed") {
            reverse(&arr_seq2);
            reverse(&list_seq2);
        } else if (order == "random") {
            shuffle(&arr_seq2);
            shuffle(&list_seq2);
        }
    }

    void TearDown() {
        delete[] arr;

    }

    void CreateArray(int *a) {
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            a[i] = i;
        }

    }

    int size = 1000;
    int *arr;
    ArraySequence<int> arr_seq;
    ArraySequence<int> arr_seq2;
    ListSequence<int> list_seq;
    ListSequence<int> list_seq2;
};

TEST_F(TestSort, QuickSortRandom) {
    SetUp("random");
    QuickSort(&arr_seq2, 0, arr_seq.get_size() - 1);
    EXPECT_TRUE(arr_seq == arr_seq2);
    QuickSort(&list_seq2, 0, list_seq.get_size() - 1);
    EXPECT_TRUE(list_seq == list_seq2);
}

TEST_F(TestSort, QuickSortSorted) {
    SetUp("sorted");
    QuickSort(&arr_seq2, 0, arr_seq.get_size() - 1);
    EXPECT_TRUE(arr_seq == arr_seq2);
    QuickSort(&list_seq2, 0, list_seq.get_size() - 1);
    EXPECT_TRUE(list_seq == list_seq2);
}

TEST_F(TestSort, QuickSortArrayReversed) {
    SetUp("reversed");
    QuickSort(&arr_seq2, 0, arr_seq.get_size() - 1);
    EXPECT_TRUE(arr_seq == arr_seq2);
    QuickSort(&list_seq2, 0, list_seq.get_size() - 1);
    EXPECT_TRUE(list_seq == list_seq2);
}


TEST_F(TestSort, SelectionSortRandom) {
    SetUp("random");
    SelectionSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    SelectionSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);

}

TEST_F(TestSort, SelectionSortSorted) {
    SetUp("sorted");
    SelectionSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    SelectionSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);
}

TEST_F(TestSort, SelectionSortReversed) {
    SetUp("reversed");
    SelectionSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    SelectionSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);
}

TEST_F(TestSort, InsertSortRandom) {
    SetUp("random");
    InsertSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    InsertSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);
}


TEST_F(TestSort, InsertSortSorted) {
    SetUp("sorted");
    InsertSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    InsertSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);
}

TEST_F(TestSort, InsertSortReversed) {
    SetUp("reversed");
    InsertSort(&arr_seq2);
    EXPECT_TRUE(arr_seq == arr_seq2);
    InsertSort(&list_seq2);
    EXPECT_TRUE(list_seq == list_seq2);


}
