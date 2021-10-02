#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

namespace {

TEST(HtmlTextConverterTest, ReturnsCorrectFilename) {
  HtmlTextConverter const converter{"foo"};
  ASSERT_EQ("foo", converter.getFilename());
}

TEST(HtmlTextConverterTest, ConvertToHtmlFailsForInvalidFileName) {
  HtmlTextConverter converter{"?ThisWontWork?"};

  ASSERT_ANY_THROW(converter.convertToHtml());
}

} // namespace
