cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set("abc" "123") # : 'abc', : '123'
set("ab c" "456") # : 'ab c', : '456'
set("ab?C" "789") # : 'ab?c', : '789'
set("/usr/bin/bash" "987") # : '/usr/bin/bash', : '987'
set("C:\\Program Files\\" "654") # : 'C:\Program Files\', : '654'
set(" " "321") # : ' ' , : '321'

function(print_name varname)
    message("Variable name: '${varname}', value : '${${varname}}'")
endfunction()

print_name("abc")
print_name("ab c")
print_name("ab?c")
print_name("usr/bin/bash")
print_name("C:\\Program Files\\")
print_name(" ")
