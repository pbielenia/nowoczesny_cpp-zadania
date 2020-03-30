#include <gmock/gmock.h>
#include "Array2D.hpp"

using namespace testing;

TEST(Array2D, ConstructsFromTemplateWithTypeRowsAndColumnsNumber) {
    Array2D<int, 2, 3>{};
}

TEST(Array2D, ConstructsWithGivenElements) {
    Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
}

TEST(Array2D, ThrowsWhileConstructingWithTooMuchElements) {
    ASSERT_THROW((Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}),
                 PassedElementsExceedArraySizeException);
}

TEST(Array2D, ThrowsWhileConstructingWithTooLittleElements) {
    ASSERT_THROW((Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e'}),
                 PassedElementsDoNotReachArraySizeException);
}

TEST(Array2D, ReturnsElementUsingAt) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THAT(arr.at(0, 1), Eq('b'));
}

TEST(Array2D, ThrowsWhenAccessingRowOutOfRangeUsingAt) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THROW(arr.at(5, 1), RowIndexOutOfRangeException);
}

TEST(Array2D, ThrowsWhenAccessingColumnOutOfRangeUsingAt) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THROW(arr.at(0, 5), ColumnIndexOutOfRangeException);
}

TEST(Array2D, ReturnsStoredData) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    auto *buffer = arr.data();
    ASSERT_THAT(std::vector(buffer, buffer + 6),
                ElementsAreArray({'a', 'b', 'c', 'd', 'e', 'f'}));
}

TEST(Array2D, ReturnsContainerSize) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THAT(arr.size(), Eq(6));
}

TEST(Array2D, ReturnsNumberOfRows) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THAT(arr.rows_count(), Eq(2));   
}

TEST(Array2D, ReturnsNumberOfColumns) {
    auto arr = Array2D<char, 2, 3>{'a', 'b', 'c', 'd', 'e', 'f'};
    ASSERT_THAT(arr.columns_count(), Eq(3));
}

TEST(Array2D, ReturnsBeginIterator) {
    auto arr = Array2D<char, 1, 2>{'a', 'b'};
    ASSERT_THAT(*arr.begin(), Eq('a'));
}

TEST(Array2D, ReturnsEndIterator) {
    auto arr = Array2D<char, 1, 2>{'a', 'b'};
    ASSERT_THAT(*(--arr.end()), Eq('b'));
}
