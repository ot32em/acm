for main in `ls main*.cpp`; do
    echo $main;
done

for i in `seq 1 10`; do
    if [ -e ${i}.in ] && [ -e ${i}.out ]; then
        echo ${i}.in
    fi
done


