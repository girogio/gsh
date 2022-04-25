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


cmake_minimum_required(VERSION 2.8.12)

project(tish)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./)

add_executable(tish ../src/tinyshell.c ../lib/linenoise.c ../src/proc.c ../src/tokenizer.c ../src/parser.c ../src/builtins.c)