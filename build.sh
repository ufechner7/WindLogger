cd out
rm -r *
cd ..
arduino-cli compile $1 --fqbn Intel:arc32:arduino_101 --build-path $PWD/out  ../WindLogger
