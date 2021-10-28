#!/usr/bin/env bash

# we run clang-format and astyle twice to get stable format output
# 感谢nihui, 感谢ncnn，白嫖党福利

find src/ test/ -type f -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' | xargs -i clang-format -i {}
astyle -n -r "test/*.h,*.cpp,*.cc"
astyle -n -r "src/*.h,*.cpp,*.cc"

find src/ test/ -type f -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' | xargs -i clang-format -i {}
astyle -n -r "test/*.h,*.cpp,*.cc"
astyle -n -r "src/*.h,*.cpp,*.cc"