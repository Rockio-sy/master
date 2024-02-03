#!/bin/bash
for ((i=1;i<10;i++))
do
   num=$i
if (( num < 10 ))
then
   num="0$num"
fi
if [ -e "pos_${num}_in.txt" ] && [ -e "pos_${num}_out.txt" ] && [ -e "pos_${num}_args.txt" ]
then
    sh pos_test.sh $num
else
    break
fi
    done

echo

for ((i=1;i<16;i++))
do
    num=$i
    if (( num < 10 ))
    then
        num="0$num"
    fi
    if [ -e "neg_${num}_in.txt" ] && [ -e "neg_00_out.txt" ] && [ -e "neg_${num}_args.txt" ]
    then
        sh neg_test.sh $num
    else
        break
    fi
        done
