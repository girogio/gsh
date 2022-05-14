#            _
#   __ _ ___| |__
#  / _` / __| '_ \
# | (_| \__ \ | | |
#  \__, |___/_| |_|
#  |___/
#                    
# ______________________________________________________                                              
#        _                 _             _          _ _
#   __ _(_) ___  _ __ __ _(_) ___    ___| |__   ___| | |
#  / _` | |/ _ \| '__/ _` | |/ _ \  / __| '_ \ / _ \ | |
# | (_| | | (_) | | | (_| | | (_) | \__ \ | | |  __/ | |
#  \__, |_|\___/|_|  \__, |_|\___/  |___/_| |_|\___|_|_|
#  |___/             |___/
#


cmake_minimum_required(VERSION 3.23.1)

project(tish)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ggdb3")

add_executable(tish ../src/tinyshell.c ../lib/linenoise.c ../src/builtins.c)