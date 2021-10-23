
add_library(TextConverter
	include/HtmlPagesConverter.h
	include/HtmlTextConverter.h
	include/StringEscapeUtils.h
	include/FileReader.hpp
	source/HtmlPagesConverter.cpp
	source/HtmlTextConverter.cpp
	source/FileReader.cpp
)
target_include_directories(TextConverter PUBLIC include )
set_property(TARGET TextConverter PROPERTY CXX_STANDARD 17)
add_subdirectory(tests)