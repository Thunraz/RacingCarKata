#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

namespace {

TEST(HtmlTextConverterTest, ReturnsCorrectFilename)
{
    HtmlTextConverter const converter { "foo" };
    ASSERT_EQ("foo", converter.getFilename());
}

TEST(HtmlTextConverterTest, ConvertToHtmlFailsForInvalidFileName)
{

    auto fn = []() {
        HtmlTextConverter converter { "?ThisWontWork?" };
        try {
            converter.convertToHtml();
        } catch (std::invalid_argument& e) {
            EXPECT_STREQ(e.what(), "Invalid file name");
            throw;
        }
    };
    ASSERT_THROW(fn(), std::invalid_argument);
}


TEST(HtmlTextConverterTest, EmptyStringConvertsToEmptyHTML)
{
    HtmlTextConverter converter { "" };

    std::string result = converter.convert("");

    std::string expected = "";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, SimpleTextConvertsToSameText)
{
    HtmlTextConverter converter { "" };

    std::string result = converter.convert("abc123");

    std::string expected = "abc123";

    ASSERT_EQ(result, expected);
}


class SpecialCharacterTestFixture
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {};

TEST_P(SpecialCharacterTestFixture,
       SpecialCharacterIsProperlyConverted) {
    HtmlTextConverter converter { "" };

    std::string result = converter.convert(GetParam().first);

    std::string expected = GetParam().second;

    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(SpecialCharacterTest,
                         SpecialCharacterTestFixture,
                         ::testing::Values(std::make_pair("<", "&lt;")));


TEST(HtmlTextConverterTest, NewlineConvertsToBrTag)
{
    HtmlTextConverter converter { "" };

    std::string result = converter.convert("\n");

    std::string expected = "<br />\n";

    ASSERT_EQ(result, expected);
}

TEST(HtmlTextConverterTest, BossMonsterFinalTest)
{
    HtmlTextConverter converter { "" };

    std::string result = converter.convert(R"(
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

} // namespace
