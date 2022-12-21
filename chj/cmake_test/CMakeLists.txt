cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set(root "real val")
message(root) # root
message(${root}) # real val