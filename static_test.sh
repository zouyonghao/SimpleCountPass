mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make
cd ..
clang -Xclang -load -Xclang ./cmake-build-debug/SimpleCountPass/libSimpleCountPass.so test.c