echo "Compiling all programs."
g++ -g -o mainthread-1matrix mainthread-1matrix.cpp
g++ -g -o mainthread-2matrix mainthread-2matrix.cpp
g++ -g -o onethread onethread.cpp
g++ -g -o twothread twothread.cpp
g++ -g -o fourthread fourthread.cpp
echo "Compilation Successfull"

echo "Main Thread on 1000x1000 matrix"
time ./mainthread-1matrix
echo "Main Thread on two 500x1000 matrices one after the other"
time ./mainthread-2matrix
echo "Single Thread on 1000x1000 matrix"
time ./onethread
echo "Two Threads on 500x1000 matrices each"
time ./twothread
echo "Four Threads on 250x1000 matrices each"
time ./fourthread
