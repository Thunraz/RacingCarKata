#include "FileReaderMock.hpp"
#include "HtmlTextConverter.h"
#include "FileReader.hpp"
#include <gmock/gmock.h>
#include <memory>

using namespace ::testing;

namespace {

TEST(HtmlTextConverterTest, EmptyStringConvertsToEmptyHTML)
{

    std::string result = convert_text_to_html("");

    std::string expected = "";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, SimpleTextConvertsToSameText)
{
    std::string result = convert_text_to_html("abc123");

    std::string expected = "abc123";

    ASSERT_EQ(result, expected);
}

class SpecialCharacterTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(SpecialCharacterTestFixture, SpecialCharacterIsProperlyConverted)
{
    std::string result = convert_text_to_html(GetParam().first);

    std::string expected = GetParam().second;

    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(SpecialCharacterTest, SpecialCharacterTestFixture,
    ::testing::Values(std::make_pair("<", "&lt;"), std::make_pair(">", "&gt;"),
        std::make_pair("&", "&amp;"), std::make_pair("\"", "&quot;"),
        std::make_pair("'", "&quot;")));

TEST(HtmlTextConverterTest, NewlineConvertsToBrTag)
{
    std::string result = convert_text_to_html("\n");

    std::string expected = "<br />\n";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, BossMonsterFinalTest)
{
    std::string result = convert_text_to_html(R"(
Lorem Ipsum
This is a <b>cool</b> text about our racing car.
It's fast & reliable.
)");

    std::string expected = R"(<br />
Lorem Ipsum<br />
This is a &lt;b&gt;cool&lt;/b&gt; text about our racing car.<br />
It&quot;s fast &amp; reliable.<br />
)";

    ASSERT_EQ(result, expected);
}

TEST(FileReaderTest, FileReaderReturnsLastFilename)
{
    FileReader reader{"my_file.txt"};
    ASSERT_EQ("my_file.txt", reader.get_last_filename());
}

class HtmlTextConverterParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(HtmlTextConverterParametrizedTestFixture, ConvertFileToHTMLWorksAsExpected)
{
    auto const input_string = GetParam().first;
    auto const expected_output = GetParam().second;
    FileReaderMock file_reader;
    EXPECT_CALL(file_reader, get_content()).WillOnce(Return(input_string));

    auto const converted_text = convert_file_to_html(file_reader);

    ASSERT_EQ(expected_output, converted_text);
}

INSTANTIATE_TEST_SUITE_P(HtmlTextConverterParametrizedTest,
    HtmlTextConverterParametrizedTestFixture,
    ::testing::Values(
        std::make_pair("abcd1234", "abcd1234"), std::make_pair("abcd1234<", "abcd1234&lt;")));

} // namespace
