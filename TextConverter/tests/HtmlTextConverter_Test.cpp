#include "FileReader.hpp"
#include "FileReaderMock.hpp"
#include "HtmlTextConverter.h"
#include <gmock/gmock.h>
#include <memory>

using namespace ::testing;

namespace {

TEST(HtmlTextConverterTest, EmptyStringConvertsToEmptyHTML)
{
    std::string const result = convert_text_to_html("");
    std::string const expected = "";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, SimpleTextConvertsToSameText)
{
    std::string const result = convert_text_to_html("abc123");
    std::string const expected = "abc123";

    ASSERT_EQ(result, expected);
}

class SpecialCharacterTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
};

TEST_P(SpecialCharacterTestFixture, SpecialCharacterIsProperlyConverted)
{
    std::string const result = convert_text_to_html(GetParam().first);
    std::string const expected = GetParam().second;

    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(SpecialCharacterTest, SpecialCharacterTestFixture,
    ::testing::Values(std::make_pair("<", "&lt;"), std::make_pair(">", "&gt;"),
        std::make_pair("&", "&amp;"), std::make_pair("\"", "&quot;"),
        std::make_pair("'", "&quot;")));

TEST(HtmlTextConverterTest, NewlineConvertsToBrTag)
{
    std::string const result = convert_text_to_html("\n");
    std::string const expected = "<br />\n";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, BossMonsterFinalTest)
{
    auto const input_string = R"(
Lorem Ipsum
This is a <b>cool</b> text about our racing car.
It's fast & reliable.
)";

    auto const expected_output_stringh = R"(<br />
Lorem Ipsum<br />
This is a &lt;b&gt;cool&lt;/b&gt; text about our racing car.<br />
It&quot;s fast &amp; reliable.<br />
)";

    std::string result = convert_text_to_html(input_string);
    ASSERT_EQ(result, expected_output_stringh);
}

TEST(FileReaderTest, FileReaderReturnsLastFilename)
{
    FileReader const reader { "my_file.txt" };
    ASSERT_EQ("my_file.txt", reader.get_last_filename());
}

class HtmlTextConverterParametrizedTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
    FileReaderMock m_file_reader;
    std::string m_expected_output;

    void SetUp() override
    {
        auto const input_string = GetParam().first;
        m_expected_output = GetParam().second;
        EXPECT_CALL(m_file_reader, get_content()).WillOnce(Return(input_string));
    }
};

TEST_P(HtmlTextConverterParametrizedTestFixture, ConvertFileToHTMLWorksAsExpected)
{
    auto const converted_text = convert_file_to_html(m_file_reader);
    ASSERT_EQ(m_expected_output, converted_text);
}

INSTANTIATE_TEST_SUITE_P(HtmlTextConverterParametrizedTest,
    HtmlTextConverterParametrizedTestFixture,
    ::testing::Values(
        std::make_pair("abcd1234", "abcd1234"), std::make_pair("abcd1234<", "abcd1234&lt;")));

} // namespace
