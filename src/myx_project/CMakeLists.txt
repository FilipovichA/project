# Название основной цели и имени программы в текущем каталоге
set(TRGT myx_project)

# cmake-format: off
###
# Списки файлов проекта
###
# Исходные коды
set(TRGT_cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/DataBaseWork.cpp
${CMAKE_CURRENT_SOURCE_DIR}/form.cpp
${CMAKE_CURRENT_SOURCE_DIR}/dbconnect.cpp)
# Заголовочные файлы, для которых необходима обработка препроцессором moc
# (содержат класс, унаследованный от QObject, использующий сигналы и/или слоты)
set(TRGT_moc_hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DataBaseWork.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/form.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dbconnect.hpp)
# Другие заголовочные файлы
set(TRGT_hpp)

# Файлы с описанием графического интерфейса для Qt
set(TRGT_ui
${CMAKE_CURRENT_SOURCE_DIR}/form.ui
${CMAKE_CURRENT_SOURCE_DIR}/dbconnect.ui)
# Файлы описания ресурсов, включаемых в исполняемый файл
set(TRGT_qrc
  ${CMAKE_SOURCE_DIR}/files/share/icon.qrc)
###
# Конец списков файлов
###
#cmake-format: on

set(TRGT_headers ${TRGT_hpp} ${TRGT_moc_hpp})

# Правило для автоматической генерации препроцессором uic
qt5_wrap_ui(TRGT_ui_h ${TRGT_ui})

# Правило для автоматической генерации препроцессором moc
qt5_wrap_cpp(TRGT_moc_cpp ${TRGT_moc_hpp})

# Поиск строк для локализации в файлах, перечисленных в ${TRGT_cpp} ${TRGT_ui}
# Создание и обновление файлов переводов в каталоге ${CMAKE_SOURCE_DIR}/l10n
# Интеграция переводов в исполняемый файл для подключения классом QTranslator
myx_cmake_qt5_translation(TRGT_qrc_cpp
  OUTPUT_DIR ${CMAKE_SOURCE_DIR}/l10n
  BASE_NAME ${TRGT}
  SOURCES ${TRGT_cpp} ${TRGT_ui}
  LANGUAGES ru_RU)

# Правило для автоматической генерации препроцессором qrc
qt5_add_resources(TRTG_qrc_cpp ${TRGT_qrc})

# Функция для создания цели, результатом которой будет сборка приложения
add_executable(${TRGT} ${TRGT_headers} ${TRGT_ui_h} ${TRGT_moc_cpp} ${TRGT_qrc_cpp} ${TRGT_cpp})


#подключение внешнего проекта
#add_dependencies(${TRGT} extlib)
#target_link_libraries(${TRGT} myx-cmake-example-library)
# Qt5: подключение заголовочных файлов
target_include_directories(${TRGT} SYSTEM PUBLIC ${Qt5Core_INCLUDE_DIRS})
target_include_directories(${TRGT} SYSTEM PUBLIC ${Qt5Gui_INCLUDE_DIRS})
target_include_directories(${TRGT} SYSTEM PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
target_include_directories(${TRGT} SYSTEM PUBLIC ${Qt5Sql_INCLUDE_DIRS})
# Qt5: подключение библиотек
target_link_libraries(${TRGT} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)
myx_cmake_common_target_properties(${TRGT})
myx_cmake_common_target_properties_post_link(${TRGT})


