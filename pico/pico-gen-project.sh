#/bin/bash

if [ "$#" -ne 1 ]; then
    echo "You did not enter a legal project folder name. Quitting."
    exit
fi

echo "This will create a new Raspberry Pi Pico project"
echo "in a subfolder of this folder."
echo ""
echo "Using the project folder name "$1

mkdir $1
cp CMakeLists.txt $1
cp generic.c $1
cp mycmake.sh $1
cp pico_sdk_import.cmake $1

cd $1
mkdir build
cp mycmake.sh build

echo ""
echo "Pico Project generated.  You are now in folder:"
echo ""
pwd

