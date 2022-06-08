#!/bin/bash
#Script to print each name that starts with 'A' OR 'B' and contains 5 or less letters.
grep -E '^[AB].{0,4}$' name.txt