#include "string_to_binary_convertion/StrToBinConverter.hpp"

#include <gmock/gmock.h>

using namespace testing;

TEST(StrToBinConverter, ReturnsCorrectFromUppercaseHexString)
{
    ASSERT_THAT(StrToBinConverter::convert("BAADF00D"),
                ElementsAre(0xBA, 0xAD, 0xF0, 0x0D));
}

TEST(StrToBinConverter, ReturnsCorrectFromLowercaseHexString)
{
    ASSERT_THAT(StrToBinConverter::convert("baadf00d"),
                ElementsAre(0xBA, 0xAD, 0xF0, 0x0D));
}

TEST(StrToBinConverter, InsertsLeadingZeroWhenPassedOddCharactersLength)
{
    ASSERT_THAT(StrToBinConverter::convert("BADF00D"),
                ElementsAre(0x0B, 0xAD, 0xF0, 0x0D));
}

TEST(StrToBinConverter, DeserializesHexstringSpaceSeparated)
{
    ASSERT_THAT(StrToBinConverter::convert("BA AD F0 0D", ' '),
                ElementsAre(0xBA, 0xAD, 0xF0, 0x0D));
}