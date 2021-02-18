add_library(ScraperSanatizer SQLite3ScraperSanatizer.cc)
target_include_directories(ScraperSanatizer PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(
  TARGETS ScraperSanatizer
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(ScraperSanatizer PROPERTIES INSTALL_RPATH
    "$LD_LIBRARY_PATH;${CMAKE_INSTALL_PREFIX}/lib")
