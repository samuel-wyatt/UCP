#!/bin/bash
#Script to print each name in "name.txt" that does not have a vowel as the last letter.
grep -E -v "*[aeiou]$" name.txt