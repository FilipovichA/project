# Минимальная версия CMake
cmake_minimum_required(VERSION 3.3)

# Предпочтительно следовать стандартам принятым в указанном диапазоне версий
cmake_policy(VERSION 3.0.2..3.7)

# Название и версия проекта и используемые языки программирования
project(FIXME VERSION 0.0.1 LANGUAGES C CXX)

###
# Обязательные переменные для MyxCMake
###
# Название организации
set(MYX_CMAKE_ORGANIZATION_NAME "FIXME" CACHE STRING "")

# Имя автора
set(MYX_CMAKE_AUTHOR_NAME "FIXME" CACHE STRING "")

# Почта автора
set(MYX_CMAKE_AUTHOR_EMAIL "FIXME" CACHE STRING "")

# Краткое описание проекта
set(MYX_CMAKE_DESCRIPTION "FIXME" CACHE STRING "")

find_package(MyxCMake 0.4.2 REQUIRED)
