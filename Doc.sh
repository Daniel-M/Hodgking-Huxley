#!/bin/bash
rm -rf doc
doxygen HH-model.cfg
cd doc
cd pdflatex
make
mupdf refman.pdf
cd ..
