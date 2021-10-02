#include "HtmlTextConverter.h"
#include <gmock/gmock.h>

namespace {

TEST(HtmlTextConverterTest, ReturnsCorrectFilename) {
  HtmlTextConverter const converter{"foo"};
  ASSERT_EQ("foo", converter.getFilename());
}

TEST(HtmlTextConverterTest, ConvertToHtmlFailsForInvalidFileName) {

  auto fn = [](){
    HtmlTextConverter converter{"?ThisWontWork?"};
    try{
      converter.convertToHtml();
    } 
    catch(std::invalid_argument &e){
      EXPECT_STREQ(e.what(),"Invalid file name");
      throw;
    }
  };
  ASSERT_THROW(fn(),std::invalid_argument);
}



} // namespace
