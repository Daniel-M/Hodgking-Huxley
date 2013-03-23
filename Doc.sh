rm -rf doc
doxygen HH-model.cfg
cd doc
make
okular refman.pdf &
cd ..
