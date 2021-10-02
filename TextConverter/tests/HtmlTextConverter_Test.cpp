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

TEST(HtmlTextConverterTest, Convert)
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
