cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/g++-9 -DCMAKE_C_COMPILER=/usr/bin/gcc-9 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# ln -s compile_commands.json ../compile_commands.json
cp compile_commands.json ..
