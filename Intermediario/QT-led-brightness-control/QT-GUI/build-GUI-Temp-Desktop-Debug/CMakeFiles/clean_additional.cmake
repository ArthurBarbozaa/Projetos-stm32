# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GUI-Temp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GUI-Temp_autogen.dir/ParseCache.txt"
  "GUI-Temp_autogen"
  )
endif()
