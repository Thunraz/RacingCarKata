#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

namespace {

// TEST(HtmlTextConverterTest, ReturnsCorrectFilename)
// {
//     ASSERT_EQ("foo", converter.getFilename());
// }

// TEST(HtmlTextConverterTest, ConvertToHtmlFailsForInvalidFileName)
// {

//     auto fn = []() {
//         try {
//             converter.convertToHtml();
//         } catch (std::invalid_argument& e) {
//             EXPECT_STREQ(e.what(), "Invalid file name");
//             throw;
//         }
//     };
//     ASSERT_THROW(fn(), std::invalid_argument);
// }

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

TEST(FileReaderTest, FileReaderReturnsEmptyStringByDefault)
{
    FileReader reader;
    ASSERT_EQ("", reader.get_last_filename());
}

TEST(FileReaderTest, FileReaderReturnsLastFilename)
{
    FileReader reader;
    reader.get_content("my_file.txt");
    ASSERT_EQ("my_file.txt", reader.get_last_filename());
}

TEST(HtmlTextConverterTest, FileReaderThrowsExceptionForInvalidFilename)
{
    auto fn = []() {
        FileReader reader;
        try {
            reader.get_content("?invalid?");
        } catch (std::invalid_argument& e) {
            EXPECT_STREQ(e.what(), "Invalid file name");
            throw;
        }
    };
    ASSERT_THROW(fn(), std::invalid_argument);
}

} // namespace
