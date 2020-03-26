#!bin/bash

find . -name "*._*"  | xargs rm -f
find . -name "run"  | xargs rm -f
find . -name "*.txt" | xargs rm -f
