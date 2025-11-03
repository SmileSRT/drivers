### Скачать модуль ядра simple.c, собрать
```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ make
make -C /lib/modules/6.8.0-85-generic/build/ M=/home/aakorovichev/Projects/drivers/task_2 modules
make[1]: Entering directory '/usr/src/linux-headers-6.8.0-85-generic'
warning: the compiler differs from the one used to build the kernel
  The kernel was built by: aarch64-linux-gnu-gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
  You are using:           gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
  CC [M]  /home/aakorovichev/Projects/drivers/task_2/main.o
  MODPOST /home/aakorovichev/Projects/drivers/task_2/Module.symvers
  CC [M]  /home/aakorovichev/Projects/drivers/task_2/main.mod.o
  LD [M]  /home/aakorovichev/Projects/drivers/task_2/main.ko
  BTF [M] /home/aakorovichev/Projects/drivers/task_2/main.ko
Skipping BTF generation for /home/aakorovichev/Projects/drivers/task_2/main.ko due to unavailability of vmlinux
make[1]: Leaving directory '/usr/src/linux-headers-6.8.0-85-generic'
```

### Вставить модуль ядра
```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ sudo insmod main.ko
```

### Проверить
```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ lsmod | grep main
main                   12288  0

aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ sudo dmesg | grep Hello
[ 4038.730390] Hello from the mai 307 team
```

### Удалить модуль ядра
```
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ sudo rmmod main.ko
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ lsmod | grep main
aakorovichev@ubuntu-22-04:~/Projects/drivers/task_2$ sudo dmesg | grep Goodbye
[ 4095.120291] Goodbye from the mai 307 team!
```
