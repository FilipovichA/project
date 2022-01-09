
# Минимальная версия CMake
cmake_minimum_required(VERSION 3.3)

# Предпочтительно следовать стандартам принятым в указанном диапазоне версий
cmake_policy(VERSION 3.0.2..3.7)

# Название и версия проекта и используемые языки программирования
project(myx VERSION 0.0.1 LANGUAGES C CXX)

###
# Обязательные переменные для MyxCMake
###
# Название организации
set(MYX_CMAKE_ORGANIZATION_NAME "организация" CACHE STRING "")

# Имя автора
set(MYX_CMAKE_AUTHOR_NAME "Александр" CACHE STRING "")

# Почта автора
set(MYX_CMAKE_AUTHOR_EMAIL "sasha_filipovich_00@mail.ru" CACHE STRING "")

# Краткое описание проекта
set(MYX_CMAKE_DESCRIPTION "myx" CACHE STRING "")


find_package(MyxCMake 0.4.2 REQUIRED)
find_package(Qt5Core COMPONENTS Private REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Sql Widgets REQUIRED)
#подключение внешнего проекта
#include(ExternalProject)
#ExternalProject_Add(extlib
 # EXCLUDE_FROM_ALL  TRUE
  #SOURCE_DIR        ${CMAKE_SOURCE_DIR}/thirdparty
 # INSTALL_DIR       ${CMAKE_BINARY_DIR}
  #DOWNLOAD_COMMAND  ""
  #BUILD_BYPRODUCTS  <INSTALL_DIR>/lib/libmyx-cmake-example-library.a
  #CMAKE_ARGS        ${MYX_CMAKE_EXTERNAL_PROJECT_ARGS} -DBUILD_MYX_CMAKE_EXAMPLE_LIBRARY_SHARED=OFF
  #)
myx_cmake_generate_private_config_header()
myx_cmake_generate_git_info_header()
add_subdirectory(src/myx_project)
myx_cmake_doc_doxygen(LATEX YES HTML YES)
