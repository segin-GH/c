 # c-programs


## how to use GDB

### STEP 1. Compile the program 

```
gcc -g program.c -o program 
```

### STEP 2. Run GDB
```
gdb program
```
### STEP 3. Run the file
```
(gdb) run
```

### STEP 4. For backtrace

```
(gdb) backtrace
```

### other cmd's
```.c

(gdb) print variable
// prints variable 

(gdb) print &variable
// prints variable address

(gdb) break program.c:10
// adds breakpoint in ine :10

(gdb) next
// step over next line

(gdb) step
// step into function

(gdb) continue
// to complete the program

```



