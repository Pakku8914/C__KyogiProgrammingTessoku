#!/bin/bash

for num in {10..20}
do
    if [ $num -lt 10 ]
    then
        mkdir "a0${num}" && touch a0${num}/a0${num}.c
        mkdir b0${num} && touch b0${num}/b0${num}.c
        mkdir c0${num} && touch c0${num}/c0${num}.c
    elif (( num > 69 ));
    then
        mkdir a${num} && touch a${num}/a${num}.c
    elif (( num > 20 ))
    then
        mkdir a${num} && touch a${num}/a${num}.c
        mkdir b${num} && touch b${num}/b${num}.c
    else
        mkdir a${num} && touch a${num}/a${num}.c
        mkdir b${num} && touch b${num}/b${num}.c
        mkdir c${num} && touch c${num}/c${num}.c
    fi
done