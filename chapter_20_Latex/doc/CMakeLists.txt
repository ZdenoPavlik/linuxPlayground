project(thesis NONE)

cmake_minimum_required(VERSION 2.4)

set(LATEX_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)
include(UseLATEX.cmake)

#sudo apt install texlive-full
# This is the important part.
ADD_LATEX_DOCUMENT(master.tex 
#                   BIBFILES references.bib
                   IMAGE_DIRS img
#                   INPUTS title.tex
#                          settings.tex
                    #FILTER_OUTPUT //using *.awk files
                    #USE_INDEX
                    #USE_GLOSSARY
                    ADD_CUSTOM_TARGET(pdf)
                  )

